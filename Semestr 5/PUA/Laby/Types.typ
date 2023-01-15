TYPE
	RoomStruct : STRUCT
		diToogle : ARRAY[1..2] OF BOOL; (* Wlaczniki *)
		doLamp : ARRAY[1..2] OF BOOL; (* Lampy *)
		aiTemperature : INT; (* Temperatura *)
		diPhotoCom : ARRAY[1..2] OF BOOL; (* Fotokomorka *)
		aiDimmer : ARRAY[1..2] OF INT; (* Obsluga sciemniacza *)
		aoLamp : ARRAY[1..2] OF INT; (* Obsluga lampy sciemnianej *)
		Dryer : DryerStruct;
	END_STRUCT;
	
	StairsStruct : STRUCT
		diParter : BOOL;
		diPietro : BOOL;
		doLamp : BOOL;
	END_STRUCT;
	
	HouseStruct : STRUCT
		Jadalnia : RoomStruct;
		Kuchnia : RoomStruct;
		Sypialnia : RoomStruct;
		Korytarz : RoomStruct;
		Schody : StairsStruct;
		Lazienka : RoomStruct;
	END_STRUCT;
	
	OperatorStruct : STRUCT
		diStart : BOOL;
		diStop : BOOL;
		diEStop : BOOL;
		doAktywny : BOOL;
		doAwaria : BOOL;
		diReset : BOOL;
		aiSetter : INT;
	END_STRUCT;
	
	EngineStruct : STRUCT
		diTermikNO : BOOL; (* Czujnik termiczny : TRUE - za wysoka temperatura, FALSE - temperatura OK => DI11 *)
		diTermikNC : BOOL; (* Czujnik termiczny : FALSE - za wysoka temperatura, TRUE - temperatura OK => DI12 *)
		doOnOff : BOOL; (* Wysterowanie silnika *)
	END_STRUCT;
	
	SensorNONCStruct : STRUCT
		uiSetValue : INT;
		uiOutNC : BOOL;
		uiOutNO : BOOL;
	END_STRUCT;
	
	TankStruct : STRUCT
		doHeater : BOOL; (* Odpowiednik pompy w hydroforze *)
		diTermik : BOOL; (* Odpowiednik zabezpieczenia stykow silnika pompy w hydroforze *)
		aiTemperature : INT;
		aoHeater : INT;
		aoFan : INT;
		uiHeaterSetValue : INT;
		ThermoMin : SensorNONCStruct;
		ThermoMax : SensorNONCStruct;
	END_STRUCT;
	
	StatisticsStruct : STRUCT
		uiWorkTime : ARRAY[1..10] OF TimeStruct;
	END_STRUCT;
	
	TimeStruct : STRUCT
		uiSeconds : USINT;
		uiMinues : USINT;
		uiHours : DINT;
	END_STRUCT;
	
	DryerStruct : STRUCT
		diHand : BOOL; (* czujnik wykrywania rak - laser lub fotokomroka NO/NC *)
		diTermik : BOOL; (* czujnik przeciazeniowy stycznika zalaczajacego grzalke i wentylator NO/NC *)
		doDryer : BOOL; (* stycznik -> wentylator i grzalka *)
	END_STRUCT;
	
	StateMachineEnum : (
		INIT := 1,
		HEAT_UP := 2,
		TEMP_CONST := 3,
		HEAT_DOWN := 4,	
		WAIT_STOP := 5,
		FAILURE := 6,
		STOP_TEMP := 7
	);
	
	FurnaceStruct : STRUCT
		aoHeater : INT;
		aoFan : INT;
		aiTemperature : INT;
		uiHeater : REAL;
		uiFan : REAL;
		uiTemperature : REAL;
		diTempFailure : BOOL;
		uiTempFailure : BOOL;
	END_STRUCT;
	
	HeatingSystemStruct : STRUCT
		Operator : OperatorStruct;
		Furnace : FurnaceStruct;
	END_STRUCT;

	HeatingSystemParStruct : STRUCT
		uiSetTime : ARRAY[1..10] OF REAL;
		uiSetTemperature : ARRAY[1..10] OF REAL;
	END_STRUCT;
	
	cOnOffStruct : STRUCT
		inPV : REAL;
		outCV : REAL;
		error : REAL;
	END_STRUCT;

	cOnOffParStruct : STRUCT
		E_min : REAL;
		E_max : REAL;
		CV_max : REAL;
		CV_min : REAL;
	END_STRUCT;
	
END_TYPE