/**
********************************************************************************
\file   sim-edrv.h

\brief  Include file for simulation interface providing edrv functions

*******************************************************************************/

/*------------------------------------------------------------------------------
Copyright (c) 2016, Franz Profelt (franz.profelt@gmail.com)
------------------------------------------------------------------------------*/

#ifndef _INC_sim_edrv_H_
#define _INC_sim_edrv_H_

//------------------------------------------------------------------------------
// includes
//------------------------------------------------------------------------------

#include <sim.h>

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

OPLKDLLEXPORT BOOL sim_setEdrvFunctions(tSimulationInstanceHdl simHdl,
                                        tEdrvFunctions edrvFunctions_p);
OPLKDLLEXPORT void sim_unsetEdrvFunctions();

tOplkError sim_initEdrv(tEdrvInitParam *pEdrvInitParam_p);
tOplkError sim_exitEdrv();
UINT8 *sim_getMacAddr();
tOplkError sim_sendTxBuffer(tEdrvTxBuffer *pBuffer_p);
tOplkError sim_allocTxBuffer(tEdrvTxBuffer *pBuffer_p);
tOplkError sim_freeTxBuffer(tEdrvTxBuffer *pBuffer_p);
tOplkError sim_changeRxFilter(tEdrvFilter *pFilter_p, UINT count_p,
                              UINT entryChanged_p, UINT changeFlags_p);
tOplkError sim_clearRxMulticastMacAddr(UINT8 *pMacAddr_p);
tOplkError sim_setRxMulticastMacAddr(UINT8 *pMacAddr_p);

#ifdef __cplusplus
}
#endif

#endif /* _INC_sim_edrv_H_ */