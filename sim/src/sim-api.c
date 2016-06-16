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
#include <sim-processsync.h>
#include <sim-apievent.h>

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

//------------------------------------------------------------------------------
// local vars
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// local function prototypes
//------------------------------------------------------------------------------

//============================================================================//
//            P U B L I C   F U N C T I O N S                                 //
//============================================================================//

tOplkError sim_oplkCreate(tOplkApiInitParam *pInitParam_p)
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

//============================================================================//
//            P R I V A T E   F U N C T I O N S                               //
//============================================================================//
/// \name Private Functions
/// \{

/// \} 
