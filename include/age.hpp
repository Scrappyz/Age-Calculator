#ifndef AGE_HPP_INCLUDED
#define AGE_HPP_INCLUDED

using namespace std;

class Age {
private:
    int years;
    int months;
    int days;
    int hours;
    int minutes;
    long long int seconds;

    bool leapyear(int);
    int daysOfMonth(int, int);
public:
    Age() : years(), months(), days(), hours(), minutes(), seconds() {}

    void setAge(const Date& past, const Date& present);
    void setAll(const Date& past, const Date& present);
    int setYears(const Date& past, const Date& present);
    int setMonths(const Date& past, const Date& present);
    int setDays(const Date& past, const Date& present);
    int setHours(const Date& past, const Date& present);
    int setMinutes(const Date& past, const Date& present);
    long long int setSeconds(const Date& past, const Date& present);

    void printAge();
};

#endif // AGE_HPP_INCLUDED
