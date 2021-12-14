//
// Created by Расим Гаджиев on 05.12.2021.
//

#include "TextDictionary.h"
#include <cctype>
#include <algorithm>
#include <fstream>
#include <utility>
#include <iostream>


void TextDictionary::word_add(std::string word) {
    std::for_each(word.begin(), word.end(), [](char &c) {
        c = ::tolower(c);
    });
    if (this->words.count(word)) {
        count_increase(word);
        return;
    }
    words[word] = 1;
}

void TextDictionary::count_increase(std::string &word) {
    words[word] += 1;
}

void TextDictionary::print() {
    std::cout << "_______________________\nWord list: \n";
    std::map<std::string, int>::iterator it;
    for (it = words.begin(); it != words.end(); it++) {
        std::cout << it->first
                  << " : "
                  << it->second
                  << std::endl;
    }
}


void TextDictionary::word_input() {
    std::cout << "Enter a new word:\n";
    std::string text;
    std::cin >> text;
    this->word_add(text);
}

void TextDictionary::scan_txt() {
    std::ifstream in(this->text_path);
    if (!in.is_open()) {
        std::cerr << "Text is not found\n";
        return;
    }
    for (std::string row; getline(in, row);) {
        auto words = word_parse(row);
        for (const auto &word: words) {
            try {
                word_add(word);
            } catch (std::exception &e) {
                continue;
            }
        }
    }
    in.close();
}

std::vector<std::string> TextDictionary::word_parse(const std::string &row) const {
    std::vector<std::string> result;
    std::string word;
    for (char i: row) {
        if (delimits.count(i) == 0) {
            word.push_back(i);
        } else {
            if (!word.empty()) {
                result.push_back(word);
                word.clear();
            }
        }
    }
    if (!word.empty()) {
        result.push_back(word);
    }
    return result;
}

TextDictionary::TextDictionary() {
    delimits.insert(' ');
    delimits.insert('\n');
    delimits.insert('\t');
    delimits.insert('?');
    delimits.insert('!');
    delimits.insert(',');
    delimits.insert('.');
    delimits.insert(';');
    delimits.insert(':');
    delimits.insert('"');
    delimits.insert('(');
    delimits.insert(')');
    delimits.insert(')');
}

void TextDictionary::input_find() {
    std::cout << "Input word you are looking for" << std::endl;
    std::string target;
    std::cin >> target;
    if (words.count(target)) {
        std::cout << "Word <" << target << "> was found!;" << std::endl;
    } else {
        std::cout << "Word <" << target << "> was not found!;" << std::endl;
    }
}
