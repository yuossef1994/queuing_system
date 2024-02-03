#include "SimObj.h"
#include <iostream>
#include "Distribution.h"
#include "Sink.h"
#include "SSSQ.h"
#include "Source.h"

using namespace std;

int main()
{
	double endTime = 0.0;
	
	Sink sink("Sink");

	SSSQ sssq("SSSQ", &sink, new Triangular(1, 3, 5));

	Source source("Source", &sssq, new Triangular(2, 3, 4));

	//Source source("Source", &sssq, new Triangular(2, 3, 4));

	SimObj::RunSimulation(100);							//runs the simulation until no events are left

	//SimObj::RunSimulation(endTime);					//runs the simulation to a specific end time

	//Display DES Performance Measures
	cout << "Total Entities Arrived in Queue: " << sssq.TotalEntitiesArrived() << endl;

	cout << "Total Entities Processed in Simulation: " << sink.TotalEntitiesProcessed() << endl;

	cout << "Average Delay in Queue (total delay / total entities that arrived in SSSQ): " << sssq.AverageDelayInQueue() << endl;

	cout << "Maximum Delay in Queue: " << sssq.MaxDelayInQueue() << endl;

	cout << "Average Flow Time: " << sink.AverageFlowTime() << endl;

	cout << "Max Flow Time: " << sink.MaxFlowTime() << endl;

	cout << "Total Service Time: " << sssq.TotalServiceTime() << endl;

	cout << "Server Utilization: " << ((sssq.TotalServiceTime() / ((endTime == 0.0) ? sink.GetEndTime() : endTime)) * 100.0) << "%" << endl;
    
//    SimObj::_eventSet.printTable();
    
		
	return 1;
}
