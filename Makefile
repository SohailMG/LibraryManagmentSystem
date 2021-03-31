GXX = g++
FLAGS = -Wall
OBJs = Main.o Book.o HashTable.o

Program:$(OBJs)
		$(GXX) $(FLAGS) $(OBJs) -o Program
Main.o:Main.cpp Book.cpp HashTable.cpp
		$(GXX) -c Main.cpp Book.cpp HashTable.cpp 
clean:
	rm *.o Program