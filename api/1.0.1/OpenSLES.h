/*
 * Copyright (c) 2007-2009 The Khronos Group Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and /or associated documentation files (the "Materials "), to
 * deal in the Materials without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Materials, and to permit persons to whom the Materials are
 * furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Materials.
 *
 * THE MATERIALS ARE PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE MATERIALS OR THE USE OR OTHER DEALINGS IN THE
 * MATERIALS.
 *
 * OpenSLES.h - OpenSL ES version 1.0.1
 *
 */

/****************************************************************************/
/* NOTE: This file is a standard OpenSL ES header file and should not be    */
/* modified in any way.                                                     */
/****************************************************************************/

#ifndef OPENSL_ES_H_
#define OPENSL_ES_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "OpenSLES_Platform.h"


/*****************************************************************************/
/* Common types, structures, and defines                                */
/*****************************************************************************/

#ifndef _KHRONOS_KEYS_
#define _KHRONOS_KEYS_

#define KHRONOS_TITLE "KhronosTitle"
#define KHRONOS_ALBUM "KhronosAlbum"
#define KHRONOS_TRACK_NUMBER "KhronosTrackNumber"
#define KHRONOS_ARTIST "KhronosArtist"
#define KHRONOS_GENRE "KhronosGenre"
#define KHRONOS_YEAR "KhronosYear"
#define KHRONOS_COMMENT "KhronosComment"
#define KHRONOS_ARTIST_URL "KhronosArtistURL"
#define KHRONOS_CONTENT_URL "KhronosContentURL"
#define KHRONOS_RATING "KhronosRating"
#define KHRONOS_ALBUM_ART "KhronosAlbumArt"
#define KHRONOS_COPYRIGHT "KhronosCopyright"

#endif


/* remap common types to SL types for clarity */
typedef sl_int8_t              SLint8;          /* 8 bit signed integer  */
typedef sl_uint8_t             SLuint8;         /* 8 bit unsigned integer */
typedef sl_int16_t             SLint16;         /* 16 bit signed integer */
typedef sl_uint16_t            SLuint16;        /* 16 bit unsigned integer */
typedef sl_int32_t             SLint32;           /* 32 bit signed integer */
typedef sl_uint32_t            SLuint32;          /* 32 bit unsigned integer */

typedef SLuint32                    SLboolean;
#define SL_BOOLEAN_FALSE            ((SLboolean) 0x00000000)
#define SL_BOOLEAN_TRUE             ((SLboolean) 0x00000001)

typedef SLuint8						SLchar;			/* UTF-8 is to be used */
typedef SLint16						SLmillibel;
typedef SLuint32					SLmillisecond;
typedef SLuint32					SLmilliHertz;
typedef SLint32						SLmillimeter;
typedef SLint32						SLmillidegree;
typedef SLint16						SLpermille;
typedef SLuint32					SLmicrosecond;
typedef SLuint32					SLresult;

#define SL_MILLIBEL_MAX 	((SLmillibel) 0x7FFF)
#define SL_MILLIBEL_MIN 	((SLmillibel) (-SL_MILLIBEL_MAX-1))

#define SL_MILLIHERTZ_MAX	((SLmilliHertz) 0xFFFFFFFF)
#define SL_MILLIMETER_MAX	((SLmillimeter) 0x7FFFFFFF)

/** Interface ID defined as a UUID */
typedef const struct SLInterfaceID_ {
    SLuint32 time_low;
    SLuint16 time_mid;
    SLuint16 time_hi_and_version;
    SLuint16 clock_seq;
    SLuint8  node[6];
} * SLInterfaceID;

/* Forward declaration for the object interface */
struct SLObjectItf_;

typedef const struct SLObjectItf_ * const * SLObjectItf;

/* Objects ID's */

#define SL_OBJECTID_ENGINE			((SLuint32) 0x00001001)
#define SL_OBJECTID_LEDDEVICE		((SLuint32) 0x00001002)
#define SL_OBJECTID_VIBRADEVICE		((SLuint32) 0x00001003)
#define SL_OBJECTID_AUDIOPLAYER		((SLuint32) 0x00001004)
#define SL_OBJECTID_AUDIORECORDER	((SLuint32) 0x00001005)
#define SL_OBJECTID_MIDIPLAYER		((SLuint32) 0x00001006)
#define SL_OBJECTID_LISTENER		((SLuint32) 0x00001007)
#define SL_OBJECTID_3DGROUP			((SLuint32) 0x00001008)
#define SL_OBJECTID_OUTPUTMIX		((SLuint32) 0x00001009)
#define SL_OBJECTID_METADATAEXTRACTOR	((SLuint32) 0x0000100A)


