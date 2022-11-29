FLAGS = -c -g3 -Wall -O3
OBJS = *.o
CC = g++

game: main.o grid.o
	g++   main.o grid.o -o game

main.o: ./main.cpp
	$(CC) $(FLAGS) ./main.cpp

grid.o : ./grid.cpp 
	$(CC) $(FLAGS)  ./grid.cpp

clean:
	rm -rf $(TARGETS) $(OBJS)