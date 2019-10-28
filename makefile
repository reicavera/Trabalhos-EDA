main:   main.o    node.o    stack.o queue.o list.o
    gcc main.o  node.o  stack.o queue.o list.o -o   main
main.o: main.c
    gcc -c main.c   -o main.o
node.o: node.c  node.h
    gcc -c  node.c  -o  node.o
stack.o: stack.c
    gcc -c  stack.c -o  stack.o
queue.o:    queue.c
    gcc -c  queue.c
list.o: list.c  list.h
    gcc -c  list.c
clear:
    rm  -rf *.o
mrproper:   clean
