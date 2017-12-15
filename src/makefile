# Makefile for SFML + Box2d project
# makefile v1 3.11.2015
# NOTE: in vim, :set noexpandtab

# -- Compiler --
CC=g++
CPPFLAGS=-g -std=c++11 -Wall -Wextra -pedantic -w
SOURCES=main.cpp Game.hpp Game.cpp GameObject.hpp Interface.hpp Car.cpp Car.hpp Coin.cpp Coin.hpp MainMenu.hpp HighScores.cpp HighScores.hpp DEFINITIONS.hpp Instructions.cpp Instructions.hpp Screens.hpp Ground.cpp Ground.hpp Goal.cpp Goal.hpp PointsSpeedClock.cpp PointsSpeedClock.hpp Box2DToSFML.cpp Box2DToSFML.hpp MainMenu.cpp LevelsMenu.cpp LevelsMenu.hpp
OBJECTS=main.o Game.o Car.o Coin.o Instructions.o Ground.o Goal.o PointsSpeedClock.o Box2DToSFML.o MainMenu.o LevelsMenu.o HighScores.o
EXECUTABLE=main
INCFLAGS=-I./Box2D_v2.1.2/Box2D
#BOX2D := /Box2D_v2.1.2/Box2D
LDFLAGS=-L./Box2D_v2.1.2/Box2D/Build/Box2D -lBox2D
# -- Linker --
#LFLAGS+=-L /lib 
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

# -- Targets --


all: main
  
main: $(SOURCES) 
	$(CC) $(CPPFLAGS) $(SOURCES) $(INCFLAGS) $(LIBS) $(LDFLAGS) -o main 

#.cc.o:
	

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
