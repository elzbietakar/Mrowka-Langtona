a.out: main.o  read_write.o ant.o board.o 
	$(CC) $^
main.o: board.h
read_write.o: board.h
ant.o: board.h
board.o: board.h
