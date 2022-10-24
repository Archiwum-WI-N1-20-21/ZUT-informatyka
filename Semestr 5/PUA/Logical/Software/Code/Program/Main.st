
PROGRAM _INIT
	(* Insert code here *)
	uiLightControl := 3;
	uiClockTON_PT[1] := 1;
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
			ClockTON[1].PT := REAL_TO_TIME(uiClockTON_PT[1] * 1000);
			ClockTON[1]();
			Home.Jadalnia.doLamp[1] := Home.Jadalnia.diToogle[2] AND (ClockTON[1].Q XOR Home.Jadalnia.doLamp[1]);
	END_CASE;
END_PROGRAM

PROGRAM _EXIT
	(* Insert code here *)
	 
END_PROGRAM

