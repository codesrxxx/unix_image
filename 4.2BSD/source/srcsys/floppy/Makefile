#	Makefile	6.2	83/09/25
#
# Make a 780 rx01 floppy
# 
BOOTS=	boot
STDBOO=	defboo.cmd anyboo.cmd restar.cmd
DEFBOO=	defboo.hk defboo.hp defboo.ra defboo.up
DEVBOO=	hkmboo.cmd hksboo.cmd hpmboo.cmd hpsboo.cmd \
	ramboo.cmd rasboo.cmd upmboo.cmd upsboo.cmd
UTILS=	format copy drtest
# order is NOT random...
OBJS=	${BOOTS} ${STDBOO} ${DEFBOO} ${DEVBOO} ${UTILS}
FROMDEC=du* dm* db* s[mbr]* *boo.* vmb.exe *.hlp cs* ci*
FLOPPY=	/dev/floppy

all:	floppy

floppy:	3tracks ${OBJS}
	cp 3tracks floppy
	arff crf floppy ${OBJS}

install: floppy
	dd if=floppy of=${FLOPPY}

# build a boot floppy from a DEC console floppy
update:	${OBJS}
	-mkdir fromdec
	cd fromdec; arff xf ${FLOPPY}; rm -f ${FROMDEC} ${OBJS}; \
		flcopy -t3 -f ${FLOPPY}; rm -f floppy; arff crf ${FLOPPY} *
	rm -rf fromdec
	arff rf ${FLOPPY} ${OBJS}

clean:
	rm -f ${BOOTS} ${UTILS} floppy
	rm -rf fromdec
