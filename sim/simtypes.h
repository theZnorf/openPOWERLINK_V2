/**
********************************************************************************
\file   simtypes.h

\brief  Include file for types used by the simulation interface

*******************************************************************************/

/*------------------------------------------------------------------------------
Copyright (c) 2016, Bernecker+Rainer Industrie-Elektronik Ges.m.b.H. (B&R)
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the copyright holders nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDERS BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
------------------------------------------------------------------------------*/

#ifndef _INC_simtypes_H_
#define _INC_simtypes_H_

//------------------------------------------------------------------------------
// includes
//------------------------------------------------------------------------------

#include <oplk/basictypes.h>

//------------------------------------------------------------------------------
// const defines
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// typedef
//------------------------------------------------------------------------------

#ifdef tOplkError
typedef tOplkError tError;
#else
typedef UINT8 tError;
#endif

#ifndef tTimerHdl
typedef  ULONG tTimerHdl;
#endif

#ifndef tEventSink
typedef UINT8 tEventSink;
#endif

#ifndef tTimerArg
/**
\brief  Structure for timer arguments

The structure defines the arguments for a timer. It is used to setup a timer.
*/
typedef struct
{
    tEventSink          eventSink;      ///< The sink to send the event when the timer expires
    union
    {
        UINT32          value;          ///< Timer argument supplied as UINT32
        void*           pValue;         ///< Timer argument supplied as void*
    } argument;                         ///< The timer argument to be sent in the timer event
} tTimerArg;
#endif

#ifndef tLedType
typedef UINT32 tLedType;
#endif

//------------------------------------------------------------------------------
// function prototypes
//------------------------------------------------------------------------------

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef __cplusplus
}
#endif

#endif /* _INC_simtypes_H_ */
