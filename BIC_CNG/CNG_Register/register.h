/*******************************************************************************
 *
 *                                   GRADIANT
 *
 *     Galician Research And Development center In AdvaNced Telecommunication
 *
 *
 * Copyright (c) 2019 by Gradiant. All rights reserved.
 * Licensed under the Mozilla Public License v2.0 (the "LICENSE").
 * https://github.com/Gradiant/BlackICE_Connect/LICENSE
 *******************************************************************************/

#ifndef REGISTER_H
#define REGISTER_H


///////////////////////////////////////////////////////////////////////////////
//
// Headers...
//
///////////////////////////////////////////////////////////////////////////////
#include <windows.h>
#include <wincrypt.h>
#include <stdlib.h>
#include <stdio.h>
#include <bcrypt.h>
#include <ncrypt.h>
#include <ncrypt_provider.h>
#include <bcrypt_provider.h>

//
// File name of key storage provider's binary. *NO* path.
//
#define KSP_BINARY							L"CNG_Connector.dll"
#define GRADIANT_KSP_PROVIDER_NAME		L"Gradiant Key Storage Provider" //name of the KSP provider

//error handling
#ifndef NT_SUCCESS
#define NT_SUCCESS(status) (status >= 0)
#endif

#ifndef STATUS_SUCCESS
#define STATUS_SUCCESS                  ((NTSTATUS)0x00000000L)
#define STATUS_NOT_SUPPORTED            ((NTSTATUS)0xC00000BBL)
#define STATUS_BUFFER_TOO_SMALL         ((NTSTATUS)0xC0000023L)
#define STATUS_INSUFFICIENT_RESOURCES   ((NTSTATUS)0xC000009AL)
#define STATUS_INTERNAL_ERROR           ((NTSTATUS)0xC00000E5L)
#define STATUS_INVALID_SIGNATURE        ((NTSTATUS)0xC000A000L)

#define STATUS_LOGON_FAILURE			((NTSTATUS)0xC000006D)
#define STATUS_DECRYPTION_FAILED		((NTSTATUS)0xC000028B)
#define STATUS_NO_SUCH_DEVICE			((NTSTATUS)0xC000000E)
#define	STATUS_DEVICE_REMOVED			((NTSTATUS)0xC00002B6)
#define STATUS_DEVICE_UNREACHABLE		((NTSTATUS)0xC0000464)
#define STATUS_INVALID_TOKEN			((NTSTATUS)0xC0000465)
#define STATUS_NO_MORE_ENTRIES			((NTSTATUS)0x8000001A)
#endif
#define STATUS_BUFFERED					((NTSTATUS)0x11111111L)




///////////////////////////////////////////////////////////////////////////////
//
// Forward declarations of local routines...
//
///////////////////////////////////////////////////////////////////////////////
void
DisplayUsage(
	void
);

void
EnumProviders(
	void
);

NTSTATUS
RegisterProvider(
	void
);

NTSTATUS
UnRegisterProvider(
	void
);



///////////////////////////////////////////////////////////////////////////////

#endif //REGISTER_H
