//
// Created by Расим Гаджиев on 13.12.2021.
//

#include "Application.h"
#include <iostream>

Application::Application(TextDictionary dictionary) {
    this->dictionary = dictionary;
    this->state = 0;
    this->actions = {"Print dictionary",
                     "Add a new word",
                     "Find a word",
                     "Sort a dictionary",
                     "Read words from file"};
}

void Application::run() {
    menu();
}

void Application::menu() {
    int k = 1;
    std::cout << "________________________\n";
    std::cout << "Type the number to select action: \n";
    for (const auto &it: this->actions) {
        std::cout << k << ". " << it << std::endl;
        k++;
    }
    std::cin >> k;
    select_action(k);
}

void Application::select_action(int action) {
    switch (action) {
        case 1:
            dictionary.print();
            menu();
        case 2:
            dictionary.word_input();
            menu();
        case 3:
            dictionary.input_find();
            menu();
        case 4:
            dictionary.sort();
            menu();
        case 5:
            dictionary.scan_txt();
            menu();
        default:
            return;
    }
}




