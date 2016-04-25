/**
********************************************************************************
\file   sim-target.h

\brief  Include file for simulation interface providing target functions

*******************************************************************************/

/*------------------------------------------------------------------------------
Copyright (c) 2016, Franz Profelt (franz.profelt@gmail.com)
------------------------------------------------------------------------------*/

#ifndef _INC_sim_target_H_
#define _INC_sim_target_H_

//------------------------------------------------------------------------------
// includes
//------------------------------------------------------------------------------

#include <common/oplkinc.h>
#include <common/led.h>

//------------------------------------------------------------------------------
// const defines
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// typedef
//------------------------------------------------------------------------------

typedef void(*tMsleepFunction)(UINT32);
typedef tOplkError(*tSetIpFunction)(char*, UINT32, UINT32, UINT16);
typedef tOplkError(*tSetDefaultGateWayFunction)(UINT32);
typedef UINT32(*tGetTickFunction)(void);
typedef tOplkError(*tSetLedFunction)(tLedType, BOOL);

typedef struct
{
    tMsleepFunction pfnMsleep;
    tSetIpFunction pfnSetIp;
    tSetDefaultGateWayFunction pfnSetDefaultGateway;
    tGetTickFunction pfnGetTick;
    tSetLedFunction pfnSetLed;
} tTargetFunctions;

//------------------------------------------------------------------------------
// function prototypes
//------------------------------------------------------------------------------

#ifdef __cplusplus
extern "C"
{
#endif


OPLKDLLEXPORT BOOL sim_setTargetFunctions(tTargetFunctions targetFunctions_p);
OPLKDLLEXPORT void sim_unsetTargetFunctions();

void sim_msleep(UINT32 milliSeconds_p);
tOplkError sim_setIpAdrs(char* ifName_p, UINT32 ipAddress_p, UINT32 subnetMask_p, UINT16 mtu_p);
tOplkError sim_setDefaultGateway(UINT32 defaultGateway_p);
UINT32 sim_getTickCount(void);
tOplkError sim_setLed(tLedType ledType_p, BOOL fLedOn_p);

#ifdef __cplusplus
}
#endif

#endif /* _INC_sim_target_H_ */
