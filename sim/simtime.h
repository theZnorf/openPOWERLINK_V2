/**
********************************************************************************
\file   simtime.h

\brief  Include file for simulation interface providing time related functions

*******************************************************************************/

/*------------------------------------------------------------------------------
Copyright (c) 2016, Franz Profelt (franz.profelt@gmail.com)
------------------------------------------------------------------------------*/

#ifndef _INC_simtime_H_
#define _INC_simtime_H_

//------------------------------------------------------------------------------
// includes
//------------------------------------------------------------------------------

#include <common/oplkinc.h>
#include <user/timeru.h>
#include <kernel/hrestimer.h>

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

OPLKDLLEXPORT void sim_sleep(UINT32 milliseconds_p);
OPLKDLLEXPORT UINT32 sim_getTickCount();
OPLKDLLEXPORT tOplkError sim_setTimer(tTimerHdl* pTimerHdl_p, ULONG timeInMs_p, tTimerArg argument_p);
OPLKDLLEXPORT tOplkError sim_modifyTimer(tTimerHdl* pTimerHdl_p, ULONG timeInMs_p, tTimerArg argument_p);
OPLKDLLEXPORT tOplkError sim_deleteTimer(tTimerHdl* pTimerHdl_p);
OPLKDLLEXPORT BOOL sim_isActive(tTimerHdl timerHdl_p);
OPLKDLLEXPORT tOplkError sim_modifyHresTimer(tTimerHdl* pTimerHdl_p, ULONGLONG time_p,
                                 tTimerkCallback pfnCallback_p, ULONG argument_p,
                                 BOOL fContinue_p);
OPLKDLLEXPORT tOplkError sim_deleteHresTimer(tTimerHdl* pTimerHdl_p);

#ifdef __cplusplus
}
#endif

#endif /* _INC_simtime_H_ */
