#include "SimObj.h"


Time SimObj::GetCurrentSimTime()
{
	//return the current simulation time
	return SimObj::_currentTime;
}

void SimObj::RunSimulation()
{
    
    Event* ev;
    while (_eventSet.HasEvent()==true)
    {
        
        //setting current sim time to event time
        _currentTime = _eventSet.GetTime();
       //get the event
       ev= _eventSet.GetEvent();
        
       //send event to application for execution
        ev->Execute();
        
        
        
    }
    
    
    
}

void SimObj::RunSimulation(Time endTime)
{
    //check if there's still events left and next event time doesn't exceed the end time
    while ( (_eventSet.HasEvent()==true) && (_eventSet.GetTime() <= endTime))
    {
        
        Event* ev;
        //setting current sim time to event time
        _currentTime = _eventSet.GetTime();
       //get the event
       ev= _eventSet.GetEvent();
        
       //send event to application for execution
       ev->Execute();
        
        
        
    }
    
    
    
    
}

Time SimObj::_currentTime = 0.0;
HashTable SimObj::_eventSet(10); //instantiates the event set

SimObj::SimObj()
{
}

void SimObj::ScheduleEventIn(Time deltaTime, Event* ev)
{
	//add the event to the event set at the appropriate time
	_eventSet.AddEvent(_currentTime + deltaTime, ev);
}

void SimObj::ScheduleEventAt(Time time, Event* ev)
{
	//add the event to the event set at the appropriate time
	_eventSet.AddEvent(time, ev);
}
