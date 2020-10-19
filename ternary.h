#ifndef TERNARY_H
#define TERNARY_H

#include <string>
using namespace std;

class Tst{
    public:
    Tst();
    ~Tst();
    void insert(string s);
    void lookup(string s);
    void deleteWord(string s);
    string preorder();
    void rangeSearch(string s1, string s2);
    struct Node{
        string dataLG, dataSM;
        int countLG, countSM;
        Node *left, *mid, *right, *parent;
        Node(string s): dataLG(""), dataSM(s), left(0), right(0), mid(0), countLG(0), countSM(1), parent(0){}
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
    void deleteWord(string s, Node* r);
    void deleteNode(Node* r);
    string preorder(Node* r);
    void rangeSearch(string s1, string s2, Node* r);
    void removeNode(Node* r);
};

#endif