/* SL Profiles */

#define SL_PROFILES_PHONE	((SLuint16) 0x0001)
#define SL_PROFILES_MUSIC	((SLuint16) 0x0002)
#define SL_PROFILES_GAME	((SLuint16) 0x0004)

/* Types of voices supported by the system */

#define SL_VOICETYPE_2D_AUDIO		((SLuint16) 0x0001)
#define SL_VOICETYPE_MIDI			((SLuint16) 0x0002)
#define SL_VOICETYPE_3D_AUDIO 		((SLuint16) 0x0004)
#define SL_VOICETYPE_3D_MIDIOUTPUT 	((SLuint16) 0x0008)

/* Convenient macros representing various different priority levels, for use with the SetPriority method */

#define SL_PRIORITY_LOWEST		((SLint32) (-0x7FFFFFFF-1))
#define SL_PRIORITY_VERYLOW		((SLint32) -0x60000000)
#define SL_PRIORITY_LOW			((SLint32) -0x40000000)
#define SL_PRIORITY_BELOWNORMAL	((SLint32) -0x20000000)
#define SL_PRIORITY_NORMAL		((SLint32) 0x00000000)
#define SL_PRIORITY_ABOVENORMAL	((SLint32) 0x20000000)
#define SL_PRIORITY_HIGH		((SLint32) 0x40000000)
#define SL_PRIORITY_VERYHIGH	((SLint32) 0x60000000)
#define SL_PRIORITY_HIGHEST	((SLint32) 0x7FFFFFFF)


/** These macros list the various sample formats that are possible on audio input and output devices. */

#define SL_PCMSAMPLEFORMAT_FIXED_8	((SLuint16) 0x0008)
#define SL_PCMSAMPLEFORMAT_FIXED_16	((SLuint16) 0x0010)
#define SL_PCMSAMPLEFORMAT_FIXED_20 	((SLuint16) 0x0014)
#define SL_PCMSAMPLEFORMAT_FIXED_24	((SLuint16) 0x0018)
#define SL_PCMSAMPLEFORMAT_FIXED_28 	((SLuint16) 0x001C)
#define SL_PCMSAMPLEFORMAT_FIXED_32	((SLuint16) 0x0020)


/** These macros specify the commonly used sampling rates (in milliHertz) supported by most audio I/O devices. */

#define SL_SAMPLINGRATE_8		((SLuint32) 8000000)
#define SL_SAMPLINGRATE_11_025	((SLuint32) 11025000)
#define SL_SAMPLINGRATE_12		((SLuint32) 12000000)
#define SL_SAMPLINGRATE_16		((SLuint32) 16000000)
#define SL_SAMPLINGRATE_22_05	((SLuint32) 22050000)
#define SL_SAMPLINGRATE_24		((SLuint32) 24000000)
#define SL_SAMPLINGRATE_32		((SLuint32) 32000000)
#define SL_SAMPLINGRATE_44_1	((SLuint32) 44100000)
#define SL_SAMPLINGRATE_48		((SLuint32) 48000000)
#define SL_SAMPLINGRATE_64		((SLuint32) 64000000)
#define SL_SAMPLINGRATE_88_2	((SLuint32) 88200000)
#define SL_SAMPLINGRATE_96		((SLuint32) 96000000)
#define SL_SAMPLINGRATE_192	((SLuint32) 192000000)

#define SL_SPEAKER_FRONT_LEFT			((SLuint32) 0x00000001)
#define SL_SPEAKER_FRONT_RIGHT			((SLuint32) 0x00000002)
#define SL_SPEAKER_FRONT_CENTER			((SLuint32) 0x00000004)
#define SL_SPEAKER_LOW_FREQUENCY			((SLuint32) 0x00000008)
#define SL_SPEAKER_BACK_LEFT			((SLuint32) 0x00000010)
#define SL_SPEAKER_BACK_RIGHT			((SLuint32) 0x00000020)
#define SL_SPEAKER_FRONT_LEFT_OF_CENTER	((SLuint32) 0x00000040)
#define SL_SPEAKER_FRONT_RIGHT_OF_CENTER	((SLuint32) 0x00000080)
#define SL_SPEAKER_BACK_CENTER			((SLuint32) 0x00000100)
#define SL_SPEAKER_SIDE_LEFT			((SLuint32) 0x00000200)
#define SL_SPEAKER_SIDE_RIGHT			((SLuint32) 0x00000400)
#define SL_SPEAKER_TOP_CENTER			((SLuint32) 0x00000800)
#define SL_SPEAKER_TOP_FRONT_LEFT		((SLuint32) 0x00001000)
#define SL_SPEAKER_TOP_FRONT_CENTER		((SLuint32) 0x00002000)
#define SL_SPEAKER_TOP_FRONT_RIGHT		((SLuint32) 0x00004000)
#define SL_SPEAKER_TOP_BACK_LEFT			((SLuint32) 0x00008000)
#define SL_SPEAKER_TOP_BACK_CENTER		((SLuint32) 0x00010000)
#define SL_SPEAKER_TOP_BACK_RIGHT		((SLuint32) 0x00020000)


