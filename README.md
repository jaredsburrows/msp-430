# MSP430 Examples

[![License](https://img.shields.io/badge/License-Apache%202.0-blue.svg)](https://www.apache.org/licenses/LICENSE-2.0)
[![Build](https://github.com/jaredsburrows/msp-430/actions/workflows/build.yml/badge.svg)](https://github.com/jaredsburrows/msp-430/actions/workflows/build.yml)
[![Twitter Follow](https://img.shields.io/twitter/follow/jaredsburrows.svg?style=social)](https://twitter.com/jaredsburrows)

Here are some examples of how to use the MSP430

### How to compile and run your code

Basic Compilation:

Filename: msp.c

```bash
msp430-gcc -mmcu=msp430g2231 -o msp.elf msp.c

mspdebug rf2500 
debug> 'erase all' 
debug> 'prog msp.elf' 
debug> 'run'
```

Here is a one-liner that will compile, show extra warnings, stop on warnings and compile the code and then push it your device:

```bash
msp430-gcc -Wall -Wextra -Werror -Os -O2 -mmcu=msp430g2231 -o msp.elf msp.c && mspdebug rf2500 'erase all' 'prog msp.elf' 'run'
```

