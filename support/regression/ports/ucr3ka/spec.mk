# Regression test specification for the z80 target running with uCsim

# simulation timeout in seconds
SIM_TIMEOUT = 40

EMU_PORT_FLAG=-tr3ka

# path to uCsim
ifdef SDCC_BIN_PATH
  UCZ80C = $(SDCC_BIN_PATH)/ucsim_rxk$(EXEEXT)

  AS_Z80C = $(SDCC_BIN_PATH)/sdasrab$(EXEEXT)
else
  ifdef UCSIM_DIR
    SZ80A = $(UCSIM_DIR)/rxk.src/ucsim_rxk$(EXEEXT)
  else
    SZ80A = $(top_builddir)/sim/ucsim/rxk.src/ucsim_rxk$(EXEEXT)
    SZ80B = $(top_builddir)/bin/ucsim_rxk$(EXEEXT)
  endif

  EMU = $(WINE) $(shell if [ -f $(SZ80A) ]; then echo $(SZ80A); else echo $(SZ80B); fi)

  AS = $(WINE) $(top_builddir)/bin/sdasrab$(EXEEXT)

ifndef CROSSCOMPILING
  SDCCFLAGS += --nostdinc -I$(top_srcdir)
  LINKFLAGS += --nostdlib -L$(top_builddir)/device/lib/build/r3ka
endif
endif

ifdef CROSSCOMPILING
  SDCCFLAGS += -I$(top_srcdir)
endif

SDCCFLAGS += -mr3ka --less-pedantic
LINKFLAGS += r3ka.lib

OBJEXT = .rel
BINEXT = .ihx

# otherwise `make` deletes testfwk.rel and `make -j` will fail
.PRECIOUS: $(PORT_CASES_DIR)/%$(OBJEXT)

# Required extras
EXTRAS = $(PORT_CASES_DIR)/testfwk$(OBJEXT) $(PORT_CASES_DIR)/support$(OBJEXT)
include $(srcdir)/fwk/lib/spec.mk

# Rule to link into .ihx
%.ihx: %$(OBJEXT) $(EXTRAS) $(FWKLIB) $(PORT_CASES_DIR)/fwk.lib
	$(SDCC) $(SDCCFLAGS) $(LINKFLAGS) $(EXTRAS) $(PORT_CASES_DIR)/fwk.lib $< -o $@

$(PORT_CASES_DIR)/%$(OBJEXT): $(PORTS_DIR)/$(PORT)/%.asm
	@# TODO: sdas should place it\'s output in the current dir
	cp $< $(PORT_CASES_DIR)
	$(AS) -plosgff $(PORT_CASES_DIR)/$(notdir $<)
	rm $(PORT_CASES_DIR)/$(notdir $<)

%$(OBJEXT): %.c
	$(SDCC) $(SDCCFLAGS) -c $< -o $@

$(PORT_CASES_DIR)/%$(OBJEXT): $(PORTS_DIR)/$(PORT)/%.c
	$(SDCC) $(SDCCFLAGS) -c $< -o $@

$(PORT_CASES_DIR)/%$(OBJEXT): $(srcdir)/fwk/lib/%.c
	$(SDCC) $(SDCCFLAGS) -c $< -o $@

$(PORT_CASES_DIR)/fwk.lib: $(srcdir)/fwk/lib/fwk.lib
	cat < $(srcdir)/fwk/lib/fwk.lib > $@


#	echo Running $(CASES_DIR)/timeout $(SIM_TIMEOUT) $(EMU) $(EMU_PORT_FLAG) $< < $(PORTS_DIR)/$(PORT)/uCsim.cmd

_clean:
