#include <string>
#include <iostream>
#include "ternary.h"

using namespace std;

int main(int argc, char** argv){
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " need at least 1 command" << endl;
    }
    Tst x;
    for (int i = 1; i < argc; i+=2){
        if(strcmp(argv[i], "lookup") == 0){
            x.lookup(argv[i+1]);
        } else if (strcmp(argv[i], "insert") == 0){
            x.insert(argv[i+1]);
        } else if (strcmp(argv[i], "delete") == 0){
            x.deleteWord(argv[i+1]);
        } else if (strcmp(argv[i], "range_search") == 0){
            x.rangeSearch(argv[i+1], argv[i+3]);
            i += 2;
        }
    }
}