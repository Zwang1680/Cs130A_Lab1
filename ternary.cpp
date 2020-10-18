#include "ternary.h"

#include <string>
#include <iostream>

using namespace std;

Tst::Tst(){
    root = NULL;
}

Tst::~Tst(){
    delete root;
}

void Tst::insert(string s){
    if (!root){
        Tst::Node* newNode = new Tst::Node(s);
        root = newNode;
        return;
        exit(1);
    }
    insert(s, root);   
}

void Tst::insert(string s, Tst::Node* r){
    if (s == r->dataLG){
        string output = s + " inserted, new count: " + to_string(r->countLG);
        cout << output << endl;
        r->countLG +=1;
        return;
    } else if (s == r->dataSM){
        string output = s + " inserted, new count: " + to_string(r->countSM);
        cout << output << endl;
        r->countSM +=1;
        return;
    }
    if (r->countSM == 0){
        if (s > r->dataLG){
            string temp = r->dataLG;
            r->dataLG = s;
            r->dataSM = temp;
            r->countSM = r->countLG;
            r->countLG = 1;
            string output = s + " inserted, new count: " + to_string(r->countLG);
            cout << output << endl;
            return;
        } else {
            r->dataSM = s;
            r->countSM = 1;
            string output = s + " inserted, new count: " + to_string(r->countSM);
            cout << output << endl;
            return;
        }
    }
    if (s > r->dataSM && s < r->dataLG){
        if(r->mid){
            insert(s, r->mid);
            return;
        } else {
            Tst::Node* newNode = new Tst::Node(s);
            r->mid = newNode;
            string output = s + " inserted, new count: " + "1";
            cout << output << endl;
            return;
        }
    } else if (s < r->dataSM){
        if(r->left){
            insert(s, r->left);
            return;
        } else {
            Tst::Node* newNode = new Tst::Node(s);
            r->left = newNode;
            string output = s + " inserted, new count: " + "1";
            cout << output << endl;
            return;
        }
    } else {
        if(r->right){
            insert(s, r->right);
            return;
        } else {
            Tst::Node* newNode = new Tst::Node(s);
            r->right = newNode;
            string output = s + " inserted, new count: " + "1";
            cout << output << endl;
            return;
        }
    }
}

string Tst::lookup(string s){
    Tst::Node* x = lookup(s, root);
    if (x){
        if (s == x->dataLG){
            string output = s + " found, count = " + to_string(x->countLG);
            return output;
        } else {
            string output = s + " found, count = " + to_string(x->countSM);
            return output;
        }
    } else {
        string output = s + " not found";
        return output;
    }
}

Tst::Node* Tst::lookup(string s, Node* r){
    if (!r){
        return NULL;
    }
    if (s == r->dataLG || s == r->dataSM){
        return r;
    }
    if (s < r->dataLG && s > r->dataSM){
        return lookup(s, r->mid);
    } else if (s < r->dataSM){
        return lookup(s, r->left);
    } else {
        return lookup(s, r->right);
    }
    return NULL;
}

string Tst::preorder(){
    string x = preorder(root);
    return x;
}

string Tst::preorder(Node* r){
    if(!r){
        return "";
    }
    string x = r->dataLG + " " + to_string(r->countLG) + " " + r->dataSM + " " + to_string(r->countSM) + "\n" + preorder(r->left) + preorder(r->mid) + preorder(r->right);
    return x;
}

void Tst::deleteWord(string s){
    deleteWord(s, root);
}

Tst::Node* Tst::deleteWord(string s, Node* r){
    // if (!r){
    //     return;
    // }
    // if ()
    return NULL;
}