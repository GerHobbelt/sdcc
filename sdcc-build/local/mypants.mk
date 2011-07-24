# NetBSD on sparc64
# Dual procressor
MAKEJOBFLAGS = -j 2
TARGETOS = sparc64-unknown-netbsd
HOSTOS = sparc64-unknown-netbsd

# local includes and libraries
TARGETCXXFLAGS = "-O2 -I$(HOME)/local-$(HOSTNAME)/include"
TARGETCFLAGS = "-O2 -I$(HOME)/local-$(HOSTNAME)/include"
# readline library at /usr/pkg/lib
TARGETLDFLAGS = "-L$(HOME)/local-$(HOSTNAME)/lib -L/usr/pkg/lib"
