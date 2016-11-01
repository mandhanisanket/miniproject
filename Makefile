all: project
project: conversion.o fraction.o integer.o main.o matrix.o trigo.o
	cc conversion.o fraction.o integer.o main.o matrix.o trigo.o -o project -lm
conversion.o: conversion.c conversion.h
	cc -c conversion.c -lm
fraction.o: fraction.c fraction.h
	cc -c fraction.c -lm
integer.o: integer.c integer.h
	cc -c integer.c -lm
main.o: main.c main.h
	cc -c main.c -lm
matrix.o: matrix.c matrix.h
	cc -c matrix.c -lm
trigo.o: trigo.c trigo.h
	cc -c trigo.c -lm
clean:
	rm *.o
