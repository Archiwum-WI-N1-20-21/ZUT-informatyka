TYPE
	RoomStruct : STRUCT
		diToogle : ARRAY[1..2] OF BOOL; (* Wlaczniki *)
		doLamp : ARRAY[1..2] OF BOOL; (* Lampy *)
		aiTemperature : INT; (* Temperatura *)
		diPhotoCom : ARRAY[1..2] OF BOOL; (* Fotokomorka *)
		aiDimmer : ARRAY[1..2] OF INT; (* Obsluga sciemniacza *)
		aoLamp : ARRAY[1..2] OF INT; (* Obsluga lampy sciemnianej *)
	END_STRUCT;
	
	HouseStruct : STRUCT
		Jadalnia : RoomStruct;
		Kuchnia : RoomStruct;
		Sypialnia : RoomStruct;
		Korytarz : RoomStruct;
	END_STRUCT;
	
END_TYPE