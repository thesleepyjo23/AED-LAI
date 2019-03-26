# AED 2018-2019, sem.2
# Makefile for LabAval Problem 3
# Last edit: abl 2019.03.15
#-----------------------------------------------------------------------
#   Compiler, Compiler Flags
CC = gcc
CFLAGS = -g -Wall -ansi -pedantic

#   Sources
SOURCES = LinkedList.c listest.c p3.c

#   Objects  ('Make' automatically compiles .c to .o)
OBJECTS = LinkedList.o p3.o
OBJECTS_33 = LinkedList.o p33.o

p3: $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS)

#   must create p33.c
p33: $(OBJECTS_33)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS_33)

LinkedList.o: LinkedList.h defs.h LinkedList.c

listest: LinkedList.o listest.c
	gcc -o $@ listest.c LinkedList.o

gv:     genVals.c
	gcc -o $@ genVals.c

# tests
t:  t1 t2 t3

t1:
	./p3 i10.txt

# text files with random ints, vmax-vcnt.txt
t2:
	./p3 i20-100.txt

t3:
	./p3 i300-10000.txt

clean::
	rm -f *.o core a.out p3 listest gv *~
