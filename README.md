# MSP430 Examples [![Build Status](https://travis-ci.org/jaredsburrows/MSP430.png)](https://travis-ci.org/jaredsburrows/MSP430)


Here are some examples of how to use the MSP430

### How to compile and run your code

Basic Compilation:

Filename: msp.c

    msp430-gcc -mmcu=msp430g2231 -o msp.elf msp2.c

    mspdebug rf2500 
    debug> 'erase all' 
    debug> 'prog msp.elf' 
    debug> 'run'

Here is a one-liner that will compile, show extra warnings, stop on warnings and compile the code and then push it your device:

    msp430-gcc -Wall -Wextra -Werror -Os -O2 -mmcu=msp430g2231 -o msp.elf msp2.c && mspdebug rf2500 'erase all' 'prog msp.elf' 'run'
