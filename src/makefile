FLAGS = -c -g3 -Wall -O3
OBJS = *.o
CC = g++

wnvgame: main.o grid.o creatures.o game.o
	g++   main.o grid.o creatures.o game.o -o game

main.o: ./main.cpp
	$(CC) $(FLAGS) ./main.cpp

grid.o : ./grid.cpp
	$(CC) $(FLAGS)  ./grid.cpp

creatures.o : ./creatures.cpp
	$(CC) $(FLAGS)  ./creatures.cpp

game.o : ./game.cpp
	$(CC) $(FLAGS)  ./game.cpp

clean:
	rm -rf $(TARGETS) $(OBJS)