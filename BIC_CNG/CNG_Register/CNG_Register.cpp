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

#include "register.h"
#include <iostream>
#include <string>
#include <fstream>
#include <streambuf>
///////////////////////////////////////////////////////////////////////////////
//
// Main entry point...
//
///////////////////////////////////////////////////////////////////////////////
using namespace std;
int __cdecl
wmain(
	__in int argc,
	__in_ecount(argc) PWSTR *argv)
{

	NTSTATUS ntStatus = STATUS_SUCCESS;
	if (argc > 1)
	{
		if ((_wcsicmp(argv[1], L"-register") == 0))
		{
			ntStatus = RegisterProvider();
			if (!NT_SUCCESS(ntStatus))
			{
				return ntStatus;
			}
			else return 0;
		}
		else if ((_wcsicmp(argv[1], L"-unregister") == 0))
		{
			ntStatus = UnRegisterProvider();
			if (!NT_SUCCESS(ntStatus))
			{
				return ntStatus;
			}
			else return 0;
		}
		else if ((_wcsicmp(argv[1], L"-enum") == 0))
		{
			EnumProviders();
		}
		else
		{
			wprintf(L"Unrecognized command \"%s\"\n", argv[1]);
			DisplayUsage();
		} 

	}
	else
	{
		ntStatus = UnRegisterProvider();
		if (!NT_SUCCESS(ntStatus))
		{
			return ntStatus;
		}
		else return 0;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////