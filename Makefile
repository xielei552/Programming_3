CC = gcc
FLAGS = -Wall -std=gnu99 -g
SOURCE = a5p2

all: view compile execute

view: $(SOURCE).c
	cat $(SOURCE).c
	cat Makefile

compile: $(SOURCE).c
	$(CC) $(FLAGS) $(SOURCE).c -o $(SOURCE)

execute: $(SOURCE)
	for i in `seq 1 20`; do \
		a5p2; \
		sleep 2; \
	done
