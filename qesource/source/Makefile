#############################################################################
#
#  Makefile for qepcad system.
#
#  (c) Copyright 1994 Research Institute for Symbolic Computation  
#                     Hoon Hong
#
#  Modified by Chris Brown, 2002. NOTE: You MUST use gmake with this file!
#############################################################################


#      Adjust these during installation
#      Note: These settings are overridden by any
#      settings in a "make" that calls this recursively
# ======================================================
CCo        =  g++
FLAGSo = -O4

CCd        =  g++
FLAGSd = -g

# ============================================================
# The readline library is in different places on solaris, i.e.
# not in /usr/lib ... also, it depends on curses.
# ============================================================
ifeq (${OSTYPE},solaris)
SPECIFLAGS =	-I/opt/sfw/include
SPECLFLAGS =	-lcurses # on solaris you have to link curses to get readline!
endif

# ============================================================
#     Do not touch below unless you know what you are doing
# ============================================================

INCLUDES  =	-I${saclib}/include \
		${SPECIFLAGS} \
		-I.

EXTLIBS   =	${qe}/extensions/sfext/sfexto.a \
		${qe}/extensions/lift2D/lift2Do.a \
		${qe}/extensions/newadj/newadjo.a \
		${qe}/extensions/adj2d/adj2do.a \
		${qe}/extensions/rend/rendo.a \
		${saclib}/lib/saclibo.a \
		-lreadline \
		${SPECLFLAGS}


EXTLIBSD  =	${qe}/extensions/sfext/sfextd.a \
		${qe}/extensions/lift2D/lift2Dd.a \
		${qe}/extensions/newadj/newadjd.a \
		${qe}/extensions/adj2d/adj2dd.a \
		${qe}/extensions/rend/rendd.a \
		${saclib}/lib/saclibd.a \
		-lreadline \
		${SPECLFLAGS}

NAME      =  qepcad
LIB       =  $(NAME).a
LIBD      =  $(NAME)d.a
EXE       =  $(NAME)
EXED      =  $(NAME)d

# ============================================================
#     Files from the primary QEPCAD program
# ============================================================

OBJS_DB = \
db/AFCSBMDB.o \
db/AFPNIPDB.o \
db/AFUPGCDB.o \
db/AFUPSFNDB.o \
db/DBADD.o \
db/DBSRCH.o \
db/DBSTATWR.o \
db/FNDTSDB.o \
db/GETRPDB.o \
db/IPFACDB.o \
db/MODCRDB.o \
db/SUBSTDB.o \
db/SINGULAR.o

OBJS_IO = \
io/OW.o \
io/AFLWR.o \
io/AFPDWR.o \
io/AFUPRWR.o \
io/AFWR.o \
io/ATOMFLWR.o \
io/ATOMFRDR.o \
io/ATOMFWR.o \
io/BKSP.o \
io/CATTRNRDR.o \
io/CATTRNWR.o \
io/CELLRDR.o \
io/CELLWR.o \
io/CELLSWR.o \
io/COMMNT.o \
io/COMMNTRD.o \
io/CONWR.o \
io/CREAD.o \
io/CWRITE.o \
io/DESIREDRDR.o \
io/DESIREDWR.o \
io/DIELOC.o \
io/DISCONWR.o \
io/DNFWR.o \
io/DNFLPWR.o \
io/DNFLWR.o \
io/DSTATWR.o \
io/FGWRITE.o \
io/FILINE.o \
io/FREADR.o \
io/FWRITE.o \
io/GETWORD.o \
io/GREADR.o \
io/IPLDWR.o \
io/IPLLDWR.o \
io/IPLLDWRMOD.o \
io/IUPRWR.o \
io/LABELWR.o \
io/LGOPRDR.o \
io/LGOPWR.o \
io/PARENTWR.o \
io/PCADWR.o \
io/PCADSWR.o \
io/PIMPTBLWR.o \
io/PLABELWR.o \
io/PRODWR.o \
io/QFFLPWR.o \
io/QFFLWR.o \
io/QFFRDR.o \
io/QFFWR.o \
io/QFRDR.o \
io/QFWR.o \
io/RLOPRDR.o \
io/RLOPWR.o \
io/SAMPLEWR.o \
io/SIGNLWR.o \
io/SIGNWR.o \
io/STACKMWR.o \
io/STATWR.o \
io/TAB.o \
io/TRMODEWR.o \
io/TRUTHWR.o \
io/VLREADR.o \
io/VREADR.o \
io/VWRITE.o \
io/XREADR.o

OBJS_MAIN = \
main/BEGINQEPCAD.o \
main/ENDQEPCAD.o \
main/INITCTRL.o \
main/INITDB.o \
main/INITIO.o \
main/INITSTAT.o \
main/INITSYS.o \
main/INPUTRD.o \
main/MAIN.o \
main/PRINTBANNER.o \
main/QEPCAD.o \
main/SETUPSYS.o \
main/FAIL.o \
main/data.o \
main/QEPCADauto.o \
main/qepcadcls.o \
main/CADautoConst.o

