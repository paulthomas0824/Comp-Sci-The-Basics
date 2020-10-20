#include <iostream>

#include <iomanip>

#include <cstring>

using namespace std;

class Employee

{

//variables

private:

char name[30];

int empNum;

string hiredate;

public:

//constructor

Employee(char name[30],int empNum,string hiredate)

{

strcpy(this->name,name);

this->empNum = empNum;

this->hiredate = hiredate;

}

//set and get methods

void setName(char name[30])

{

strcpy(this->name,name);

}

void setEmpNum(int empNum)

{

this->empNum = empNum;

}

void setHiredate(string hiredate)

{

this->hiredate = hiredate;

}

char* getName()

{

return name;

}

int getEmpNum()

{

return empNum;

}

string getHiredate()

{

return hiredate;

}

void display()

{

cout<<"\nName: "<<getName();

cout<<"\nEmployee number: "<<getEmpNum();

cout<<"\nHire date: "<<getHiredate();

}

};

class ProductionWorker :public Employee

{

private :

int shift;

double hourlyPayRate;

public:

//passing parameters to base class Employee from derived class ProductionWorker

ProductionWorker(char name[30],int empNum,string hiredate,int shift,double hourlyPayRate):Employee(name,empNum,hiredate)

{

this->shift = shift;

this->hourlyPayRate = hourlyPayRate;

}

//get and set functions

void setShift(double shift)

{

this->shift = shift;

}

void setHouryPayRate(double hourlyPayRate)

{

this->hourlyPayRate = hourlyPayRate;

}

double getShift()

{

return shift;

}

double getHourlyPayRate()

{

return hourlyPayRate;

}

void displayDetails()

{

display(); //call to Employee class function

cout<<"\nShift: $"<<getShift();

cout<<"\nHourly Pay Rate : "<<getHourlyPayRate();

}

};

class TeamLeader : ProductionWorker

{

private:

double monthlyBonus;

int reqTrainingHours;

int attendedHours;

public:

  

TeamLeader(char name[30],int empNum,string hiredate,int shift,double hourlyPayRate,double monthlyBonus,int reqTrainingHours,int attendedHours):ProductionWorker(name,empNum,hiredate,shift,hourlyPayRate)

{

this->monthlyBonus = monthlyBonus;

this->reqTrainingHours = reqTrainingHours;

this->attendedHours = attendedHours;

}

//get and set functions

void setMonthlyBonus(double monthlyBonus)

{

this->monthlyBonus = monthlyBonus;

}

void setReqTrainingHours(int reqTrainingHours)

{

this->reqTrainingHours = reqTrainingHours;

}

void setAttendedHours(int attendedHours)

{

this->attendedHours = attendedHours;

}

double getMonthlyBonus()

{

return monthlyBonus;

}

int getReqTrainingHours()

{

return reqTrainingHours;

}

int getAttendedHours()

{

return attendedHours;

}

void displayDetails()

{

cout<<"\nTeam leader : ";

display(); //call to Employee class function

cout<<"\nMonthly Bonus : $"<<getMonthlyBonus();

cout<<"\nRequired Training Hours : "<<getReqTrainingHours();

cout<<"\nAttended Training Hours : "<<getAttendedHours();

}

};

class ShiftSupervisor :public Employee

{

private :

double annualSalary;

double annualProductionBonus;

public:

//passing parameters to base class Employee from derived classShiftSupervisor

ShiftSupervisor(char name[30],int empNum,string hiredate,double annualSalary,double annualProductionBonus):Employee(name,empNum,hiredate)

{

this->annualSalary = annualSalary;

this->annualProductionBonus = annualProductionBonus;

}

//get and set functions

void setAnnualSalary(double annualSalary)

{

this->annualSalary = annualSalary;

}

void setAnnualProductionBonus(double annualProductionBonus)

{

this->annualProductionBonus = annualProductionBonus;

}

double getAnnualSalary()

{

return annualSalary;

}

double getAnnualProductionBonus()

{

return annualProductionBonus;

}

void displayDetails()

{

display(); //call to Employee class function

cout<<"\nAnnual Salary: $"<<getAnnualSalary();

cout<<"\nAnnual Production Bonus: $"<<getAnnualProductionBonus();

}

};

int main()

{

TeamLeader tl("Paul Thomas",676,"2/15/2018",1,7.8,500.50,40,25);

  

  

cout<<fixed<<setprecision(2); //use manipulator functions

tl.displayDetails();

  

ShiftSupervisor ss("Meiru Che",859,"9/04/2015",75000,15000);

cout<<fixed<<setprecision(2); //use manipulator functions

ss.displayDetails();

return 0;

}
