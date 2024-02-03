//
//  events_in.hpp
//  assignment_4
//
//  Created by Youssef Z on 3/28/22.
//sub class of events class

#ifndef events_in_hpp
#define events_in_hpp

#include <stdio.h>
#include "Event.h"

class events_in : public Event

{
    
public:
    
    //virtual function implementation
    void Execute();
    
    
    
};
#endif /* events_in_hpp */
