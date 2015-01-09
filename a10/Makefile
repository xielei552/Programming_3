CC = gcc
FLAGS = -Wall -std=c99 -g 
SOURCE = a10p3

all: view compile execute

view: $(SOURCE).c
		cat $(SOURCE).c
		cat Makefile

compile: $(SOURCE).c
		$(CC) $(FLAGS) $(SOURCE).c -o $(SOURCE)

execute: $(SOURCE)
		cat a10p3-test1
		$(SOURCE) a10p3-test1
		echo
		cat a10p3-test2
		$(SOURCE) a10p3-test2
		echo
		-$(SOURCE) a10p3-test1 a10p3-test2
		echo
		-cat no-such-file
		-$(SOURCE) no-such-file
		echo


