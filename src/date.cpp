#include "main.hpp"
#include "time.hpp"
#include "date.hpp"
#include "age.hpp"

using namespace std;

Month Date::getMonth() const
{
    return month;
}

int Date::getDay() const
{
    return day;
}

int Date::getYear() const
{
    return year;
}

Time Date::getTime() const
{
    return time;
}

void Date::setDate()
{
    string d;
    char ch;
    while(cin.get(ch)) {
        if(ch == '-' || ch == '\n')
            break;
        d += ch;
    }
    parseDate(d);
}

void Date::setDate(vector<string>& args) // get date from command line argument
{
    string d;
    for(int i = 0; i<args.size(); i++) {
        if(args[i] == "-") {
            args.erase(args.begin()+i);
            break;
        }
        d += args[i];
        args.erase(args.begin()+i);
        i--;
        d += " ";
    }
    parseDate(d);
}

void Date::setDateToday()
{
    auto endt = chrono::system_clock::now();
    time_t tt = chrono::system_clock::to_time_t(endt);
    struct tm* timeinfo = localtime(&tt);
    char d[50];
    strftime(d, 50,"%m/%d/%Y %H:%M:%S",timeinfo);

    parseDate(d);
}

void Date::parseDate(const string& str)
{
    stringstream ss(str);
    //cout << "STR MONTH: "<< str << endl;
    char ch;
    int i = 1;
    while(ss.get(ch)) {
        if(ch >= '0' && ch <= '9') {
            ss.unget();
            switch(i) { // iterate through our data members
            case 1:
                ss >> month.num;
                month.word = numToMonth(month.num);
                break;
            case 2:
                ss >> day;
                break;
            case 3:
                ss >> year;
                break;
            case 4: {
                string t;
                getline(ss, t);
                time.parseTime(t);
                break;
                }
            default:
                break;
            }
            i++;
        } else if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            ss.unget();
            ss >> month.word;
            month.num = monthToNum(month.word);
            i++;
        }
    }
}

int Date::monthToNum(string& month)
{
    for(int i = 0; i<month.size(); i++) {
        if(month[i] >= 'A' && month[i] <= 'Z')
            month[i] = tolower(month[i]);
    }
    if(month == "january" || month == "jan") {
        month = "January";
        return 1;
    } else if(month == "february" || month == "feb") {
        month = "February";
        return 2;
    } else if(month == "march" || month == "mar") {
        month = "March";
        return 3;
    } else if(month == "april" || month == "apr") {
        month = "April";
        return 4;
    } else if(month == "may") {
        month = "May";
        return 5;
    } else if(month == "june" || month == "jun") {
        month = "June";
        return 6;
    } else if(month == "july" || month == "jul") {
        month = "July";
        return 7;
    } else if(month == "august" || month == "aug") {
        month = "August";
        return 8;
    } else if(month == "september" || month == "sep") {
        month = "September";
        return 9;
    } else if(month == "october" || month == "oct") {
        month = "October";
        return 10;
    } else if(month == "november" || month == "nov") {
        month = "November";
        return 11;
    } else if(month == "december" || month == "dec") {
        month = "December";
        return 12;
    } else
        return 0;
}

string Date::numToMonth(int n)
{
    switch(n) {
    case 1:
        return "January";
    case 2:
        return "February";
    case 3:
        return "March";
    case 4:
        return "April";
    case 5:
        return "May";
    case 6:
        return "June";
    case 7:
        return "July";
    case 8:
        return "August";
    case 9:
        return "September";
    case 10:
        return "October";
    case 11:
        return "November";
    case 12:
        return "December";
    default:
        return string(); // return empty string
    }
}

void Date::printDate()
{
    if(Main::getFlag("-n") || Main::getFlag("--number-format"))
        cout << month.num << "/" << day << "/" << year << " ";
    else
        cout << month.word << " " << day << ", " << year << " ";
    if(time.isValidTime())
        time.printTime();
}

bool Date::isValidDate()
{
    if(month.num > 0 && month.num <= 12 && day > 0 && day <= daysOfMonth() && time.isValidTime())
        return true;
    return false;
}

bool Date::operator<(const Date& present) const
{
    if(year < present.year)
        return true;
    if(year == present.year && month.num < present.month.num)
        return true;
    if(year == present.year && month.num == present.month.num && day < present.day)
        return true;
    if(year == present.year && month.num == present.month.num && day == present.day && time < present.time)
        return true;
    return false;
}

bool Date::leapyear() const
{
    if(year % 4 == 0 && year % 100 != 0)
        return true;
    if(year % 100 == 0 && year % 400 == 0)
        return true;
    return false;
}

int Date::daysOfMonth(int m) const
{
    if(m == 0)
        m = month.num; // if m is uninitialized (no argument passed), will use the object's month number instead
    switch(m) {
    case 1:
        return 31;
    case 2:
        if(leapyear())
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
