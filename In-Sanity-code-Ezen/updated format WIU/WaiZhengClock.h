#pragma once
#include <iostream>
#include <chrono>
class WaiZhengClock
{
private:

    std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTime;
    std::chrono::time_point<std::chrono::high_resolution_clock> m_EndTime;
    std::chrono::duration<double> elapsed;
    bool m_Stopped = false;

public:
    // Constructor
    WaiZhengClock();

    ~WaiZhengClock();

    // Start the timer
    void Start();

    void Stop();

    // Reset the timer
    void Reset();

    // Elapsed
    double getElapsed();

};

