/**
********************************************************************************
\file   sim-apievent.c

\brief  Stub implementation of api event specific functions for simulation

\ingroup module_sim
*******************************************************************************/

/*------------------------------------------------------------------------------
Copyright (c) 2016, Franz Profelt (franz.profelt@gmail.com)
------------------------------------------------------------------------------*/

//------------------------------------------------------------------------------
// includes
//------------------------------------------------------------------------------

#include <sim-api.h>

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
\brief  Instance struct for sim-apievent module

This struct contains informations about the current instance.
*/
typedef struct
{
    tApiEventFunctions eventFunctions;     ///< Struct with all simulation interface functions
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
BOOL sim_setApiEventFunctions(tSimulationInstanceHdl simHdl_p,
                              tApiEventFunctions eventFunctions_p)
{
    if (instance_l.fInitialized != TRUE)
    {
        // check function pointers
        if (eventFunctions_p.pfnCbEvent == NULL)
            return FALSE;

        instance_l.eventFunctions = eventFunctions_p;
        instance_l.simHdl = simHdl_p;
        instance_l.fInitialized = TRUE;

        return TRUE;
    }

    return FALSE;
}

void sim_unsetApiEventFunctions()
{
    instance_l.fInitialized = FALSE;
}

tOplkError sim_eventCb(tOplkApiEventType eventType_p,
                       tOplkApiEventArg *pEventArg_p,
                       void *pUserArg_p)
{
    // check module initialization
    if (instance_l.fInitialized == TRUE)
    {
        // call function pointer
        return instance_l.eventFunctions
                         .pfnCbEvent(instance_l.simHdl, eventType_p,
                                     pEventArg_p, pUserArg_p);
    }

    return kErrorApiNotInitialized;
}

//============================================================================//
//            P R I V A T E   F U N C T I O N S                               //
//============================================================================//
/// \name Private Functions
/// \{


/// \} 
