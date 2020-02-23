CC = g++
CFGLAGS = -Wall

main: main.cpp
	$(CC) graph.cpp main.cpp -o main

main_dcsc: main_dcsc.cpp
	$(CC) graph.cpp main_dcsc.cpp -o main