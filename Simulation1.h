#ifndef Simulation1_h
#define Simulation1_h
using namespace std;

#include <vector>
#include <queue>


#include "Customer.h"
#include "Event.h"

class QueueComp
{
public:
	bool operator() (CUSTOMER*& c1,CUSTOMER*& c2) {
		if (c1->GetFlightTime() > c2->GetFlightTime()) {
			return true;
		}
		else if (c1->GetFlightTime() == c2->GetFlightTime()) {
			if (c1->GetArrivalTime() > c2->GetArrivalTime())
				return true;
		}
		return false;
	}
};


class SIMULATION1
{
public:
	int CLOCK, luggage_number, security_number, free_luggage, free_security;
	bool Online, VIP;
	priority_queue<EVENT*, vector<EVENT*>, EventComp> myevents;
	priority_queue<CUSTOMER*, vector<CUSTOMER*>, QueueComp> luggage_queue, security_queue;
	Record records;
	vector<CUSTOMER*>::iterator it;
	vector<CUSTOMER*>* arrivals;
public:
	SIMULATION1();
	SIMULATION1(bool _Online, bool _VIP, int _l, int _s, vector<CUSTOMER*>* arrival);
	~SIMULATION1();
	SIMULATION1(const SIMULATION1& sim);
	SIMULATION1 &operator=(const SIMULATION1& sim);
	SIMULATION1(SIMULATION1&& sim);
	SIMULATION1 &operator=(SIMULATION1&& sim);
	void Start();
	Record Results();
	void ScheduleNextArrival();
	void NextEvent();
	void MoveToLuggageQueue(CUSTOMER*& c, const int& time);
	void MoveToSecurityQueue(CUSTOMER*& c, const int& time);
	void EnterRecords(CUSTOMER*& c, const int& time);
	void CallLuggageCustomer();
	void CallSecurityCustomer();
};




#endif // !Simulation.h

