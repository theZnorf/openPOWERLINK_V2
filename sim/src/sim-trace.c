/**
********************************************************************************
\file   sim-trace.c

\brief  Implementation of stub for trace functions using simulation interface

\ingroup module_sim
*******************************************************************************/

/*------------------------------------------------------------------------------
Copyright (c) 2016, Franz Profelt (franz.profelt@gmail.com)
------------------------------------------------------------------------------*/

//------------------------------------------------------------------------------
// includes
//------------------------------------------------------------------------------
#include <sim-trace.h>

//============================================================================//
//            G L O B A L   D E F I N I T I O N S                             //
//============================================================================//

//------------------------------------------------------------------------------
// const defines
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// module global vars
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// global function prototypes
//------------------------------------------------------------------------------

//============================================================================//
//            P R I V A T E   D E F I N I T I O N S                           //
//============================================================================//

//------------------------------------------------------------------------------
// const defines
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// local types
//------------------------------------------------------------------------------

typedef struct
{
    tTraceFunctions traceFunctions;
    tSimulationInstanceHdl simHdl;
    BOOL fInitialized;
} tSimTraceInstance;

//------------------------------------------------------------------------------
// local vars
//------------------------------------------------------------------------------

static tSimTraceInstance instance_l = {{NULL}, 0, FALSE};

//------------------------------------------------------------------------------
// local function prototypes
//------------------------------------------------------------------------------

//============================================================================//
//            P U B L I C   F U N C T I O N S                                 //
//============================================================================//

BOOL sim_setTraceFunctions(tSimulationInstanceHdl simHdl_p,
                           tTraceFunctions traceFunctions_p)
{
    if (instance_l.fInitialized != TRUE)
    {
        // check function pointer
        if (traceFunctions_p.pfnTrace == NULL)
            return FALSE;

        instance_l.traceFunctions = traceFunctions_p;
        instance_l.simHdl = simHdl_p;
        instance_l.fInitialized = TRUE;

        return TRUE;
    }

    return FALSE;
}

void sim_unsetTraceFunctions()
{
    instance_l.fInitialized = FALSE;
}

void sim_trace(char const *pmsg_p)
{
    // check if module was initialized
    if (instance_l.fInitialized == TRUE)
    {
        // call function
        instance_l.traceFunctions.pfnTrace(instance_l.simHdl, pmsg_p);
    }
}

//============================================================================//
//            P R I V A T E   F U N C T I O N S                               //
//============================================================================//
/// \name Private Functions
/// \{

/// \}
