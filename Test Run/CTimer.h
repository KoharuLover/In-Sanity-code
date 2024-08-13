#pragma once
#include <chrono>
#include <iostream>

class CTimer {
private:

    std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTime;
    std::chrono::time_point<std::chrono::high_resolution_clock> m_EndTime;
    bool m_bRunning;


public:
    // Constructor
    CTimer();

    // Start the timer
    void Start();

    // Stop the timer and return the elapsed time in seconds
    double Stop();

    // Reset the timer
    void Reset();

    bool HasIntervalPassed(double interval);


};

