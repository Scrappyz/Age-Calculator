#ifndef DATE_HPP_INCLUDED
#define DATE_HPP_INCLUDED

using namespace std;

struct Month {
    string word;
    int num;
};

class Date {
private:
    Month month;
    int day;
    int year;
    Time time;
public:
    Date() : month(), day(), year(), time() {}
    Date(Month m, int d, int y) : month(m), day(d), year(y), time() {}
    Date(Month m, int d, int y, Time t) : month(m), day(d), year(y), time(t) {}

    void setDate();
    void setDate(vector<string>&); // get date from command line argument
    void setDateToday();

    Month getMonth() const;
    int getDay() const;
    int getYear() const;
    Time getTime() const;

    void parseDate(const string&);
    int monthToNum(string&);
    string numToMonth(int);
    void printDate();
    bool isValidDate();
    bool operator<(const Date& present) const;
    bool leapyear() const;
    int daysOfMonth(int = 0) const;
};

#endif // DATE_HPP_INCLUDED
