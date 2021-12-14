//
// Created by Расим Гаджиев on 13.12.2021.
//

#ifndef COURSETASKRASIM_APPLICATION_H
#define COURSETASKRASIM_APPLICATION_H
#include "TextDictionary.h"
#include <vector>


class Application {
public:
    Application(TextDictionary dictionary);

    int state;
    std::vector<std::string> actions;
    TextDictionary dictionary;
    void run();
    void menu();
    void select_action(int action);
};


#endif //COURSETASKRASIM_APPLICATION_H
