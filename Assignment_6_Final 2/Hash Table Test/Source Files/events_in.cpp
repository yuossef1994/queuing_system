//
//  events_in.cpp
//  assignment_4
//
//  Created by Youssef Z on 3/28/22.
//sub class of events class

#include "events_in.hpp"
#include "Event.h"
#include "events_scheduled.hpp"
#include <iostream>
using namespace std;

void events_in::Execute(){
    
    //event execution that shows what time the event is scheduled at
    cout<<" I am scheduled at time  "<<event_scheduled::GetCurrentSimTime()<<endl;
    
}




