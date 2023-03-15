run : comp display clean

comp : src/main.cpp
	g++ -g -o main src/main.cpp

display :
	./main

clean :
	rm -rf main *.o
