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

typedef tOplkError(*tInitEdrvFunction)(tSimulationInstanceHdl,
                                       tEdrvInitParam *);

typedef tOplkError(*tExitEdrvFunction)(tSimulationInstanceHdl);

typedef UINT8 *(*tgetMacAddrFunction)(tSimulationInstanceHdl);

typedef tOplkError(*tTxBufferFunction)(tSimulationInstanceHdl, tEdrvTxBuffer *);

typedef tOplkError(*tChangeRxBufferFunction)(tSimulationInstanceHdl,
                                             tEdrvFilter *, UINT, UINT, UINT);

typedef tOplkError(*tMulticastFunction)(tSimulationInstanceHdl, UINT8 *);

typedef struct
{
    tInitEdrvFunction pfnInit;
    tExitEdrvFunction pfnExit;
    tgetMacAddrFunction pfnGetMacAddr;
    tTxBufferFunction pfnSendTxBuffer;
    tTxBufferFunction pfnAllocTxBuffer;
    tTxBufferFunction pfnFreeTxBuffer;
    tChangeRxBufferFunction pfnChangeRxBufferFiler;
    tMulticastFunction pfnSetMulticastMacAddr;
    tMulticastFunction pfnClearMulticastMacAddr;
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
