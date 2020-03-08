

#
# This is an example Makefile for a countwords program.  This
# program uses both the scanner module and a counter module.
# Typing 'make' or 'make count' will create the executable file.
#
CC = gcc
CFLAGS  = -g -Wall -Wextra -std="c99"

# typing 'make' will invoke the first target entry in the file 
# (in this case the default target entry)
# you can name this target entry anything, but "default" or "all"
# are the most commonly used names by convention
#
all: Exercise4

Exercise4:  Exercise4.o PrimeFactors.o 
	$(CC) $(CFLAGS) -o Exercise4 Exercise4.o PrimeFactors.o 


Exercise4.o:  Exercise4.c 
	$(CC) $(CFLAGS) -c Exercise4.c


PrimeFactors.o:  PrimeFactors.c PrimeFactors.h 
	$(CC) $(CFLAGS) -c PrimeFactors.c


# To start over from scratch, type 'make clean'.  This
# removes the executable file, as well as old .o object
# files and *~ backup files:
#
clean: 
	$(RM) Exercise4 *.o *~
