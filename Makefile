GXX = g++
FLAGS = -Wall
OBJs = Main.o Book.o HashTable.o
DEPs = Main.cpp Book.cpp HashTable.cpp

Program:$(OBJs)
		$(GXX) $(FLAGS) $(OBJs) -o Program
Main.o:$(DEPs)
		$(GXX) -c $(DEPs) 
clean:
	rm *.o Program