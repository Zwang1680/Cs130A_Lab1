#include "test.h"
#include "ternary.h"
#include <string>
using namespace std;

int main(){
    runAll();
    return 0;
}

void runAll(){
    test_insert();
    test_search();
}

void test_insert(){
    START_TEST("test insert");
    test_insert_empty_list();
    test_insert_full_list();
    test_insert_word_twice();
    END_TEST("test insert");
}

void test_search(){
    START_TEST("test search");
    test_search_empty_list();
    test_search_not_there();
    test_search_there();
    END_TEST("test search");
}

void test_insert_empty_list(){
    Tst x;
    x.insert("bruh");
    string s = "bruh 1\n";
    string result = x.preorder();
    assertEquals(result, s, "Inserting into empty tree");
}

void test_insert_full_list(){
    Tst x;
    string y("hello"), t("boi"), b("ba ba boey");
    x.insert(y);
    x.insert(t);
    x.insert(b);
    string s = "hello 1\nboi 1\nba ba boey 1\n";
    string result = x.preorder();
    assertEquals(result, s, "Inserting multiple different words");
}

void test_insert_word_twice(){
    Tst x;
    string y("ma"), t("aladdin"), b("ma");
    x.insert(y);
    x.insert(t);
    x.insert(b);
    string s = "ma 2\naladdin 1\n";
    string result = x.preorder();
    assertEquals(result, s, "Inserting the same word twice");
}

void test_search_empty_list(){
    Tst x;
    string result = x.lookup("stuff");
    string s = "stuff not found";
    assertEquals(result, s, "looking up in an empty tree");
}

void test_search_not_there(){
    Tst x;
    string y("ma"), t("aladdin"), b("ma"), f("abc"), j("bob");
    x.insert(y);
    x.insert(t);
    x.insert(b);
    x.insert(f);
    x.insert(j);
    string result = x.lookup("rough");
    string s = "rough not found";
    assertEquals(result, s, "looking up in full tree but not there");
}

void test_search_there(){
    Tst x;
    string y("ma"), t("aladdin"), b("ma"), f("abc"), j("bob");
    x.insert(y);
    x.insert(t);
    x.insert(b);
    x.insert(f);
    x.insert(j);
    string result = x.lookup("ma");
    string s = "ma found, count = 1";
    assertEquals(result, s, "looking up in full tree but not there");
}