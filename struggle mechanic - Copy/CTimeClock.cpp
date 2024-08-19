#include "CTimeClock.h"
CTimeClock::CTimeClock()
{
}

CTimeClock::~CTimeClock()
{

}

void CTimeClock::Start()
{
    m_StartTime = std::chrono::high_resolution_clock::now();
}

void CTimeClock::Stop()
{
    m_EndTime = std::chrono::high_resolution_clock::now();
}


void CTimeClock::Reset()
{
}

double CTimeClock::getElapsed()
{
    auto currentTime = std::chrono::high_resolution_clock::now();
    elapsed = currentTime - m_StartTime;
    return elapsed.count();
}