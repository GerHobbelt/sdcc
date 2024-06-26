# uCsim

## Micro-controller simulator

### What is uCsim?

uCsim is a micro-controller simulator. It is extensible to support
different micro-controller families. Currently it supports Intel MCS51
family, 8080, 8085, XA, Z80, Rabbit, SM83, TLCS90, ST7, STM8, PDK,
MC6800, MC6809, M68HC08, M68HC11, M68HC12, MOS6502, PicoBlaze, F8,
p1516/p2223 and some AVR processors.


### How to get uCsim?

uCsim is distributed in source code under GPL. It can be downloaded
from its home site:

[](http://mazsola.iit.uni-miskolc.hu/~drdani/embedded/ucsim/)

uCsim is included in sdcc, free C compiler of Sandeep Dutta. It is a
complete development package with debugger (see below). It can be
downloaded from its home site (or from its mirrors):

[](http://sdcc.sourceforge.net/)


### Mailing list

There is no mailing list which is specifically opened for
uCsim. Announcements are sent to sdcc's mailing list. See sdcc's main
page at above URL for subscribing information and the archive. Ideas,
bug reports or fixes should be sent to sdcc's list too.


### Features of uCsim

Features of uCsim are similar to features of other simulators. It
simulates instructions of the program code and all parts of the
microcontroller including timer/counters, uart, etc. Peripherals are
simulated as accurate as possible. Time resolution is machine cycle
based which means that 1 machine cycle is the smallest time quantity
which is handled by the simulator.

uCsim has some features which may not available in other
simulators. They include:

- No GUI. It is not the simulator's job to do graphical representation
  of the CPU. It should be done by external programs. uCsim tries to
  help GUI and other external tool writers.

- More than one command console. It is possible to use as many command
  interpreters as many needed. uCsim accepts commands from command
  consoles simultaneously. It makes possible to give commands to the
  simulator during execution of the simulated program.

- Simulating UART of the controller makes it possible to connect two
  instances of the simulator together via simulated serial lines. It
  is also possible to connect simulated UART to serial port of the
  host machine.

- Profiling support. uCsim provides "virtual timers" to measure
  execution time of any part of the code. It also makes statistic
  about ratio of main program and interrupt services.

- Event breakpoints. Simulator can stop the execution when read or
  write event occurs at any location of any kind of memory.


### External tools

uCsim is not well supported (yet) by external tools. But some exist
already.

** SerialView **

    It is written by Timothy Hurman <ee62th@ee.surrey.ac.uk> and it is
    now included in the uCsim package. It is simple "terminal
    emulator" which can be used to provide input for the simulated
    UART as well as present the output of the UART.

** sdcdb **

    Debugger of the free C compiler, called sdcc written by Sandeep
    Dutta <sandeep.dutta@usa.net>. It is a usual debugger with command
    line interface which uses uCsim in background to run the
    code. "Standard" interface of the sdcdb makes it possible to use
    any debugger GUI such as ddd to make it comfortable.


### Contributors and maintainers

Gunnar Holm <gunnarh@foa.nft.no>
Sandeep Dutta <dutta@comm.mot.com>
Salvador Eduardo Tropea <salvador@inti.gov.ar>
Josef Wolf <jw@raven.inka.de>
Stephane MEYER <smeyer@cea.fr>
Larry Doolittle <LRDoolittle@lbl.gov>
Timothy Hurman <ee62th@ee.surrey.ac.uk>
Karl-Max Wagner <karlmax@oberland.net>
Edmar Wienskoski Jr <edmar-w-jr@technologist.com>
Alexandre Frey <Alexandre.Frey@trusted-logic.fr>
Kaido Karner <kaido@tradenet.ee>
Karl Bongers <karl@turbobit.com>
Alexis Pavlov <alexis.pavlov@certess.com>
Davide Zanni <davide.zanni@libero.it>
Anton Persson <anton@omicron.se>
Nicolas Lesser <>
Mike Jagdis <>
Jiri Simek <>
Zbynek Krivka <krivka@fit.vutbr.cz>
Vaclav Peroutka <vaclavpe@users.sourceforge.net>
Valentin Dudouyt <valentin.dudouyt@gmail.com>
Erik Petrich <epetrich@users.sourceforge.net>
Leland Morrison <>
Johan Knol <johan.knol@iduna.nl>

Maintainer of serialview: Timothy Hurman <ee62th@ee.surrey.ac.uk>
Maintainer of other parts: Daniel Drotos <drdani@mazsola.iit.uni-miskolc.hu>
