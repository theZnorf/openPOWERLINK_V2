/**
********************************************************************************
\file   sim-sdoudp.c

\brief  Implementation of stub for sdo udp functions using simulation interface

\ingroup module_sim
*******************************************************************************/

/*------------------------------------------------------------------------------
Copyright (c) 2016, Franz Profelt (franz.profelt@gmail.com)
------------------------------------------------------------------------------*/

//------------------------------------------------------------------------------
// includes
//------------------------------------------------------------------------------
#include <sim-sdoudp.h>

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
    tSdoUdpFunctions sdoUdpFunctions;
    tSimulationInstanceHdl simHdl;
    BOOL fInitialized;
} tSimSdoUdpInstance;

//------------------------------------------------------------------------------
// local vars
//------------------------------------------------------------------------------

static tSimSdoUdpInstance instance_l = {{NULL}, 0, FALSE};

//------------------------------------------------------------------------------
// local function prototypes
//------------------------------------------------------------------------------

//============================================================================//
//            P U B L I C   F U N C T I O N S                                 //
//============================================================================//

BOOL sim_setSdoUdpFunctions(tSimulationInstanceHdl simHdl_p,
                            tSdoUdpFunctions sdoUdpFunctions_p)
{
    if (instance_l.fInitialized != TRUE)
    {
        // check function pointer
        if ((sdoUdpFunctions_p.pfnCreateSocket == NULL) ||
            (sdoUdpFunctions_p.pfnCloseSocket == NULL) ||
            (sdoUdpFunctions_p.pfnSendToSocket == NULL) ||
            (sdoUdpFunctions_p.pfnCiritcalSection == NULL))
            return FALSE;

        instance_l.sdoUdpFunctions = sdoUdpFunctions_p;
        instance_l.simHdl = simHdl_p;
        instance_l.fInitialized = TRUE;
    }

    return FALSE;
}

void sim_unsetSdoUdpFunctions()
{
    instance_l.fInitialized = FALSE;
}

tOplkError sim_createSdoUdpSocket(tSdoUdpCon *pSdoUdpCon_p)
{
    // check if module was initialized
    if (instance_l.fInitialized == TRUE)
    {
        // call function
        return instance_l.sdoUdpFunctions
                         .pfnCreateSocket(instance_l.simHdl, pSdoUdpCon_p);
    }

    return kErrorApiNotInitialized;
}

tOplkError sim_closeSdoUdpSocket(void)
{
    // check if module was initialized
    if (instance_l.fInitialized == TRUE)
    {
        // call function
        return instance_l.sdoUdpFunctions.pfnCloseSocket(instance_l.simHdl);
    }

    return kErrorApiNotInitialized;
}

tOplkError sim_sendToSdoUdpSocket(tSdoUdpCon *pSdoUdpCon_p,
                                  tPlkFrame *pSrcData_p, UINT32 dataSize_p)
{
    // check if module was initialized
    if (instance_l.fInitialized == TRUE)
    {
        // call function
        return instance_l.sdoUdpFunctions
                         .pfnSendToSocket(instance_l.simHdl, pSdoUdpCon_p,
                                          pSrcData_p, dataSize_p);
    }

    return kErrorApiNotInitialized;
}

void sim_criticalSectionSdoUdp(BOOL fEnable_p)
{
    // check if module was initialized
    if (instance_l.fInitialized == TRUE)
    {
        // call function
        instance_l.sdoUdpFunctions
                  .pfnCiritcalSection(instance_l.simHdl, fEnable_p);
    }
}

//============================================================================//
//            P R I V A T E   F U N C T I O N S                               //
//============================================================================//
/// \name Private Functions
/// \{

/// \}
