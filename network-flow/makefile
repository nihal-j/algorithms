CC = g++
CFLAGS = -O2 -I include

main: build/main.o build/fordfulkerson.o
	$(CC) $(CFLAGS) -g build/fordfulkerson.o build/main.o -o main

main_bp: build/main_bp.o build/fordfulkerson.o
	$(CC) $(CFLAGS) -g build/fordfulkerson.o build/main_bp.o -o main_bp

build/main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp -o build/main.o

build/main_bp.o: main_bp.cpp
	$(CC) $(CFLAGS) -c main_bp.cpp -o build/main_bp.o

build/fordfulkerson.o: src/fordfulkerson.cpp
	$(CC) $(CFLAGS) -c src/fordfulkerson.cpp -o build/fordfulkerson.o