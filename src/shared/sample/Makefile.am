INCLUDES = $(SRDGAME_INCLUDES) -I$(srcdir) -I$(srcdir)/../util -I$(srcdir)/../thread -I$(srcdir)/../../login -I$(srcdir)/../../sample -I$(srcdir)/../packet -I$(srcdir)/../database -I$(srcdir)/../log -I$(srcdir)/../config -I$(srcdir)/../game

noinst_LIBRARIES = libsample.a

libsample_a_SOURCES = ro_defs.h\
					  strlib.h \
					  strlib.cpp \
					  rouser.h \
					  rosql.h \
					  rosql.cpp \
					  rojob.h \
					  rojob.cpp \
					  roconf.h \
					  roconf.cpp \
					  romap.h \
					  romap.cpp \
					  grfio.h \
					  grfio.cpp \
					  itemdefs.h \
					  roitemdb.h \
					  roitemdb.cpp \
					  itemhelper.h \
					  rocharinfo.h \
					  romobinfo.h \
					  ronpcinfo.h

#libsample_a_LIBADD = ldatabase
#libsample_a_LDFLAGS = -L$(srcdir)/../shared/database
