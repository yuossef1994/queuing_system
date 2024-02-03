#include "Sink.h"
#include "SimObj.h"
#include <iostream>

using namespace std;

Sink::Sink(std::string name)
{
	_name = name;
	_totalEntitiesProcessed = 0;
	_totalFlowTime = 0;
	_maxFlowTime = 0;
	_flowTime = 0;
}

void Sink::Depart(Entity * en)
{
	cout << SimObj::GetCurrentSimTime() << ", Sink " << _name << ", Depart, Entity " << en->GetID() << endl;
	cout << "Entity " << en->GetID() << " Arrival Time: " << en->getArrivalTime() << ", Service Start Time: " << en->getServiceStartTime() <<
		", Departure Time: " << en->getDepartureTime() << endl;

	//count the total entities completing the process
	_totalEntitiesProcessed += 1;

	//compute total flow time for this entity
	_flowTime = en->getDepartureTime() - en->getArrivalTime();
	_totalFlowTime += _flowTime;

	//compute max flow time
	if (_flowTime > _maxFlowTime)
	{
		_maxFlowTime = _flowTime;
	}

	_endTime = en->getDepartureTime();
}

int Sink::TotalEntitiesProcessed()
{
	return _totalEntitiesProcessed;
}

Time Sink::AverageFlowTime()
{
	return _totalFlowTime / _totalEntitiesProcessed;
}

Time Sink::MaxFlowTime()
{
	return _maxFlowTime;
}

Time Sink::GetEndTime()
{
	return _endTime;
}