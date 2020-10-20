
#include <iostream>
using namespace std;

// Date class declaration.
class Date
{
   private:
      string month;
      int year;
      int day;
   public:
      void setMonth(string);
      void setYear(int);
      void setDay(int);
      string getMonth() const;
      int getYear() const;
      int getDay() const;
};




void Date::setDay(int d)
{
	day = d;
}


void Date::setMonth(string m)
{
   month = m;
}

void Date::setYear(int y)
{
   year = y;
}


int Date::getDay() const
{
	return day;
}

string Date::getMonth() const
{
   return month;
}


int Date::getYear() const
{
   return year;
}


//*****************************************************
// Function main                                      *
//*****************************************************

int main()
{
   Date today;     
   string dateMonth;  
   int dateYear; 
   int dateDay;

   cout << "This program will calculate the date" << endl;
   cout << "What is the day in numbers? " << endl;
   cin >> dateDay;
   while(dateDay <=1 || dateDay >=31)
{
	cout << "Im sorry that information you gave me is incorrect, try again " << endl;
	cin >> dateDay;
}
   cout << "What is todays month? ";
   cin >> dateMonth;
   cout << "What is todays year? ";
   cin >> dateYear;

 
   today.setDay(dateDay);
   today.setMonth(dateMonth);
   today.setYear(dateYear);


   cout << "Here is date from the information you gave me " << endl;
   cout << today.getMonth() << " " <<  today.getDay() << " " << today.getYear() << endl;
   
   return 0;
}
