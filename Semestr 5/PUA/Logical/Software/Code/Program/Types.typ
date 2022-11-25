TYPE
	RoomStruct : STRUCT
		diToogle : ARRAY[1..2] OF BOOL; (* Wlaczniki *)
		doLamp : ARRAY[1..2] OF BOOL; (* Lampy *)
		aiTemperature : INT; (* Temperatura *)
		diPhotoCom : ARRAY[1..2] OF BOOL; (* Fotokomorka *)
		aiDimmer : ARRAY[1..2] OF INT; (* Obsluga sciemniacza *)
		aoLamp : ARRAY[1..2] OF INT; (* Obsluga lampy sciemnianej *)
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
	
END_TYPE