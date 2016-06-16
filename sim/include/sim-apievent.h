/**
********************************************************************************
\file   sim-apievent.h

\brief  Include file for simulation interface providing api event functions

 This include file only provides the functions which require a customized
 behavior. All other api functions can be called directly by the simulation
 environment.

*******************************************************************************/

/*------------------------------------------------------------------------------
Copyright (c) 2016, Franz Profelt (franz.profelt@gmail.com)
------------------------------------------------------------------------------*/

#ifndef _INC_sim_api_event_H_
#define _INC_sim_api_event_H_

//------------------------------------------------------------------------------
// includes
//------------------------------------------------------------------------------

#include <sim.h>

//------------------------------------------------------------------------------
// const defines
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// typedef
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// function prototypes
//------------------------------------------------------------------------------

#ifdef __cplusplus
extern "C"
{
#endif

OPLKDLLEXPORT BOOL sim_setApiEventFunctions(tSimulationInstanceHdl simHdl,
                                        tApiEventFunctions eventFunctions_p);
OPLKDLLEXPORT void sim_unsetApiEventFunctions();

tOplkError sim_eventCb(tOplkApiEventType eventType_p,
                       tOplkApiEventArg *pEventArg_p,
                       void *pUserArg_p);

#ifdef __cplusplus
}
#endif

#endif /* _INC_sim_api_event_H_ */
