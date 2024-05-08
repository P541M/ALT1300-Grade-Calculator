CC=gcc
CFLAGS=-Wall -g -std=c11

all: gradeCalculator

gradeCalculator: gradeCalculator.c
	$(CC) -o gradeCalculator gradeCalculator.c $(CFLAGS)

clean:
	del /f gradeCalculator.exe
