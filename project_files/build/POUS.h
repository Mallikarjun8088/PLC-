#include "beremiz.h"
#ifndef __POUS_H
#define __POUS_H

#include "accessor.h"
#include "iec_std_lib.h"

__DECLARE_ENUMERATED_TYPE(LOGLEVEL,
  LOGLEVEL__CRITICAL,
  LOGLEVEL__WARNING,
  LOGLEVEL__INFO,
  LOGLEVEL__DEBUG
)
// FUNCTION_BLOCK LOGGER
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,TRIG)
  __DECLARE_VAR(STRING,MSG)
  __DECLARE_VAR(LOGLEVEL,LEVEL)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,TRIG0)

} LOGGER;

void LOGGER_init__(LOGGER *data__, BOOL retain);
// Code part
void LOGGER_body__(LOGGER *data__);
// PROGRAM TRAFFIC_LIGHT
// Data part
typedef struct {
  // PROGRAM Interface - IN, OUT, IN_OUT variables

  // PROGRAM private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,IN1)
  __DECLARE_VAR(BOOL,RED)
  __DECLARE_VAR(BOOL,YELLOW)
  __DECLARE_VAR(BOOL,GREEN)
  __DECLARE_VAR(BOOL,TIMER)
  TP TP0;
  TP TP2;
  TP TP3;

} TRAFFIC_LIGHT;

void TRAFFIC_LIGHT_init__(TRAFFIC_LIGHT *data__, BOOL retain);
// Code part
void TRAFFIC_LIGHT_body__(TRAFFIC_LIGHT *data__);
#endif //__POUS_H
