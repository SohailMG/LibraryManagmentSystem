output:Main.o 
		g++ -Wall Main.o -o output

Main.o:Main.cpp
		g++ -c Main.cpp



clean:
	rm *.o output