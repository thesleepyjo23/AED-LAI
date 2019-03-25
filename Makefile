# AED 2018-2019, sem.2
# Makefile for LabAval Problem 2
# Last edit: abl 2019.03.19
#-----------------------------------------------------------------------
#   Compiler, Compiler Flags
CC = gcc
CFLAGS = -g -Wall -ansi -pedantic

#  Sources
SOURCES = p2.c


p2: $(SOURCES)
	$(CC) $(CFLAGS) -o $@ $(SOURCES)

# tests
t:  t1 t2 t3

t1:
	./p2 m3x3.txt

t2:
	./p2 m4x4.txt

t3:
	./p2 m5x6.txt

    
# tests w/ valgrind mem check
v:  v1 v2 v3

v1:
	valgrind --leak-check=full ./p2 m3x3.txt

v2:
	valgrind --leak-check=full ./p2 m4x4.txt

v3:
	valgrind --leak-check=full ./p2 m5x6.txt

clean::
	rm -f *.o core a.out  *~
