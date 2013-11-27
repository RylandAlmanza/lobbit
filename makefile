CC=g++
LIBS=-lsfml-graphics -lsfml-window -lsfml-system

main: main.cc point.cc rectangle.cc collision.cc bodypart.cc being.cc waddleblockus.cc
	$(CC) main.cc point.cc rectangle.cc collision.cc bodypart.cc being.cc waddleblockus.cc -o main $(LIBS)
