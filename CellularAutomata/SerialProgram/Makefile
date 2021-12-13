# Makefile for the cellular automata project

main: main.c world.c world.o neighbourhood.c neighbourhood.o infectionRate.c infectionRate.o header.h
	gcc main.c neighbourhood.o world.o infectionRate.o header.h -lpthread -o main

infectionRate.o: infectionRate.c
	gcc -c infectionRate.c

world.o: world.c
	gcc -c world.c

neighbourhood.o: neighbourhood.c
	gcc -c neighbourhood.c



