#pragma once
#include <iostream>
using std::cout;
using std::cin;

class Date
{
public:
	int day;
	int month;
	int year;
	char ch;
	Date();
	Date(int, int, int);
	int getday();
	int getmonth();
	int getyear();
	void setday(int d);
	void setmonth(int m);
	void setyear(int y);
	void printdate();
};

