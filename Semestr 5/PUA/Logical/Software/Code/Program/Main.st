
PROGRAM _INIT
	(* Insert code here *)
	uiLightControl := 8;
	//uiClockTON_PT[1] := 1;
	Tank.uiHeaterSetValue := 15000;
	Tank.ThermoMin.uiSetValue := 550;
	Tank.ThermoMax.uiSetValue := 600;
END_PROGRAM

PROGRAM _CYCLIC
	(* Insert code here *)
	CASE uiLightControl OF
		1 : // Klasyczne sterowanie
			Home.Jadalnia.doLamp[1] := Home.Jadalnia.diToogle[1];
			
		2: // Dotyk
			Home.Jadalnia.doLamp[1] := EDGEPOS(Home.Jadalnia.diToogle[1]) XOR Home.Jadalnia.doLamp[1];
			
		3: // Mrugajace
			ClockTON[1].IN := Home.Jadalnia.diToogle[2] AND NOT (ClockTON[1].Q);
			//ClockTON[1].PT := REAL_TO_TIME(uiClockTON_PT[1] * 1000);
			ClockTON[1]();
			Home.Jadalnia.doLamp[1] := Home.Jadalnia.diToogle[2] AND (ClockTON[1].Q XOR Home.Jadalnia.doLamp[1]);
			
			IF EDGEPOS(Home.Jadalnia.doLamp[1]) THEN
				ClockTON[1].PT := REAL_TO_TIME(uiClockTON_PT[1] * 1000);
			END_IF;
			IF EDGENEG(Home.Jadalnia.doLamp[1]) THEN
				ClockTON[1].PT := REAL_TO_TIME(uiClockTON_PT[2] * 1000);
			END_IF;
		
		4: // Fotokomorka
			ClockTOF[1].IN := Home.Korytarz.diPhotoCom[1];
			ClockTOF[1].PT := REAL_TO_TIME(uiClockTOF_PT[1] * 1000);
			ClockTOF[1]();
			Home.Korytarz.doLamp[1] := ClockTOF[1].Q;
		
		5: // Potencjometr
			(*
			Scale[1].x := INT_TO_REAL(Home.Jadalnia.aiDimmer[1]); // Obsluga potencjometrem
			Scale[1].x1 := 4;
			Scale[1].y1 := 14000;
			Scale[1].x2 := 32767;
			Scale[1].y2 := 28000;
			Scale[1]();
			Home.Jadalnia.aoLamp[1] := REAL_TO_INT(Scale[1].y);
			*)
			Scale[2].x := INT_TO_REAL(Home.Jadalnia.aiDimmer[2]); // Obsluga termometrem
			Scale[2].x1 := 290;
			Scale[2].y1 := 14000;
			Scale[2].x2 := 350;
			Scale[2].y2 := 28000;
			Scale[2]();
			Home.Jadalnia.aoLamp[1] := REAL_TO_INT(Scale[2].y);	
		
		6: // Schodowy
			//Home.Schody.doLamp := Home.Schody.diParter AND NOT (Home.Schody.diPietro) OR NOT (Home.Schody.diParter) AND Home.Schody.diPietro;
			Home.Schody.doLamp := Home.Schody.diParter XOR Home.Schody.diPietro;
			IF Home.Schody.doLamp THEN
				Home.Jadalnia.aoLamp[1] := 20000;
			ELSE
				Home.Jadalnia.aoLamp[1] := 0;
			END_IF
		
		7: // Procedura start stop
			//Operator.doAktywny := (EDGEPOS(Operator.diStart) OR Operator.doAktywny) AND NOT (Operator.diStop) AND NOT(Operator.doAwaria); (* Start odpali sie tylko raz *)
			//Operator.doAwaria := Engine.diTermikNC OR (Operator.doAwaria AND NOT(Operator.diReset));
			
			Operator.doAwaria := Engine.diTermikNC OR (Operator.doAwaria AND NOT(Operator.diReset));
		
			fRS[1].SET := EDGEPOS(Operator.diStart);
			fRS[1].RESET1 := Operator.diStop OR Operator.doAwaria (* OR Operator.diEStop *);
			fRS[1]();
			Operator.doAktywny := fRS[1].Q1;
		
			fSR[1].SET1 := Tank.diTermik OR Operator.diEStop;
			fSR[1].RESET := Operator.diReset;
			fSR[1]();
			Operator.doAwaria := fSR[1].Q1;
		
			// Obsluga termostatu
			IF Tank.aiTemperature >= Tank.ThermoMax.uiSetValue THEN // Poziom temperatury wylaczania
				Tank.ThermoMax.uiOutNC := FALSE;
				Tank.ThermoMax.uiOutNO := TRUE;
			ELSE
				Tank.ThermoMax.uiOutNC := TRUE;
				Tank.ThermoMax.uiOutNO := FALSE;
			END_IF;
		
			IF Tank.aiTemperature >= Tank.ThermoMin.uiSetValue THEN // Poziom temperatury wlaczania
				Tank.ThermoMin.uiOutNC := FALSE;
				Tank.ThermoMin.uiOutNO := TRUE;
			ELSE
				Tank.ThermoMin.uiOutNC := TRUE;
				Tank.ThermoMin.uiOutNO := FALSE;
			END_IF;
			
			IF Tank.doHeater THEN // Obsluga grzalki
				Tank.aoHeater := Tank.uiHeaterSetValue;
			ELSE
				Tank.aoHeater := 0;
			END_IF;
		
			fRS[2].SET := Tank.ThermoMin.uiOutNC AND Operator.doAktywny;
			fRS[2].RESET1 := NOT(Tank.ThermoMax.uiOutNC) OR Operator.diStop;
			fRS[2]();
			Tank.doHeater := fRS[2].Q1;
			Tank.aoFan := Operator.aiSetter; // Obsluga wentylatora
		
			// Pomiar czasu pracy
			ClockTON[2].IN := Tank.doHeater AND NOT(ClockTON[2].Q);
			ClockTON[2].PT := T#1s;
			ClockTON[2]();
		
			IF ClockTON[2].Q THEN
	  			Statistic.uiWorkTime[1].uiSeconds := Statistic.uiWorkTime[1].uiSeconds + 1;
			END_IF;
			IF Statistic.uiWorkTime[1].uiSeconds >= 60 THEN
				Statistic.uiWorkTime[1].uiSeconds := 0;
				Statistic.uiWorkTime[1].uiMinues := Statistic.uiWorkTime[1].uiMinues + 1;
			END_IF;
			IF Statistic.uiWorkTime[1].uiMinues >= 60 THEN
				Statistic.uiWorkTime[1].uiMinues := 0;
				Statistic.uiWorkTime[1].uiHours := Statistic.uiWorkTime[1].uiHours + 1;
			END_IF;
			IF EDGEPOS(Operator.doAktywny) THEN
				Statistic.uiWorkTime[1].uiSeconds := 0;
				Statistic.uiWorkTime[1].uiMinues := 0;
				Statistic.uiWorkTime[1].uiHours := 0;
			END_IF;
		
		8: // obsluga suszarki do rak + pomiary czasu
			ClockTOF[3].IN := Home.Lazienka.Dryer.diHand;
			ClockTOF[3].PT := T#0.5s;
			ClockTOF[3]();
			ClockTON[3].IN := ClockTOF[3].Q;
			ClockTON[3].PT := T#15s;
			ClockTON[3]();
			Home.Lazienka.Dryer.doDryer := NOT(ClockTON[3].Q) AND ClockTOF[3].Q;
		
			// Pomiar czasu pracy
			ClockTON[2].IN := Home.Lazienka.Dryer.doDryer AND NOT(ClockTON[2].Q);
			ClockTON[2].PT := T#1s;
			ClockTON[2]();
		
			IF ClockTON[2].Q THEN
				Statistic.uiWorkTime[3].uiSeconds := Statistic.uiWorkTime[3].uiSeconds + 1;
			END_IF;
			IF Statistic.uiWorkTime[3].uiSeconds >= 60 THEN
				Statistic.uiWorkTime[3].uiSeconds := 0;
				Statistic.uiWorkTime[3].uiMinues := Statistic.uiWorkTime[3].uiMinues + 1;
			END_IF;
			IF Statistic.uiWorkTime[3].uiMinues >= 60 THEN
				Statistic.uiWorkTime[3].uiMinues := 0;
				Statistic.uiWorkTime[3].uiHours := Statistic.uiWorkTime[3].uiHours + 1;
			END_IF;
			IF EDGEPOS(Operator.diReset) THEN
				Statistic.uiWorkTime[3].uiSeconds := 0;
				Statistic.uiWorkTime[3].uiMinues := 0;
				Statistic.uiWorkTime[3].uiHours := 0;
			END_IF;
			
			
			IF EDGEPOS((TIME_TO_DINT(ClockTON[3].ET) MOD 1000) = 0) AND (TIME_TO_DINT(ClockTON[3].ET) > 0) THEN
				Statistic.uiWorkTime[4].uiSeconds := Statistic.uiWorkTime[4].uiSeconds + 1;
			END_IF;
			IF Statistic.uiWorkTime[4].uiSeconds >= 60 THEN
				Statistic.uiWorkTime[4].uiSeconds := 0;
				Statistic.uiWorkTime[4].uiMinues := Statistic.uiWorkTime[4].uiMinues + 1;
			END_IF;
			IF Statistic.uiWorkTime[4].uiMinues >= 60 THEN
				Statistic.uiWorkTime[4].uiMinues := 0;
				Statistic.uiWorkTime[4].uiHours := Statistic.uiWorkTime[4].uiHours + 1;
			END_IF;
			IF EDGEPOS(Operator.diReset) THEN
				Statistic.uiWorkTime[4].uiSeconds := 0;
				Statistic.uiWorkTime[4].uiMinues := 0;
				Statistic.uiWorkTime[4].uiHours := 0;
			END_IF;
	END_CASE;
END_PROGRAM

PROGRAM _EXIT
	(* Insert code here *)
	 
END_PROGRAM

