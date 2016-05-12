/**
********************************************************************************
\file   sim-hrestimer.c

\brief  Implementation of stub for hrestimer functions using simulation interface

\ingroup module_sim
*******************************************************************************/

/*------------------------------------------------------------------------------
Copyright (c) 2016, Franz Profelt (franz.profelt@gmail.com)
------------------------------------------------------------------------------*/

//------------------------------------------------------------------------------
// includes
//------------------------------------------------------------------------------
#include <sim-hrestimer.h>
#include <sim.h>

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
    tHresTimerFunctions hresTimerFunctions;
    tSimulationInstanceHdl simHdl;
    BOOL fInitialized;
} tSimHresTimerInstance;

//------------------------------------------------------------------------------
// local vars
//------------------------------------------------------------------------------

static tSimHresTimerInstance instance_l = {{NULL}, 0, FALSE};

//------------------------------------------------------------------------------
// local function prototypes
//------------------------------------------------------------------------------

//============================================================================//
//            P U B L I C   F U N C T I O N S                                 //
//============================================================================//

BOOL sim_setHresTimerFunctions(tSimulationInstanceHdl simHdl_p,
                               tHresTimerFunctions hresTimerFunctions_p)
{
    if (instance_l.fInitialized != TRUE)
    {
        // check function pointer
        if ((hresTimerFunctions_p.pfnInitHresTimer == NULL) ||
            (hresTimerFunctions_p.pfnExitHresTimer == NULL) ||
            (hresTimerFunctions_p.pfnModifyHresTimer == NULL) ||
            (hresTimerFunctions_p.pfnDeleteHresTimer == NULL))
            return FALSE;

        instance_l.hresTimerFunctions = hresTimerFunctions_p;
        instance_l.simHdl = simHdl_p;
        instance_l.fInitialized = TRUE;

        return TRUE;
    }

    return FALSE;
}

void sim_unsetHresTimerFunctions()
{
    instance_l.fInitialized = FALSE;
}


tOplkError sim_initHresTimer()
{
    // check if module was initialized
    if (instance_l.fInitialized == TRUE)
    {
        // call function
        return instance_l.hresTimerFunctions.pfnInitHresTimer(instance_l.simHdl);
    }
}

tOplkError sim_exitHresTimer()
{
    // check if module was initialized
    if (instance_l.fInitialized == TRUE)
    {
        // call function
        return instance_l.hresTimerFunctions.pfnExitHresTimer(instance_l.simHdl);
    }
}

tOplkError sim_modifyHresTimer(tTimerHdl *pTimerHdl_p, ULONGLONG time_p,
                               tTimerkCallback pfnCallback_p, ULONG argument_p,
                               BOOL fContinue_p)
{
    // check if module was initialized
    if (instance_l.fInitialized == TRUE)
    {
        // call function
        return instance_l.hresTimerFunctions
                         .pfnModifyHresTimer(instance_l.simHdl, pTimerHdl_p,
                                             time_p, pfnCallback_p,
                                             argument_p, fContinue_p);
    }

    return kErrorApiNotInitialized;
}

tOplkError sim_deleteHresTimer(tTimerHdl *pTimerHdl_p)
{
    // check if module was initialized
    if (instance_l.fInitialized == TRUE)
    {
        // call function
        return instance_l.hresTimerFunctions
                         .pfnDeleteHresTimer(instance_l.simHdl, pTimerHdl_p);
    }

    return kErrorApiNotInitialized;
}

//============================================================================//
//            P R I V A T E   F U N C T I O N S                               //
//============================================================================//
/// \name Private Functions
/// \{

/// \}
