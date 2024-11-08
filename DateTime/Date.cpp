#include <iostream>
#include <cstring>
#include "Date.h"
#pragma warning(disable:4996)
using namespace std;

void Date::setDay(int day) {
	if (day >= 1 && day <= 30) {
		this->day = day;
	}
}

void Date::setMonth(int month) {
	if (month >= 1 && month <= 12) {
		this->month = month;
	}
}

void Date::setYear(int year) {
	this->year = year;
}

Date::Date(int day, int month, int year) {
	setDay(day);
	setMonth(month);
	setYear(year);
}

Date::Date() {
	Date(25, 9, 2024);
}

ostream& operator<<(ostream& os, const Date& date) {
	os << date.day << "/" << date.month << "/" << date.year;
	return os;
}

bool Date::operator>(const Date& date)const {
	if (year < date.year) {
		return true;
	}
	else if (year > date.year) {
		return false;
	}
	if (month < date.month) {
		return true;
	}
	else if (month > date.month) {
		return false;
	}
	if (day < date.day) {
		return true;
	}
	return false;
}

bool Date::operator<(const Date& date)const {
	if (year > date.year) {
		return true;
	}
	else if (year < date.year) {
		return false;
	}
	if (month > date.month) {
		return true;
	}
	else if (month < date.month) {
		return false;
	}
	if (day > date.day) {
		return true;
	}
	return false;
}

bool Date::operator==(const Date& date)const {
	if (year == date.year && month == date.month && day == date.day) {
		return true;
	}
	return false;
}