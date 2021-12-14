//
// Created by Расим Гаджиев on 05.12.2021.
//

#ifndef COURSETASKRASIM_TEXTDICTIONARY_H
#define COURSETASKRASIM_TEXTDICTIONARY_H

#include <vector>
#include <string>
#include <map>
#include <set>

class TextDictionary {
public:
    std::string text_path;
    std::set<char> delimits;
    std::map<std::string, int> words;

    std::vector<std::string> word_parse(const std::string &row) const;

    TextDictionary();

    void word_input();

    void word_add(std::string word);

    void count_increase(std::string &word);

    void print();

    void scan_txt();

    void input_find();
};


#endif //COURSETASKRASIM_TEXTDICTIONARY_H
