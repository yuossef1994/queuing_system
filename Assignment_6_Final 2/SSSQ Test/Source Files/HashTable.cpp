//
//  HashTable.cpp
//  Hash_table_test
//
//  Created by Youssef Z on 4/28/22.
//

#include "HashTable.hpp"


int HashTable::hash(int itemKey)
{
    //generate keys here
    
    return (itemKey) % _length;
}

HashTable::HashTable(int tableLength)
{
    if (tableLength <= 0) tableLength = 13;
    _array = new LinkedList[tableLength];
    _length = tableLength;
    
    
    
    _first_item = nullptr;
   
}



bool HashTable::removeItem(int itemKey)
{
    int index = hash(itemKey);
    return _array[index].removeItem(itemKey);
}

Item * HashTable::getItemByKey(int itemKey)
{
    int index = hash(itemKey);
    return _array[index].getItem(itemKey);
}

void HashTable::printTable()
{
    cout << "\n\nHash Table:\n";
    for (int i = 0; i < _length; i++)
    {
        cout << "Bucket " << i + 1 << "; ";
        _array[i].printList();
    }
}

void HashTable::printHistogram()
{
    cout << "\n\nHash Table Contains ";
    cout << getNumberOfItems() << " Items total\n";
    for (int i = 0; i < _length; i++)
    {
        cout << i + 1 << ":\t";
        for (int j = 0; j < _array[i].getLength(); j++)
            cout << " X";
        cout << "\n";
    }
}

int HashTable::getLength()
{
    return _length;
}

int HashTable::getNumberOfItems()
{
    int itemCount = 0;
    for (int i = 0; i < _length; i++)
    {
        itemCount += _array[i].getLength();
    }
    return itemCount;
}
void HashTable::AddEvent(Time time, Event* ev)
{
    //create a new eventnode
    //test to see if first event
    //test to see if the new event is before the first event in the set
    //place the new event in the proper time order
    //using the next event key to keep track of events order
    Item* newItem = new Item();
    newItem->key= _key_counter;
    newItem->time=time;
    newItem->ev=ev;
    newItem->next=NULL;
    newItem->next_key=-1; //intializing next item key
    int index = hash(newItem->key);
    _array[index].insertItem(newItem);

    if (_first_item == nullptr)
    {
        _first_item = newItem;
    }
    else if (time < _first_item->time)
    {
        
        
        newItem->next_key = _first_item->key;
        
        _first_item = newItem;
    }
    else
    {
      
        
        Item* current = newItem; 
      
        for (int i=0; (_key_counter);i++)
            
        {
           
            if (getItemByKey(i)->next_key==-1)
            {
                
                getItemByKey(i)->next_key=current->key;
                break;
                
            }
            
            
           else if ( ((current->time)>getItemByKey(i)->time)&&((current->time)<getItemByKey(getItemByKey(i)->next_key)->time))
                
            {
                current->next_key=getItemByKey(getItemByKey(i)->next_key)->key;
                getItemByKey(i)->next_key=current->key;
                break;
               
            }
            
            
           
            
        }
                
            
       
        newItem = current;
       
    }
    
    _key_counter++;
}

Event* HashTable::GetEvent()
{
    //get pointer to first event in the event set
    //remove that event to use it and update the event set head pointer
   
    Event* ev = _first_item->ev;

    if (_first_item->next_key==-1)
    {
        _first_item=nullptr;
    }
    else
    {
    _first_item = getItemByKey(_first_item->next_key);
    }
        
    return ev;
}

Time HashTable::GetTime()
{
    //return the time of the next event in the event set
    return _first_item->time;
}

bool HashTable::HasEvent()
{
    //return true if there are events left in the event set
    return (_first_item != nullptr);
}
