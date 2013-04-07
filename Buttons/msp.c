#include <msp430g2231.h>

// BOARD NOTES
// BIT0 = 0x01 // RED LED     // P1.0 // LED1
// BIT6 = 0x06 // GREEN LED   // P1.6 // LED2
// BIT3 = 0x03 // LEFT Button // P1.3 // 

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

int blink = 0;

int main()
{
  // Setup Watchdog - Stop Watchdog - password + hold counter
  WDTCTL = WDTPW + WDTHOLD;

  // Set RED LED on
  P1DIR |= BIT0 + BIT6;
  0x01 + 0x06

  // Set GREEN LED off
  P1OUT &= ~BIT6;

  // Setup up the Button
  P1IE |= BIT3;
  P1IFG &= ~BIT3;

  __enable_interrupt();

  return 0;
}

// Port 1 interrupt service routine
#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)
{
  if (blink == 0)
  {
    blink = 1;
    P1OUT ^= (BIT0 + BIT6);
  }
  else
  {
    blink = 0;  
  }
  P1IFG &= ~BIT3; // P1.3 IFG cleared
  P1IES ^= BIT3; // toggle the interrupt edge,
}