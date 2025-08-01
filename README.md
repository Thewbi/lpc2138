# lpc2138

Samples and Tools for the lpc2138.

The NXP LPC2138 chip is almost identical to the LPC2134 chip used in the infamous T962 reflow oven!
See https://github.com/UnifiedEngineering/T-962-improvements

I am trying to learn programming the LPC2134 / LPC2138 in order to understand what the improved firmware
of the reflow oven does! This knowledge could be applied to building another reflow oven using a simple
toaster oven of something of that sorts.

As an alternative to this approach, you can use the Rowley CrossWorks IDE. This IDE works very, very well
but has a limitation of the size of the .hex file it will produce when using the unpayed, free version.
The payed version does not have this size limitation.

## Hardware

I am using the OLIMEX LPC-H2138 header board https://www.olimex.com/Products/ARM/NXP/LPC-H2138/
It is the most afordable of all boards and I own the Olimex ARM-USB-OCD-H adapter (https://www.olimex.com/Products/ARM/JTAG/ARM-USB-OCD-H/) already.

You can also take a look at this board: https://www.olimex.com/Products/ARM/NXP/LPC-MT-2138/
Or this one: https://www.olimex.com/Products/ARM/NXP/LPC-P2138/
Or this one for the LPC-2148: https://www.olimex.com/Products/ARM/NXP/LPC-P2148/

## Software

The folder "bin" contais the GNU none eabi toolchain and the OpenOCD tool to flash and debug the LPC2134/8.

The folder OpenOCD_GDB_Sample contains steps and config files to flash and debug the microcontroller.

