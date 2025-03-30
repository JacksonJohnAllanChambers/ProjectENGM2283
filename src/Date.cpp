#include "Date.h"
#include <iostream>

using namespace std;

Date::Date(int m, int d, int y) : month(m), day(d), year(y) {}

bool Date::operator>(const Date& other) const {
    if (year > other.year) return true;
    if (year == other.year && month > other.month) return true;
    if (year == other.year && month == other.month && day > other.day) return true;
    return false;
}

bool Date::operator<(const Date& other) const {
    if (year < other.year) return true;
    if (year == other.year && month < other.month) return true;
    if (year == other.year && month == other.month && day < other.day) return true;
    return false;
}

bool Date::operator==(const Date& other) const {
    return (year == other.year && month == other.month && day == other.day);
}

void Date::print() const {
    const char* months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    cout << months[month - 1] << " " << day << ", " << year;
} 

int Date::getMonth() const {
    return month;
}

int Date::getDay() const {
    return day;
} 

int Date::getYear() const {
    return year;
}
