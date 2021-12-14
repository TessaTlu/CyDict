#include "TextDictionary.h"
#include "Application.h"

int main() {
    auto dictionary = TextDictionary();
    dictionary.text_path = "text.txt";
    Application app(dictionary);
    app.run();
 }
