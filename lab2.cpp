#include<iostream>
using namespace std;
/*
* Division structure
*/
struct Division
{
   string Division_name;
   double first_quarter;
   double second_quarter;
   double third_quarter;
   double fourth_quarter;
   double annual_sales;
   double avg_quarter_sales;
};
/*
* Function definations
*/
void DisplayCorpInformation(const Division& east, const Division& west, const Division& north, const Division& south);
void FindTotalAndAverageSales(Division& div);
void GetDivisionSales(Division& div);
int main()
{
   Division east,west,north,south;
   east.Division_name="East";
   west.Division_name="West";
   north.Division_name="North";
   south.Division_name="South";
   /*
   * take input from user
   */
   cout<<"Enter the quartly sales for East Division"<<endl;
   cout<<"\t First quarter: ";
   cin>>east.first_quarter;
   cout<<"\t Second quarter: ";
   cin>>east.second_quarter;
   cout<<"\t Third quarter: ";
   cin>>east.third_quarter;
   cout<<"\t Fourth quarter: ";
   cin>>east.fourth_quarter;
   cout<<"Enter the quartly sales for West Division"<<endl;
   cout<<"\t First quarter: ";
   cin>>west.first_quarter;
   cout<<"\t Second quarter: ";
   cin>>west.second_quarter;
   cout<<"\t Third quarter: ";
   cin>>west.third_quarter;
   cout<<"\t Fourth quarter: ";
   cin>>west.fourth_quarter;
   cout<<"Enter the quartly sales for North Division"<<endl;
   cout<<"\t First quarter: ";
   cin>>north.first_quarter;
   cout<<"\t Second quarter: ";
   cin>>north.second_quarter;
   cout<<"\t Third quarter: ";
   cin>>north.third_quarter;
   cout<<"\t Fourth quarter: ";
   cin>>north.fourth_quarter;
   cout<<"Enter the quartly sales for South Division"<<endl;
   cout<<"\t First quarter: ";
   cin>>south.first_quarter;
   cout<<"\t Second quarter: ";
   cin>>south.second_quarter;
   cout<<"\t Third quarter: ";
   cin>>south.third_quarter;
   cout<<"\t Fourth quarter: ";
   cin>>south.fourth_quarter;
   FindTotalAndAverageSales(east);
   FindTotalAndAverageSales(west);
   FindTotalAndAverageSales(north);
   FindTotalAndAverageSales(south);
   DisplayCorpInformation(east,west,north,south);
}
void DisplayCorpInformation(const Division& east, const Division& west, const Division& north, const Division& south)
{
   cout<<"Total Annual Sales"<<endl;
   cout<<"\t"<<"East Division: $"<<east.annual_sales<<endl;
   cout<<"\t"<<"West Division: $"<<west.annual_sales<<endl;
   cout<<"\t"<<"North Division: $"<<north.annual_sales<<endl;
   cout<<"\t"<<"South Division: $"<<south.annual_sales<<endl<<endl;
   cout<<"Average Quartely Sales"<<endl;
   cout<<"\t"<<"East Division: $"<<(east.avg_quarter_sales)<<endl;
   cout<<"\t"<<"West Division: $"<<(west.avg_quarter_sales)<<endl;
   cout<<"\t"<<"North Division: $"<<(north.avg_quarter_sales)<<endl;
   cout<<"\t"<<"South Division: $"<<(south.avg_quarter_sales)<<endl;
}
void FindTotalAndAverageSales(Division& div){
   double total_sales=(div.first_quarter+div.second_quarter+div.third_quarter+div.fourth_quarter);
   double avg_sales=(total_sales/4.0);
   div.annual_sales=total_sales;
   div.avg_quarter_sales=avg_sales;
}
void GetDivisionSales(Division& div){
   cout<<"Quartly sales for "<<div.Division_name<<" division"<<endl;
   cout<<"\t First quarter: "<<div.first_quarter<<endl;
   cout<<"\t Second quarter: "<<div.second_quarter<<endl;
   cout<<"\t Third quarter: "<<div.third_quarter<<endl;
   cout<<"\t Fourth quarter: "<<div.fourth_quarter<<endl;
}
