#include "main.hpp"
#include "time.hpp"

using namespace std;

int Time::getHour() const
{
    return hour;
}

int Time::getMinute() const
{
    return minute;
}

int Time::getSeconds() const
{
    return seconds;
}

void Time::printTime(bool military_time)
{
    string period = "am";
    int temp_hour = hour;
    int temp_minute = minute;
    int temp_seconds = seconds;
    if(!military_time) {
        if(temp_hour > 12) {
            temp_hour -= 12;
            period = "pm";
        }
        if(temp_hour == 0)
            temp_hour = 12;
    }

    if(temp_hour < 10)
        cout << "0";
    cout << temp_hour << ":";
    if(temp_minute < 10)
        cout << "0";
    cout << temp_minute << ":";
    if(temp_seconds < 10)
        cout << "0";
    cout << temp_seconds;
    if(!military_time)
        cout << " " << period;
    cout << endl;
}

void Time::parseTime(const string& str)
{
    stringstream ss(str);
    //cout << "STR TIME: " << str << endl;
    string period;
    char ch;
    int i = 1;
    while(ss.get(ch)) {
        if(ch >= '0' && ch <= '9') {
            ss.unget();
            switch(i) {
            case 1:
                ss >> hour;
                break;
            case 2:
                ss >> minute;
                break;
            case 3:
                ss >> seconds;
                break;
            default:
                break;
            }
            i++;
        } else if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            ss.unget();
            ss >> period;
            //cout << "Period: " << period << endl;
            if(period != "am" && period != "pm" && period != "AM" && period != "PM") {
                //cerr << "FALSE" << endl;
                period.clear();
            }
        }
    }
    if(!period.empty()) {
        evaluateTimePeriod(period);
    }
}

void Time::evaluateTimePeriod(const string& p)
{
    if(hour > 12)
        return;
    if((p == "pm" || p == "PM") && hour <= 12) {
        hour += 12;
        if(hour >= 24)
            hour = 24 - hour;
    }
}

bool Time::initialized() const
{
    if(hour == 0 && minute == 0 && seconds == 0)
        return false;
    return true;
}

bool Time::isValidTime() const
{
    if((hour >= 0 && hour < 24) && (minute >= 0 && minute < 60) && (seconds >= 0 && seconds < 60))
        return true;
    return false;
}

bool Time::operator<(const Time& present) const
{
    if(hour < present.hour)
        return true;
    if(hour == present.hour && minute < present.minute)
        return true;
    if(hour == present.hour && minute == present.minute && seconds < present.seconds)
        return true;
    return false;
}
