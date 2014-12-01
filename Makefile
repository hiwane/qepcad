
.PHONY: qepcad saclib

all: saclib qepcad

saclib: saclib/lib/objd saclib/lib/objo
	(cd saclib && \
	 export saclib=`pwd` && \
	 bin/sconf && \
	 bin/mkproto && \
	 bin/mkmake && \
	 bin/mklib all)

qepcad:
	(cd qesource && saclib=`pwd`/../saclib qe=`pwd` make)
	@if [ -f "/bin/csh" ]; then \
		(cd qesource && saclib=`pwd`/../saclib qe=`pwd` ${MAKE}) \
	else \
		(cd qesource && saclib=`pwd`/../saclib qe=`pwd` ${MAKE} SHELL=/bin/sh) \
	fi

saclib/lib/objd:
	mkdir -p saclib/lib/objd

saclib/lib/objo:
	mkdir -p saclib/lib/objo


