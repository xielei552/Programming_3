CC = gcc
FLAGS = -Wall -std=c99 -g 
SOURCE = a11p2

all: view compile execute

view: $(SOURCE).c
		cat $(SOURCE).c
		cat caculator.h
		cat caculator.c
		cat Makefile

compile: $(SOURCE).c
		$(CC) $(FLAGS) $(SOURCE).c caculator.c -o $(SOURCE)

execute: $(SOURCE)
		$(SOURCE) 1/2 + 3/4
		echo
		$(SOURCE) 2/3 x -153/7
		echo
		$(SOURCE) 99/100 '*' 22
		echo
		$(SOURCE) 3/1 \* 4/7
		echo
		-$(SOURCE) 1 / 2 + 3 / 4
		echo
		-$(SOURCE) 2/3x153/7
		echo
		-$(SOURCE) 2/3/4 - 5
		echo
		-$(SOURCE) 1/0 + 3/5
		echo
		-$(SOURCE) 1/5 / 6/-7
		echo


