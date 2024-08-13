#include "CTimeClock.h"
CTimeClock::CTimeClock() 
{ 
    m_bRunning = false;
}

CTimeClock::~CTimeClock()
{
    
}

void CTimeClock::Start()
{
    m_StartTime = std::chrono::high_resolution_clock::now();
    m_bRunning = true;
}

void CTimeClock::Stop()
{
    m_StartTime = std::chrono::high_resolution_clock::now();
    m_bRunning = false;
}


void CTimeClock::Reset()
{
    m_bRunning = false;
}

double CTimeClock::getElapsed() 
{
    auto currentTime = std::chrono::high_resolution_clock::now();
    elapsed = currentTime - m_StartTime;
    std::cout << elapsed.count() << std::endl;
    return elapsed.count();
}



