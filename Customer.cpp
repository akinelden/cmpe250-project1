#include "Customer.h"

CUSTOMER::CUSTOMER() : a_time(0), f_time(0), l_time(0), s_time(0), luggage(0), vip(0)
{
}

CUSTOMER::CUSTOMER(int& a, int &f, int& l, int& s, bool& lug, bool& v) : a_time(a),f_time(f),l_time(l),s_time(s),luggage(lug),vip(v)
{
}

CUSTOMER::~CUSTOMER()
{
}

CUSTOMER::CUSTOMER(const CUSTOMER & c)
{
	a_time = c.a_time;
	f_time = c.f_time;
	l_time = c.l_time;
	s_time = c.s_time;
	luggage = c.luggage;
	vip = c.vip;
}

CUSTOMER & CUSTOMER::operator=(const CUSTOMER & c)
{
	a_time = c.a_time;
	f_time = c.f_time;
	l_time = c.l_time;
	s_time = c.s_time;
	luggage = c.luggage;
	vip = c.vip;
	return *this;
}

CUSTOMER::CUSTOMER(CUSTOMER && c)
{
	a_time = move(c.a_time);
	f_time = move(c.f_time);
	l_time = move(c.l_time);
	s_time = move(c.s_time);
	luggage = move(c.luggage);
	vip = move(c.vip);
	c.a_time = 0;
	c.f_time = 0;
	c.l_time = 0;
	c.s_time = 0;
	c.luggage = 0;
	c.vip = 0;
}

CUSTOMER & CUSTOMER::operator=(CUSTOMER && c)
{
	a_time = move(c.a_time);
	f_time = move(c.f_time);
	l_time = move(c.l_time);
	s_time = move(c.s_time);
	luggage = move(c.luggage);
	vip = move(c.vip);
	c.a_time = 0;
	c.f_time = 0;
	c.l_time = 0;
	c.s_time = 0;
	c.luggage = 0;
	c.vip = 0;
	return *this;
}

int CUSTOMER::GetFlightTime() const
{
	return f_time;
}

int CUSTOMER::GetArrivalTime() const
{ 
	return a_time;
}

int CUSTOMER::GetLuggageTime() const
{
	return l_time;
}

int CUSTOMER::GetSecurityTime() const
{
	return s_time;
}

bool CUSTOMER::IsVIP() const
{
	return vip;
}

bool CUSTOMER::IsOnline() const
{
	return !luggage;
}

