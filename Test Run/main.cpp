#include <iostream>

#include "CTimeClock.h"

int main() {
    CTimeClock timer;

    timer.Start();

    while (true) 
    {
        timer.getElapsed();
        int a;
        std::cin >> a;
        if (a == 1)
        {
            timer.Start();
            std::cout << "free takoyaki" << std::endl;
            
        }
        else if (timer.getElapsed() >= 5)
        {
            std::cout << "suck my balls" << std::endl;
            break;
        }
    }

    return 0;
}





























//progress 01 for clock/timer
//#include <iostream>
//
//#include "CTimeClock.h"
//
//int main() {
//    CTimeClock timer;
//    double interval = 0.0; // Interval in seconds
//
//    timer.Start();
//
//    while (true) {
//        //if (timer.HasIntervalPassed(interval)) {
//        //    //std::cout << interval << " seconds have passed. Performing action..." << std::endl;
//
//        //    // Reset the timer if you want to perform the action repeatedly at this interval
//        //    /*timer.Reset();
//        //    timer.Start();*/
//        //    timer.getElapsed();
//        //    if (interval == 5)
//        //    {
//        //        int a;
//        //        std::cout << "penis" << std::endl;
//        //        std::cin >> a;
//        //        if (a == 1)
//        //        {
//        //            return 0;
//        //        }
//        //        else
//        //        {
//
//        //        }
//        //    }
//
//        //    // Uncomment the break statement if you only want the action to occur once
//
//        //    interval++;
//
//        //}
//        timer.getElapsed();
//        int a;
//        std::cin >> a;
//        if (timer.getElapsed() >= 5)
//        {
//            std::cout << "suck my balls";
//            break;
//        }
//
//
//        // Other code can run here if needed
//    }
//
//    return 0;
//}