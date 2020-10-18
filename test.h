#ifndef TESTS_H
#define TESTS_H

#include <iostream>
#include <string>
#include "ternary.h"

using namespace std;

void runAll();
void test_insert();
void test_search();

void test_insert_empty_list();
void test_insert_full_list();
void test_insert_word_twice();

void test_search_empty_list();
void test_search_not_there();
void test_search_there();

void START_TEST(string testname){
    cout << "START: " << testname << endl;
}

void END_TEST(string testname) {
    cout << "END: " << testname << endl;
}

template <class T>
void assertEquals(T actual, T expected, string testDescription){
    if (actual == expected){
        cout<< "PASSED: " << endl;
    } else {
        cout << "   FAILED: " << testDescription << endl << "   EXPECTED: " << expected << "    ACTUAL: " << actual << endl;
    }
}

#endif