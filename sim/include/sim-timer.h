/**
********************************************************************************
\file   sim-timer.h

\brief  Include file for simulation interface providing user timer related
 functions

*******************************************************************************/

/*------------------------------------------------------------------------------
Copyright (c) 2016, Franz Profelt (franz.profelt@gmail.com)
------------------------------------------------------------------------------*/

#ifndef _INC_sim_timer_H_
#define _INC_sim_timer_H_

//------------------------------------------------------------------------------
// includes
//------------------------------------------------------------------------------

#include <common/oplkinc.h>
#include <user/timeru.h>

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

UINT32 sim_getTickCount();
tOplkError sim_setTimer(tTimerHdl* pTimerHdl_p, ULONG timeInMs_p, tTimerArg argument_p);
tOplkError sim_modifyTimer(tTimerHdl* pTimerHdl_p, ULONG timeInMs_p, tTimerArg argument_p);
tOplkError sim_deleteTimer(tTimerHdl* pTimerHdl_p);
BOOL sim_isActive(tTimerHdl timerHdl_p);

#ifdef __cplusplus
}
#endif

#endif /* _INC_sim_timer_H_ */
