#ifndef MENU_H
#define MENU_H

#include <string>

class Menu
{
public:
    Menu();
    void showMenu();
    void showCredits();

protected:


private:
    std::string menuControl;
};

#endif // MENU_H