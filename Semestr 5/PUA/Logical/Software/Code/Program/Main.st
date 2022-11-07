
PROGRAM _INIT
	(* Insert code here *)
	uiLightControl := 7;
	//uiClockTON_PT[1] := 1;
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
			Opearator.doAktywny := (EDGEPOS(Opearator.diStart) OR Opearator.doAktywny) AND NOT (Opearator.diStop) AND NOT(Opearator.doAwaria); (* Start odpali sie tylko raz *)
			Opearator.doAwaria := Engine.diTermikNO OR (Opearator.doAwaria AND NOT(Opearator.diReset));
	END_CASE;
END_PROGRAM

PROGRAM _EXIT
	(* Insert code here *)
	 
END_PROGRAM