/*****************************************************************************/
/* Errors                                                                    */
/*                                                                           */
/*****************************************************************************/

#define SL_RESULT_SUCCESS				((SLuint32) 0x00000000)
#define SL_RESULT_PRECONDITIONS_VIOLATED	((SLuint32) 0x00000001)
#define SL_RESULT_PARAMETER_INVALID		((SLuint32) 0x00000002)
#define SL_RESULT_MEMORY_FAILURE			((SLuint32) 0x00000003)
#define SL_RESULT_RESOURCE_ERROR			((SLuint32) 0x00000004)
#define SL_RESULT_RESOURCE_LOST			((SLuint32) 0x00000005)
#define SL_RESULT_IO_ERROR				((SLuint32) 0x00000006)
#define SL_RESULT_BUFFER_INSUFFICIENT		((SLuint32) 0x00000007)
#define SL_RESULT_CONTENT_CORRUPTED		((SLuint32) 0x00000008)
#define SL_RESULT_CONTENT_UNSUPPORTED		((SLuint32) 0x00000009)
#define SL_RESULT_CONTENT_NOT_FOUND		((SLuint32) 0x0000000A)
#define SL_RESULT_PERMISSION_DENIED		((SLuint32) 0x0000000B)
#define SL_RESULT_FEATURE_UNSUPPORTED		((SLuint32) 0x0000000C)
#define SL_RESULT_INTERNAL_ERROR			((SLuint32) 0x0000000D)
#define SL_RESULT_UNKNOWN_ERROR			((SLuint32) 0x0000000E)
#define SL_RESULT_OPERATION_ABORTED		((SLuint32) 0x0000000F)
#define SL_RESULT_CONTROL_LOST			((SLuint32) 0x00000010)


/* Object state definitions */

#define SL_OBJECT_STATE_UNREALIZED	((SLuint32) 0x00000001)
#define SL_OBJECT_STATE_REALIZED		((SLuint32) 0x00000002)
#define SL_OBJECT_STATE_SUSPENDED	((SLuint32) 0x00000003)

/* Object event definitions */

#define SL_OBJECT_EVENT_RUNTIME_ERROR			((SLuint32) 0x00000001)
#define SL_OBJECT_EVENT_ASYNC_TERMINATION		((SLuint32) 0x00000002)
#define SL_OBJECT_EVENT_RESOURCES_LOST			((SLuint32) 0x00000003)
#define SL_OBJECT_EVENT_RESOURCES_AVAILABLE		((SLuint32) 0x00000004)
#define SL_OBJECT_EVENT_ITF_CONTROL_TAKEN		((SLuint32) 0x00000005)
#define SL_OBJECT_EVENT_ITF_CONTROL_RETURNED		((SLuint32) 0x00000006)
#define SL_OBJECT_EVENT_ITF_PARAMETERS_CHANGED	((SLuint32) 0x00000007)


/*****************************************************************************/
/* Interface definitions                                                     */
/*****************************************************************************/

/** NULL Interface */

extern const SLInterfaceID SL_IID_NULL;

/*---------------------------------------------------------------------------*/
/* Data Source and Data Sink Structures                                      */
/*---------------------------------------------------------------------------*/

/** Data locator macros  */
#define SL_DATALOCATOR_URI			((SLuint32) 0x00000001)
#define SL_DATALOCATOR_ADDRESS		((SLuint32) 0x00000002)
#define SL_DATALOCATOR_IODEVICE		((SLuint32) 0x00000003)
#define SL_DATALOCATOR_OUTPUTMIX		((SLuint32) 0x00000004)
#define SL_DATALOCATOR_RESERVED5		((SLuint32) 0x00000005)
#define SL_DATALOCATOR_BUFFERQUEUE	((SLuint32) 0x00000006)
#define SL_DATALOCATOR_MIDIBUFFERQUEUE	((SLuint32) 0x00000007)
#define SL_DATALOCATOR_RESERVED8		((SLuint32) 0x00000008)



