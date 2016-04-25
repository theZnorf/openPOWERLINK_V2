/**
********************************************************************************
\file   sim-hrestimer.h

\brief  Include file for simulation interface providing hrestimer functions

*******************************************************************************/

/*------------------------------------------------------------------------------
Copyright (c) 2016, Franz Profelt (franz.profelt@gmail.com)
------------------------------------------------------------------------------*/

#ifndef _INC_sim_hrestimer_H_
#define _INC_sim_hrestimer_H_

//------------------------------------------------------------------------------
// includes
//------------------------------------------------------------------------------

#include <common/oplkinc.h>
#include <kernel/hrestimer.h>

//------------------------------------------------------------------------------
// const defines
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// typedef
//------------------------------------------------------------------------------

typedef tOplkError(*tModifyHresTimerFunction)(tTimerHdl *, ULONGLONG,
                                              tTimerkCallback, ULONG, BOOL);
typedef tOplkError(*tDeleteHresTimerFunction)(tTimerHdl *);


typedef struct
{
    tModifyHresTimerFunction pfnModifyHresTimer;
    tDeleteHresTimerFunction pfnDeleteHresTimer;
} tHresTimerFunctions;

//------------------------------------------------------------------------------
// function prototypes
//------------------------------------------------------------------------------

#ifdef __cplusplus
extern "C"
{
#endif

OPLKDLLEXPORT BOOL sim_setHresTimerFunctions(tHresTimerFunctions hresTimerFunctions_p);
OPLKDLLEXPORT void sim_unsetHresTimerFunctions();

tOplkError sim_modifyHresTimer(tTimerHdl *pTimerHdl_p, ULONGLONG time_p,
                               tTimerkCallback pfnCallback_p, ULONG argument_p,
                               BOOL fContinue_p);

tOplkError sim_deleteHresTimer(tTimerHdl *pTimerHdl_p);

#ifdef __cplusplus
}
#endif

#endif /* _INC_sim_hrestimer_H_ */
