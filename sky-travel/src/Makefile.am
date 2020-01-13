## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = sky-travel

sky_travel_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h \
	fonction.c fonction.h \
	afficheragent.c afficheragent.h \
	ajoutagent.c ajoutagent.h \
	affichervoiture.c affichervoiture.h \
	afficherevaluation.c afficherevaluation.h \
	vol.c vol.h \
	code.c code.h \
	voiture.c voiture.h \
	vols.c vols.h 

sky_travel_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)