/** URI-based data locator definition where locatorType must be SL_DATALOCATOR_URI*/
typedef struct SLDataLocator_URI_ {
	SLuint32 		locatorType;
	SLchar *		URI;
} SLDataLocator_URI;

/** Address-based data locator definition where locatorType must be SL_DATALOCATOR_ADDRESS*/
typedef struct SLDataLocator_Address_ {
	SLuint32 	locatorType;
	void 		*pAddress;
	SLuint32	length;
} SLDataLocator_Address;

/** IODevice-types */
#define SL_IODEVICE_AUDIOINPUT	((SLuint32) 0x00000001)
#define SL_IODEVICE_LEDARRAY	((SLuint32) 0x00000002)
#define SL_IODEVICE_VIBRA		((SLuint32) 0x00000003)
#define SL_IODEVICE_RESERVED4	((SLuint32) 0x00000004)
#define SL_IODEVICE_RESERVED5	((SLuint32) 0x00000005)

/** IODevice-based data locator definition where locatorType must be SL_DATALOCATOR_IODEVICE*/
typedef struct SLDataLocator_IODevice_ {
	SLuint32	locatorType;
	SLuint32	deviceType;
	SLuint32	deviceID;
	SLObjectItf	device;
} SLDataLocator_IODevice;

/** OutputMix-based data locator definition where locatorType must be SL_DATALOCATOR_OUTPUTMIX*/
typedef struct SLDataLocator_OutputMix {
	SLuint32 		locatorType;
	SLObjectItf		outputMix;
} SLDataLocator_OutputMix;


/** BufferQueue-based data locator definition where locatorType must be SL_DATALOCATOR_BUFFERQUEUE*/
typedef struct SLDataLocator_BufferQueue {
	SLuint32	locatorType;
	SLuint32	numBuffers;
} SLDataLocator_BufferQueue;

/** MidiBufferQueue-based data locator definition where locatorType must be SL_DATALOCATOR_MIDIBUFFERQUEUE*/
typedef struct SLDataLocator_MIDIBufferQueue {
	SLuint32	locatorType;
	SLuint32	tpqn;
	SLuint32	numBuffers;
} SLDataLocator_MIDIBufferQueue;

/** Data format defines */
#define SL_DATAFORMAT_MIME		((SLuint32) 0x00000001)
#define SL_DATAFORMAT_PCM		((SLuint32) 0x00000002)
#define SL_DATAFORMAT_RESERVED3	((SLuint32) 0x00000003)


/** MIME-type-based data format definition where formatType must be SL_DATAFORMAT_MIME*/
typedef struct SLDataFormat_MIME_ {
	SLuint32 		formatType;
	SLchar * 		mimeType;
	SLuint32		containerType;
} SLDataFormat_MIME;

/* Byte order of a block of 16- or 32-bit data */
#define SL_BYTEORDER_BIGENDIAN				((SLuint32) 0x00000001)
#define SL_BYTEORDER_LITTLEENDIAN			((SLuint32) 0x00000002)

