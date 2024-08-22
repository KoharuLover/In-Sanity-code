#include "WaiZhengClock.h"

WaiZhengClock::WaiZhengClock()
{
}

WaiZhengClock::~WaiZhengClock()
{
}

void WaiZhengClock::Start()
{
	m_StartTime = std::chrono::high_resolution_clock::now();
	m_Stopped = false; // Reset the stop flag when starting
}

void WaiZhengClock::Stop()
{
	if (!m_Stopped) {
		m_EndTime = std::chrono::high_resolution_clock::now();
		m_Stopped = true;
	}
}

void WaiZhengClock::Reset()
{
	// Reset the clock and clear the stopped flag
	m_StartTime = std::chrono::high_resolution_clock::time_point();
	m_EndTime = std::chrono::high_resolution_clock::time_point();
	m_Stopped = false;
}

double WaiZhengClock::getElapsed()
{
	using namespace std::chrono;
	if (m_Stopped) {
		return duration_cast<milliseconds>(m_EndTime - m_StartTime).count();
	}
	else {
		return duration_cast<milliseconds>(high_resolution_clock::now() - m_StartTime).count();
	}
}

