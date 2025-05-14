TYPE
  LOGLEVEL : (CRITICAL, WARNING, INFO, DEBUG) := INFO;
END_TYPE

FUNCTION_BLOCK LOGGER
  VAR_INPUT
    TRIG : BOOL;
    MSG : STRING;
    LEVEL : LOGLEVEL := INFO;
  END_VAR
  VAR
    TRIG0 : BOOL;
  END_VAR

  IF TRIG AND NOT TRIG0 THEN
  {{
   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  }}
  END_IF;
  TRIG0:=TRIG;
END_FUNCTION_BLOCK


PROGRAM traffic_light
  VAR
    in1 : BOOL;
    red : BOOL;
    yellow : BOOL;
    green : BOOL;
    timer : BOOL;
    TP0 : TP;
    TP2 : TP;
    TP3 : TP;
  END_VAR

  TP0(IN := NOT(yellow) AND NOT(green) AND in1, PT := T#5000ms);
  red := TP0.Q;
  TP2(IN := NOT(red) AND NOT(green) AND in1, PT := T#5000ms);
  yellow := TP2.Q;
  TP3(IN := NOT(red) AND NOT(yellow) AND NOT(red) AND NOT(green) AND in1, PT := T#5000ms);
  green := TP3.Q;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : traffic_light;
  END_RESOURCE
END_CONFIGURATION
