all: project1.out
		./project1.out
project1.out: main.cpp ternary.cpp
		g++ main.cpp ternary.cpp -o project1.out
clean:
		rm project1.out
