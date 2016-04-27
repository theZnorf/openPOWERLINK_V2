/**
********************************************************************************
\file   sim.h

\brief  Include file for defines regarding all simulation interfaces

*******************************************************************************/

/*------------------------------------------------------------------------------
Copyright (c) 2016, Franz Profelt (franz.profelt@gmail.com)
------------------------------------------------------------------------------*/

#ifndef _INC_sim_H_
#define _INC_sim_H_

//------------------------------------------------------------------------------
// includes
//------------------------------------------------------------------------------

#include <kernel/hrestimer.h>

//------------------------------------------------------------------------------
// const defines
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// typedef
//------------------------------------------------------------------------------

typedef UINT32 tSimulationInstanceHdl;


typedef tOplkError(*tModifyHresTimerFunction)(tSimulationInstanceHdl,
                                              tTimerHdl *, ULONGLONG,
                                              tTimerkCallback, ULONG, BOOL);

typedef tOplkError(*tDeleteHresTimerFunction)(tSimulationInstanceHdl,
                                              tTimerHdl *);


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

#ifdef __cplusplus
}
#endif

#endif /* _INC_sim_H_ */
