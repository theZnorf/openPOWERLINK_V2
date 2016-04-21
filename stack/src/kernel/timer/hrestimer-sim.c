/**
********************************************************************************
\file   hrestimer-sim.c

\brief  High-resolution timer module using simulation interface

\ingroup module_hrestimer
*******************************************************************************/

/*------------------------------------------------------------------------------
Copyright (c) 2016, Franz Profelt (franz.profelt@gmail.com)
------------------------------------------------------------------------------*/

//------------------------------------------------------------------------------
// includes
//------------------------------------------------------------------------------
#include <common/oplkinc.h>
#include <kernel/hrestimer.h>

#include "../../../../sim/simtime.h"

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
//          P R I V A T E   D E F I N I T I O N S                             //
//============================================================================//

//------------------------------------------------------------------------------
// const defines
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// local types
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// module local vars
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// local function prototypes
//------------------------------------------------------------------------------

//============================================================================//
//            P U B L I C   F U N C T I O N S                                 //
//============================================================================//

//------------------------------------------------------------------------------
/**
\brief    Initialize high-resolution timer module

The function initializes the high-resolution timer module

\return Returns a tOplkError error code.

\ingroup module_hrestimer
*/
//------------------------------------------------------------------------------
tOplkError hrestimer_init(void)
{
    return kErrorOk;
}

//------------------------------------------------------------------------------
/**
\brief    Shut down high-resolution timer module

The function shuts down the high-resolution timer module.

\return Returns a tOplkError error code.

\ingroup module_hrestimer
*/
//------------------------------------------------------------------------------
tOplkError hrestimer_exit(void)
{
    return kErrorOk;
}

//------------------------------------------------------------------------------
/**
\brief    Modify a high-resolution timer

The function modifies the timeout of the timer with the specified handle.
If the handle to which the pointer points to is zero, the timer must be created
first. If it is not possible to stop the old timer, this function always assures
that the old timer does not trigger the callback function with the same handle
as the new timer. That means the callback function must check the passed handle
with the one returned by this function. If these are unequal, the call can be
discarded.

\param  pTimerHdl_p     Pointer to timer handle.
\param  time_p          Relative timeout in [ns].
\param  pfnCallback_p   Callback function, which is called when timer expires.
                        (The function is called mutually exclusive with the Edrv
                        callback functions (Rx and Tx)).
\param  argument_p      User-specific argument
\param  fContinue_p     If TRUE, the callback function will be called continuously.
                        Otherwise, it is a one-shot timer.

\return Returns a tOplkError error code.

\ingroup module_hrestimer
*/
//------------------------------------------------------------------------------
tOplkError hrestimer_modifyTimer(tTimerHdl* pTimerHdl_p, ULONGLONG time_p,
                                 tTimerkCallback pfnCallback_p, ULONG argument_p,
                                 BOOL fContinue_p)
{
    return sim_modifyHresTimer(pTimerHdl_p, time_p, pfnCallback_p, argument_p, fContinue_p);
}

//------------------------------------------------------------------------------
/**
\brief    Delete a high-resolution timer

The function deletes an created high-resolution timer. The timer is specified
by its timer handle. After deleting, the handle is reset to zero.

\param  pTimerHdl_p     Pointer to timer handle.

\return Returns a tOplkError error code.

\ingroup module_hrestimer
*/
//------------------------------------------------------------------------------
tOplkError hrestimer_deleteTimer(tTimerHdl* pTimerHdl_p)
{
    return sim_deleteHresTimer(pTimerHdl_p);
}

//------------------------------------------------------------------------------
/**
\brief  Control external synchronization interrupt

This function enables/disables the external synchronization interrupt. If the
external synchronization interrupt is not supported, the call is ignored.

\param  fEnable_p       Flag determines if sync should be enabled or disabled.

\ingroup module_hrestimer
*/
//------------------------------------------------------------------------------
void hrestimer_controlExtSyncIrq(BOOL fEnable_p)
{
    UNUSED_PARAMETER(fEnable_p);
}

//------------------------------------------------------------------------------
/**
\brief  Set external synchronization interrupt time

This function sets the time when the external synchronization interrupt shall
be triggered to synchronize the host processor. If the external synchronization
interrupt is not supported, the call is ignored.

\param  time_p          Time when the sync shall be triggered

\ingroup module_hrestimer
*/
//------------------------------------------------------------------------------
void hrestimer_setExtSyncIrqTime(tTimestamp time_p)
{
    UNUSED_PARAMETER(time_p);
}

//============================================================================//
//            P R I V A T E   F U N C T I O N S                               //
//============================================================================//
/// \name Private Functions
/// \{

/// \}