OBJS_NORMQFF = \
normqff/EXPAFEQ.o \
normqff/EXPAFGT.o \
normqff/EXPAFGTS.o \
normqff/EXPAFLT.o \
normqff/EXPAFLTS.o \
normqff/ISATOMF.o \
normqff/NEGRLOP.o \
normqff/NORMAF.o \
normqff/NORMAFS.o \
normqff/NORMQFF.o \
normqff/PQFF.o \
normqff/RMCAFS.o \
normqff/RMCAON.o \
normqff/RMLREOP.o \
normqff/RMNOTOP.o \
normqff/RMNOTOPN.o \
normqff/TYPEAF.o \
normqff/TYPEQFF.o

OBJS_PROJ = \
proj/APPEND.o \
proj/APPENDEC.o \
proj/ECLEVEL.o \
proj/EXTRACT.o \
proj/EXTRACTS.o \
proj/GROUPSAMEPJ.o \
proj/IPDSCRPRS.o \
proj/IPDSCRQE.o \
proj/IPLFAC.o \
proj/IPRESQE.o \
proj/LCM.o \
proj/LOAR.o \
proj/LUNION.o \
proj/MPOLY.o \
proj/PROJ.o \
proj/PROJCO.o \
proj/PROJHO.o \
proj/PROJLA.o \
proj/PROJMC.o \
proj/PROJMCx.o \
proj/PROJMCmod.o \
proj/PROJMCECmod.o \
proj/PROJECT.o \
proj/PROJMCEC.o \
proj/PROPCONS.o \
proj/UDEQNCONST.o \
proj/SEPLAB.o \
proj/PROJECTauto.o

OBJS_SYSOLVE = \
sysolve/ASSUMPTIONSRATVEVAL.o \
sysolve/CHANGEASSUMPTIONSLEVEL.o \
sysolve/COEFFSYS.o \
sysolve/EVALSYS.o \
sysolve/FINDRATCOORD.o \
sysolve/IPRSOL.o \
sysolve/LBMIPL.o \
sysolve/LOSETSBF.o \
sysolve/LPSILB.o \
sysolve/PRINTCOEFFSYSTEM.o \
sysolve/SIMPLIFYSYS.o \
sysolve/SIMPLIFYSYSLIST.o \
sysolve/SYSSOLVE.o \
sysolve/SYSTOUNNORMFORMULA.o \
sysolve/VERIFYCONSTSIGN.o

OBJS_TICAD = \
ticad/ECLI.o \
ticad/ISFECLI.o \
ticad/CELLNA.o \
ticad/ACCCVBC.o \
ticad/ACCCVBCR.o \
ticad/AFCSBM.o \
ticad/AFMSBM.o \
ticad/AFUPLM.o \
ticad/AFUPMPR.o \
ticad/APEQC.o \
ticad/CELLATTR.o \
ticad/CELLCOMP.o \
ticad/CELLSQ.o \
ticad/CHCELL.o \
ticad/CHOOSE.o \
ticad/CHSCN.o \
ticad/CONSTRUCT.o \
ticad/CONVERT.o \
ticad/CSSP.o \
ticad/CVCOMP.o \
ticad/DELINPOL.o \
ticad/DELINPOLR.o \
ticad/PFPRDQ.o \
ticad/PPPRDQ.o \
ticad/IPALLPARTIALS.o \
ticad/DESCENDANT.o \
ticad/DMAFUPNR.o \
ticad/DSCOMP.o \
ticad/EC.o \
ticad/EC1.o \
ticad/ECR.o \
ticad/EVALUATE.o \
ticad/FNDTS.o \
ticad/GETRP.o \
ticad/INITPCAD.o \
ticad/IPFSBM.o \
ticad/IPLSRP.o \
ticad/ISDESIRED.o \
ticad/ISPRIMIT.o \
ticad/IXCOMP.o \
ticad/LVCOMP.o \
ticad/LPFTOLRLP.o \
ticad/LPFZCALL.o \
ticad/MAFDIF.o \
ticad/MAFHOM.o \
ticad/MAFINV.o \
ticad/MAFPROD.o \
ticad/MAFUPDIF.o \
ticad/MAFUPEPROD.o \
ticad/MAFUPGCD.o \
ticad/MAFUPMON.o \
ticad/MAFUPNR.o \
ticad/MCELL.o \
ticad/MKMUL.o \
ticad/MODCR.o \
ticad/MUPNR.o \
ticad/NORMAL.o \
ticad/NZFOPQ.o \
ticad/NZFOPQR.o \
ticad/PFCOICQ.o \
ticad/PLPOS.o \
ticad/PROPAGATE.o \
ticad/QFFTEV.o \
ticad/RCFAFC.o \
ticad/SETTRUTHVALUE.o \
ticad/SIGNB.o \
ticad/SIGNL.o \
ticad/SIGNP.o \
ticad/SIGNP1.o \
ticad/SIGNPR.o \
ticad/SIMPLEQE.o \
ticad/SPFRPSFT.o \
ticad/SSCOMP.o \
ticad/STACKMULT.o \
ticad/SUBST.o \
ticad/SUBSTR.o \
ticad/TCHILD.o \
ticad/TICAD.o \
ticad/TICADauto.o

