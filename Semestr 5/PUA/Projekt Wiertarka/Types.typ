TYPE
	StateMachineEnum: (
		INIT := 0, (* Drill waiting for start signal *)
		DRILL_PREP := 1, (* Drill preparation for work *)
		DRILLING := 2, (* Drilling in progress *)
		RETRACTING :=3, (* Drill retracting after drilling is done *)
		DRILL_STOPPING := 4, (* Drilling stopping *)
		PAUSED := 5, (* Drilling paused *)
		FAILURE := 6 (* Error occured *)
	);
	
	FailureEnum: (
		NO_ERROR := 0, (* No error *)
		DRILL_MOTOR_NOK := 1, (* Drill motor didn't turn on *)
		END_POS_UNREACHABLE := 2, (* Drill couldn't reach end position *)
		START_POS_UNREACHABLE := 3, (* Dril couldn't reach start position *)
		DRILL_MOTOR_OVERHEAT := 4, (* Drill motor overheated *)
		ESTOP := 5 (* EStop pressed *)
	);
	
	AlarmsStruct : STRUCT
		current : ARRAY[0..9] OF BOOL;
		acknowledge : ARRAY[0..9] OF BOOL;
	END_STRUCT;

	OperatorStruct : STRUCT
		diStart : BOOL; (* Start button *)
		diStop : BOOL;	(* Stop button *)
		diEStop : BOOL; (* Emergency stop button *)
		diConfirmFailure : BOOL; (* Failure clear button *)
		doActive : BOOL; (* Active state *)
	END_STRUCT;
	
	LightsStruct : STRUCT
		doActiveLED : BOOL; (* Machine active LED *)
		doPausedLED : BOOL; (* Machine paused LED *)
		doFailureLED : BOOL; (* Machine stopped because of error LED *)
	END_STRUCT;
	
	DrillStruct : STRUCT
		diThermMotorOK : BOOL; (* Motor temperature sensor *)
		diPowerMotorOK : BOOL; (* Motor power sensor *)
		doPowerMotor : BOOL; (* Drill motor power switch *)
		doDirMotor : BOOL; (* Drill direction switch; TRUE - clockwise, FALSE - counter clockwise *)
	END_STRUCT;
	
	FeedStruct : STRUCT
		diStartPosition : BOOL; (* Drill top position sensor *)
		diEndPosition : BOOL; (* Drill bottom position sensor *)
		doFeedPower : BOOL; (* Feeding motor power switch *)
		doDirFeed : BOOL; (* Drill vertical direction; TRUE - downwards, FALSE - upwards *) 
	END_STRUCT;
END_TYPE