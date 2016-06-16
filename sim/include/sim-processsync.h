/**
********************************************************************************
\file   sim-processsync.h

\brief  Include file for simulation interface providing process sync functions

 This include file only provides the functions which require a customized
 behavior. All other api functions can be called directly by the simulation
 environment.

*******************************************************************************/

/*------------------------------------------------------------------------------
Copyright (c) 2016, Franz Profelt (franz.profelt@gmail.com)
------------------------------------------------------------------------------*/

#ifndef _INC_sim_process_sync_H_
#define _INC_sim_process_sync_H_

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

OPLKDLLEXPORT BOOL sim_setProcessSyncFunctions(tSimulationInstanceHdl simHdl,
                                        tSimProcessSyncCb processSyncFunctions_p);
OPLKDLLEXPORT void sim_unsetProcessSyncFunctions();

tOplkError sim_processSyncCb();

#ifdef __cplusplus
}
#endif

#endif /* _INC_sim_process_sync_H_ */
