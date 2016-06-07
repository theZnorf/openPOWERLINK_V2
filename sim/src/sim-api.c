/**
********************************************************************************
\file   sim-api.c

\brief  Stub implementation of api specific functions for simulation

\ingroup module_sim
*******************************************************************************/

/*------------------------------------------------------------------------------
Copyright (c) 2016, Franz Profelt (franz.profelt@gmail.com)
------------------------------------------------------------------------------*/

//------------------------------------------------------------------------------
// includes
//------------------------------------------------------------------------------

#include <sim-api.h>
#include <oplk/oplk.h>

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

/**
\brief  Instance struct for sim-edrv module

This struct contains informations about the current instance.
*/
typedef struct
{
    tApiFunctions apiFunctions;     ///< Struct with all simulation interface functions
    tSimulationInstanceHdl simHdl;  ///< Handle to running simulation for multiple simulated instances
    BOOL fInitialized;              ///< Initialization flag signalling if the stores functions are valid
} tSimApiInstance;

//------------------------------------------------------------------------------
// local vars
//------------------------------------------------------------------------------

static tSimApiInstance instance_l = {{NULL}, 0, FALSE};

//------------------------------------------------------------------------------
// local function prototypes
//------------------------------------------------------------------------------

static tOplkError sim_processSyncCb(void);

static tOplkError sim_eventCb(tOplkApiEventType eventType_p,
                              tOplkApiEventArg *pEventArg_p,
                              void *pUserArg_p);

//============================================================================//
//            P U B L I C   F U N C T I O N S                                 //
//============================================================================//

/**
\brief  Setter for simulation interface functions for edrv

This function sets the simulation interface functions for edrv

\param simInstanceHdl_p     The handle of the current simulated stack instance
\param edrvFunctions_p      Structure with all simulation interface functions

\return The function returns TRUE when the all given functions are valid
    and the structure was set internally, otherwise the function returns FALSE
*/
BOOL sim_setApiFunctions(tSimulationInstanceHdl simHdl_p,
                         tApiFunctions apiFunctions_p)
{
    if (instance_l.fInitialized != TRUE)
    {
        // check function pointers
        if ((apiFunctions_p.pfnCbProcessSync == NULL) ||
            (apiFunctions_p.pfnCbEvent == NULL))
            return FALSE;

        instance_l.apiFunctions = apiFunctions_p;
        instance_l.simHdl = simHdl_p;
        instance_l.fInitialized = TRUE;

        return TRUE;
    }

    return FALSE;
}

void sim_unsetApiFunctions()
{
    instance_l.fInitialized = FALSE;
}

tOplkError sim_oplkCreate(tOplkApiInitParam *pInitParam_p)
{
    // check initialization
    if (instance_l.fInitialized == TRUE)
    {
        // check parameter
        if (pInitParam_p == NULL)
            return kErrorApiInvalidParam;

        // change event callback
        pInitParam_p->pfnCbEvent = sim_eventCb;

        // change process sync callback
        pInitParam_p->pfnCbSync = sim_processSyncCb;

        // forward api call
        return oplk_create(pInitParam_p);
    }
}

//============================================================================//
//            P R I V A T E   F U N C T I O N S                               //
//============================================================================//
/// \name Private Functions
/// \{

static tOplkError sim_processSyncCb(void)
{
    // check module initialization
    if (instance_l.fInitialized == TRUE)
    {
        // call function pointer
        return instance_l.apiFunctions.pfnCbProcessSync(instance_l.simHdl);
    }

    return kErrorApiNotInitialized;
}

static tOplkError sim_eventCb(tOplkApiEventType eventType_p,
                              tOplkApiEventArg *pEventArg_p,
                              void *pUserArg_p)
{
    // check module initialization
    if (instance_l.fInitialized == TRUE)
    {
        // call function pointer
        return instance_l.apiFunctions
                         .pfnCbEvent(instance_l.simHdl, eventType_p,
                                     pEventArg_p, pUserArg_p);
    }

    return kErrorApiNotInitialized;
}

/// \} 
