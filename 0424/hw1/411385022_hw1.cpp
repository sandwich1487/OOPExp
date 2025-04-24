#include <iostream>
#include <tgmath.h>

using namespace std;

int CalculateAngle(int hr, int min)
{
    hr %= 12;
    double angle_hr = hr * 30 + min / 2.0;
    double angle_min = min * 6;
    double result = abs(angle_hr - angle_min);
    result = result > 180 ? 360 - result : result;
    result = round(result);
    return (int)result;
}

int main()
{
    int hour = 0;
    int minute = 0;

    while (true)
    {
        cin >> hour;
        if (hour == -1) break;
        cin >> minute;
        if (minute == -1) break;
        cout << CalculateAngle(hour, minute) << endl;
        cout << endl;
    }
    

    return 0;
}