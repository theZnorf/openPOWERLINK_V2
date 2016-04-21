/**
********************************************************************************
\file   simethernet.h

\brief  Include file for simulation interface providing ethernet functions

*******************************************************************************/

/*------------------------------------------------------------------------------
Copyright (c) 2016, Franz Profelt (franz.profelt@gmail.com)
------------------------------------------------------------------------------*/

#ifndef _INC_ethernet_H_
#define _INC_ethernet_H_

//------------------------------------------------------------------------------
// includes
//------------------------------------------------------------------------------

#include <common/oplkinc.h>

//------------------------------------------------------------------------------
// const defines
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// typedef
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// function prototypes
//------------------------------------------------------------------------------

#ifdef __cplusplus
extern "C"
{
#endif

OPLKDLLEXPORT tOplkError sim_initEthernet(tEdrvInitParam* pEdrvInitParam_p);
OPLKDLLEXPORT tOplkError sim_exitEthernet();
OPLKDLLEXPORT UINT8* sim_getMacAddr();
OPLKDLLEXPORT tOplkError sim_sendTxBuffer(tEdrvTxBuffer* pBuffer_p);
OPLKDLLEXPORT tOplkError sim_allocTxBuffer(tEdrvTxBuffer* pBuffer_p);
OPLKDLLEXPORT tOplkError sim_freeTxBuffer(tEdrvTxBuffer* pBuffer_p);
OPLKDLLEXPORT tOplkError sim_changeRxFilter(tEdrvFilter* pFilter_p, UINT count_p,
                                             UINT entryChanged_p, UINT changeFlags_p);
OPLKDLLEXPORT tOplkError sim_clearRxMulticastMacAddr(UINT8* pMacAddr_p);
OPLKDLLEXPORT tOplkError sim_setRxMulticastMacAddr(UINT8* pMacAddr_p);


#ifdef __cplusplus
}
#endif

#endif /* _INC_ethernet_H_ */
