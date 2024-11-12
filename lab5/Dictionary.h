//
// Created by Hubert on 12.11.2024.
//


#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <map>
#include <string>

using namespace std;
class Dictionary {
private:
    map<string, string> words;
public:
    Dictionary();
    void add(string word, string explain);
    void deleteWord(string word);
    void showAll();
    void showWord(string word);
    void showSortedByExplain();
};



#endif //DICTIONARY_H
