main:   main.o    node.o    stack.o queue.o list.o
    gcc main.o  node.o  stack.o queue.o list.o -o   main    -Wall -Wextra -Werror -Wpedantic
main.o: main.c
    gcc -c main.c   -o main.o   -Wall -Wextra -Werror -Wpedantic
node.o: node.c  node.h
    gcc -c  node.c  -o  node.o  -Wall -Wextra -Werror -Wpedantic
stack.o: stack.c
    gcc -c  stack.c -o  stack.o -Wall -Wextra -Werror -Wpedantic
queue.o:    queue.c
    gcc -c  queue.c -Wall -Wextra -Werror -Wpedantic
list.o: list.c  list.h
    gcc -c  list.c  -Wall -Wextra -Werror -Wpedantic
clear:
    rm  -rf *.o -Wall -Wextra -Werror -Wpedantic
mrproper:   clean
