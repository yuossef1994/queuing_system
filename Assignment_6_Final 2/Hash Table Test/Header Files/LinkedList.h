#pragma once

#include <iostream>
#include <string>
#include "Event.h"
typedef double Time;
using namespace std;

struct Item
{
    int key;
    Item* next;
    Event* ev;
    Time time;
    
    int next_key;
    
};

class LinkedList
{
private:
    Item *_head;
    int _length;

public:
    LinkedList();
    void insertItem(Item *newItem);
    bool removeItem(int itemKey);
    Item *getItem(int itemKey);
    void printList();
    int getLength();
};
