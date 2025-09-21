#include <ntifs.h>
#include <intrin.h>

NTSTATUS DriverEntry(PDRIVER_OBJECT DriverObject, PUNICODE_STRING RegistryPath) {
	_disable();
	__writecr8(HIGH_LEVEL);
	UINT64 cr0 = __readcr0();
	cr0 &= 0xfffffffffffeffff;
	__writecr0(cr0);
	__halt();
	return STATUS_SUCCESS;
}