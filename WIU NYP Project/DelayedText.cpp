#include "DelayedText.h"
#include <iostream>
#include <thread>
#include <cstdlib>

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void printWithDelay(const std::string& text, std::chrono::milliseconds delay) {
    for (char c : text) {
        std::cout << c << std::flush;
        std::this_thread::sleep_for(delay);
    }
    std::cout << std::endl;
}
