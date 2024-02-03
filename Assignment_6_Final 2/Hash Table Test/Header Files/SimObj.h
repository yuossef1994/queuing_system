#pragma once

#include "Event.h"
#include "HashTable.hpp"
typedef double Time;



class SimObj
{
public:
	static Time GetCurrentSimTime();

	static void RunSimulation();

	static void RunSimulation(Time endTime);

	Time GetEndTime();

protected:
	SimObj();

	void ScheduleEventIn(Time deltaTime, Event* ev);

	void ScheduleEventAt(Time time, Event* ev);

private:
	static Time _currentTime;

//	class EventSet;

	static HashTable _eventSet;

	static Time _endtime;

};

