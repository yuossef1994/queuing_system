//
//  HashTable.hpp
//  Hash_table_test
//
//  Created by Youssef Z on 4/28/22.
//
//Hash table to hold events with their associated time
#ifndef HashTable_hpp
#define HashTable_hpp

#include <stdio.h>
#include "LinkedList.h"

class HashTable
{
private:
    LinkedList *_array;
    int _length;
    int hash(int itemKey); // key is an integer generated automatically at each event addition
    int _key_counter=0 ; // counter for the number of keys, starts at zero and increase with each event that's added
   
    Item* _first_item; //item variable corresponds to event node that holds the event and it's time
 
    
public:
    HashTable(int tableLength = 13);
    bool removeItem(int itemKey);
    Item *getItemByKey(int itemKey);
    void printTable();
    void printHistogram();
    int getLength();
    int getNumberOfItems();
    void AddEvent(Time time, Event* ev); // adding events
    Event* GetEvent(); //getting events to excute
    Time GetTime(); //getting simulation time
    bool HasEvent(); //checking if there's anymore events
};

#endif /* HashTable_hpp */
