#ifndef Simulation0_h
#define Simulation0_h
using namespace std;

#include <vector>
#include <queue>
#include <list>


#include "Customer.h"
#include "Event.h"


class SIMULATION0
{
public:
	int CLOCK, luggage_number, security_number, free_luggage, free_security;
	bool Online, VIP;
	priority_queue<EVENT*, vector<EVENT*>, EventComp> myevents;
	list<CUSTOMER*> luggage_queue, security_queue;
	Record records;
	vector<CUSTOMER*>::iterator it;
	vector<CUSTOMER*>* arrivals;
public:
	SIMULATION0();
	SIMULATION0(bool _Online,bool _VIP, int _l, int _s, vector<CUSTOMER*>* arrival);
	~SIMULATION0();
	SIMULATION0(const SIMULATION0& sim);
	SIMULATION0 &operator=(const SIMULATION0& sim);
	SIMULATION0(SIMULATION0&& sim);
	SIMULATION0 &operator=(SIMULATION0&& sim);
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
