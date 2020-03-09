CC = g++
CFLAGS = -O3

main: main.cpp graph.cpp
	$(CC) $(CFLAGS) graph.cpp main.cpp -o main

main_dcsc: main_dcsc.cpp graph.cpp
	$(CC) $(CFLAGS) -g graph.cpp main_dcsc.cpp -o main