/** @file
  Find and extract SMBIOS data.

  SPDX-License-Identifier: BSD-2-Clause-Patent
**/

#include <Library/MemoryAllocationLib.h> // FreePool()
#include <OvmfPlatforms.h>               // CLOUDHV_DEVICE_ID

#include "SmbiosPlatformDxe.h"

/**
  Installs SMBIOS information for OVMF

  @param ImageHandle     Module's image handle
  @param SystemTable     Pointer of EFI_SYSTEM_TABLE

  @retval EFI_SUCCESS    Smbios data successfully installed
  @retval Other          Smbios data was not installed

**/
EFI_STATUS
EFIAPI
SmbiosTablePublishEntry (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  )
{
  EFI_STATUS  Status;
  UINT8       *SmbiosTables;

  // TODO(b/236184260): Add conditional back once we can reliably identify crosvm.
  Status = EFI_NOT_FOUND;
  SmbiosTables = GetCloudHvSmbiosTables ();
  if (SmbiosTables != NULL) {
    Status = InstallAllStructures (SmbiosTables);
  }

  return Status;
}
