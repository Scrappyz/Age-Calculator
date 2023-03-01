#include "main.hpp"
#include "time.hpp"
#include "date.hpp"
#include "age.hpp"

using namespace std;

void Age::printAge()
{
    if(!Main::hasFlags()) {
        cout << "You are " << years << " years, " << months << " months, " << days << " days old..." << endl;
        return;
    } else if(Main::getFlag("-a") || Main::getFlag("--all")) {
        cout << "You are " << years << " years, " << months << " months, " << days << " days, "
        << hours << " hours, " << minutes << " minutes, " << seconds << " seconds old..." << endl;
    } else if(Main::getFlag("-y") || Main::getFlag("--years")) {
        cout << "You are " << years << " years old..." << endl;
    } else if(Main::getFlag("-m") || Main::getFlag("--months")) {
        cout << "You are " << months << " months old..." << endl;
    } else if(Main::getFlag("-d") || Main::getFlag("--days")) {
        cout << "You are " << days << " days old..." << endl;
    } else if(Main::getFlag("-hh") || Main::getFlag("--hours")) {
        cout << "You are " << hours << " hours old..." << endl;
    } else if(Main::getFlag("-mm") || Main::getFlag("--minutes")) {
        cout << "You are " << minutes << " minutes old..." << endl;
    } else if(Main::getFlag("-s") || Main::getFlag("--seconds")) {
        cout << "You are " << seconds << " seconds old..." << endl;
    }
}

void Age::setAge(const Date& past, const Date& present)
{
    if(Main::getFlag("-a") || Main::getFlag("--all") || !Main::hasFlags()) {
        setAll(past, present);
    } else if(Main::getFlag("-y") || Main::getFlag("--years")) {
        years = setYears(past, present);
    } else if(Main::getFlag("-m") || Main::getFlag("--months")) {
        months = setMonths(past, present);
    } else if(Main::getFlag("-d") || Main::getFlag("--days")) {
        days = setDays(past, present);
    } else if(Main::getFlag("-hh") || Main::getFlag("--hours")) {
        hours = setHours(past, present);
    } else if(Main::getFlag("-mm") || Main::getFlag("--minutes")) {
        minutes = setMinutes(past, present);
    } else if(Main::getFlag("-s") || Main::getFlag("--seconds")) {
        seconds = setSeconds(past, present);
    }
}

void Age::setAll(const Date& past, const Date& present) // Formula: if past <= present, present - past
{                                                       //          if past > present, (max - past) + present
    years = present.getYear() - past.getYear();
    if(past.getMonth().num > present.getMonth().num || (present.getMonth().num == past.getMonth().num && past.getDay() > present.getDay()))
        years--;

    int present_m = present.getMonth().num;
    int past_m = past.getMonth().num;
    int month_counter;
    for(month_counter = 0; past_m != present_m; month_counter++) {
        if(past_m >= 12)
            past_m = 0;
        past_m++;
    }
    months = month_counter;

    int present_d = present.getDay();
    int past_d = past.getDay();
    int day_counter;
    if(past.getDay() > present.getDay())
        months--;
    for(day_counter = 0; past_d != present_d; day_counter++) {
        if(past_d >= present.daysOfMonth(past_m))
            past_d = 0;
        past_d++;
    }
    days = day_counter;

    Time present_t = present.getTime();
    Time past_t = past.getTime();
    if(present_t.isValidTime() && past_t.isValidTime()) {
        int present_h = present_t.getHour();
        int past_h = past_t.getHour();
        int hour_counter;
        if(past_h > present_h)
            days--;
        for(hour_counter = 0; past_h != present_h; hour_counter++) {
            if(past_h >= 23)
                past_h = -1;
            past_h++;
        }
        hours = hour_counter;

        int present_min = present_t.getMinute();
        int past_min = past_t.getMinute();
        int minute_counter;
        if(past_min > present_min)
            hours--;
        for(minute_counter = 0; past_min != present_min; minute_counter++) {
            if(past_min >= 59)
                past_min = -1;
            past_min++;
        }
        minutes = minute_counter;

        int present_s = present_t.getSeconds();
        int past_s = past_t.getSeconds();
        int second_counter;
        if(past_s > present_s)
            minutes--;
        for(second_counter = 0; past_s != present_s; second_counter++) {
            if(past_s >= 59)
                past_s = -1;
            past_s++;
        }
        seconds = second_counter;
        if(minutes < 0) {
            minutes = 60 + minutes;
            hours--;
        }
        if(hours < 0) {
            hours = 24 + hours;
            days--;
        }
    }
    if(days < 0) {
        days = 30 + days;
        months--;
    }
    if(months < 0) {
        months = 12 + months;
    }
    if(years < 0)
        years = 0;
}

