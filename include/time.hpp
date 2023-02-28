#ifndef TIME_HPP_INCLUDED
#define TIME_HPP_INCLUDED

using namespace std;

class Time {
private:
    int hour;
    int minute;
    int seconds;
public:
    Time() : hour(), minute(), seconds() {}
    Time(const Time& t) : hour(t.hour), minute(t.minute), seconds(t.seconds) {}
    Time(int h, int m, int s) : hour(h), minute(m), seconds(s) {}

    int getHour() const;
    int getMinute() const;
    int getSeconds() const;

    void parseTime(const string&);
    void evaluateTimePeriod(const string&);
    void printTime(bool = false);
    bool initialized() const;
    bool isValidTime() const;
    bool operator<(const Time& present) const;
};

#endif // TIME_HPP_INCLUDED
