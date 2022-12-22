#include <bits\stdc++.h>
using namespace std;

class MonthError
{
    string itsMonth;
    string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "Septemper", "October", "November", "December"};

public:
    MonthError(int month)
    {
        if (month < 0 || month > 12)
        {
            throw 404;
        }
        itsMonth = months[month - 1];
    }
    string get_Month()
    {
        return itsMonth;
    }
};
class DayError
{
    int itsDay;

public:
    DayError(int day)
    {
        if (day > 31 || day < 0)
        {
            throw 404;
        }

        itsDay = day;
    }
    int get_Day()
    {
        return itsDay;
    }
};
int main()
{

    string str, strmonth, strday;
    cout << "enter a date" << endl;
    cin >> str;
    int index = str.find('/');
    strmonth = str.substr(0, index);
    strday = str.substr(index + 1, str.size());
    int day = stoi(strday);
    int month = stoi(strmonth);
    MonthError Month(month);
        DayError Day(day);
    try
    {
        MonthError Month(month);
        DayError Day(day);
    }
    catch (const int error)
    {
        cout << "ERROR " << error << endl;
    }
    cout<< Month.get_Month()<<" "<< Day.get_Day()<<endl;
}