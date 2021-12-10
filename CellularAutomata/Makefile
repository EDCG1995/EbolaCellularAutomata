# Makefile for the cellular automata project

main: main.c world.c world.o neighbourhood.c neighbourhood.o  header.h
	gcc main.c neighbourhood.o world.o header.h -lpthread -o main

world.o: world.c
	gcc -c world.c

neighbourhood.o: neighbourhood.c
	gcc -c neighbourhood.c


