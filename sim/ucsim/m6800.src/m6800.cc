/*
 * Simulator of microcontrollers (m6800.cc)
 *
 * Copyright (C) 2020,20 Drotos Daniel, Talker Bt.
 * 
 * To contact author send email to drdani@mazsola.iit.uni-miskolc.hu
 *
 */

/* This file is part of microcontroller simulator: ucsim.

UCSIM is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

UCSIM is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with UCSIM; see the file COPYING.  If not, write to the Free
Software Foundation, 59 Temple Place - Suite 330, Boston, MA
02111-1307, USA. */
/*@1@*/

#include <stdlib.h>
#include <ctype.h>

#include "globals.h"
#include "utils.h"

#include "dregcl.h"

#include "glob.h"

#include "m6800cl.h"


cl_m6800::cl_m6800(class cl_sim *asim):
  cl_uc(asim)
{
}

int
cl_m6800::init(void)
{
  cl_uc::init();
  fill_def_wrappers(itab);
  
  xtal= 1000000;
    
#define RCV(R) reg_cell_var(&c ## R , &r ## R , "" #R "" , "CPU register " #R "")
  RCV(A);
  RCV(B);
  RCV(CC);
  RCV(IX);
  RCV(SP);
#undef RCV
    
  class cl_memory_operator *op= new cl_cc_operator(&cCC);
  cCC.append_operator(op);

  return 0;
}

const char *
cl_m6800::id_string(void)
{
  return "M6800";
}

void
cl_m6800::reset(void)
{
  cl_uc::reset();

  CC= 0xc0;
  PC= rom->read(0xfffe)*256 + rom->read(0xffff);
  tick(6);
}
  
void
cl_m6800::set_PC(t_addr addr)
{
  PC= addr;
}

void
cl_m6800::mk_hw_elements(void)
{
  class cl_hw *h;
  
  cl_uc::mk_hw_elements();

  add_hw(h= new cl_dreg(this, 0, "dreg"));
  h->init();
}

void
cl_m6800::make_cpu_hw(void)
{
}

void
cl_m6800::make_memories(void)
{
  class cl_address_space *as;
  class cl_address_decoder *ad;
  class cl_memory_chip *chip;
  
  rom= as= new cl_address_space("rom", 0, 0x10000, 8);
  as->init();
  address_spaces->add(as);

  chip= new cl_chip8("rom_chip", 0x10000, 8);
  chip->init();
  memchips->add(chip);
  ad= new cl_address_decoder(as= rom,
			     chip, 0, 0xffff, 0);
  ad->init();
  as->decoders->add(ad);
  ad->activate(0);
}

struct dis_entry *
cl_m6800::dis_tbl(void)
{
  return(disass_m6800);
}

char *
cl_m6800::disass(t_addr addr)
{
  chars work= chars(), temp= chars();
  const char *b;
  t_mem code= rom->get(addr);
  struct dis_entry *dt= dis_tbl();//, *dis_e;
  int i;
  bool first;
  
  if (!dt)
    return NULL;

  i= 0;
  while (((code & dt[i].mask) != dt[i].code) &&
	 dt[i].mnemonic)
    i++;
  //dis_e= &dt[i];
  if (dt[i].mnemonic == NULL)
    return strdup("-- UNKNOWN/INVALID");
  b= dt[i].mnemonic;

  first= true;
  work= "";
  for (i=0; b[i]; i++)
    {
      if ((b[i] == ' ') && first)
	{
	  first= false;
	  while (work.len() < 6) work.append(' ');
	}
      if (b[i] == '%')
	{
	  i++;
	  switch (b[i])
	    {
	    }
	}
      else
	work+= b[i];
    }

  return(strdup(work.c_str()));
}

void
cl_m6800::print_regs(class cl_console_base *con)
{
  con->dd_color("answer");
  con->dd_printf("A= 0x%02x %3d %+4d %c  ", A, A, (i8_t)A, isprint(A)?A:'.');
  con->dd_printf("B= 0x%02x %3d %+4d %c  ", B, B, (i8_t)B, isprint(B)?B:'.');
  con->dd_printf("\n");
  con->dd_printf("CC= "); con->print_bin(CC, 8); con->dd_printf("\n");
  con->dd_printf("      HINZVC\n");

  con->dd_printf("IX= ");
  rom->dump(0, IX, IX+7, 8, con);
  con->dd_color("answer");
  
  con->dd_printf("SP= ");
  rom->dump(0, SP, SP+7, 8, con);
  con->dd_color("answer");
  
  print_disass(PC, con);
}

int
cl_m6800::exec_inst(void)
{
  t_mem code;
  int res= resGO;

  if ((res= exec_inst_tab(itab)) != resNOT_DONE)
    return res;

  instPC= PC;
  if (fetch(&code))
    return(resBREAKPOINT);
  tick(1);
  res= inst_unknown(code);
  return(res);
}

class cl_cell8 &
cl_m6800::idx(void)
{
  t_addr a= fetch();
  a+= rX;
  class cl_cell8 *c= (class cl_cell8 *)rom->get_cell(a);
  tick(3);
  return *c;
}

class cl_cell8 &
cl_m6800::ext(void)
{
  t_addr a;
  u8_t h, l;
  h= fetch();
  l= fetch();
  a= h*256 + l;
  class cl_cell8 *c= (class cl_cell8 *)rom->get_cell(a);
  tick(2);
  return *c;
}

class cl_cell8 &
cl_m6800::dir(void)
{
  t_addr a= fetch();
  class cl_cell8 *c= (class cl_cell8 *)rom->get_cell(a);
  return *c;
}

/* End of m6800.src/m6800.cc */