OBJS_USERINT = \
userint/CELLFIDX.o \
userint/ESPIWR.o \
userint/ESPORD.o \
userint/GETCID.o \
userint/GFPCSTAT.o \
userint/HELPFRD.o \
userint/HELPWR.o \
userint/INTERACT.o \
userint/PRAFUPBRI.o \
userint/PRAPPROX.o \
userint/PRCCS.o \
userint/PRCCSF.o \
userint/PRDC.o \
userint/PRDCC.o \
userint/PRDCS.o \
userint/PRDDESIRED.o \
userint/PRDESIRED.o \
userint/PRDF.o \
userint/PRDFPCSTAT.o \
userint/PRDIP.o \
userint/PRDLFI.o \
userint/PRDLPI.o \
userint/PRDLV.o \
userint/PRDNQFF.o \
userint/PRDPC.o \
userint/PRDPCS.o \
userint/PRDPF.o \
userint/PRDPJ.o \
userint/PRDQ.o \
userint/PRDQFF.o \
userint/PRDSEARCH.o \
userint/PRDSET.o \
userint/PRDSTACK.o \
userint/PRDTRACEA.o \
userint/PRDTRACED.o \
userint/PRDVL.o \
userint/PREQNCONST.o \
userint/PRFINISH.o \
userint/PRGO.o \
userint/PRHELP.o \
userint/PRIPFZT.o \
userint/PRIGS.o \
userint/PRLDB.o \
userint/PRMCC.o \
userint/PROMPT.o \
userint/PRPROJOP.o \
userint/PRQUIT.o \
userint/PRRMPF.o \
userint/PRRMPJ.o \
userint/PRRSP.o \
userint/PRSEARCH.o \
userint/PRSIMPLIFIER.o \
userint/PRSTEP.o \
userint/PRTCN.o \
userint/PRTRACEA.o \
userint/PRTRACED.o \
userint/PRUDB.o \
userint/PRUSEDESIRED.o \
userint/PRWHATIS.o \
userint/RMMPF.o \
userint/RMMPJ.o \
userint/PRCHPIVOT.o \
userint/PRDEQNCONST.o \
userint/PREQNCONSTL.o \
userint/PRPROPEC.o \
userint/PRRESALG.o \
userint/USERINT.o

OBJS_UTIL = \
util/CELLDEG.o \
util/CELLDIM.o \
util/MATCHWORD.o \
util/MBPROD.o \
util/MMFLR.o \
util/PLDEG.o \
util/PSIMREP.o \
util/RMCONS.o \
util/RNFAF.o \
util/SVPOWR.o \
util/SVPROD.o \
util/VALIDLBL.o

#  To replace saclib routines. 
OBJS_SACLIB = \
saclib/GCSI.o \
saclib/gcword.o \
saclib/IPFZT.o \
saclib/IPFZT1.o \
saclib/IPPSCT.o \
saclib/IPRNEVAL.o \
saclib/RVSPTSVSP.o \
saclib/SOSRSUBS.o \
saclib/SOSRSUPS.o \
saclib/SUBSET.o

# ============================================================
#     Dependecies
# ============================================================

DEPENDENCIESo =    $(LIB)( \
$(OBJS_DB) \
$(OBJS_IO) \
$(OBJS_MAIN) \
$(OBJS_NORMQFF) \
$(OBJS_PROJ) \
$(OBJS_SYSOLVE) \
$(OBJS_TICAD) \
$(OBJS_TUNE) \
$(OBJS_USERINT) \
$(OBJS_UTIL) \
$(OBJS_SACLIB) \
)

DEPENDENCIESd =    $(LIBD)( \
$(OBJS_DB) \
$(OBJS_IO) \
$(OBJS_MAIN) \
$(OBJS_NORMQFF) \
$(OBJS_PROJ) \
$(OBJS_SYSOLVE) \
$(OBJS_TICAD) \
$(OBJS_TUNE) \
$(OBJS_USERINT) \
$(OBJS_UTIL) \
$(OBJS_SACLIB) \
)

# ============================================================
#     Make rules
# ============================================================
opt:		override CFLAGS = $(FLAGSo)
opt:		override CC = $(CCo)
opt:		$(DEPENDENCIESo)
		ranlib $(LIB)
		@echo Linking the optimized program......
		$(CCo) $(FLAGSo) $(INCLUDES) saclib/GCSI.c \
			$(LIB) $(EXTLIBS) $(LIB) $(EXTLIBS) -o $(EXE)


deb:		override CFLAGS = $(FLAGSd)
deb:		override CC = $(CCd)
deb:		$(DEPENDENCIESd)
		ranlib $(LIBD)
		@echo Linking the debugged program......
		$(CCd) $(FLAGSd) $(INCLUDES) saclib/GCSI.c \
			 $(LIBD) $(EXTLIBSD) $(LIBD)  $(EXTLIBSD) -o $(EXED) #\
			#/home/wcbrown/Downloads/duma_2_4_27/libduma.a -lpthread

.c.o:	
		$(CC) $(INCLUDES) $(CFLAGS) -o $@ -c $<
