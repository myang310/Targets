OBJS = main.o board.o target.o
CC = g++
FLAGS = -Wall
CFLAGS = -Wall -c

Targets: $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o Targets

main.o: main.cc board.h target.h
	$(CC) $(CFLAGS) main.cc

board.o: board.cc board.h target.h
	$(CC) $(CFLAGS) board.cc

target.o: target.cc target.h
	$(CC) $(CFLAGS) target.cc

clean:
	rm *.o Targets
