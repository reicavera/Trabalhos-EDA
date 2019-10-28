OBJS	= main.o node.o stack.o queue.o list.o
SOURCE	= main.c node.c stack.c queue.c list.c
HEADER	= node.h stack.h queue.h list.h
OUT	= trab03
CC	 = gcc
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.c
	$(CC) $(FLAGS) main.c 

node.o: node.c
	$(CC) $(FLAGS) node.c 

stack.o: stack.c
	$(CC) $(FLAGS) stack.c 

queue.o: queue.c
	$(CC) $(FLAGS) queue.c 

list.o: list.c
	$(CC) $(FLAGS) list.c 


clean:
	rm -f $(OBJS) $(OUT)
