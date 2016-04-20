/**
********************************************************************************
\file   trace-sim.c

\brief  Trace function using simulation interface

*******************************************************************************/

/*------------------------------------------------------------------------------
Copyright (c) 2016, Franz Profelt (franz.profelt@gmail.com)
------------------------------------------------------------------------------*/

//------------------------------------------------------------------------------
// includes
//------------------------------------------------------------------------------

#include <common/oplkinc.h>
#include <stdarg.h>
#include "../../sim/simoutput.h"

//============================================================================//
//            P U B L I C   F U N C T I O N S                                 //
//============================================================================//

static char buffer_l[TRACE_SIM_BUFFER_SIZE];


//------------------------------------------------------------------------------
/**
\brief  Print debug trace message

The function prints a debug trace message using the simulation inteface

\param  fmt         Format string
\param  ...         Arguments to print
*/
//------------------------------------------------------------------------------
void trace(const char* fmt, ...)
{
    // clear buffer
    OPLK_MEMSET(buffer_l, 0, TRACE_SIM_BUFFER_SIZE);

    va_list argptr;

    va_start(argptr, fmt);
    sprintf(buffer_l, fmt, argptr);
    va_end(argptr);

    sim_trace(buffer_l);
}
