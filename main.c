#include "LPC17xx.h"

// Global variable to store DAC value
volatile uint16_t dac_value = 0;

// Initialize DAC
void DAC_Init(void)
{
    // Enable power to DAC (PCDAC = bit 15)
    LPC_SC->PCONP |= (1 << 15);

    // Pin function select: P0.26 → AOUT (function 2)
    LPC_PINCON->PINSEL1 &= ~(3 << 20);   // Clear bits
    LPC_PINCON->PINSEL1 |=  (2 << 20);   // Set function 2 (AOUT)
}

// Write a 10-bit value to DAC
void DAC_Write(uint16_t value)
{
    // Update the global variable
    dac_value = value;

    // Write to DAC register (LPC1768 DAC is 10-bit → bits [15:6])
    LPC_DAC->DACR = (value & 0x3FF) << 6;  // Set DAC value
}

int main(void)
{
    uint16_t i;

    DAC_Init();  // Initialize DAC

    while (1)
    {
        // Ramp from 0V to 3.3V (0 to 1023)
        for (i = 0; i <= 1023; i++)
        {
            DAC_Write(i);  // Write value to DAC
            for (volatile int d = 0; d < 100; d++);  // Small delay for smooth ramp
        }

        // Immediately drop to 0V
        DAC_Write(0);  // Set DAC to 0V

        // Stay at 0V for a while (e.g., 1000 iterations)
        for (volatile int d = 0; d < 100000; d++);  // Delay to stay at 0V

        // Ramp from 0V to 3.3V again (0 to 1023)
        for (i = 0; i <= 1023; i++)
        {
            DAC_Write(i);  // Write value to DAC
            for (volatile int d = 0; d < 100; d++);  // Small delay for smooth ramp
        }

        // Again immediately drop to 0V
        DAC_Write(0);  // Set DAC to 0V

        // Stay at 0V for a while again (e.g., 1000 iterations)
        for (volatile int d = 0; d < 100000; d++);  // Delay to stay at 0V
    }
}