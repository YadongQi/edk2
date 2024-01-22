/** @file
  OVMF ACPI Platform Driver

  Copyright (C) 2015, Red Hat, Inc.
  Copyright (c) 2008 - 2014, Intel Corporation. All rights reserved.<BR>

  SPDX-License-Identifier: BSD-2-Clause-Patent
**/

#include <OvmfPlatforms.h> // CLOUDHV_DEVICE_ID
#include <ConfidentialComputingGuestAttr.h>

#include <Library/AcpiPlatformLib.h>

#include "AcpiPlatform.h"

/**
  Effective entrypoint of Acpi Platform driver.

  @param  ImageHandle
  @param  SystemTable

  @return EFI_SUCCESS
  @return EFI_LOAD_ERROR
  @return EFI_OUT_OF_RESOURCES

**/
EFI_STATUS
EFIAPI
InstallAcpiTables (
  IN   EFI_ACPI_TABLE_PROTOCOL  *AcpiTable
  )
{
  // TODO(b/236184260): Add conditional back once we can reliably identify
  // crosvm.
  return InstallCloudHvTables(AcpiTable);
}
