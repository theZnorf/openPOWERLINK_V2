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
    BOOL fInitialized;
} tSimEdrvInstance;

//------------------------------------------------------------------------------
// local vars
//------------------------------------------------------------------------------

static tSimEdrvInstance instance_l = {{NULL}, FALSE};

//------------------------------------------------------------------------------
// local function prototypes
//------------------------------------------------------------------------------

//============================================================================//
//            P U B L I C   F U N C T I O N S                                 //
//============================================================================//

BOOL sim_setEdrvFunctions(tEdrvFunctions edrvFunctions_p)
{
    if (instance_l.fInitialized != TRUE)
    {
        // check function pointer
        if ((instance_l.edrvFunctions.pfnInit == NULL) ||
            (instance_l.edrvFunctions.pfnExit == NULL) ||
            (instance_l.edrvFunctions.pfnGetMacAddr == NULL) ||
            (instance_l.edrvFunctions.pfnSendTxBuffer == NULL) ||
            (instance_l.edrvFunctions.pfnAllocTxBuffer == NULL) ||
            (instance_l.edrvFunctions.pfnFreeTxBuffer == NULL) ||
            (instance_l.edrvFunctions.pfnChangeRxBufferFiler == NULL) ||
            (instance_l.edrvFunctions.pfnSetMulticastMacAddr == NULL) ||
            (instance_l.edrvFunctions.pfnClearMulticastMacAddr == NULL))
            return FALSE;

        instance_l.edrvFunctions = edrvFunctions_p;
        instance_l.fInitialized = TRUE;
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
        return instance_l.edrvFunctions.pfnInit(pEdrvInitParam_p);
    }

    return kErrorApiNotInitialized;
}

tOplkError sim_exitEdrv()
{
    // check if functions are initialized
    if (instance_l.fInitialized == TRUE)
    {
        return instance_l.edrvFunctions.pfnExit();
    }

    return kErrorApiNotInitialized;
}

UINT8 *sim_getMacAddr()
{
    // check if functions are initialized
    if (instance_l.fInitialized == TRUE)
    {
        return instance_l.edrvFunctions.pfnGetMacAddr();
    }

    return NULL;
}

tOplkError sim_sendTxBuffer(tEdrvTxBuffer *pBuffer_p)
{
    // check if functions are initialized
    if (instance_l.fInitialized == TRUE)
    {
        return instance_l.edrvFunctions.pfnSendTxBuffer(pBuffer_p);
    }

    return kErrorApiNotInitialized;
}

tOplkError sim_allocTxBuffer(tEdrvTxBuffer *pBuffer_p)
{
    // check if functions are initialized
    if (instance_l.fInitialized == TRUE)
    {
        return instance_l.edrvFunctions.pfnAllocTxBuffer(pBuffer_p);
    }

    return kErrorApiNotInitialized;
}

tOplkError sim_freeTxBuffer(tEdrvTxBuffer *pBuffer_p)
{
    // check if functions are initialized
    if (instance_l.fInitialized == TRUE)
    {
        return instance_l.edrvFunctions.pfnFreeTxBuffer(pBuffer_p);
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
                         .pfnChangeRxBufferFiler(pFilter_p, count_p,
                                                 entryChanged_p, changeFlags_p);
    }

    return kErrorApiNotInitialized;
}

tOplkError sim_clearRxMulticastMacAddr(UINT8 *pMacAddr_p)
{
    // check if functions are initialized
    if (instance_l.fInitialized == TRUE)
    {
        return instance_l.edrvFunctions.pfnClearMulticastMacAddr(pMacAddr_p);
    }

    return kErrorApiNotInitialized;
}

tOplkError sim_setRxMulticastMacAddr(UINT8 *pMacAddr_p)
{
    // check if functions are initialized
    if (instance_l.fInitialized == TRUE)
    {
        return instance_l.edrvFunctions.pfnSetMulticastMacAddr(pMacAddr_p);
    }

    return kErrorApiNotInitialized;
}

//============================================================================//
//            P R I V A T E   F U N C T I O N S                               //
//============================================================================//
/// \name Private Functions
/// \{

/// \} 
