#include <iostream>/*
#include "CTimer.h"*/
#include "Windows.h"
#include "Ccheck.h"



int main() 
{
    int a;

    while (true)
    {
    Ccheck checking; 
    checking.result();

    bool result = checking.result();
    bool iskeyfound = checking.findkey();
    
        if (result)
        {
            std::cout << "there's nothing here.\n";
        }
        else
        {
            std::cout << "there's something here...\n";

            if (iskeyfound)
            {
                std::cout << "its a key.\n";
            }
            else
            {
                std::cout << "its some juice.\n";
            }
        }
        std::cout << "-------------------------------------------------\n";
        system("pause");
        system("cls");
    }
    
    //CTimer timer;
    //double interval = 0.0; // Interval in seconds

    //timer.Start();

    //while (true) {
    //    if (timer.HasIntervalPassed(interval)) {
    //        std::cout << interval << " seconds have passed. Performing action..." << std::endl;

    //        // Reset the timer if you want to perform the action repeatedly at this interval
    //        /*timer.Reset();
    //        timer.Start();*/
    //        

    //        // Uncomment the break statement if you only want the action to occur once
    //        if (interval == 5)
    //        {
    //            std::cout << "penis" << std::endl;
    //        }


    //        interval++;
    //        
    //    }
    //   

    //    // Other code can run here if needed
    //}

    return 0;
}






//int main() {
//    CTimer timer;
//
//    timer.Start();
//
//    // Code block to time
//    for (int i = 0; i < 1000000; ++i) 
//    {
//        // Simulating some work
//    }
//
//    double elapsedTime = timer.Stop();
//
//    std::cout << "Elapsed time: " << elapsedTime << " seconds" << std::endl;
//
//    return 0;
//}

