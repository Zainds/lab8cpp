#include <string> 
#include <iostream>
#include <vector>
#include "MagicEnum.h"
using namespace std;

enum class Day { Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday };

class MyTime
{
private:
    int hourTime;
    int minuteTime;
    int secondTime;
    Day curDay;

public:
    MyTime() {};
    MyTime(int h, int m, int s, Day d) {
        try {
            if (s < 0 || s > 59 || m < 0 || m > 59 || h < 0 || h > 23) {
                throw string{ "IncorrectTimeException" };
            }

            hourTime = h;
            minuteTime = m;
            secondTime = s;
            curDay = d;
        }

        catch (string& ex) {
            cout << ex;
            exit(EXIT_FAILURE);
        }
    }

    int GetAllInSeconds() {
        return hourTime * 60 * 60 + minuteTime * 60 + secondTime;
    }
    void Add5Seconds() {
        secondTime += 5;
        if (secondTime >= 60) {
            minuteTime += 1;
            secondTime -= 60;
            if (minuteTime >= 60) {
                hourTime += 1;
                minuteTime -= 60;
                if (hourTime >= 24)
                {
                    hourTime = 0;

                }
            }
        }
    }
    void SetHours(int hours) {
        hourTime = hours;
    }
    void SetMinutes(int minutes) {
        minuteTime = minutes;
    }
    void SetSeconds(int Seconds) {
        secondTime = Seconds;
    }

    int GetHours() const {
        return hourTime;
    }

    int GetMinutes() const {
        return minuteTime;
    }

    int GetSeconds() const {
        return secondTime;
    }
    auto getDay() const {
        return magic_enum::enum_name(curDay);
    }
    void PrintTime() {
        string h, m, s, d;
        if (hourTime < 10) {
            h = "0" + to_string(hourTime);
        }
        else {
            h = "" + to_string(hourTime);
        }
        if (minuteTime < 10) {
            m = "0" + to_string(minuteTime);
        }
        else {
            m = "" + to_string(minuteTime);
        }
        if (secondTime < 10) {
            s = "0" + to_string(secondTime);
        }
        else {
            s = "" + to_string(secondTime);
        }
        
        d = magic_enum::enum_name(curDay);
        
        cout << h << ":" << m << ":" << s << " " << d << endl;
        
    }

};
int main()
{
    setlocale(LC_ALL, "");
    vector<MyTime> times = { MyTime(22, 50, 11, Day::Tuesday), MyTime(20, 44, 10, Day::Thursday) ,
        MyTime(05, 20, 04, Day::Monday) , MyTime(11, 25, 16, Day::Wednesday) };
    
    for (MyTime it : times) {
        if (it.getDay() == "Monday") it.PrintTime();
    }
    
}