#ifndef Event_h
#define Event_h

#include "Customer.h"

class SIMULATION0;
class SIMULATION1;


class EVENT
{
	int time, type;
	CUSTOMER* cust;
public:
	EVENT();
	EVENT(int& _time,int _type,CUSTOMER*& c);
	~EVENT();
	EVENT(const EVENT& e);
	EVENT &operator=(const EVENT& e);
	EVENT(EVENT&& e);
	EVENT &operator=(EVENT&& e);
	int GetTime() const;
	int GetType() const;
	CUSTOMER* GetCustomer() const;
	void Happen(SIMULATION0* s);
	void Happen(SIMULATION1* s);
};

class EventComp
{
public:
	bool operator() (EVENT*& e1,EVENT*& e2)
	{
		if (e1->GetTime() > e2->GetTime()) {
			return true;
		}
		else if (e1->GetTime() == e2->GetTime()) {
			if (e1->GetType() < e2->GetType())
				return true;
			else if (e1->GetType() == e2->GetType())
				if (e1->GetCustomer()->GetArrivalTime() > e2->GetCustomer()->GetArrivalTime())
					return true;
		}
		return false;
	}
};

#endif // !Event_h