/* Container type */
#define SL_CONTAINERTYPE_UNSPECIFIED	((SLuint32) 0x00000001)
#define SL_CONTAINERTYPE_RAW		((SLuint32) 0x00000002)
#define SL_CONTAINERTYPE_ASF		((SLuint32) 0x00000003)
#define SL_CONTAINERTYPE_AVI		((SLuint32) 0x00000004)
#define SL_CONTAINERTYPE_BMP		((SLuint32) 0x00000005)
#define SL_CONTAINERTYPE_JPG		((SLuint32) 0x00000006)
#define SL_CONTAINERTYPE_JPG2000		((SLuint32) 0x00000007)
#define SL_CONTAINERTYPE_M4A		((SLuint32) 0x00000008)
#define SL_CONTAINERTYPE_MP3		((SLuint32) 0x00000009)
#define SL_CONTAINERTYPE_MP4		((SLuint32) 0x0000000A)
#define SL_CONTAINERTYPE_MPEG_ES		((SLuint32) 0x0000000B)
#define SL_CONTAINERTYPE_MPEG_PS		((SLuint32) 0x0000000C)
#define SL_CONTAINERTYPE_MPEG_TS		((SLuint32) 0x0000000D)
#define SL_CONTAINERTYPE_QT		((SLuint32) 0x0000000E)
#define SL_CONTAINERTYPE_WAV		((SLuint32) 0x0000000F)
#define SL_CONTAINERTYPE_XMF_0		((SLuint32) 0x00000010)
#define SL_CONTAINERTYPE_XMF_1		((SLuint32) 0x00000011)
#define SL_CONTAINERTYPE_XMF_2		((SLuint32) 0x00000012)
#define SL_CONTAINERTYPE_XMF_3		((SLuint32) 0x00000013)
#define SL_CONTAINERTYPE_XMF_GENERIC	((SLuint32) 0x00000014)
#define SL_CONTAINERTYPE_AMR  		((SLuint32) 0x00000015)
#define SL_CONTAINERTYPE_AAC		((SLuint32) 0x00000016)
#define SL_CONTAINERTYPE_3GPP		((SLuint32) 0x00000017)
#define SL_CONTAINERTYPE_3GA		((SLuint32) 0x00000018)
#define SL_CONTAINERTYPE_RM		((SLuint32) 0x00000019)
#define SL_CONTAINERTYPE_DMF		((SLuint32) 0x0000001A)
#define SL_CONTAINERTYPE_SMF		((SLuint32) 0x0000001B)
#define SL_CONTAINERTYPE_MOBILE_DLS	((SLuint32) 0x0000001C)
#define SL_CONTAINERTYPE_OGG	((SLuint32) 0x0000001D)


/** PCM-type-based data format definition where formatType must be SL_DATAFORMAT_PCM*/
typedef struct SLDataFormat_PCM_ {
	SLuint32 		formatType;
	SLuint32 		numChannels;
	SLuint32 		samplesPerSec;
	SLuint32 		bitsPerSample;
	SLuint32 		containerSize;
	SLuint32 		channelMask;
	SLuint32		endianness;
} SLDataFormat_PCM;

typedef struct SLDataSource_ {
	void *pLocator;
	void *pFormat;
} SLDataSource;


typedef struct SLDataSink_ {
	void *pLocator;
	void *pFormat;
} SLDataSink;


/*---------------------------------------------------------------------------*/
/* Standard Object Interface                                                 */
/*---------------------------------------------------------------------------*/

extern const SLInterfaceID SL_IID_OBJECT;

/** Object callback */


typedef void (SLAPIENTRY *slObjectCallback) (
	SLObjectItf caller,
	const void * pContext,
	SLuint32 event,
	SLresult result,
    SLuint32 param,
    void *pInterface
);


struct SLObjectItf_ {
	SLresult (*Realize) (
		SLObjectItf self,
		SLboolean async
	);
	SLresult (*Resume) (
		SLObjectItf self,
		SLboolean async
	);
	SLresult (*GetState) (
		SLObjectItf self,
		SLuint32 * pState
	);
	SLresult (*GetInterface) (
		SLObjectItf self,
		const SLInterfaceID iid,
		void * pInterface
	);
	SLresult (*RegisterCallback) (
		SLObjectItf self,
		slObjectCallback callback,
		void * pContext
	);
	void (*AbortAsyncOperation) (
		SLObjectItf self
	);
	void (*Destroy) (
		SLObjectItf self
	);
	SLresult (*SetPriority) (
		SLObjectItf self,
		SLint32 priority,
		SLboolean preemptable
	);
	SLresult (*GetPriority) (
		SLObjectItf self,
		SLint32 *pPriority,
		SLboolean *pPreemptable
	);
	SLresult (*SetLossOfControlInterfaces) (
		SLObjectItf self,
		SLint16 numInterfaces,
		SLInterfaceID * pInterfaceIDs,
		SLboolean enabled
	);
};


/*---------------------------------------------------------------------------*/
/* Audio IO Device capabilities interface                                    */
/*---------------------------------------------------------------------------*/

#define SL_DEFAULTDEVICEID_AUDIOINPUT 	((SLuint32) 0xFFFFFFFF)
#define SL_DEFAULTDEVICEID_AUDIOOUTPUT 	((SLuint32) 0xFFFFFFFE)
#define SL_DEFAULTDEVICEID_LED          ((SLuint32) 0xFFFFFFFD)
#define SL_DEFAULTDEVICEID_VIBRA        ((SLuint32) 0xFFFFFFFC)
#define SL_DEFAULTDEVICEID_RESERVED1    ((SLuint32) 0xFFFFFFFB)


