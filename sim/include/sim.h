/**
********************************************************************************
\file   sim.h

\brief  Include file for defines regarding all simulation interfaces

*******************************************************************************/

/*------------------------------------------------------------------------------
Copyright (c) 2016, Franz Profelt (franz.profelt@gmail.com)
------------------------------------------------------------------------------*/

#ifndef _INC_sim_H_
#define _INC_sim_H_

//------------------------------------------------------------------------------
// includes
//------------------------------------------------------------------------------

#include <kernel/hrestimer.h>
#include <common/led.h>
#include <kernel/edrv.h>
#include <user/sdoudp.h>


//------------------------------------------------------------------------------
// const defines
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// typedef
//------------------------------------------------------------------------------


typedef UINT32 tSimulationInstanceHdl;

typedef tOplkError (*tInitExitHresTimerFunction)(tSimulationInstanceHdl);

typedef tOplkError(*tModifyHresTimerFunction)(tSimulationInstanceHdl,
                                              tTimerHdl *, ULONGLONG,
                                              tTimerkCallback, ULONG, BOOL);

typedef tOplkError(*tDeleteHresTimerFunction)(tSimulationInstanceHdl,
                                              tTimerHdl *);


typedef struct
{
    tInitExitHresTimerFunction pfnInitHresTimer;
    tInitExitHresTimerFunction pfnExitHresTimer;
    tModifyHresTimerFunction pfnModifyHresTimer;
    tDeleteHresTimerFunction pfnDeleteHresTimer;
} tHresTimerFunctions;


typedef void(*tMsleepFunction)(tSimulationInstanceHdl, UINT32);

typedef tOplkError(*tSetIpFunction)(tSimulationInstanceHdl, char *, UINT32,
                                    UINT32, UINT16);

typedef tOplkError(*tSetDefaultGateWayFunction)(tSimulationInstanceHdl, UINT32);

typedef UINT32(*tGetTickFunction)(tSimulationInstanceHdl);

typedef tOplkError(*tSetLedFunction)(tSimulationInstanceHdl, tLedType, BOOL);

typedef struct
{
    tMsleepFunction pfnMsleep;
    tSetIpFunction pfnSetIp;
    tSetDefaultGateWayFunction pfnSetDefaultGateway;
    tGetTickFunction pfnGetTick;
    tSetLedFunction pfnSetLed;
} tTargetFunctions;

typedef void(*tTraceFunction)(tSimulationInstanceHdl, char const *);

typedef struct
{
    tTraceFunction pfnTrace;
} tTraceFunctions;


//------------------------------------------------------------------------------
// edrv types
//------------------------------------------------------------------------------

/**
\brief Type for initEdrv function pointer

This type defines a function pointer for the simulation interface function
 for initEdrv.

\param simInstanceHdl_p     The handle of the current simulated stack instance
\param pEdrvInitParam_p     Pointer to the edrv init parameter

\return The function returns a tOplkError error code
*/
typedef tOplkError(*tInitEdrvFunction)(tSimulationInstanceHdl simInstanceHdl_p,
                                       tEdrvInitParam *pEdrvInitParam_p);

/**
\brief Type for exitEdrv function pointer

This type defines a function pointer for the simulation interface function
 for exitEdrv.

\param simInstanceHdl_p     The handle of the current simulated stack instance

\return The function returns a tOplkError error code
*/
typedef tOplkError(*tExitEdrvFunction)(tSimulationInstanceHdl simInstanceHdl_p);

/**
\brief  Type for getMacAddr function pointer

This type defines a function pointer for the simulation interface function
 for getMacAddr.

\param simInstanceHdl_p     The handle of the current simulated stack instance

\return The function returns a pointer to the MAC address.
*/
typedef UINT8 *(*tgetMacAddrFunction)(tSimulationInstanceHdl simInstanceHdl_p);

