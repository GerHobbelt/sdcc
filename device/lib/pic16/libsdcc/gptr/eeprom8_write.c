/*-------------------------------------------------------------------------
   eeprom_write8.c - write one byte to EEPROM and wait for completion

   Copyright (C) 1999, Sandeep Dutta . sandeep.dutta@usa.net
   Adopted for pic16 port by Vangelis Rokas, 2004 <vrokas AT otenet.gr>

   This library is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by the
   Free Software Foundation; either version 2, or (at your option) any
   later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License 
   along with this library; see the file COPYING. If not, write to the
   Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston,
   MA 02110-1301, USA.

   As a special exception, if you link this library with other files,
   some of which are compiled with SDCC, to produce an executable,
   this library does not by itself cause the resulting executable to
   be covered by the GNU General Public License. This exception does
   not however invalidate any other reasons why the executable file
   might be covered by the GNU General Public License.
-------------------------------------------------------------------------*/

extern char EEADR;
extern char EECON1;
extern char EECON2;

void __eeprom8_write(void) __naked
{
  __asm
    movlw       0x55
    movwf       _EECON2, 0
    movlw       0xAA
    movwf       _EECON2, 0
    bsf         _EECON1, 1, 0   ; WR

    wait_till_done:
    btfsc       _EECON1, 1, 0   ; WR still set?
    bra         wait_till_done

    incf        _EEADR, 1, 0    ; address next byte
  __endasm;
}
