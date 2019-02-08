#include "Event.h"
#include "Simulation0.h"
#include "Simulation1.h"

EVENT::EVENT()
{
	time = type = 0;
	cust = nullptr;
}

EVENT::EVENT(int& _time,int _type,CUSTOMER *& c) : time(_time), type(_type), cust(c)
{
}


EVENT::~EVENT()
{
}

EVENT::EVENT(const EVENT & e)
{
	time = e.time;
	type = e.type;
	cust = e.cust;
}

EVENT & EVENT::operator=(const EVENT & e)
{
	time = e.time;
	type = e.type;
	cust = e.cust;
	return *this;
}

EVENT::EVENT(EVENT && e)
{
	time = e.time;
	type = e.type;
	cust = e.cust;
	e.time = 0;
	e.type = 0;
	e.cust = nullptr;

}

EVENT & EVENT::operator=(EVENT && e)
{
	time = e.time;
	type = e.type;
	cust = e.cust;
	e.time = 0;
	e.type = 0;
	e.cust = nullptr;
	return *this;
}


int EVENT::GetTime() const
{
	return time;
}

int EVENT::GetType() const
{
	return type;
}

CUSTOMER * EVENT::GetCustomer() const
{
	return cust;
}

void EVENT::Happen(SIMULATION0 * s)
{
	if (type == 0) {
		s->MoveToLuggageQueue(cust,time);
		s->ScheduleNextArrival();
		return;
	}
	else if (type == 1) {
		s->MoveToSecurityQueue(cust,time);
		s->CallLuggageCustomer();
		return;
	}
	else {
		s->EnterRecords(cust,time);
		s->CallSecurityCustomer();
		return;
	}
}

void EVENT::Happen(SIMULATION1 * s)
{
	if (type == 0) {
		s->MoveToLuggageQueue(cust,time);
		s->ScheduleNextArrival();
		return;
	}
	else if (type == 1) {
		s->MoveToSecurityQueue(cust, time);
		s->CallLuggageCustomer();
		return;
	}
	else {
		s->EnterRecords(cust, time);
		s->CallSecurityCustomer();
		return;
	}
}



