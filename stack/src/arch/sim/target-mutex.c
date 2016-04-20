/**
********************************************************************************
\file   linux/target-mutex.c

\brief  Architecture specific mutex implementation

This file contains the mutex implementation for the usage of the simulation
 interface and implemented empty mutex methods.

\ingroup module_target
*******************************************************************************/

/*------------------------------------------------------------------------------
Copyright (c) 2016, Franz Profelt (franz.profelt@gmail.com)
------------------------------------------------------------------------------*/

//------------------------------------------------------------------------------
// includes
//------------------------------------------------------------------------------
#include <common/oplkinc.h>

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
\brief  Create Mutex

The function creates a mutex.

\param  mutexName_p             The name of the mutex to create.
\param  pMutex_p                Pointer to store the created mutex.

\return The function returns a tOplkError error code.
\retval kErrorOk                Mutex was successfully created.
\retval kErrorNoFreeInstance    An error occured while creating the mutex.

\ingroup module_target
*/
//------------------------------------------------------------------------------
tOplkError target_createMutex(char* mutexName_p, OPLK_MUTEX_T* pMutex_p)
{
    UNUSED_PARAMETER(mutexName_p);
    UNUSED_PARAMETER(pMutex_p);

    return kErrorOk;
}


//------------------------------------------------------------------------------
/**
\brief  Destroy Mutex

The function destroys a mutex.

\param  mutexId_p               The ID of the mutex to destroy.

\ingroup module_target
*/
//------------------------------------------------------------------------------
void target_destroyMutex(OPLK_MUTEX_T mutexId_p)
{
    UNUSED_PARAMETER(mutexId_p);
}

//------------------------------------------------------------------------------
/**
\brief  Lock Mutex

The function locks a mutex.

\param  mutexId_p               The ID of the mutex to lock.

\return The function returns a tOplkError error code.
\retval kErrorOk                Mutex was successfully locked.
\retval kErrorNoFreeInstance    An error occured while locking the mutex.

\ingroup module_target
*/
//------------------------------------------------------------------------------
tOplkError target_lockMutex(OPLK_MUTEX_T mutexId_p)
{
    UNUSED_PARAMETER(mutexId_p);

    return kErrorOk;
}

//------------------------------------------------------------------------------
/**
\brief  Unlock Mutex

The function unlocks a mutex.

\param  mutexId_p               The ID of the mutex to unlock.

\ingroup module_target
*/
//------------------------------------------------------------------------------
void target_unlockMutex(OPLK_MUTEX_T mutexId_p)
{
    UNUSED_PARAMETER(mutexId_p);
}

//============================================================================//
//            P R I V A T E   F U N C T I O N S                               //
//============================================================================//
/// \name Private Functions
/// \{

///\}
