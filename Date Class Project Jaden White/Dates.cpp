#include "Dates.h"
#include <iostream>
#include <iomanip>
using namespace std;

    void Dates::Datefunct()
    {
        cout << "Type Tomorrow to see tomorrow's date." << endl << "Type Set to set the date." << endl << "Type Yesterday to see yesterday's date." << endl << "Type Compare to compare two dates." << endl;
        cin >> input;
        if (input == "Tomorrow")
        {
            cout << "Type Pre to pre-increment and Post to post-increment." << endl;
            cin >> input;
            if (input == "Pre")
            {
                DateAddPre();
            }
            if (input == "Post")
            {
                DateAddPost();
            }
        }
        if (input == "Set")
        {
            DateInput();
        }
        if (input == "Yesterday")
        {
            cout << "Type Pre to pre-decrement and Post to post-decrement." << endl;
            cin >> input;
            if (input == "Pre")
            {
                DateSubPre();
            }
            if (input == "Post")
            {
                DateSubPost();
            }
        }
        if (input == "Compare")
        {
            DateCompare();
        }
        DateResults();
        MonthDayCount();
        cout << endl;
        Datefunct();
    }

    string input;
    int month = 1;
    int date = 1;
    int year = 1930;
    float testyear;
    string Monthlist[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
    int DaysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int leapyear = false;
    int TotalDays;

    void Dates::DateInput()
    {
        cout << endl;
        cout << "Set valid month (number). ";
        cin >> month;
        cout << "Set a valid date. ";
        cin >> date;
        cout << "Set a year. ";
        cin >> year;
        testyear = year;
        Leapyear();
        if (month < 1 || month > 12)
        {
            cout << "This input is invalid." << endl;
            Datefunct();
        }
        if (leapyear == true && month == 2 && date == 29)
        {
            DateResults();
            MonthDayCount();
            cout << endl;
            Datefunct();
        }
        if (date < 1 || date > DaysInMonth[month - 1])
        {
            cout << "This input is invalid." << endl << endl;
            Datefunct();
        }

    }

    void Dates::DateResults()
    {
        cout << endl;
        cout << month << "/" << date << "/" << year << endl;
        cout << Monthlist[month - 1] << " " << date << ", " << year << endl;
        cout << date << " " << Monthlist[month - 1] << " " << year << endl;
        Leapyear();
        if (leapyear == true)
        {
            cout << "This year is a leap year." << endl;
        }
        if (leapyear == false)
        {
            cout << "This year is not a leap year." << endl;
        }
    }

    void Dates::Leapyear()
    {
        float leaptest;
        int yearvalue;

        leaptest = testyear / 4;
        yearvalue = testyear / 4;

        if (leaptest == yearvalue)
        {

            leapyear = true;
        }
        else
        {
            leapyear = false;
        }
    }

    void Dates::MonthDayCount()
    {
        TotalDays = 0;

        if (leapyear == true && month == 2)
        {
            cout << "Days this month: " << 29 << endl;
        }
        else
        {
            cout << "Days this month: " << DaysInMonth[month - 1] << endl;
        }

        for (int i = 0; i < (month - 1); i++)
        {
            TotalDays = DaysInMonth[i] + TotalDays;
        }
        TotalDays = date + TotalDays;
        if (leapyear == true && month > 2)
        {
            TotalDays++;
        }
        cout << "Total days: " << TotalDays << endl;
    }

    void Dates::DateAddPost()
    {
        Leapyear();
        date++;
        bool lept = false;
        if (leapyear == true && month == 2 && date == 29)
        {
            date = 29;
            month = 2;
            lept = true;
        }
        if (date > DaysInMonth[month - 1] && lept == false)
        {
            if (month == 12)
            {
                year++;
                month = 0;
            }
            date = 1;
            month++;
        }
        lept = false;
    }

    void Dates::DateAddPre()
    {
        Leapyear();
        ++date;
        bool lept = false;
        if (leapyear == true && month == 2 && date == 29)
        {
            date = 29;
            month = 2;
            lept = true;
        }
        if (date > DaysInMonth[month - 1] && lept == false)
        {
            if (month == 12)
            {
                ++year;
                month = 0;
            }
            date = 1;
            ++month;
        }
        lept = false;
    }

    void Dates::DateSubPost()
    {
        date--;
        if (date < 1)
        {
            month--;
            if (month < 1)
            {
                month = 12;
                year--;
            }
            date = DaysInMonth[month - 1];
        }
    }

    void Dates::DateSubPre()
    {
        --date;
        if (date < 1)
        {
            --month;
            if (month < 1)
            {
                month = 12;
                --year;
            }
            date = DaysInMonth[month - 1];
        }
    }

    void Dates::DateCompare()
    {
        cout << endl;
        int CompareDateOne;
        int CompareDateTwo;
        int CompareDayTotal;
        int YearOne;
        int YearTwo;
        int YearTotal;
        float LeapYearTest;
        int LeapYearYear;
        int YearDif;
        bool compareleap;

        DateInput();
        leapyear = false;
        MonthDayCount();
        CompareDateOne = TotalDays;
        YearOne = year;
        DateInput();
        leapyear = false;
        MonthDayCount();
        CompareDateTwo = TotalDays;
        YearTwo = year;
        CompareDayTotal = CompareDateOne - CompareDateTwo;
        YearDif = abs(YearOne - YearTwo);
        YearTotal = 365 * YearDif;
        int CompareTotal = abs(CompareDayTotal + YearTotal);

        for (int i = 0; i < YearDif; i++)
        {
            LeapYearTest = YearOne;
            LeapYearYear = YearOne;
            LeapYearTest = LeapYearTest / 4;
            LeapYearYear = LeapYearYear / 4;
            if (LeapYearTest == LeapYearYear)
            {
                CompareTotal++;
            }
            YearOne++;
        }
        cout << endl << "Between these two dates, there are " << CompareTotal << " days." << endl;
    };