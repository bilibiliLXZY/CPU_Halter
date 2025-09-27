#include <ntifs.h>
#include <intrin.h>

NTSTATUS DriverEntry(PDRIVER_OBJECT DriverObject, PUNICODE_STRING RegistryPath) {
	ULONG apicBase = (ULONG)(__readmsr(0x1B) & 0xFFFFF000);
	volatile ULONG* lapic = MmMapIoSpace(MmGetPhysicalAddress((PVOID)apicBase), PAGE_SIZE, MmNonCached);
	if (lapic) {
		ULONG lvt = lapic[0x320 / 4];
		lvt |= (1 << 16);
		lapic[0x320 / 4] = lvt;
		MmUnmapIoSpace((PVOID)lapic, PAGE_SIZE);
	}
	__writecr8(26);
	for(;;)__halt();
	return STATUS_FAILED_DRIVER_ENTRY;
}