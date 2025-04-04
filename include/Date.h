#ifndef DATE_H
#define DATE_H

#include <string>
#include <iostream>

class Date{
    private: 
        int month;
        int day;
        int year;
    public:
        Date(int m = 1, int d = 1, int y = 2000); // changed default year to 2000

        bool operator>(const Date& other) const;
        bool operator<(const Date& other) const;
        bool operator==(const Date& other) const;

        void print() const;
        
        int getMonth() const;
        int getDay() const;
        int getYear() const;

};
#endif
