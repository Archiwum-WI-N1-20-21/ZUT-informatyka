TYPE
	RoomStruct : STRUCT
		diToogle : ARRAY[1..2] OF BOOL; (* Wlaczniki *)
		doLamp : ARRAY[1..2] OF BOOL; (* Lampy *)
		aiTemperature : INT; (* Temperatura *)
	END_STRUCT;
	
	HouseStruct : STRUCT
		Jadalnia : RoomStruct;
		Kuchnia : RoomStruct;
		Sypialnia : RoomStruct;
	END_STRUCT;
	
END_TYPE