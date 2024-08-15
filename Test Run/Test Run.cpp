#include <iostream>
#include "Windows.h"
#include "Ccheck.h"
#include "Cseedrandom.h"
#include "Citemtracking.h"

int main() 
{
    seed rand;
    rand.rando();//seed random every time you start up the game

    Ccheck checking;// create check
    checking.roomid();//randomise key location


    int playerlocation = 1;//set player location here

    track itemcount; // track items
    bool firstkeyfound=itemcount.keystate();//track if the player has already found a key

    for (int i = 0; i < 100; i++)//for loop just for testing purposes, just copy the code inside into the check statement
    {
    
    checking.result();
    checking.findkey();

    checking.currentlocation(playerlocation);//update room id here
    bool result = checking.result(); //run the randomizer   
    bool iskeyfound = checking.findkey();//check if the key is in the same room
    
        if (result&&!iskeyfound)
        {
            std::cout << "there's nothing here.\n";
        }
        else
        {
            std::cout << "there's something here...\n";

            if (iskeyfound==true && firstkeyfound == false)
            {
                std::cout << "its a key.\n";
                itemcount.keystate();
                itemcount.key();
            }
            else
            {
                std::cout << "its just some juice.\n";
                itemcount.potion();
            }

        }
        playerlocation++;
        
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

