/**
********************************************************************************
\file   sim-trace.h

\brief  Include file for trace functions using the simulation inteface

*******************************************************************************/

/*------------------------------------------------------------------------------
Copyright (c) 2016, Franz Profelt (franz.profelt@gmail.com)
------------------------------------------------------------------------------*/

#ifndef _INC_sim_trace_H_
#define _INC_sim_trace_H_

//------------------------------------------------------------------------------
// includes
//------------------------------------------------------------------------------
#include <common/oplkinc.h>

//------------------------------------------------------------------------------
// const defines
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// typedef
//------------------------------------------------------------------------------

typedef void(*tTraceFunction)(char const *);

typedef struct
{
    tTraceFunction pfnTrace;
} tTraceFunctions;

//------------------------------------------------------------------------------
// function prototypes
//------------------------------------------------------------------------------

#ifdef __cplusplus
extern "C"
{
#endif

OPLKDLLEXPORT BOOL sim_setTraceFunctions(tTraceFunctions traceFunctions_p);
OPLKDLLEXPORT void sim_unsetTraceFunctions();

void sim_trace(char const * pmsg_p);

#ifdef __cplusplus
}
#endif

#endif /* _INC_sim_trace_H_ */