// 1feb_structDate.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>

using namespace std;

struct Date {
	int day;
	int month;
	int year;
	Date()
	{
		SYSTEMTIME dt;
		GetLocalTime(&dt);
		day = dt.wDay;
		month = dt.wMonth;
		year = dt.wYear;
	}
	Date(int Day) 
	{
		SYSTEMTIME dt;
		GetLocalTime(&dt);
		day = Day;
		month = dt.wMonth;
		year = dt.wYear;
	}
	Date(int Day, int Month)
	{
		SYSTEMTIME dt;
		GetLocalTime(&dt);
		day = Day;
		month = Month;
		year = dt.wYear;
	}
	Date(int Day, int Month, int Year)
	{
		SYSTEMTIME dt;
		GetLocalTime(&dt);
		day = Day;
		month = Month;
		year = Year;
	}
	void add_day()
	{
		if (day == 30) {
			day = 1;
			if (month == 12) {
				year++;
				month = 1;
			}
			else {
				month++;
			}
		}
		else {
			day++;
		}
	}
	void print_data()
	{
		cout << day << "/" << month << "/" << year << endl;
	}
};

int main()
{
	Date myDay;
	myDay.print_data();
	myDay.add_day();
	myDay.print_data();
    return 0;
}

