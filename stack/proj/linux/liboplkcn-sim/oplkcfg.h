/**
********************************************************************************
\file   oplkcfg.h

\brief  Configuration options for openPOWERLINK CN library

This file contains the configuration options for the openPOWERLINK CN libary
on Linux with simulation inteface.

*******************************************************************************/

/*------------------------------------------------------------------------------
Copyright (c) 2016, Franz Profelt (franz.profelt@gmail.com)
------------------------------------------------------------------------------*/

#ifndef _INC_oplkcfg_H_
#define _INC_oplkcfg_H_

//==============================================================================
// generic defines which for whole openPOWERLINK stack
//==============================================================================

#ifndef BENCHMARK_MODULES
#define BENCHMARK_MODULES                           0 //0xEE800042L
#endif

// Default debug level:
// Only debug traces of these modules will be compiled which flags are set in define DEF_DEBUG_LVL.
#ifndef DEF_DEBUG_LVL
#define DEF_DEBUG_LVL                               (0xFFFFFFFFFL)
#endif

#undef FTRACE_DEBUG

/* assure that system priorities of hrtimer and net-rx kernel threads are set appropriate */
#define CONFIG_THREAD_PRIORITY_HIGH                 75
#define CONFIG_THREAD_PRIORITY_MEDIUM               50
#define CONFIG_THREAD_PRIORITY_LOW                  49

// These macros define all modules which are included
#define CONFIG_INCLUDE_PDO
#define CONFIG_INCLUDE_SDOS
#define CONFIG_INCLUDE_SDOC
#define CONFIG_INCLUDE_SDO_ASND
#define CONFIG_INCLUDE_MASND
#define CONFIG_INCLUDE_LEDK

#define CONFIG_DLLCAL_QUEUE                         CIRCBUF_QUEUE

#define CONFIG_VETH_SET_DEFAULT_GATEWAY             FALSE

#define CONFIG_CHECK_HEARTBEAT_PERIOD               1000        // 1000 ms

//==============================================================================
// Ethernet driver (Edrv) specific defines
//==============================================================================

// switch this define to TRUE if Edrv supports fast tx frames
#define CONFIG_EDRV_FAST_TXFRAMES                   FALSE

// switch this define to TRUE if Edrv supports early receive interrupts
#define CONFIG_EDRV_EARLY_RX_INT                    FALSE

// switch this define to TRUE if Edrv supports auto delay responses
#define CONFIG_EDRV_AUTO_RESPONSE_DELAY             FALSE

// switch this define to TRUE to include Edrv diagnostic functions
#define CONFIG_EDRV_USE_DIAGNOSTICS                 FALSE

//==============================================================================
// Data Link Layer (DLL) specific defines
//==============================================================================

// switch this define to TRUE if Edrv supports fast tx frames
// and DLL shall pass PRes as ready to Edrv after SoC
#define CONFIG_DLL_PRES_READY_AFTER_SOC             FALSE

// switch this define to TRUE if Edrv supports fast tx frames
// and DLL shall pass PRes as ready to Edrv after SoA
#define CONFIG_DLL_PRES_READY_AFTER_SOA             FALSE

// CN supports PRes Chaining
#define CONFIG_DLL_PRES_CHAINING_CN                 FALSE

// negative time shift of isochronous task in relation to SoC
#define CONFIG_DLL_SOC_SYNC_SHIFT_US                150

// time when CN processing the isochronous task (sync callback of application and cycle preparation)
#define CONFIG_DLL_PROCESS_SYNC                     DLL_PROCESS_SYNC_ON_SOC

// Disable deferred release of rx-buffers until EdrvPcap supports it
#define CONFIG_DLL_DEFERRED_RXFRAME_RELEASE_SYNC    FALSE
#define CONFIG_DLL_DEFERRED_RXFRAME_RELEASE_ASYNC   FALSE

//==============================================================================
// OBD specific defines
//==============================================================================

// Switch this define to TRUE if the stack should check the object ranges
#define CONFIG_OBD_CHECK_OBJECT_RANGE               TRUE

// set this define to TRUE if there are strings or domains in OD, which
// may be changed in object size and/or object data pointer by its object
// callback function (called event kObdEvWrStringDomain)
#define CONFIG_OBD_USE_STRING_DOMAIN_IN_RAM         TRUE

// Set this string to true if OD configuration save and load feature is
// supported by the device
#ifdef CONFIG_STORE_RESTORE
#define CONFIG_OBD_USE_STORE_RESTORE                TRUE
#define CONFIG_OBD_CALC_OD_SIGNATURE                TRUE
#endif

//==============================================================================
// Timer module specific defines
//==============================================================================

// if TRUE the high resolution timer module will be used (must always be TRUE!)
#define CONFIG_TIMER_USE_HIGHRES                    TRUE

//==============================================================================
// SDO module specific defines
//==============================================================================


//==============================================================================
// Trace defines
//==============================================================================

// size of character buffer holding trace messages
#define TRACE_SIM_BUFFER_SIZE                       256

#endif // _INC_oplkcfg_H_
