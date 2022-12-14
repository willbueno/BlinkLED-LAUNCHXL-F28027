#include "Peripheral_Setup.h"

uint32_t count = 0;

/**
 * main.c
 */
int main(void)
{
    InitSysCtrl();          // Initialize System Control
    DINT;                   // Disable CPU interrupts
    InitPieCtrl();          // Initialize the PIE control registers to their default state

    IER = 0x0000;           // Disable CPU interrupts
    IFR = 0x0000;           // Clear all CPU interrupt flags

    InitPieVectTable();     // Initialize the PIE vector table

    Setup_GPIO();

    EINT;                   // Enable Global interrupt INTM
    ERTM;                   // Enable Global real time interrupt DBGM

    while (1)
    {
        for (count = 0; count < 0x000FFFFF; count++)
        {
        }

        GpioDataRegs.GPATOGGLE.bit.GPIO0 = 1;
        GpioDataRegs.GPATOGGLE.bit.GPIO1 = 1;
        GpioDataRegs.GPATOGGLE.bit.GPIO2 = 1;
        GpioDataRegs.GPATOGGLE.bit.GPIO3 = 1;
    }

    return 0;
}
