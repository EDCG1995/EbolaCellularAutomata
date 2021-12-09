# Makefile for the cellular automata project

main: main.c world.c world.o neighbourhood.c neighbourhood.o dataoutput.c dataoutput.o header.h
	gcc main.c neighbourhood.o dataoutput.o world.o header.h -lpthread -o main

dataoutput.o: dataoutput.c
	gcc -c dataoutput.c

world.o: world.c
	gcc -c world.c

neighbourhood.o: neighbourhood.c
	gcc -c neighbourhood.c


