MSP430
======

Here are some examples of how to use the MSP430


<<<<<<< HEAD
## How to compile and run your code
=======
How to compile and run your code
=====
>>>>>>> 96d31d7e51cbda9f1be6ff2944604313509cb731

Basic Compilation:

Filename: msp.c

<<<<<<< HEAD
    msp430-gcc -mmcu=msp430g2231 -o msp.elf msp2.c

    mspdebug rf2500 
    debug> 'erase all' 
    debug> 'prog msp.elf' 
    debug> 'run'

Here is a one-liner that will compile, show extra warnings, stop on warnings and compile the code and then push it your device:

    msp430-gcc -Wall -Wextra -Werror -Os -O2 -mmcu=msp430g2231 -o msp.elf msp2.c && mspdebug rf2500 'erase all' 'prog msp.elf' 'run'
=======
msp430-gcc -mmcu=msp430g2231 -o msp.elf msp2.c

mspdebug rf2500 
debug> 'erase all' 
debug> 'prog msp.elf' 
debug> 'run'

Here is a one-liner that will compile, show extra warnings, stop on warnings and compile the code and then push it your device:

msp430-gcc -Wall -Wextra -Werror -Os -O2 -mmcu=msp430g2231 -o msp.elf msp2.c && mspdebug rf2500 'erase all' 'prog msp.elf' 'run'
>>>>>>> 96d31d7e51cbda9f1be6ff2944604313509cb731

