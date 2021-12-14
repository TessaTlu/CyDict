//
// Created by Расим Гаджиев on 05.12.2021.
//

#ifndef COURSETASKRASIM_TEXTDICTIONARY_H
#define COURSETASKRASIM_TEXTDICTIONARY_H

#include <vector>
#include <string>
#include <set>

struct Word {
    std::string text;
    int count;
};

class TextDictionary {
public:
    std::string text_path;
    std::set<char> delimits;
    std::vector<Word*> words;
    std::vector<std::string> word_parse(const std::string &row) const;
    TextDictionary();
    void sort();
    void word_input();
    void word_add(std::string word);
    void count_increase(Word* word);
    void print();
    void scan_txt();
    Word* find(const std::string& word);
    void input_find();
};


#endif //COURSETASKRASIM_TEXTDICTIONARY_H
