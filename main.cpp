#include <string>
#include <iostream>
#include "ternary.h"

using namespace std;

int main(int argc, char** argv){
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " need at least 1 command" << endl;
    }
    Tst x;
    string temp;
    for (int i = 1; i < argc; i+=2){
        if(strcmp(argv[i], "lookup") == 0){
            temp = argv[i+1];
            int c = temp.find(",");
            if (c> 1){
                temp.erase(c, c+1);
            }
            x.lookup(temp);
        } else if (strcmp(argv[i], "insert") == 0){
            temp = argv[i+1];
            int c = temp.find(",");
            if (c> 1){
                temp.erase(c, c+1);
            }
            x.insert(temp);
        } else if (strcmp(argv[i], "delete") == 0){
            temp = argv[i+1];
            int c = temp.find(",");
            if (c> 1){
                temp.erase(c, c+1);
            }
            x.deleteWord(temp);
        } else if (strcmp(argv[i], "range_search") == 0){
            temp = argv[i+3];
            int c = temp.find(",");
            if (c> 1){
                temp.erase(c, c+1);
            }
            x.rangeSearch(argv[i+1], temp);
            i += 2;
        }
    }
}