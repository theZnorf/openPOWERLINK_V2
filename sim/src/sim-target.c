/**
********************************************************************************
\file   sim-target.c

\brief  Stub implementation of target specific functions for simulation

\ingroup module_sim
*******************************************************************************/

/*------------------------------------------------------------------------------
Copyright (c) 2016, Franz Profelt (franz.profelt@gmail.com)
------------------------------------------------------------------------------*/

//------------------------------------------------------------------------------
// includes
//------------------------------------------------------------------------------

#include <sim-target.h>

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
    tTargetFunctions targetFunctions;
    tSimulationInstanceHdl simHdl;
    BOOL fInitialized;
} tSimTargetInstance;

//------------------------------------------------------------------------------
// local vars
//------------------------------------------------------------------------------

static tSimTargetInstance instance_l = {{NULL}, 0, FALSE};

//------------------------------------------------------------------------------
// local function prototypes
//------------------------------------------------------------------------------

//============================================================================//
//            P U B L I C   F U N C T I O N S                                 //
//============================================================================//

OPLKDLLEXPORT BOOL sim_setTargetFunctions(tSimulationInstanceHdl simHdl_p,
                                          tTargetFunctions targetFunctions_p)
{
    if (instance_l.fInitialized != TRUE)
    {
        // check given functions
        if ((targetFunctions_p.pfnMsleep == NULL) ||
            (targetFunctions_p.pfnSetIp == NULL) ||
            (targetFunctions_p.pfnSetDefaultGateway == NULL) ||
            (targetFunctions_p.pfnGetTick == NULL) ||
            (targetFunctions_p.pfnSetLed == NULL))
            return FALSE;

        // set functions
        instance_l.targetFunctions = targetFunctions_p;
        instance_l.simHdl = simHdl_p;
        instance_l.fInitialized = TRUE;

        return TRUE;
    }

    return FALSE;
}

OPLKDLLEXPORT void sim_unsetTargetFunctions()
{
    instance_l.fInitialized = FALSE;
}

void sim_msleep(UINT32 milliSeconds_p)
{
    // check if module was initialized
    if (instance_l.fInitialized == TRUE)
    {
        // call function
        instance_l.targetFunctions.pfnMsleep(instance_l.simHdl, milliSeconds_p);
    }
}

tOplkError sim_setIpAdrs(char *ifName_p, UINT32 ipAddress_p,
                         UINT32 subnetMask_p, UINT16 mtu_p)
{
    // check if module was initialized
    if (instance_l.fInitialized == TRUE)
    {
        // call function
        return instance_l.targetFunctions
                         .pfnSetIp(instance_l.simHdl, ifName_p, ipAddress_p,
                                   subnetMask_p, mtu_p);
    }

    return kErrorApiNotInitialized;
}

tOplkError sim_setDefaultGateway(UINT32 defaultGateway_p)
{
    // check if module was initialized
    if (instance_l.fInitialized == TRUE)
    {
        // call function
        return instance_l.targetFunctions
                         .pfnSetDefaultGateway(instance_l.simHdl,
                                               defaultGateway_p);
    }

    return kErrorApiNotInitialized;
}

UINT32 sim_getTickCount(void)
{
    // check if module was initialized
    if (instance_l.fInitialized == TRUE)
    {
        // call function
        return instance_l.targetFunctions.pfnGetTick(instance_l.simHdl);
    }

    return 0;
}

tOplkError sim_setLed(tLedType ledType_p, BOOL fLedOn_p)
{
    // check if module was initialized
    if (instance_l.fInitialized == TRUE)
    {
        // call function
        return instance_l.targetFunctions
                         .pfnSetLed(instance_l.simHdl, ledType_p, fLedOn_p);
    }

    return kErrorApiNotInitialized;
}


//============================================================================//
//            P R I V A T E   F U N C T I O N S                               //
//============================================================================//
/// \name Private Functions
/// \{

/// \} 
