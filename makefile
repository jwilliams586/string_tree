CC=gcc

tree: main.o buildTree.o traversals.o
	$(CC) -o tree main.o buildTree.o traversals.o

clean:
	rm tree *.o

.SUFFIXES: .o .c

.c.o :
	$(CC) -c $<