/**
\brief   Type for Ethernet txBuffer function pointer

This type defines a function pointer for the simulation interface function
 for allocTxBuffer and freeTxBuffer.

\param simInstanceHdl_p     The handle of the current simulated stack instance
\param  pBuffer_p           Tx buffer descriptor

\return The function returns a tOplkError error code.
*/
typedef tOplkError(*tTxBufferFunction)(tSimulationInstanceHdl simInstanceHdl_p,
                                       tEdrvTxBuffer * pBuffer_p);

/**
\brief  Type for changeRxBuffer function pointer

This type defines a function pointer for the simulation interface function
 for changeRxBuffer.

\param simInstanceHdl_p     The handle of the current simulated stack instance
\param  pFilter_p           Base pointer of Rx filter array
\param  count_p             Number of Rx filter array entries
\param  entryChanged_p      Index of Rx filter entry that shall be changed
\param  changeFlags_p       Bit mask that selects the changing Rx filter property

\return The function returns a tOplkError error code.
*/
typedef tOplkError(*tChangeRxBufferFunction)(tSimulationInstanceHdl simInstanceHdl_p,
                                             tEdrvFilter *pFilter_p, UINT count_p,
                                             UINT entryChanged_p, UINT changeFlags_p);

/**
\brief  Type for Ethernet multicast function pointer

This type defines a function pointer for the simulation interface function
 for setRxMulticastMacAddr and clearRxMulticastMacAddr.

\param simInstanceHdl_p     The handle of the current simulated stack instance
\param  pMacAddr_p           Base pointer of Rx filter array

\return The function returns a tOplkError error code.
*/
typedef tOplkError(*tMulticastFunction)(tSimulationInstanceHdl simInstanceHdl_p,
                                        UINT8 * pMacAddr_p);

/**
\brief Edrv function pointer

This struct holds all funtion pointer to the edrv functions used in the
 simulation interface (\ref sim-edrv.g).
*/
typedef struct
{
    tInitEdrvFunction pfnInit;                          ///< Pointer to the initEdrv function
    tExitEdrvFunction pfnExit;                          ///< Pointer to the exitEdrv function
    tgetMacAddrFunction pfnGetMacAddr;                  ///< Pointer to the getMacAddr function
    tTxBufferFunction pfnSendTxBuffer;                  ///< Pointer to the sendTxBuffer function
    tTxBufferFunction pfnAllocTxBuffer;                 ///< Pointer to the allocTxBuffer function
    tTxBufferFunction pfnFreeTxBuffer;                  ///< Pointer to the freeTxBuffer function
    tChangeRxBufferFunction pfnChangeRxBufferFiler;     ///< Pointer to the changeRcBufferFilter function
    tMulticastFunction pfnSetMulticastMacAddr;          ///< Pointer to the setMulticastMacAddr function
    tMulticastFunction pfnClearMulticastMacAddr;        ///< Pointer to the clearMulticastMacAddr function
} tEdrvFunctions;


typedef tOplkError(*tCreateSdoUdpSocketFunction)(tSimulationInstanceHdl,
                                                 tSdoUdpCon *);

typedef tOplkError(*tCloseSdoUdpSocketFunction)(tSimulationInstanceHdl);

typedef tOplkError(*tSendToSdoUdpSocketFunction)(tSimulationInstanceHdl,
                                                 tSdoUdpCon *, tPlkFrame *,
                                                 UINT32);

typedef void(*tCriticalSectionSdoUdpFunction)(tSimulationInstanceHdl, BOOL);


typedef struct
{
    tCreateSdoUdpSocketFunction pfnCreateSocket;
    tCloseSdoUdpSocketFunction pfnCloseSocket;
    tSendToSdoUdpSocketFunction pfnSendToSocket;
    tCriticalSectionSdoUdpFunction pfnCiritcalSection;
} tSdoUdpFunctions;

//------------------------------------------------------------------------------
// function prototypes
//------------------------------------------------------------------------------

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef __cplusplus
}
#endif

#endif /* _INC_sim_H_ */
