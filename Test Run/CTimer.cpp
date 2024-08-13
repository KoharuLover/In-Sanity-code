#include "CTimer.h"
CTimer::CTimer() : m_bRunning(false) {}

void CTimer::Start() 
{
    m_StartTime = std::chrono::high_resolution_clock::now();
    m_bRunning = true;
}

double CTimer::Stop() 
{
    if (m_bRunning) 
    {
        m_EndTime = std::chrono::high_resolution_clock::now();
        m_bRunning = false;
        std::chrono::duration<double> elapsed = m_EndTime - m_StartTime;
        return elapsed.count();
    }
    return 0.0;
}

void CTimer::Reset() 
{
    m_bRunning = false;
}

bool CTimer::HasIntervalPassed(double interval) 
{
    if (m_bRunning) 
    {
        auto currentTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = currentTime - m_StartTime;
        std::cout << elapsed.count() << std::endl;
        return elapsed.count() >= interval;
        
    }
    return false;
}