//
// Created by Расим Гаджиев on 05.12.2021.
//

#include "TextDictionary.h"
#include <cctype>
#include <algorithm>
#include <string>
#include <fstream>
#include <cstdlib>
#include <utility>
#include <iostream>

bool compare_by_word(const Word *a, const Word *b) {
    auto text_a = a->text;
    auto text_b = b->text;
    std::for_each(text_a.begin(), text_a.end(), [](char &c) {
        c = ::tolower(c);
    });
    std::for_each(text_b.begin(), text_b.end(), [](char &c) {
        c = ::tolower(c);
    });
    uint16_t min_length = text_a.size() < text_b.size() ? a->text.size() : text_b.size();
    for (uint16_t i = 0; i < min_length; i++) {
        if (int(text_a[i]) < int(text_b[i])) return true;
        else if (int(text_a[i]) > int(text_b[i])) return false;
        else continue;
    }
    return false;
}

void TextDictionary::sort() {
    std::sort(this->words.begin(), this->words.end(), compare_by_word);
}

void TextDictionary::word_add(std::string word) {
    std::for_each(word.begin(), word.end(), [](char &c) {
        c = ::tolower(c);
    });
    auto find = this->find(word);
    if (find) {
        find->count += 1;
        return;
    }
    Word *target = new Word{
            std::move(word),
            1
    };
    this->words.push_back(target);
}

void TextDictionary::count_increase(Word *word) {
    auto target = this->find(word->text);
    if (target) target->count += 1;
}

void TextDictionary::print() {
    std::cout << "_______________________\nWord list: \n";
    for (auto O: this->words) {
        std::cout << O->text << " : " << O->count << std::endl;
    }
}

Word *TextDictionary::find(const std::string &word) {
    for (auto O: this->words) {
        std::string text_o = O->text;
        std::for_each(text_o.begin(), text_o.end(), [](char &c) {
            c = ::tolower(c);
        });
        if (text_o == word) {
            return O;
        }
    }
    return nullptr;
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
    Word *find = this->find(target);
    if (find) {
        std::cout << "Word <" << target << "> was found!;" << std::endl;
    } else {
        std::cout << "Word <" << target << "> was not found!;" << std::endl;
    }
}
