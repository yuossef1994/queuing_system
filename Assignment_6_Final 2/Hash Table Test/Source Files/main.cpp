//
//  main.cpp
//  Hash_table_test
//
//  Created by Youssef Z on 4/28/22.
//
#include "HashTable.hpp"
#include "events_scheduled.hpp"
#include "events_in.hpp"




int main()
{
   /*

    HashTable table;
    table.insertItem(new Item());
    table.insertItem(new Item());
    table.insertItem(new Item());
    table.printTable();
    table.printHistogram();

    table.insertItem(new Item());
    table.insertItem(new Item());
    table.insertItem(new Item());
    table.insertItem(new Item());
    table.insertItem(new Item());
    table.insertItem(new Item());
    table.insertItem(new Item());
    table.insertItem(new Item());
    table.insertItem(new Item());
    table.insertItem(new Item());
    table.insertItem(new Item());
    table.insertItem(new Item());
    table.insertItem(new Item());
    table.insertItem(new Item());
    table.insertItem(new Item());
    table.insertItem(new Item());
    table.insertItem(new Item());
    table.insertItem(new Item());
    table.insertItem(new Item());
    table.insertItem(new Item());
    table.insertItem(new Item());
    table.insertItem(new Item());
    table.insertItem(new Item());
    table.printTable();
    table.printHistogram();

    Item * result = table.getItemByKey(3);
    cout << result->key << endl;
    */




    event_scheduled application;
    
    application.schedule_at(1.5, new events_in());
    application.schedule_at(1, new events_in());
    application.schedule_at(3.2, new events_in());
    application.schedule_at(2, new events_in());
    application.schedule_at(5, new events_in());
    
    SimObj::RunSimulation();
    
    
    
    

    
    
    
    return 0;
}
