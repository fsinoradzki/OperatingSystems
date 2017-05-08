# Makefile



# Source files

SOURCES = driver.cpp UI.cpp directory.cpp file.cpp diskprocess.cpp



# Objects that result from compilation

OBJECTS = diskprocess.o UI.o directory.o file.o



# Include files

DEFS = diskprocess.h UI.h directory.h file.h



# Flags

CPPFLAGS = -g



# Libraries

LIBFLAGS = -lm



CISC3595_team5_atos-fs: $(SOURCES) $(DEFS)
	g++ $(CPPFLAGS) $(SOURCES) -o CISC3595_team5_atos-fs $(LIBFLAGS)
