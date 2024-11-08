#ifndef __DATE_H
#define __DATE_H
#include <iostream>

class Date {
	int day;
	int month;
	int year;

public:
	int getDay() const { return day; }
	int getMonth() const { return month; }
	int getYear() const { return year; }
	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);
	Date(int day, int month, int year);
	Date();
	friend std::ostream& operator<<(std::ostream& os, const Date& date);
	bool operator>(const Date& date) const;
	bool operator<(const Date& date) const;
	bool operator==(const Date& date) const;
};
#endif