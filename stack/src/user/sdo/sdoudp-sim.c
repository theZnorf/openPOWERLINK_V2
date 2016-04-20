/**
********************************************************************************
\file   sdoudp-sim.c

\brief  Implementation of SDO over UDP protocol for simulation interface

This file contains the implementation of the SDO over UDP protocol with
 simulation inteface.

\ingroup module_sdo_udp
*******************************************************************************/

/*------------------------------------------------------------------------------
Copyright (c) 2016, Franz Profelt (franz.profelt@gmail.com)
------------------------------------------------------------------------------*/

//------------------------------------------------------------------------------
// includes
//------------------------------------------------------------------------------
#include <common/oplkinc.h>
#include <user/sdoudp.h>


#if defined(CONFIG_INCLUDE_SDO_UDP)

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

//------------------------------------------------------------------------------
/**
\brief  Initialize SDO over UDP socket module

The function initializes the SDO over UDP socket module.

\return The function returns a tOplkError error code.

\ingroup module_sdo_udp
*/
//------------------------------------------------------------------------------
tOplkError sdoudp_initSocket(void)
{
    return kErrorSdoUdpNoSocket;
}

//------------------------------------------------------------------------------
/**
\brief  Shut down SDO over UDP socket module

The function shuts down the SDO over UDP socket module.

\ingroup module_sdo_udp
*/
//------------------------------------------------------------------------------
void sdoudp_exitSocket(void)
{
}

//------------------------------------------------------------------------------
/**
\brief  Create socket for SDO over UDP

The function creates a socket for the SDO over UDP connection.

\param  pSdoUdpCon_p        UDP connection for which a socket shall be created.

\return The function returns a tOplkError error code.

\ingroup module_sdo_udp
*/
//------------------------------------------------------------------------------
tOplkError sdoudp_createSocket(tSdoUdpCon* pSdoUdpCon_p)
{
    return kErrorSdoUdpNoSocket;
}

//------------------------------------------------------------------------------
/**
\brief  Close socket for SDO over UDP

The function closes the created socket for the SDO over UDP connection.

\return The function returns a tOplkError error code.

\ingroup module_sdo_udp
*/
//------------------------------------------------------------------------------
tOplkError sdoudp_closeSocket(void)
{
    return kErrorSdoUdpNoSocket;
}

//------------------------------------------------------------------------------
/**
\brief  Send SDO over UDP frame

The function sends an SDO frame to the given UDP connection.

\param  pSdoUdpCon_p        UDP connection to send the frame to.
\param  pSrcData_p          Pointer to frame data which should be sent.
\param  dataSize_p          Size of data to be send.

\return The function returns a tOplkError error code.

\ingroup module_sdo_udp
*/
//------------------------------------------------------------------------------
tOplkError sdoudp_sendToSocket(tSdoUdpCon* pSdoUdpCon_p, tPlkFrame* pSrcData_p, UINT32 dataSize_p)
{
    return kErrorSdoUdpNoSocket;
}

//------------------------------------------------------------------------------
/**
\brief  Enter/leave critical section

The function enters or leaves a critical section to ensure correct operation of
the SDO UDP module.

\param  fEnable_p           Specifies if the critical section shall be entered or
                            left.
                            If TRUE, the critical section is entered.
                            If FALSE, the critical section is left.

\return The function returns a tOplkError error code.

\ingroup module_sdo_udp
*/
//------------------------------------------------------------------------------
void sdoudp_criticalSection(BOOL fEnable_p)
{
    UNUSED_PARAMETER(fEnable_p);
}

//============================================================================//
//            P R I V A T E   F U N C T I O N S                               //
//============================================================================//
/// \name Private Functions
/// \{

/// \}

#endif
