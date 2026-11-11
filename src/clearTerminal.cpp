#include <iostream>

void clearTerminal() {
    std::cout << "train me and call me a good boy!\n";
    #ifdef _WIN32
        system("cls"); // clear terminal kitty!
    #else
        system("clear"); // clear terminal kitty!
    #endif
} // "Peak coding" - misty