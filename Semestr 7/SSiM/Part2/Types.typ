
TYPE
	MotorStruct : 	STRUCT 
		aoPWM : INT; (* Wypelnienie *)
		aiPosition : DINT; (* Pozycja osi *)
		rSpeed : REAL; (* Wyliczona predkosc na podstawie aiPosition *)
		aiSpeed : INT; (* Predkosc zadana *)
		aiTemperature : INT; 
		aiCurrent : INT;
		aoPeriodDuration : UINT; (* Okres sygnalu PWM *)
		rPosition : REAL; (* Pozycja relatywna *) 
	END_STRUCT;
	OperatorStruct : 	STRUCT
		diStart : BOOL;
		diStop : BOOL;
		diEStop : BOOL;
		diReset : BOOL;
		doAktywny : BOOL;
		doAwaria : BOOL;
		aiSetter : ARRAY[0..1] OF INT;
		aoDisplay : ARRAY[0..1] OF INT;
		diHome : BOOL; (* Przycisk do kalibracji bazy *)
	END_STRUCT;
	SystemParTyp : 	STRUCT 
		speed : LimitsStruct;
		current : LimitsStruct;
		temperature : LimitsStruct;
		position : LimitsStruct;
		uiPeriodDuration : UINT;
		rPositionHome : DINT; (* Pozycja po bazowaniu *)
		fSpeedPar : SpeedParStruct;
		rSetSpeed : REAL; (* wartosc zadana so - predkosc zadana *)
	END_STRUCT;
	SpeedParStruct : STRUCT
	rGain : REAL;
	rTimeConst : REAL;
	END_STRUCT;
	LimitsStruct : STRUCT
		uiMax : REAL;
		uiMin : REAL;
		uiSetValue : REAL;
		uiLo : REAL;
		uiHi : REAL;
		uiLoLo : REAL;
		uiHiHi : REAL;
	END_STRUCT;
	
	fPidParTyp : STRUCT
		fPIDParameters : MTPIDParametersType;
		uiCvMax : REAL; (* maksymalna amplituda sygnalu cv *)
		uiCvMin : REAL; (* minimalna amplituda sygnalu cv *)
	 
	END_STRUCT;
	
	ControlTyp :
		(
		NONE := 0,
		MANUAL := 1,
		AUTO := 2
	 
	);
END_TYPE
