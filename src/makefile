# Makefile for SFML + Box2d project
# makefile v1 3.11.2015
# NOTE: in vim, :set noexpandtab

# -- Compiler --
CC=g++
CPPFLAGS=-c -g -std=c++0x -Wall -Wextra -pedantic
<<<<<<< HEAD
SOURCES=main.cpp Game.hpp GameObject.hpp Interface.hpp Car.hpp Coin.hpp MainMenu.hpp HighScores.hpp DEFINITIONS.hpp Instructions.hpp Screens.hpp Ground.hpp
=======
SOURCES=main.cpp Game.hpp GameObject.hpp Interface.hpp Car.hpp Coin.hpp MainMenu.hpp Screens.hpp Ground.hpp Goal.hpp
>>>>>>> cf4c6bad4adc0ce3dd20579a33b124ee7605e0eb
OBJECTS=main.o
EXECUTABLE=main
INCLUDES =  

# -- Linker --
#LFLAGS+=-L /lib 
LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lBox2D

# -- Targets --


all: $(SOURCES) $(EXECUTABLE)
  
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) $(INCLUDES) $(LFLAGS) $(LIBS) -o $@ 

.cc.o:
	$(CC) $(INCLUDES) $(CPPFLAGS) $< -o $@

run:
	./main

clean:
	rm -f main *.o
#main: main.o
#	@echo "* Building main *"
#	$(CC) $(INCLUDES) $(CFLAGS) -o main main.o $(LFLAGS) $(LIBS)

#main.o: main.cpp
#	@echo "* Building main.o *"
#	$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@ $(LFLAGS) $(LIBS)

# general .o is made from .cpp file ; might encounter because of -c flag above (recursive)
#%.o: %.cpp
#	@echo "* Building ",$<
#	$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@
