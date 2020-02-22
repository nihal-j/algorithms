CC = g++
CFGLAGS = -Wall

main: main.cpp graph.cpp graph.h
	$(CC) graph.cpp main.cpp -o main