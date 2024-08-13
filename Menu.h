#ifndef MENU_H
#define MENU_H

#include <string>
using namespace std;

class Menu
{
public:
    Menu();
    void showMenu();
    void showCredits();
protected:
private:
    string menuControl;
};

#endif // MENU_H