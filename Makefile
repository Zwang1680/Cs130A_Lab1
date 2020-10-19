all: runTST
runTST: main.cpp ternary.cpp
		g++ main.cpp ternary.cpp -o project1
clean:
		rm project1