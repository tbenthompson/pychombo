# -*- Mode: Makefile -*- 

# This is clearly overkill for compiling one file into a dynamic library
# but I just kept it in something like the form I had it for compiling
# the AdvectDiffuse example
# the location of the Chombo "lib" directory
CHOMBO_HOME = /home/tbent/packages/Chombo-3.1/lib
CHOMBO_SOURCE = $(CHOMBO_HOME)/src
CT=2d.Linux.64.g++.gfortran.DEBUG

CC=g++
STARTCFLAGS=-g -pedantic -Wall -ggdb  -Wno-long-long -Wno-sign-compare -Wno-deprecated -Wno-invalid-offsetof -Wno-variadic-macros -m64 -Wno-unused-but-set-variable
MORECFLAGS=-fPIC 
CFLAGS= $(STARTCFLAGS) $(MORECFLAGS)
INCLUDE_FOLDERS=-I$(CHOMBO_HOME)/include -I/usr/include/openmpi -I./srcAdvectDiffuse -I/usr/include/python2.7
LDFLAGS=-shared  $(STARTCFLAGS) -L$(CHOMBO_HOME) -lamrelliptic$(CT) -lamrtimedependent$(CT) -lamrtools$(CT) -lboxtools$(CT) -lbasetools$(CT)  -L/usr/lib/x86_64-linux-gnu -lhdf5 -lz -lgfortran -lm -lboost_python -lboost_system -lboost_date_time
SOURCES=src/chomboWrapper.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=libpychombo.so

# all: Fortran $(SOURCES) $(EXECUTABLE)
all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDE_FOLDERS) -c $< -o $@

clean:
	rm $(OBJECTS) $(EXECUTABLE)
