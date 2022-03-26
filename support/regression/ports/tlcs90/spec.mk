# Regression test specification for the tlcs90 target running with uCsim

# simulation timeout in seconds
SIM_TIMEOUT = 40

# path to uCsim
ifdef SDCC_BIN_PATH
  UCTLCS90C = $(SDCC_BIN_PATH)/ucsim_tlcs$(EXEEXT)

  AS_TLCS90C = $(SDCC_BIN_PATH)/sdastlcs90$(EXEEXT)
else
  ifdef UCSIM_DIR
    UCTLCS90A = $(UCSIM_DIR)/tlcs.src/ucsim_tlcs$(EXEEXT)
  else
    UCTLCS90A = $(top_builddir)/sim/ucsim/tlcs.src/ucsim_tlcs$(EXEEXT)
    UCTLCS90B = $(top_builddir)/bin/ucsim_tlcs$(EXEEXT)
  endif

  EMU = $(WINE) $(shell if [ -f $(UCTLCS90A) ]; then echo $(UCTLCS90A); else echo $(UCTLCS90B); fi)

  AS = $(WINE) $(top_builddir)/bin/sdastlcs90$(EXEEXT)

ifndef CROSSCOMPILING
  SDCCFLAGS += --nostdinc -I$(top_srcdir)
  LINKFLAGS += --nostdlib -L$(top_builddir)/device/lib/build/tlcs90
endif
endif

ifdef CROSSCOMPILING
  SDCCFLAGS += -I$(top_srcdir)
endif

SDCCFLAGS += --debug -mtlcs90 --less-pedantic --out-fmt-ihx
LINKFLAGS += tlcs90.lib

OBJEXT = .rel
BINEXT = .ihx

# otherwise `make` deletes testfwk.rel and `make -j` will fail
.PRECIOUS: $(PORT_CASES_DIR)/%$(OBJEXT)

# Required extras
EXTRAS = $(PORT_CASES_DIR)/testfwk$(OBJEXT) $(PORT_CASES_DIR)/support$(OBJEXT)
include $(srcdir)/fwk/lib/spec.mk

# Rule to link into .ihx
%$(BINEXT): %$(OBJEXT) $(EXTRAS) $(FWKLIB) $(PORT_CASES_DIR)/fwk.lib
	$(SDCC) $(SDCCFLAGS) $(LINKFLAGS) $(EXTRAS) $(PORT_CASES_DIR)/fwk.lib $< -o $@

%$(OBJEXT): %.asm
	$(AS) -plosgff $<

%$(OBJEXT): %.c
	$(SDCC) $(SDCCFLAGS) -c $< -o $@

$(PORT_CASES_DIR)/%$(OBJEXT): $(PORTS_DIR)/$(PORT)/%.c
	$(SDCC) $(SDCCFLAGS) -c $< -o $@

$(PORT_CASES_DIR)/%$(OBJEXT): $(srcdir)/fwk/lib/%.c
	$(SDCC) $(SDCCFLAGS) -c $< -o $@

$(PORT_CASES_DIR)/fwk.lib: $(srcdir)/fwk/lib/fwk.lib
	cat < $(srcdir)/fwk/lib/fwk.lib > $@

_clean:
