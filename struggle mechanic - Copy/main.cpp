#include "player.h"
using namespace std;

//void gotoxy(int x, int y)
//{
//    COORD scrn;
//    HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
//
//    scrn.X = x; scrn.Y = y;
//    SetConsoleCursorPosition(hConsoleOutput, scrn);
//}
//
//
//int main()
//{
//    gotoxy(65, 13);
//    cout << "\033[3;34m" << "penis" << "\033[0m" << endl;
//    cout << endl;
//    gotoxy(7, 27);
//    cout << "You approached a seemingly normal wooden cart walking through the unfamiliar landscape, with a flickering neon light illuminating the darkness.";
//    cout.flush();
//    
//    return 0;
//}










int main() {
	player austin;
	
	//after player fails their hide chance
	austin.struggle();

}

//#include <iostream>
//#include <windows.h>
//
//bool IsKeyPressed(int key) {
//    SHORT state = GetAsyncKeyState(key);
//    return (state & 0x8000) != 0;
//}
//
//void WaitForKeyPress(int key) {
//    std::cout << "Press the specified key to continue...\n";
//
//    while (true) {
//        if (IsKeyPressed('Q')) {
//            std::cout << "Key pressed. Exiting...\n";
//            break;
//        }
//        Sleep(100); // Sleep for 100 milliseconds to reduce CPU usage
//    }
//}
//
//int main() {
//    std::cout << "Press 'Q' to exit the program.\n";
//    WaitForKeyPress('E'); // Wait for the 'Q' key press
//    return 0;
//}

//#include <iostream>
//#include <windows.h>
//
//void SetCursorPosition(int x, int y) {
//    COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
//    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
//}
//
//void CenterText(const std::string& text) {
//    CONSOLE_SCREEN_BUFFER_INFO csbi;
//    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
//
//    // Get console width and height
//    int consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
//    int consoleHeight = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
//
//    // Calculate the position to center the text
//    int x = (consoleWidth - static_cast<int>(text.length())) / 2;
//    int y = consoleHeight / 2;
//
//    // Set the cursor position to center and print the text
//    SetCursorPosition(x, y);
//    std::cout << text;
//}
//
//int main() {
//    // Set the console window to full screen
//    HWND consoleWindow = GetConsoleWindow();
//    DWORD dwStyle = GetWindowLong(consoleWindow, GWL_STYLE);
//    SetWindowLong(consoleWindow, GWL_STYLE, dwStyle & ~WS_OVERLAPPEDWINDOW);
//    ShowWindow(consoleWindow, SW_MAXIMIZE);
//    SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, nullptr);
//
//    // Wait to let the console window adjust its size
//    Sleep(1000); // Sleep for 1 second
//
//    CenterText("Hello, World!");
//
//    // Wait for user input to keep the window open
//    std::cin.get();
//    return 0;
//}