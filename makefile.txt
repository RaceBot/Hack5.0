#
# makefile for tic-tac-toe project
#

CC = gcc
FLAGS = -Wall -std=gnu99 -g
INCLUDES =

ticTacToe: gameUtils.o playerUtils.o ticTacToeDriver.c
	$(CC) $(FLAGS) gameUtils.o playerUtils.o ticTacToeDriver.c -o ticTacToe $(INCLUDES)

gameUtils.o: gameUtils.c gameUtils.h
	$(CC) $(FLAGS) -c gameUtils.c -o gameUtils.o $(INCLUDES)

playerUtils.o: playerUtils.c playerUtils.h
	$(CC) $(FLAGS) -c playerUtils.c -o playerUtils.o $(INCLUDES)

clean:
	rm -Rf *~ *.o ticTacToe.dSYM
