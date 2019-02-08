#ifndef Customer_h
#define Customer_h

#include <iostream>
using namespace std;

struct Record
{
	long double waiting_time;
	int missed_flight;
};

class CUSTOMER
{
	int a_time, f_time, l_time, s_time;
	bool luggage, vip;
public:
	CUSTOMER();
	CUSTOMER(int& a, int& f, int& l, int& s, bool& lug, bool& v);
	~CUSTOMER();
	CUSTOMER(const CUSTOMER& c);
	CUSTOMER &operator=(const CUSTOMER& c);
	CUSTOMER(CUSTOMER&& c);
	CUSTOMER &operator=(CUSTOMER&& c);
	int GetFlightTime() const;
	int GetArrivalTime() const;
	int GetLuggageTime() const;
	int GetSecurityTime() const;
	bool IsVIP() const;
	bool IsOnline() const;

};
#endif // !Customer_h

