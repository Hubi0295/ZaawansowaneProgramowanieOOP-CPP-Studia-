//
// Created by Hubert on 12.11.2024.
//

#include "Dictionary.h"

#include <algorithm>
#include <iostream>
#include <ostream>
#include <vector>


Dictionary::Dictionary() {
}

void Dictionary::add(string word, string explain) {
    words[word]=explain;
}

void Dictionary::deleteWord(string word) {
    words.erase(word);
}

void Dictionary::showAll() {
    for(map<string,string>::iterator it = words.begin(); it != words.end(); it++) {
        cout<<it->first<<" "<<it->second<<endl;
    }
}

void Dictionary::showWord(string word) {
    cout<<word<<" "<<words[word]<<endl;
}

void Dictionary::showSortedByExplain() {
    vector<string> keys;
    for(map<string,string>::iterator it = words.begin(); it != words.end(); it++) {
        keys.push_back(it->second);
    }
    sort(keys.begin(), keys.end());
    for(string word : keys) {
        for(map<string,string>::iterator it = words.begin(); it != words.end(); it++) {
            if(it->second==word) {
                cout<<it->first<<" "<<it->second<<endl;
            }
        }
    }
}

