PROGRAM _CYCLIC
	IF NOT(Operator.diEStop) THEN (* If Estop pressed, go to failure *)
		FailureReason := ESTOP;
		Alarms.current[0] := TRUE;
		StateMachine := FAILURE;
	END_IF;
			
	IF Drill.diThermMotorOK THEN (* If engine overheats, throw error *)
		FailureReason := DRILL_MOTOR_OVERHEAT;
		Alarms.current[1] := TRUE;
		StateMachine := FAILURE;
	END_IF;
	
	gAlarm := FALSE; (* Handling alarms *)
	FOR i := 0 TO 9 DO
		IF Alarms.current[i] OR Alarms.acknowledge[i] THEN
			gAlarm := TRUE;
		END_IF;
	END_FOR;
	
	CASE StateMachine OF
		INIT:
			CheckDrillEngineTON.IN := FALSE; (* Reset timers *)
			CheckDrillEngineTON();
			LiftingFeedTON.IN := FALSE;
			LiftingFeedTON();
			LoweringFeedTON.IN := FALSE;
			LoweringFeedTON();
			PauseDrillTON.IN := FALSE;
			PauseDrillTON();
			StopDrillTON.IN := FALSE;
			StopDrillTON();
			
			Operator.doActive := FALSE;
			ActivateSystemTON(IN := Operator.diStart, PT := T#2.0s); (* Wait for start button *)
			Operator.doActive := ActivateSystemTON.Q;
		
			IF Operator.doActive AND NOT(Drill.diThermMotorOK) THEN
				IF NOT(Feed.diStartPosition) THEN (* If feed not in start position, try to reach it *)
					Feed.doDirFeed := TRUE;
					Feed.doFeedPower := TRUE;
					
					LiftingFeedTON(IN := NOT(Feed.diStartPosition), PT := T#5.0s);
					
					IF LiftingFeedTON.Q THEN (* If start position unreachable, throw error *)
						FailureReason := START_POS_UNREACHABLE;
						Alarms.current[3] := TRUE;
						StateMachine := FAILURE;
					END_IF;
				END_IF;
					
				Lights.doActiveLED := TRUE; (* Activate active LED and go to drill preparation *)
				StateMachine := DRILL_PREP;
			END_IF;
			
		DRILL_PREP:
			Drill.doDirMotor := TRUE; (* Set drilling direction and power on the motor *)
			Drill.doPowerMotor := TRUE;
			
			CheckDrillEngineTON(IN := NOT(Drill.diPowerMotorOK), PT := T#5.0s); (* Limit time to turn on engine to 5s *)
			IF CheckDrillEngineTON.Q THEN (* If engine didn't turn on, throw error *)
				FailureReason := DRILL_MOTOR_NOK;
				Alarms.current[2] := TRUE;
				StateMachine := FAILURE;
			END_IF;
		
			IF Drill.diPowerMotorOK THEN (* If motor works start drilling *)
				StateMachine := DRILLING;
			END_IF;
		
		DRILLING:
			Feed.doDirFeed := TRUE; (* Set feed direction and power it *)
			Feed.doFeedPower := TRUE;
			
			LoweringFeedTON(IN := NOT(Feed.diEndPosition), PT := T#15.0s); (* Limit time to reach end position to 15s *)
			IF LoweringFeedTON.Q THEN (* If end position not reached, throw error *)
				FailureReason := END_POS_UNREACHABLE;
				Alarms.current[4] := TRUE;
				StateMachine := FAILURE;
			END_IF;
			
			PauseDrillTON(IN := Operator.diStop, PT := T#0.5s); (* Check if operator pauses or stops process *)
			StopDrillTON(IN := Operator.diStop, PT := T#2.0s);
			IF PauseDrillTON.Q THEN
				PauseHelperFlag := TRUE;
			END_IF;
			IF PauseHelperFlag AND NOT Operator.diStop THEN
				PauseHelperFlag := FALSE;
				StateMachine := PAUSED;
			END_IF;
			IF StopDrillTON.Q THEN
				StateMachine := DRILL_STOPPING;
			END_IF;
			
			IF Feed.diEndPosition THEN 
				StateMachine := RETRACTING;	(* If drill reaches final position, start retracting *)
			END_IF;
		
		RETRACTING:
			Feed.doDirFeed := FALSE; (* Change feed and drill directions *)
			Drill.doDirMotor := FALSE;
			
			LiftingFeedTON(IN := NOT(Feed.diStartPosition), PT := T#5.0s); (* Limit time to retract to 5s *)
			IF LiftingFeedTON.Q THEN (* If start position not reached, throw error *)
				FailureReason := START_POS_UNREACHABLE;
				Alarms.current[3] := TRUE;
				StateMachine := FAILURE;
			END_IF;
			
			IF Feed.diStartPosition THEN
				Feed.doFeedPower := FALSE; (* If drill reaches start position, turn off feed and start drill stopping*)
				StateMachine := DRILL_STOPPING;
			END_IF;
		
		DRILL_STOPPING:
			Drill.doPowerMotor := FALSE; (* Turning off drill motor *)
			
			CheckDrillEngineTON(IN := Drill.diPowerMotorOK, PT := T#5.0s); (* Limit time to turn off engine to 5s *)
			IF CheckDrillEngineTON.Q THEN (* If engine didn't turn off, throw error *)
				FailureReason := DRILL_MOTOR_NOK;
				Alarms.current[2] := TRUE;
				StateMachine := FAILURE;
			END_IF;
		
			IF NOT(Drill.diPowerMotorOK) THEN
				StateMachine := INIT; (* If drill motor turns off, go to init state *)
			END_IF;
			
		PAUSED:
			Feed.doFeedPower := FALSE; (* Turn off feed and drill motor, turn on paused LED *)
			Drill.doPowerMotor := FALSE;
			
			CheckDrillEngineTON.IN := FALSE; (* Reset timers *)
			CheckDrillEngineTON();
			LiftingFeedTON.IN := FALSE;
			LiftingFeedTON();
			LoweringFeedTON.IN := FALSE;
			LoweringFeedTON();
			PauseDrillTON.IN := FALSE;
			PauseDrillTON();
			StopDrillTON.IN := FALSE;
			StopDrillTON();
			
			BlinkLedOnTON(IN := NOT(BlinkLedOffTON.Q), PT := T#1.0s);
			BlinkLedOffTON(IN := BlinkLedOnTON.Q, PT := T#1.0s);
			Lights.doPausedLED := BlinkLedOnTON.Q AND NOT(BlinkLedOffTON.Q);
			
			IF NOT(Drill.diPowerMotorOK) THEN (* If motor stopped, wait for start or abort *)
				IF EDGEPOS(Operator.diStart) THEN 
					Lights.doPausedLED := FALSE; (* If start then resume drilling *)
					StateMachine := DRILLING;
				END_IF;
				
				IF EDGEPOS(Operator.diStop) THEN
					Feed.doFeedPower := TRUE; (* If stop then turn on feed and drill and start retracting *)
					Drill.doPowerMotor := TRUE;
					Lights.doPausedLED := FALSE;
					StateMachine := RETRACTING;
				END_IF;
			END_IF;
		
		FAILURE:
			CheckDrillEngineTON.IN := FALSE; (* Reset timers *)
			CheckDrillEngineTON();
			LiftingFeedTON.IN := FALSE;
			LiftingFeedTON();
			LoweringFeedTON.IN := FALSE;
			LoweringFeedTON();
			PauseDrillTON.IN := FALSE;
			PauseDrillTON();
			StopDrillTON.IN := FALSE;
			StopDrillTON();
			
			Feed.doFeedPower := FALSE; (* If failure occurs, turn off feed, drill and active led *)
			Drill.doPowerMotor := FALSE;
			Operator.doActive := FALSE;
			Lights.doActiveLED := FALSE;
			
			BlinkLedOnTON(IN := NOT(BlinkLedOffTON.Q), PT := T#1.0s);
			BlinkLedOffTON(IN := BlinkLedOnTON.Q, PT := T#1.0s);
			Lights.doFailureLED := BlinkLedOnTON.Q AND NOT(BlinkLedOffTON.Q);
			
			IF EDGEPOS(Operator.diConfirmFailure) AND NOT(Operator.diEStop) THEN (* If failure resolved, clear failure reason and go to init state *)
				Lights.doFailureLED := FALSE;
				FailureReason := NO_ERROR;
				FOR i := 0 TO 9 DO
					Alarms.current[i] := FALSE;
				END_FOR;
				StateMachine := INIT;
			END_IF;
	END_CASE;	
END_PROGRAM