#define SL_DEVCONNECTION_INTEGRATED         ((SLint16) 0x0001)
#define SL_DEVCONNECTION_ATTACHED_WIRED     ((SLint16) 0x0100)
#define SL_DEVCONNECTION_ATTACHED_WIRELESS  ((SLint16) 0x0200)
#define SL_DEVCONNECTION_NETWORK 		    ((SLint16) 0x0400)


#define SL_DEVLOCATION_HANDSET 	((SLuint16) 0x0001)
#define SL_DEVLOCATION_HEADSET 	((SLuint16) 0x0002)
#define SL_DEVLOCATION_CARKIT 	((SLuint16) 0x0003)
#define SL_DEVLOCATION_DOCK 	((SLuint16) 0x0004)
#define SL_DEVLOCATION_REMOTE 	((SLuint16) 0x0005)
/* Note: SL_DEVLOCATION_RESLTE is deprecated, use SL_DEVLOCATION_REMOTE instead. */
#define SL_DEVLOCATION_RESLTE 	((SLuint16) 0x0005)


#define SL_DEVSCOPE_UNKNOWN     ((SLuint16) 0x0001)
#define SL_DEVSCOPE_ENVIRONMENT ((SLuint16) 0x0002)
#define SL_DEVSCOPE_USER        ((SLuint16) 0x0003)


/*---------------------------------------------------------------------------*/
/* Playback interface                                                        */
/*---------------------------------------------------------------------------*/

/** Playback states */
#define SL_PLAYSTATE_STOPPED	((SLuint32) 0x00000001)
#define SL_PLAYSTATE_PAUSED	((SLuint32) 0x00000002)
#define SL_PLAYSTATE_PLAYING	((SLuint32) 0x00000003)

/** Play events **/
#define SL_PLAYEVENT_HEADATEND		((SLuint32) 0x00000001)
#define SL_PLAYEVENT_HEADATMARKER	((SLuint32) 0x00000002)
#define SL_PLAYEVENT_HEADATNEWPOS	((SLuint32) 0x00000004)
#define SL_PLAYEVENT_HEADMOVING		((SLuint32) 0x00000008)
#define SL_PLAYEVENT_HEADSTALLED	((SLuint32) 0x00000010)

#define SL_TIME_UNKNOWN	((SLuint32) 0xFFFFFFFF)


extern const SLInterfaceID SL_IID_PLAY;

/** Playback interface methods */

struct SLPlayItf_;
typedef const struct SLPlayItf_ * const * SLPlayItf;

typedef void (SLAPIENTRY *slPlayCallback) (
	SLPlayItf caller,
	void *pContext,
	SLuint32 event
);

struct SLPlayItf_ {
	SLresult (*SetPlayState) (
		SLPlayItf self,
		SLuint32 state
	);
	SLresult (*GetPlayState) (
		SLPlayItf self,
		SLuint32 *pState
	);
	SLresult (*GetDuration) (
		SLPlayItf self,
		SLmillisecond *pMsec
	);
	SLresult (*GetPosition) (
		SLPlayItf self,
		SLmillisecond *pMsec
	);
	SLresult (*RegisterCallback) (
		SLPlayItf self,
		slPlayCallback callback,
		void *pContext
	);
	SLresult (*SetCallbackEventsMask) (
		SLPlayItf self,
		SLuint32 eventFlags
	);
	SLresult (*GetCallbackEventsMask) (
		SLPlayItf self,
		SLuint32 *pEventFlags
	);
	SLresult (*SetMarkerPosition) (
		SLPlayItf self,
		SLmillisecond mSec
	);
	SLresult (*ClearMarkerPosition) (
		SLPlayItf self
	);
	SLresult (*GetMarkerPosition) (
		SLPlayItf self,
		SLmillisecond *pMsec
	);
	SLresult (*SetPositionUpdatePeriod) (
		SLPlayItf self,
		SLmillisecond mSec
	);
	SLresult (*GetPositionUpdatePeriod) (
		SLPlayItf self,
		SLmillisecond *pMsec
	);
};

/*---------------------------------------------------------------------------*/
/* Standard Recording Interface                                              */
/*---------------------------------------------------------------------------*/

/** Recording states */
#define SL_RECORDSTATE_STOPPED 	((SLuint32) 0x00000001)
#define SL_RECORDSTATE_PAUSED	((SLuint32) 0x00000002)
#define SL_RECORDSTATE_RECORDING	((SLuint32) 0x00000003)


