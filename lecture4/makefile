#
# This is an example Makefile for a Hare and Tortoise 
# Competition project.  This
# program uses Hare, Tortoise, Road, and Competition modules.
# Typing 'make' or 'make run' will create the executable file.
#

# define some Makefile variables for the compiler and compiler flags
# to use Makefile variables later in the Makefile: $()
#
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
#
# for C++ define  CC = g++
CC = g++ -std=c++11
#CFLAGS  = -g -Wall

# typing 'make' will invoke the first target entry in the file 
# (in this case the default target entry)
# you can name this target entry anything, but "default" or "all"
# are the most commonly used names by convention
#
all: run

# To create the executable file run we need the object files
# RunCompetition.o, Competition.o, Hare.o, Tortoise.o, and Road.o:
run:  RunCompetition.o Competition.o Animal.o Hare.o Tortoise.o Duck.o Elephant.o Road.o
	$(CC) -o run RunCompetition.o Competition.o Animal.o Hare.o Tortoise.o Duck.o Elephant.o Road.o

# To create the object file RunCompetition.o, we need the source
# files RunCompetition.cpp, Competition.h 
RunCompetition.o:  RunCompetition.cpp
	$(CC) -c RunCompetition.cpp

# To create the object file Competition.o, we need the source
# files Competition.cpp and Competition.h 
#
Competition.o:  Competition.cpp
	$(CC) -c Competition.cpp

# To create the object file Hare.o, we need the source files
# Hare.cpp. By default, $(CC) -c Hare.cpp generate Hare.o
#
Hare.o:  Hare.cpp
	$(CC) -c Hare.cpp

# To create the object file Tortoise.o, we need the source files
# Tortoise.cpp. 
# By default, $(CC) -c Tortoise.cpp generates Tortoise.o
Tortoise.o:  Tortoise.cpp
	$(CC) -c Tortoise.cpp

# To create the object file Tortoise.o, we need the source files
# Tortoise.cpp. 
Duck.o:  Duck.cpp
	$(CC) -c Duck.cpp

# To create the object file Elephant.o, we need the source files
# Elephant.cpp. 
Elephant.o:  Elephant.cpp
	$(CC) -c Elephant.cpp

#
# To create the object file Animal.o, we need the source files
# Animal.cpp. 
# By default, $(CC) -c Animal.cpp generates Animal.o
Animal.o:  Animal.cpp
	$(CC) -c Animal.cpp

# To create the object file Road.o, we need the source files
# Road.cpp.
# By default, $(CC) -c Road.cpp generates Road.o
Road.o:  Road.cpp
	$(CC) -c Road.cpp

# To start over from scratch, type 'make clean'.  This
# removes the executable file, as well as old .o object
# files and *~ backup files:
#
clean: 
	$(RM) run *.o *~
