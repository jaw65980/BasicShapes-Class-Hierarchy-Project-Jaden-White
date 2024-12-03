#pragma once
#include <string>
using std::string;

class Dates
{
public:
	void Datefunct();
private:
	string input;
	int month = 1;
	int date = 1;
	int year = 1930;
	float testyear;
	string Monthlist[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	int DaysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int leapyear = false;
	int TotalDays;

	void DateInput();
	void DateResults();
	void Leapyear();
	void MonthDayCount();
	void DateAddPost();
	void DateAddPre();
	void DateSubPost();
	void DateSubPre();
	void DateCompare();
};

