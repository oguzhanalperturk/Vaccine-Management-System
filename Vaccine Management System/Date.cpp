#include "Date.h"
Date::Date() {
	day = 0;
	month = 0;
	year = 0;
	ch = '/';
}
Date::Date(int d, int m, int y) {
	ch = '/';
	if (d > 31) {
		day = 0;
	}
	else {
		day = d;
	}
	if (m > 12) {
		month = 0;
	}
	else {
		month = m;
	}
	year = y;
}
int Date::getday() {
	return day;
}
int Date::getmonth() {
	return month;
}
int Date::getyear() {
	return year;
}
void Date::setday(int d) {
	if (d > 31) {
		day = 0;
	}
	else {
		day = d;
	}
}
void Date::setmonth(int m) {
	if (m > 12) {
		month = 0;
	}
	else {
		month = m;
	}
}
void Date::setyear(int y) {
	year = y;
}
void Date::printdate() {
	cout << day << "/" << month << "/" << year;
}

