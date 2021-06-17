#
# This is an example Makefile for Person and Doctor project.
# program uses Person and Doctor modules.
# Typing 'make' or 'make run' will create the executable file.
#

# define some Makefile variables for the compiler and compiler flags
# to use Makefile variables later in the Makefile: $()
#
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
#
# for C++ define  CC = g++
CC = g++
#CFLAGS  = -g -Wall
#CFLAGS = -std=c++11 #c++11 for constructor delegation feature

# typing 'make' will invoke the first target entry in the file 
# (in this case the default target entry)
# you can name this target entry anything, but "default" or "all"
# are the most commonly used names by convention
#
all: person_doc

# To create the executable file run we need the object files
# RunCompetition.o, Competition.o, Hare.o, Tortoise.o, and Road.o:
person_doc: PersonTest.o Person.o Doctor.o 
	$(CC) -std=c++11 -o person_doc PersonTest.o Person.o Doctor.o

# To create the object file TestPerson.o, we need the source
# files TestPerson.cpp
TestPerson.o:  PersonTest.cpp
	$(CC) -c -std=c++11 PersonTest.cpp

# To create the object file Person.o, we need the source
# files Person.cpp and Person.hpp
#
Person.o:  Person.cpp
	$(CC) -c -std=c++11 Person.cpp

# To create the object file Doctor.o, we need the source files
# Doctor.cpp. By default, $(CC) -c Doctor.cpp generate Doctor.o
#
Doctor.o:  Doctor.cpp
	$(CC) -c -std=c++11 Doctor.cpp

# To start over from scratch, type 'make clean'.  This
# removes the executable file, as well as old .o object
# files and *~ backup files:
#
clean: 
	$(RM) run *.o *~
