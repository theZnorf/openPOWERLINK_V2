/**
********************************************************************************
\file   sim-sdoudp.h

\brief  Include file for simulation interface providing sdoudp functions

*******************************************************************************/

/*------------------------------------------------------------------------------
Copyright (c) 2016, Franz Profelt (franz.profelt@gmail.com)
------------------------------------------------------------------------------*/

#ifndef _INC_sim_sdoudp_H_
#define _INC_sim_sdoudp_H_

//------------------------------------------------------------------------------
// includes
//------------------------------------------------------------------------------

#include <common/oplkinc.h>
#include <user/sdoudp.h>

//------------------------------------------------------------------------------
// const defines
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// typedef
//------------------------------------------------------------------------------

typedef tOplkError(*tCreateSdoUdpSocketFunction)(tSdoUdpCon *);

typedef tOplkError(*tCloseSdoUdpSocketFunction)(void);

typedef tOplkError(*tSendToSdoUdpSocketFunction)(tSdoUdpCon *, tPlkFrame *,
                                                 UINT32);
typedef void(*tCriticalSectionSdoUdpFunction)(BOOL);


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

OPLKDLLEXPORT BOOL sim_setSdoUdpFunctions(
        tSdoUdpFunctions sdoUdpFunctions_p);

OPLKDLLEXPORT void sim_unsetSdoUdpFunctions();

tOplkError sim_createSdoUdpSocket(tSdoUdpCon *pSdoUdpCon_p);

tOplkError sim_closeSdoUdpSocket(void);

tOplkError sim_sendToSdoUdpSocket(tSdoUdpCon *pSdoUdpCon_p,
                                  tPlkFrame *pSrcData_p, UINT32 dataSize_p);

void sim_criticalSectionSdoUdp(BOOL fEnable_p);

#ifdef __cplusplus
}
#endif

#endif /* _INC_sim_sdoudp_H_ */
