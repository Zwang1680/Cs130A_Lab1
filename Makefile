all: runTST test
runTST: main.cpp ternary.cpp
		g++ main.cpp ternary.cpp -o project1
test: test.cpp ternary.cpp
		g++ test.cpp ternary.cpp -g -o tests
clean:
		rm project1
		rm tests