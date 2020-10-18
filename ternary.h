#ifndef TERNARY_H
#define TERNARY_H

#include <string>
using namespace std;

class Tst{
    public:
    Tst();
    ~Tst();
    void insert(string s);
    string lookup(string s);
    void deleteWord(string s);
    string preorder();
    struct Node{
        string dataLG, dataSM;
        int countLG, countSM;
        Node *left, *mid, *right;
        Node(string s): dataLG(s), dataSM(""), left(0), right(0), mid(0), countLG(1), countSM(0){}
        ~Node(){
            delete left;
            delete mid;
            delete right;
        }
    };

    private:
    Node* root;
    void insert(string s, Node *r);
    Node* lookup(string s, Node* r);
    Node* deleteWord(string s, Node* r);
    string preorder(Node* r);
};

#endif