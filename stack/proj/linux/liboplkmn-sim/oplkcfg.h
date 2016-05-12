/**
********************************************************************************
\file   oplkcfg.h

\brief  Configuration options for openPOWERLINK MN library

This file contains the configuration options for the openPOWERLINK MN libary
on Linux with simulation interface.

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
#define CONFIG_INCLUDE_NMT_MN
#define CONFIG_INCLUDE_PDO
#define CONFIG_INCLUDE_SDOS
#define CONFIG_INCLUDE_SDOC
#define CONFIG_INCLUDE_SDO_ASND
#define CONFIG_INCLUDE_SDO_UDP
#define CONFIG_INCLUDE_VETH
#define CONFIG_INCLUDE_IP
#define CONFIG_INCLUDE_CFM
#define CONFIG_INCLUDE_PRES_FORWARD

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

#if defined(CONFIG_INCLUDE_CFM)
#define CONFIG_OBD_DEF_CONCISEDCF_FILENAME          "mnobd.cdc"
#define CONFIG_CFM_CONFIGURE_CYCLE_LENGTH           TRUE
#endif

// Configure if the range from 0xA000 is used for mapping client objects.
// openCONFIGURATOR uses this range for mapping objects.
#define CONFIG_OBD_INCLUDE_A000_TO_DEVICE_PART      TRUE

//==============================================================================
// Timer module specific defines
//==============================================================================

// if TRUE the high resolution timer module will be used (must always be TRUE!)
#define CONFIG_TIMER_USE_HIGHRES                    TRUE

//==============================================================================
// SDO module specific defines
//==============================================================================

// increase the number of SDO channels, because we are master
#define CONFIG_SDO_MAX_CONNECTION_ASND              100
#define CONFIG_SDO_MAX_CONNECTION_SEQ               100
#define CONFIG_SDO_MAX_CONNECTION_COM               100
#define CONFIG_SDO_MAX_CONNECTION_UDP               50


//==============================================================================
// Trace defines
//==============================================================================

// size of character buffer holding trace messages
#define TRACE_SIM_BUFFER_SIZE                       256

#endif // _INC_oplkcfg_H_