/** Record event **/
#define SL_RECORDEVENT_HEADATLIMIT	((SLuint32) 0x00000001)
#define SL_RECORDEVENT_HEADATMARKER	((SLuint32) 0x00000002)
#define SL_RECORDEVENT_HEADATNEWPOS	((SLuint32) 0x00000004)
#define SL_RECORDEVENT_HEADMOVING	((SLuint32) 0x00000008)
#define SL_RECORDEVENT_HEADSTALLED 	((SLuint32) 0x00000010)
/* Note: SL_RECORDEVENT_BUFFER_INSUFFICIENT is deprecated, use SL_RECORDEVENT_BUFFER_FULL instead. */
#define SL_RECORDEVENT_BUFFER_INSUFFICIENT      ((SLuint32) 0x00000020)
#define SL_RECORDEVENT_BUFFER_FULL	((SLuint32) 0x00000020)


extern const SLInterfaceID SL_IID_RECORD;

struct SLRecordItf_;
typedef const struct SLRecordItf_ * const * SLRecordItf;

typedef void (SLAPIENTRY *slRecordCallback) (
	SLRecordItf caller,
	void *pContext,
	SLuint32 event
);

/** Recording interface methods */
struct SLRecordItf_ {
	SLresult (*SetRecordState) (
		SLRecordItf self,
		SLuint32 state
	);
	SLresult (*GetRecordState) (
		SLRecordItf self,
		SLuint32 *pState
	);
	SLresult (*SetDurationLimit) (
		SLRecordItf self,
		SLmillisecond msec
	);
	SLresult (*GetPosition) (
		SLRecordItf self,
		SLmillisecond *pMsec
	);
	SLresult (*RegisterCallback) (
		SLRecordItf self,
		slRecordCallback callback,
		void *pContext
	);
	SLresult (*SetCallbackEventsMask) (
		SLRecordItf self,
		SLuint32 eventFlags
	);
	SLresult (*GetCallbackEventsMask) (
		SLRecordItf self,
		SLuint32 *pEventFlags
	);
	SLresult (*SetMarkerPosition) (
		SLRecordItf self,
		SLmillisecond mSec
	);
	SLresult (*ClearMarkerPosition) (
		SLRecordItf self
	);
	SLresult (*GetMarkerPosition) (
		SLRecordItf self,
		SLmillisecond *pMsec
	);
	SLresult (*SetPositionUpdatePeriod) (
		SLRecordItf self,
		SLmillisecond mSec
	);
	SLresult (*GetPositionUpdatePeriod) (
		SLRecordItf self,
		SLmillisecond *pMsec
	);
};

/*---------------------------------------------------------------------------*/
/* Volume Interface                                                           */
/* --------------------------------------------------------------------------*/

extern const SLInterfaceID SL_IID_VOLUME;

struct SLVolumeItf_;
typedef const struct SLVolumeItf_ * const * SLVolumeItf;

struct SLVolumeItf_ {
	SLresult (*SetVolumeLevel) (
		SLVolumeItf self,
		SLmillibel level
	);
	SLresult (*GetVolumeLevel) (
		SLVolumeItf self,
		SLmillibel *pLevel
	);
	SLresult (*GetMaxVolumeLevel) (
		SLVolumeItf  self,
		SLmillibel *pMaxLevel
	);
	SLresult (*SetMute) (
		SLVolumeItf self,
		SLboolean mute
	);
	SLresult (*GetMute) (
		SLVolumeItf self,
		SLboolean *pMute
	);
	SLresult (*EnableStereoPosition) (
		SLVolumeItf self,
		SLboolean enable
	);
	SLresult (*IsEnabledStereoPosition) (
		SLVolumeItf self,
		SLboolean *pEnable
	);
	SLresult (*SetStereoPosition) (
		SLVolumeItf self,
		SLpermille stereoPosition
	);
	SLresult (*GetStereoPosition) (
		SLVolumeItf self,
		SLpermille *pStereoPosition
	);
};

/*---------------------------------------------------------------------------*/
/* Engine Interface                                                          */
/* --------------------------------------------------------------------------*/


extern const SLInterfaceID SL_IID_ENGINE;

struct SLEngineItf_;
typedef const struct SLEngineItf_ * const * SLEngineItf;


struct SLEngineItf_ {

