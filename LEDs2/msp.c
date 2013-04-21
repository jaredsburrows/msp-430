#include <msp430g2231.h>

// BOARD NOTES
// BIT0 = 0x01 // RED LED   // P1.0 // LED1
// BIT6 = 0x06 // GREEN LED // P1.6 // LED2

// C NOTES
// binary bitwise
// &  AND
// ^  exclusive OR (XOR)
// |  inclusive OR
// unary bitwise
// ~  complement (NOT)

// TOGGLING
// x = x ^ mask; 
// (or shorthand x ^= mask;)
// XOR truth table
// 0 ^ 0 = 0
// 1 ^ 0 = 1
// 0 ^ 1 = 1
// 1 ^ 1 = 0

// x = x & (~mask); 
// (or x &= (~mask);)
// AND truth table
// 0 & 0 = 0
// 1 & 0 = 0
// 0 & 1 = 0
// 1 & 1 = 1

// x = x | mask; 
// (or x |= mask;)
// OR truth table
// 0 | 0 = 0
// 1 | 0 = 1
// 0 | 1 = 1
// 1 | 1 = 1

// non negative
unsigned int i = 0;
unsigned int blink = 0;

int main()
{
  // stop he watchdog timer
  WDTCTL = WDTPW + WDTHOLD;

  // set the output direction
  P1DIR |= (BIT0 + BIT6);

  // make sure the LEDS are off
  P1OUT &= ~(BIT0 + BIT6);               
  
  for (;;) 
  {
    for (i = 0; i < 2000; i++)
    {
      P1OUT ^= BIT0;
      P1OUT ^= BIT6;
    }

    for (i = 0; i < 20000; i++)
    {
      P1OUT &= ~(BIT0 + BIT6);
    }
  }
}