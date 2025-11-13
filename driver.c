#include <ntifs.h>
#include <ntddk.h>
#include <intrin.h>

NTSTATUS DriverEntry(PDRIVER_OBJECT DriverObject, PUNICODE_STRING RegistryPath) {
	__writecr8(DISPATCH_LEVEL);
	_disable();
	for (;;)__halt();
	return STATUS_FAILED_DRIVER_ENTRY;
}