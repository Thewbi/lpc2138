cd C:\Users\lapto\Downloads\Wbudy-main\Wbudy-main\2138

# Introduction

To connect to the LPC2138, there is a way to restart the chip and make it boot into the bootloader.
Once the bootloader is running (instead of a firmware application) a simple USB to serial adapter
can be used and can be connected to the UART pins of the microcontroller. Using this serial connection,
it is possible to transfer new firmware to the bootloader which will flash that firmware into the chip's
flash. The application lpc21isp (https://github.com/capiman/lpc21isp) is an application which uses this approach.

A second approach is to send firmware to the chip using the JTAG interface. In order to send JTAG signals, a 
JTAG adapter is needed. We will use the Olimex ARM-USB-OCD-H adapter. The adapter will be plugged into a PC or
Laptop using a USB cable. Using the Zadig tool (binary in the bin folder of this repository), the driver for
the two USB interfaces (0 and 1) that the Olimex ARM-USB-OCD-H provides is set to libusb. Using libusb, the
OpenOCD application is able to talk to the Olimex ARM-USB-OCD-H adapter. On the other side, OpenOCD will open
a local TCP/IP server. This server is able to understand the debugger protocol that the GNU debugger (gdb) uses.

This means that once OpenOCD is started, it should be kept running for gdb to connect to it and so that it can
constantly send JTAG commands to the LPC2138 chip.

The last step is to start gdb. In it's simplest form, gdb is used without a graphical frontend. It is a command
line tool. An important step is to transfer firmware to the LCP2138. This is accomplished by using the load
command on a .elf file. gbd will read the correct flash addresses from the .elf file and it will transfer the
firmware to openocd. OpenOCD will use JTAG to write the data to flash and then the new firmware is executed.

The running firmware can be interrupted using gdb and all information about the code, the memory and the registers
can be retrieved and diplayed on the command line using gdb commands.

# Installing a version of OpenOCD that works with the LPC2138 and the Olimex ARM-USB-OCD-H adapter

Download the oldest openocd version you can get from https://github.com/ilg-archived/openocd/releases
For me, this is the version GNU ARM Eclipse OpenOCD v0.8.0-20150119* (binary file is available in the bin folder of this repository)

Install this version to a folder called OpenOCD_080:

```
"C:\Program Files (x86)\GNU ARM Eclipse\OpenOCD_080\bin\openocd.exe" -f openocd-usb.cfg -f lpc2138.cfg
```

# Install the ARM toolchain for cross compiling ARM7TDMI code on Windows

You can download the ARM toolchain from here: https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads
(binary file is available in the bin folder of this repository)

# Starting GNU Debugger (gdb)

```
C:\Users\lapto\Downloads\arm-gnu-toolchain-14.3.rel1-mingw-w64-x86_64-arm-none-eabi\bin\arm-none-eabi-gdb.exe
target remote localhost:3333
monitor init
monitor halt
monitor reset

info all-registers

b main
continue
clear main

info break
del 3

file C:/Users/lapto/Downloads/Wbudy-main/Wbudy-main/2138/led.elf
```

This works: the load command and a .elf file works!!!
https://www.zeuthen.desy.de/dv/documentation/unixguide/infohtml/gdb/Starting.html

```
load C:/Users/lapto/Downloads/Wbudy-main/Wbudy-main/2138/led.elf
continue
```

The application is now running.

The specific sample application (led.elf) provided in this folder, is called led.elf but it actually does provide a UART interface.
Whenever you send in a string of characters into the UART using some terminal emulator (115200 baud, 8N1) then the microcontroller
will echo this text. As a terminal emulator use teraterm, hyperterm, putty or YAT.

To start debugging, interrupt the process by typing Ctrl+C (for me this sometimes immediaetly continues the app. Try several times)

list displays the source code.

To single step:

stepi or nexti (which can be abbreviated to si or ni)






next steps compile hex file with arm none eabi MiniDemo2138.hex and flash that hex file via openocd

C:\Users\lapto\Downloads\make-3.81-bin\bin\make.exe






# Install msys2 (64 bit version)

In order to compile applications on windows, you need to install make on windows.
A simple way to achieve this is to install msys2. Download and install msys2.
Msys2 is used in it's own console.

In the msys2 console type:

```
pacman -S --needed base-devel mingw-w64-i686-toolchain mingw-w64-x86_64-toolchain git subversion mercurial mingw-w64-i686-cmake mingw-w64-x86_64-cmake
```

to install all development tools.

To cross compile, configure the make file so that it uses the path to the arm-gnu-eabi toolchain.
Then type make.


# Converting .elf to .hex

```
objcopy -O ihex input.elf output.hex
```

cd C:\Users\lapto\dev\c\lpc2138\CrossFire_LPC2138\led\led ARM Flash Debug

```
"C:/Users/lapto/Downloads/arm-gnu-toolchain-14.3.rel1-mingw-w64-x86_64-arm-none-eabi/bin/arm-none-eabi-objcopy" -O ihex led.elf led.hex
```

"C:\Users\lapto\dev\c\lpc2138\CrossFire_LPC2138\led\led ARM Flash Debug\led.hex"