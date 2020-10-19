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
        string output = s + " inserted, new count: " + to_string(newNode->countSM);
        cout << output << endl;
        root = newNode;
        return;
        exit(1);
    }
    insert(s, root);   
}

void Tst::insert(string s, Tst::Node* r){
    if (s == r->dataLG){
        r->countLG +=1;
        string output = s + " inserted, new count: " + to_string(r->countLG);
        cout << output << endl;
        return;
    } else if (s == r->dataSM){
        r->countSM +=1;
        string output = s + " inserted, new count: " + to_string(r->countSM);
        cout << output << endl;
        return;
    }
    if (r->countLG == 0){
        if (s < r->dataSM){
            string temp = r->dataSM;
            r->dataSM = s;
            r->dataLG = temp;
            r->countLG = r->countSM;
            r->countSM = 1;
            string output = s + " inserted, new count: " + to_string(r->countSM);
            cout << output << endl;
            return;
        } else {
            r->dataLG = s;
            r->countLG = 1;
            string output = s + " inserted, new count: " + to_string(r->countLG);
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
            r->left->parent = r;
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
            r->right->parent = r;
            string output = s + " inserted, new count: " + "1";
            cout << output << endl;
            return;
        }
    }
}

void Tst::lookup(string s){
    Tst::Node* x = lookup(s, root);
    if (x){
        if (s == x->dataLG){
            string output = s + " found, count = " + to_string(x->countLG);
            cout << output << endl;
            return;
        } else {
            string output = s + " found, count = " + to_string(x->countSM);
            cout << output << endl;
            return;
        }
    } else {
        string output = s + " not found";
        cout << output << endl;
        return;
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
    Tst::Node* temp = lookup(s, root);
    if (!temp){
        return;
    }
    deleteWord(s, temp);
}

// void removeNode(Tst::Node* r){
//     if(!r){
//         return:
//     }

// }

void Tst::deleteWord(string s, Node* r){
    string output;
    // if (s == r->dataSM){
    //     r->countSM -= 1;
    //     if (r->countSM == 0){

    //     }
    // }
    if (s == r->dataSM){
        if (r->countSM > 1){
            r->countSM -= 1;
            output = s + " deleted, new count = " + to_string(r->countSM);
            cout << output << endl;
            return;
        } else {
            if (r->left || r->right || r->mid){
                if(r->mid){
                    if (r->mid->countSM != 0){
                        r->dataSM = r->mid->dataSM;
                        r->countSM = r->mid->countSM;
                        r->mid->countSM = 1;
                        deleteWord(r->mid->dataSM, r->mid);
                        return;
                    } else if (r->mid->countLG != 0){
                        r->dataSM = r->mid->dataLG;
                        r->countSM = r->mid->countLG;
                        r->mid->countLG = 1;
                        deleteWord(r->mid->dataLG, r->mid);
                        return;
                    }
                } else if (r->left){
                    if (r->left->countSM != 0){
                        r->dataSM = r->left->dataSM;
                        r->countSM = r->left->countSM;
                        r->left->countSM = 1;
                        deleteWord(r->left->dataSM, r->left);
                        return;
                    } else if (r->left->countLG != 0){
                        r->dataSM = r->left->dataLG;
                        r->countSM = r->left->countLG;
                        r->left->countLG = 1;
                        deleteWord(r->left->dataLG, r->left);
                        return;
                    }
                }
            } else {
                 if (r->countLG == 0) {
                    r->left = NULL;
                    r->right = NULL;
                    r->mid = NULL;
                    Node* temp = r->parent;
                    if (r == temp->left){
                        temp->left = NULL;
                    } else if (r == temp->right){
                        temp->right = NULL;
                    } else {
                        temp->mid = NULL;
                    }
                    delete(r);
                    output = s + " deleted";
                    cout << output << endl;
                    return;
                } else {
                    r->dataSM = r->dataLG;
                    r->countSM = r->countLG;
                    r->countLG = 0;
                    r->dataLG = "";
                    output = s + " deleted";
                    cout << output << endl;
                    return;
                }
            }
        }
    }
    if (s == r->dataLG){
        if (r->countLG > 1){
            r->countLG -= 1;
            output = s + " deleted, new count = " + to_string(r->countLG);
            cout << output << endl;
            return;
        } else {
            if (r->left || r->right || r->mid){
                if(r->mid){
                    if (r->mid->countSM != 0){
                        r->dataLG = r->mid->dataSM;
                        r->countLG = r->mid->countSM;
                        r->mid->countSM = 1;
                        deleteWord(r->mid->dataSM, r->mid);
                        return;
                    } else if (r->mid->countLG != 0){
                        r->dataLG = r->mid->dataLG;
                        r->countLG = r->mid->countLG;
                        r->mid->countLG = 1;
                        deleteWord(r->mid->dataLG, r->mid);
                        return;
                    }
                } else if (r->right){
                    if (r->right->countSM != 0){
                        r->dataLG = r->left->dataSM;
                        r->countLG = r->left->countSM;
                        r->right->countSM = 1;
                        deleteWord(r->right->dataSM, r->right);
                        return;
                    } else if (r->right->countLG != 0){
                        r->dataLG = r->left->dataLG;
                        r->countLG = r->left->countLG;
                        r->right->countLG = 1;
                        deleteWord(r->right->dataLG, r->right);
                        return;
                    }
                }
            } else {
                if (r->countSM == 0){
                    r->left = NULL;
                    r->right = NULL;
                    r->mid = NULL;
                    Node* temp = r->parent;
                    if (r == temp->left){
                        temp->left = NULL;
                    } else if (r == temp->right){
                        temp->right = NULL;
                    } else {
                        temp->mid = NULL;
                    }
                    delete(r);
                    output = s + " deleted";
                    cout << output << endl;
                    return;
                } else {
                    r->countLG = 0;
                    r->dataLG = "";
                    output = s + " deleted";
                    cout << output << endl;
                    return;
                }
            }
        }
    }
}


void Tst::rangeSearch(string s1, string s2){
    rangeSearch(s1, s2, root);
}

void Tst::rangeSearch(string s1, string s2, Tst::Node* r){
    if(!r){
        return;
    }
    rangeSearch(s1, s2, r->left);
    if (r->dataSM >= s1 && r->dataSM <= s2){
        if (r->countSM != 0){
            cout << r->dataSM << endl;
        }
    }
    rangeSearch(s1, s2, r->mid);
    if (r->dataLG >= s1 && r->dataLG <= s2){
        if (r->countLG != 0){
            cout << r->dataLG << endl;
        }
    }
    rangeSearch(s1, s2, r->right);
}