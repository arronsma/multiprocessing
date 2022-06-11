flag = -std=c++11 -lpthread

main: main.o resource.o
	g++ main.o resource.o ${flag}

resource.o: resource.cpp
	g++ -c resource.cpp -o resource.o ${flag}

main.o: main.cpp
	g++ -c main.cpp -o main.o ${flag}