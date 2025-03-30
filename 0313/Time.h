#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

class Time
{
public:
    Time(int = 0, int = 0, int = 0);

    int setTime(int, int, int);
    int setTime(int);
    void showTime() const;

private:
    int hour;
    int minute;
    int second;
};

#endif
