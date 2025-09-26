# CPU_Halter
A Simple KMDF Driver based CPU Halter

## Process ##
1. Get APIC physical address
2. Map the APIC memory to Virtual Address Space
3. Get current LVT timer value
4. Set the timer mode to Periodic
5. Set the Timer Interrupt to enable (Allowing the Timer interrupt to wake the CPU)
6. Set CR8 Value to HIGH_LEVEL
7. Halt CPU in a dead loop
