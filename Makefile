GXX = g++
FLAGS = -Wall

Program:Main.o Book.o 
		$(GXX) $(FLAGS) Main.o Book.o -o Program
Main.o:Main.cpp Book.cpp 
		$(GXX) -c Main.cpp Book.cpp 
clean:
	rm *.o Program