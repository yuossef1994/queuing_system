//
//  events_scheduled.hpp
//  assignment_4
//
//  Created by Youssef Z on 3/28/22.
//subclass of simobj class

#ifndef events_scheduled_hpp
#define events_scheduled_hpp

#include <stdio.h>
#include "SimObj.h"

#include "events_in.hpp"

class event_scheduled : public SimObj

{
public:

    event_scheduled(){};
    void schedule_at(Time time, events_in* ev);
    
 
    
private:
    
    events_in* ev1;

    
    
    
    
    


};








#endif /* events_scheduled_hpp */
