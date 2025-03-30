#include "Time.h"
#include <iostream>
#include <iomanip>

using namespace std;

Time::Time(int hour, int minute, int second)
{
    setTime(hour, minute, second);
    cout << "Initial Time is: ";
    showTime();
    cout << endl;
}

int Time::setTime(int hour, int minute, int second)
{
    if (hour < 0 || hour > 23 || minute < 0 || minute > 59 || second < 0 || second > 59 )
    {
        return 0;
    }

    this->hour = hour;
    this->minute = minute;
    this->second = second;

    return 1;
}

int Time::setTime(int seconds)
{
    if (seconds == -1) return -1;
    if (seconds < 0 || seconds >= 86400)
    {
        return 0;
    }

    this->hour = seconds / 3600;
    seconds %= 3600;
    this->minute = seconds / 60;
    this->second = seconds %= 60;

    return 1;
}

void Time::showTime() const
{
    char meridiem;
    if (hour >= 0 && hour < 12)
    {
        meridiem = 'A';
    }
    else
    {
        meridiem = 'P';
    }
    cout << setfill('0') << setw(2) << hour << ':';
    cout << setfill('0') << setw(2) << minute << ':';
    cout << setfill('0') << setw(2) << second << ' ';
    cout << meridiem << 'M';
}