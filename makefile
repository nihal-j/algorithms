CC = g++
CFLAGS = -O3

main: main.cpp graph.cpp kosaraju.cpp DCSC.cpp
	$(CC) $(CFLAGS) -g graph.cpp kosaraju.cpp DCSC.cpp main.cpp -o main

main_dcsc: main_dcsc.cpp graph.cpp
	$(CC) $(CFLAGS) -g graph.cpp main_dcsc.cpp -o main