	SLresult (*CreateLEDDevice) (
		SLEngineItf self,
		SLObjectItf * pDevice,
		SLuint32 deviceID,
		SLuint32 numInterfaces,
		const SLInterfaceID * pInterfaceIds,
		const SLboolean * pInterfaceRequired
	);
	SLresult (*CreateVibraDevice) (
		SLEngineItf self,
		SLObjectItf * pDevice,
		SLuint32 deviceID,
		SLuint32 numInterfaces,
		const SLInterfaceID * pInterfaceIds,
		const SLboolean * pInterfaceRequired
	);
	SLresult (*CreateAudioPlayer) (
		SLEngineItf self,
		SLObjectItf * pPlayer,
		SLDataSource *pAudioSrc,
		SLDataSink *pAudioSnk,
		SLuint32 numInterfaces,
		const SLInterfaceID * pInterfaceIds,
		const SLboolean * pInterfaceRequired
	);
	SLresult (*CreateAudioRecorder) (
		SLEngineItf self,
		SLObjectItf * pRecorder,
		SLDataSource *pAudioSrc,
		SLDataSink *pAudioSnk,
		SLuint32 numInterfaces,
		const SLInterfaceID * pInterfaceIds,
		const SLboolean * pInterfaceRequired
	);
	SLresult (*CreateMidiPlayer) (
		SLEngineItf self,
		SLObjectItf * pPlayer,
		SLDataSource *pMIDISrc,
		SLDataSource *pBankSrc,
		SLDataSink *pAudioOutput,
		SLDataSink *pVibra,
		SLDataSink *pLEDArray,
		SLuint32 numInterfaces,
		const SLInterfaceID * pInterfaceIds,
		const SLboolean * pInterfaceRequired
	);
	SLresult (*CreateListener) (
		SLEngineItf self,
		SLObjectItf * pListener,
		SLuint32 numInterfaces,
		const SLInterfaceID * pInterfaceIds,
		const SLboolean * pInterfaceRequired
	);
	SLresult (*Create3DGroup) (
		SLEngineItf self,
		SLObjectItf * pGroup,
		SLuint32 numInterfaces,
		const SLInterfaceID * pInterfaceIds,
		const SLboolean * pInterfaceRequired
	);
	SLresult (*CreateOutputMix) (
		SLEngineItf self,
		SLObjectItf * pMix,
		SLuint32 numInterfaces,
		const SLInterfaceID * pInterfaceIds,
		const SLboolean * pInterfaceRequired
	);
	SLresult (*CreateMetadataExtractor) (
		SLEngineItf self,
		SLObjectItf * pMetadataExtractor,
		SLDataSource * pDataSource,
		SLuint32 numInterfaces,
		const SLInterfaceID * pInterfaceIds,
		const SLboolean * pInterfaceRequired
	);
    SLresult (*CreateExtensionObject) (
        SLEngineItf self,
        SLObjectItf * pObject,
        void * pParameters,
        SLuint32 objectID,
        SLuint32 numInterfaces,
        const SLInterfaceID * pInterfaceIds,
        const SLboolean * pInterfaceRequired
    );
	SLresult (*QueryNumSupportedInterfaces) (
		SLEngineItf self,
		SLuint32 objectID,
		SLuint32 * pNumSupportedInterfaces
	);
	SLresult (*QuerySupportedInterfaces) (
		SLEngineItf self,
		SLuint32 objectID,
		SLuint32 index,
		SLInterfaceID * pInterfaceId
	);
    SLresult (*QueryNumSupportedExtensions) (
        SLEngineItf self,
        SLuint32 * pNumExtensions
    );
    SLresult (*QuerySupportedExtension) (
        SLEngineItf self, 
        SLuint32 index,
        SLchar * pExtensionName,
        SLint16 * pNameLength
    );
    SLresult (*IsExtensionSupported) (
        SLEngineItf self, 
        const SLchar * pExtensionName,
        SLboolean * pSupported
    );
};


/*****************************************************************************/
/* SL engine constructor                                                     */
/*****************************************************************************/

#define SL_ENGINEOPTION_THREADSAFE	((SLuint32) 0x00000001)
#define SL_ENGINEOPTION_LOSSOFCONTROL	((SLuint32) 0x00000002)

typedef struct SLEngineOption_ {
	SLuint32 feature;
	SLuint32 data;
} SLEngineOption;


SLresult SLAPIENTRY slCreateEngine(
	SLObjectItf             *pEngine,
	SLuint32                numOptions,
	const SLEngineOption    *pEngineOptions,
	SLuint32                numInterfaces,
	const SLInterfaceID     *pInterfaceIds,
	const SLboolean         * pInterfaceRequired
);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* OPENSL_ES_H_ */
