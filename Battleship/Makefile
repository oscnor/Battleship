#comment
# Target: Dependencies

CC = g++
CFLAGS = -g -Wall -Wextra -Werror -pedantic
LSFML = -lsfml-graphics -lsfml-window -lsfml-system
CVERSION = --std=c++17
TARGET = Battleship

DEPS = playingfield.hpp ship.hpp
OBJ = main.o playingfield.o ship.o

all: main clean

main: $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(CVERSION) $(CFLAGS) $(LSFML)

main.o: main.cpp
	$(CC) -c main.cpp $(CVERSION) $(CFLAGS) $(LSFML)

playingfield.o: playingfield.hpp
	$(CC) -c playingfield.cpp $(CVERSION) $(CFLAGS) $(LSFML)

ship.o: ship.hpp
	$(CC) -c ship.cpp $(CVERSION) $(CFLAGS) $(LSFML)

.PHONY: clean

clean: 
	rm -f *.o
