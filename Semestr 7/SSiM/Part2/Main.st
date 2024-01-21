
PROGRAM _INIT
	(* Insert code here *)
	Controller := AUTO;
	Motor.aoPeriodDuration := 100;
	SystemPars.fSpeedPar.rGain := 1;
	SystemPars.fSpeedPar.rTimeConst := 0.01; // Filtracja szymu 100Hz
	SystemPars.temperature.uiMax := 500;
	fPidPars[0].uiCvMax := 32767;
	fPidPars[0].uiCvMin := -32767;
END_PROGRAM

// SP - set point - wartosc zadana
// E - blad regulacji
// CV - control value (sygnal niskiej mocy)
// MV - manipulated value - sygnal wykonawczo nastawczy - napiecie - (sygnal wysokiej mocy)
// PV - process value - sygnal sterowany, pomierzony

PROGRAM _CYCLIC
	(* Wyliczenie predkosci *)
	fSpeed[0].Enable := TRUE;
	fSpeed[0].In := Motor.rPosition;
	fSpeed[0].Gain := SystemPars.fSpeedPar.rGain;
	fSpeed[0].TimeConstant := SystemPars.fSpeedPar.rTimeConst;
	fSpeed[0]();
	//Motor.rSpeed := fSpeed[0].Out;
	
	fScale[1].x := fSpeed[0].Out;
	fScale[1].x1 := -50000;
	fScale[1].y1 := -100;
	fScale[1].x2 := 50000;
	fScale[1].y2 := 100;
	fScale[1]();
	
	Motor.rSpeed := fScale[1].y;
	
	fStatistics[0].Enable := TRUE;
	fStatistics[0].In := Motor.rSpeed;
	fStatistics[0]();
	
	(* Bazowanie *)
	IF EDGEPOS(Operator.diHome) THEN
		SystemPars.rPositionHome := Motor.aiPosition;
	END_IF
	
	Motor.rPosition := DINT_TO_REAL(Motor.aiPosition - SystemPars.rPositionHome);
	
	Operator.aoDisplay[1] := Motor.aoPWM;
	
	(* Start - stop *)
	fRS[0].SET := Operator.diStart;
	fRS[0].RESET1 := Operator.diStop OR Operator.diEStop OR Operator.doAwaria;
	fRS[0]();
	Operator.doAktywny := fRS[0].Q1;
	
	(* Obsluga awarii *)
	fSR[0].SET1 := (Motor.aiTemperature > SystemPars.temperature.uiMax);
	fSR[0].RESET := Operator.diReset;
	fSR[0]();
	Operator.doAwaria := fSR[0].Q1;
	
	CASE Controller OF
		NONE:
		MANUAL:
			IF Operator.doAktywny THEN
				fScale[0].x := INT_TO_REAL(Operator.aiSetter[0]);
				fScale[0].x1 := 0;
				fScale[0].y1 := -32767;
				fScale[0].x2 := 32767;
				fScale[0].y2 := 32767;
				fScale[0]();
				
				IF fScale[0].y > 1000 OR fScale[0].y < -1000 THEN
					Motor.aoPWM := REAL_TO_INT(fScale[0].y);
				ELSE
					Motor.aoPWM := 0;
				END_IF
			ELSE
				Motor.aoPWM := 0;
			END_IF
		AUTO:
			fPID[0].Enable := Operator.doAktywny;
			fPID[0].ActValue := Motor.rSpeed; // pv
			fPID[0].SetValue := SystemPars.rSetSpeed; // sp <-100, 100>
			fPID[0]();
			fPID[0].MaxOut := fPidPars[0].uiCvMax;
			fPID[0].MinOut := fPidPars[0].uiCvMin;
			fPID[0].PIDParameters.Gain := fPidPars[0].fPIDParameters.Gain; // KP wzmocnienie czesci 
			fPID[0].PIDParameters.IntegrationTime := fPidPars[0].fPIDParameters.IntegrationTime; // TI - stala czasowa calkowania
			fPID[0].PIDParameters.DerivativeTime := fPidPars[0].fPIDParameters.DerivativeTime; // TD - stala czasowa rozniczkowania
			fPID[0].PIDParameters.FilterTime := fPidPars[0].fPIDParameters.FilterTime;
			
			IF (fPID[0].Update = TRUE) THEN
				fPID[0].Update := FALSE;
			END_IF
			
			IF Operator.doAktywny THEN
				Motor.aoPWM := REAL_TO_INT(fPID[0].Out);
			ELSE
				Motor.aoPWM := 0;
			END_IF
	END_CASE;
	 
END_PROGRAM

PROGRAM _EXIT
	(* Insert code here *)
	 
END_PROGRAM

