CC = gcc
FLAGS = -Wall -std=c99 -g -lm
SOURCE = a9p1

all: view compile execute

view: $(SOURCE).c
		cat $(SOURCE).c
		cat mystery.h
		cat Makefile

compile: $(SOURCE).c
		$(CC) $(FLAGS) $(SOURCE).c mystery.o -o $(SOURCE)

execute: $(SOURCE)
		$(SOURCE) 0.0001 100
		echo
		$(SOURCE) 0.0000001 100
		echo
		$(SOURCE) 0.0000000000001 100
		echo
		$(SOURCE) 0.0000000000001 50
		echo
		-$(SOURCE) 20
		echo
		-$(SOURCE) 20 30 40
		echo
		-$(SOURCE) -2 10
		echo
		-$(SOURCE) 0.001 -5
		echo
		-$(SOURCE) sjd -5
		echo
		-$(SOURCE) 0.001 sdsd
		echo

