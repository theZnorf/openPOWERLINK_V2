/**
********************************************************************************
\file   sim-edrv.c

\brief  Stub implementation of edrv specific functions for simulation

\ingroup module_sim
*******************************************************************************/

/*------------------------------------------------------------------------------
Copyright (c) 2016, Franz Profelt (franz.profelt@gmail.com)
------------------------------------------------------------------------------*/

//------------------------------------------------------------------------------
// includes
//------------------------------------------------------------------------------

#include <sim-edrv.h>

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
    tEdrvFunctions edrvFunctions;
    tSimulationInstanceHdl simHdl;
    BOOL fInitialized;
} tSimEdrvInstance;

//------------------------------------------------------------------------------
// local vars
//------------------------------------------------------------------------------

static tSimEdrvInstance instance_l = {{NULL}, 0, FALSE};

//------------------------------------------------------------------------------
// local function prototypes
//------------------------------------------------------------------------------

//============================================================================//
//            P U B L I C   F U N C T I O N S                                 //
//============================================================================//

BOOL sim_setEdrvFunctions(tSimulationInstanceHdl simHdl_p,
                          tEdrvFunctions edrvFunctions_p)
{
    if (instance_l.fInitialized != TRUE)
    {
        // check function pointer
        if ((edrvFunctions_p.pfnInit == NULL) ||
            (edrvFunctions_p.pfnExit == NULL) ||
            (edrvFunctions_p.pfnGetMacAddr == NULL) ||
            (edrvFunctions_p.pfnSendTxBuffer == NULL) ||
            (edrvFunctions_p.pfnAllocTxBuffer == NULL) ||
            (edrvFunctions_p.pfnFreeTxBuffer == NULL) ||
            (edrvFunctions_p.pfnChangeRxBufferFiler == NULL) ||
            (edrvFunctions_p.pfnSetMulticastMacAddr == NULL) ||
            (edrvFunctions_p.pfnClearMulticastMacAddr == NULL))
            return FALSE;

        instance_l.edrvFunctions = edrvFunctions_p;
        instance_l.simHdl = simHdl_p;
        instance_l.fInitialized = TRUE;

        return TRUE;
    }

    return FALSE;
}

void sim_unsetEdrvFunctions()
{
    instance_l.fInitialized = FALSE;
}

tOplkError sim_initEdrv(tEdrvInitParam *pEdrvInitParam_p)
{
    // check if functions are initialized
    if (instance_l.fInitialized == TRUE)
    {
        return instance_l.edrvFunctions
                         .pfnInit(instance_l.simHdl, pEdrvInitParam_p);
    }

    return kErrorApiNotInitialized;
}

tOplkError sim_exitEdrv()
{
    // check if functions are initialized
    if (instance_l.fInitialized == TRUE)
    {
        return instance_l.edrvFunctions.pfnExit(instance_l.simHdl);
    }

    return kErrorApiNotInitialized;
}

UINT8 *sim_getMacAddr()
{
    // check if functions are initialized
    if (instance_l.fInitialized == TRUE)
    {
        return instance_l.edrvFunctions.pfnGetMacAddr(instance_l.simHdl);
    }

    return NULL;
}

tOplkError sim_sendTxBuffer(tEdrvTxBuffer *pBuffer_p)
{
    // check if functions are initialized
    if (instance_l.fInitialized == TRUE)
    {
        return instance_l.edrvFunctions
                         .pfnSendTxBuffer(instance_l.simHdl, pBuffer_p);
    }

    return kErrorApiNotInitialized;
}

tOplkError sim_allocTxBuffer(tEdrvTxBuffer *pBuffer_p)
{
    // check if functions are initialized
    if (instance_l.fInitialized == TRUE)
    {
        return instance_l.edrvFunctions
                         .pfnAllocTxBuffer(instance_l.simHdl, pBuffer_p);
    }

    return kErrorApiNotInitialized;
}

tOplkError sim_freeTxBuffer(tEdrvTxBuffer *pBuffer_p)
{
    // check if functions are initialized
    if (instance_l.fInitialized == TRUE)
    {
        return instance_l.edrvFunctions
                         .pfnFreeTxBuffer(instance_l.simHdl, pBuffer_p);
    }

    return kErrorApiNotInitialized;
}

tOplkError sim_changeRxFilter(tEdrvFilter *pFilter_p, UINT count_p,
                              UINT entryChanged_p, UINT changeFlags_p)
{
    // check if functions are initialized
    if (instance_l.fInitialized == TRUE)
    {
        return instance_l.edrvFunctions
                         .pfnChangeRxBufferFiler(instance_l.simHdl, pFilter_p,
                                                 count_p,
                                                 entryChanged_p, changeFlags_p);
    }

    return kErrorApiNotInitialized;
}

tOplkError sim_clearRxMulticastMacAddr(UINT8 *pMacAddr_p)
{
    // check if functions are initialized
    if (instance_l.fInitialized == TRUE)
    {
        return instance_l.edrvFunctions
                         .pfnClearMulticastMacAddr(instance_l.simHdl,
                                                   pMacAddr_p);
    }

    return kErrorApiNotInitialized;
}

tOplkError sim_setRxMulticastMacAddr(UINT8 *pMacAddr_p)
{
    // check if functions are initialized
    if (instance_l.fInitialized == TRUE)
    {
        return instance_l.edrvFunctions
                         .pfnSetMulticastMacAddr(instance_l.simHdl, pMacAddr_p);
    }

    return kErrorApiNotInitialized;
}

//============================================================================//
//            P R I V A T E   F U N C T I O N S                               //
//============================================================================//
/// \name Private Functions
/// \{

/// \} 
