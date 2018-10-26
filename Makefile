2048: main.cpp game.o
	g++ -o 2048 main.cpp game.o
game.o: game.cpp game.h
	g++ -c game.cpp
clean:
	rm game.o
