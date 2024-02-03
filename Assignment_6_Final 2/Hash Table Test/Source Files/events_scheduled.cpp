//
//  events_scheduled.cpp
//  assignment_4
//
//  Created by Youssef Z on 3/28/22.
//

#include "events_scheduled.hpp"

#include "SimObj.h"
#include <iostream>
using namespace std;

//function to scheduale events
void event_scheduled::schedule_at(Time time, events_in* ev)
{
    
    ev1=ev;
    ScheduleEventAt(time, ev1);
    
    
}



