# Makefile for the cellular automata project

main: main.c world.c world.o neighbourhood.c neighbourhood.o header.h
	gcc main.c world.o header.h -o main -lpthread

world.o: world.c
	gcc -c world.c

neighbourhood.o: neighbourhood.c
	gcc -c neighbourhood.c
