TARGET = lab.exe
CC = gcc

.PHONY: edit run clean install uninstall valgrind

edit: $(TARGET)		 
	
Node.o: Node.cpp Node.h
				$(CC) -c Node.cpp
Tree.o: Tree.cpp Tree.h
				$(CC) -c Tree.cpp
TreeG.o: TreeG.cpp
				$(CC) -c TreeG.cpp

a.out: Node.c Tree.c TreeG.c
	gcc -g Node.c Tree.c TreeG.c

$(TARGET): Node.o Tree.o TreeG.o
				$(CC) -o $(TARGET) Node.o Tree.o TreeG.o
valgrind: a.out
	valgrind -q ./a.out	
	
splint:
	splint *.c
clean:
			@rm -rf $(TARGET) *.o *.i *.s *.gch *.out *.exe
install: $(TARGET) 
			install $(TARGET) /
run:
			$(TARGET)
uninstall:
			@rm -rf /$(TARGET)