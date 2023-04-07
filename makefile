all: compile

dev: compile run

compile:
	g++  src/*.cpp -o dist/main.o -lSDL2 -lGL -lGLEW

run:
	dist/main.o