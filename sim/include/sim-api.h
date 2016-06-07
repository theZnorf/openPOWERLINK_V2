/**
********************************************************************************
\file   sim-api.h

\brief  Include file for simulation interface providing api functions

 This include file only provides the functions which require a customized
 behavior. All other api functions can be called directly by the simulation
 environment.

*******************************************************************************/

/*------------------------------------------------------------------------------
Copyright (c) 2016, Franz Profelt (franz.profelt@gmail.com)
------------------------------------------------------------------------------*/

#ifndef _INC_sim_api_H_
#define _INC_sim_api_H__INC_sim_api_H_

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

OPLKDLLEXPORT BOOL sim_setApiFunctions(tSimulationInstanceHdl simHdl,
                                        tApiFunctions apiFunctions_p);
OPLKDLLEXPORT void sim_unsetApiFunctions();

OPLKDLLEXPORT tOplkError sim_oplkCreate(tOplkApiInitParam* pInitParam_p);

#ifdef __cplusplus
}
#endif

#endif /* _INC_sim_api_H_ */
