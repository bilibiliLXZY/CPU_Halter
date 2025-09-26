#include <ntifs.h>
#include <intrin.h>

NTSTATUS DriverEntry(PDRIVER_OBJECT DriverObject, PUNICODE_STRING RegistryPath) {
	ULONG apicBase = (ULONG)(__readmsr(0x1B) & 0xFFFFF000);
	volatile ULONG* lapic = MmMapIoSpace(MmGetPhysicalAddress((PVOID)apicBase), PAGE_SIZE, MmNonCached);
	ULONG lvt = lapic[0x320 / 4];
	lvt = (lvt & ~0x700) | (0x4 << 8);
	lvt &= ~(1 << 16);
	lapic[0x320 / 4] = lvt;
	_disable();
	__writecr8(HIGH_LEVEL);
	for(;;)__halt();
	return STATUS_FAILED_DRIVER_ENTRY;
}