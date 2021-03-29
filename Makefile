GXX = g++
FLAGS = -Wall

Program:Main.o Book.o HashTable.o
		$(GXX) $(FLAGS) Main.o Book.o HashTable.o -o Program
Main.o:Main.cpp Book.cpp HashTable.cpp
		$(GXX) -c Main.cpp Book.cpp HashTable.cpp 
clean:
	rm *.o Program