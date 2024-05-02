> Please see `doc/README.txt` for up-to-date, complete info.

# SDCC - free open source, retargettable, optimizing ISO C compiler

Welcome to SDCC, free open source, retargettable, optimizing ISO C
compiler suite that targets a growing list of processors including the
Intel MCS-51 based microprocessors (8031, 8032, 8051, 8052, etc.), Maxim
(formerly Dallas) DS80C390 variants, Freescale (formerly Motorola) HC08
based (hc08, s08), Zilog Z80 based MCUs (Z80, Z80N, Z180, SM83 (e.g. Game Boy),
Rabbit 2000, Rabbit 2000A/3000, Rabbit 3000A, TLCS-90, R800),
STMicroelectronics STM8, Padauk PDK14 and PDK15 and MOS 6502.
Work is in progress on supporting the Padauk PDK13 target.
There are unmaintained Microchip PIC16 and PIC18 targets.
It can be retargeted for other microprocessors.

See `share/sdcc/doc/INSTALL.txt` for the installation instructions for
the binary kits.

See the `share/sdcc/doc` directory for more documentation.

See http://sdcc.sourceforge.net/ for the latest information on sdcc.


## Licenses

SDCC compiler suite is a collection of several components derived from
different sources with different FOSS licenses. See the `sdccman.pdf`
document, chapter "SDCC Suite Licenses" for details.

The code or object files generated by SDCC suite are not licensed, so
they can be used in FLOSS or proprietary (closed source) applications.

The great majority of sdcc run-time libraries are licensed under the
GPLv2+LE which allows linking of sdcc run time libraries with
proprietary (closed source) applications.

Exception are pic device libraries and header files which are derived
from Microchip header (`.inc`) and linker script (`.lkr`) files. Microchip
requires that "The header files should state that they are only to be
used with authentic Microchip devices" which makes them incompatible
with the GPL. Pic device libraries and header files are located at
`non-free/lib` and `non-free/include` directories respectively. Sdcc should
be run with the `--use-non-free` command line option in order to include
the potentially non-free header files and libraries.

However: Many think that the Microchip requirement is not legally enforceable,
arguing that the header files only contain noncopyrightable facts.

See:

- http://www.gnu.org/copyleft/gpl.html

- http://sourceforge.net/apps/trac/sdcc/wiki/SDCC%20Library%20Licenses


