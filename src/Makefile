FLAGS = -Wall -Wextra

class.o : class.cpp
	g++ $(FLAGS) class.cpp -c -o class.o

main.o : main.cpp
	g++ $(FLAGS) main.cpp -c -o main.o

prog.out : main.o class.o
	g++ $(FLAGS) main.o class.o -o prog.out

clean:
	rm -f main.o class.o prog.out