int Age::setYears(const Date& past, const Date& present)
{
    int y = present.getYear() - past.getYear();
    if(past.getMonth().num > present.getMonth().num || (present.getMonth().num == past.getMonth().num && past.getDay() > present.getDay()))
        y--;
    return y;
}

int Age::setMonths(const Date& past, const Date& present)
{
    int temp_years = years;
    if(temp_years == 0)
        temp_years = setYears(past, present);
    int temp_months = 0;
    if(past.getMonth().num <= present.getMonth().num)
        temp_months = present.getMonth().num - past.getMonth().num;
    else
        temp_months = (12 - past.getMonth().num) + present.getMonth().num;
    return (temp_years * 12) + temp_months;
}

int Age::setDays(const Date& past, const Date& present)
{
    int d = 0;
    int temp_years = years;
    if(temp_years == 0)
        temp_years = setYears(past, present);

    if(temp_years > 0) {
        int year_counter = 0;
        while(year_counter != temp_years) {
            if(leapyear(past.getYear() + year_counter)) // check if current year is leapyear
                d += 366;
            else
                d += 365;
            year_counter++;
        }
    }

    int past_m = past.getMonth().num;
    int present_m = present.getMonth().num;
    while(past_m != present_m) { // count the days in the remaining months
        if(past_m == present_m-1 && past.getDay() > present.getDay())
            break;
        d += daysOfMonth(past_m, present.getYear()); // adds the exact number of days in that month
        past_m++;
        if(past_m > 12) // reset
            past_m = 1;
    }

    int max_days = daysOfMonth(past_m, present.getYear());
    int temp_days = 0;
    if(past.getDay() <= present.getDay())
        temp_days = present.getDay() - past.getDay();
    else
        temp_days = (max_days - past.getDay()) + present.getDay();
    return d + temp_days;
}

int Age::setHours(const Date& past, const Date& present)
{
    int temp_days = days;
    if(temp_days == 0)
        temp_days = setDays(past, present);
    int temp_hour = 0;
    if(past.getTime().getHour() <= present.getTime().getHour())
        temp_hour = present.getTime().getHour() - past.getTime().getHour();
    else
        temp_hour = (24 - past.getTime().getHour()) + present.getTime().getHour();
    return (temp_days * 24) + temp_hour;
}

int Age::setMinutes(const Date& past, const Date& present)
{
    int temp_hours = hours;
    if(temp_hours == 0) // uninitialized
        temp_hours = setHours(past, present);
    int temp_minutes = 0;
    if(past.getTime().getMinute() <= present.getTime().getMinute())
        temp_minutes = present.getTime().getMinute() - past.getTime().getMinute();
    else
        temp_minutes = (60 - past.getTime().getMinute()) + present.getTime().getMinute();
    return (temp_hours * 60) + temp_minutes;
}

long long int Age::setSeconds(const Date& past, const Date& present)
{
    long long int temp_minutes = minutes;
    if(temp_minutes == 0)
        temp_minutes = setMinutes(past, present);
    long long int temp_seconds = 0;
    if(past.getTime().getSeconds() <= present.getTime().getSeconds())
        temp_seconds = present.getTime().getSeconds() - past.getTime().getSeconds();
    else
        temp_seconds = (60 - past.getTime().getSeconds()) + present.getTime().getSeconds();
    return (temp_minutes * 60) + temp_seconds;
}

bool Age::leapyear(int y)
{
    if(y % 4 == 0 && y % 100 != 0)
        return true;
    if(y % 100 == 0 && y % 400 == 0)
        return true;
    return false;
}

int Age::daysOfMonth(int m, int y)
{
    switch(m) {
    case 1:
        return 31;
    case 2:
        if(leapyear(y))
            return 29;
        return 28;
    case 3:
        return 31;
    case 4:
        return 30;
    case 5:
        return 31;
    case 6:
        return 30;
    case 7:
        return 31;
    case 8:
        return 31;
    case 9:
        return 30;
    case 10:
        return 31;
    case 11:
        return 30;
    case 12:
        return 31;
    default:
        return 0;
    }
}
