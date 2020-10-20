#include<iostream>
#include<cmath>
#include<string>

using namespace std;

/*
****************************************************************
                      PARKED CAR CLASS
- Simulates a parked car.
****************************************************************
*/

class ParkedCar
{
    private:
        string carMake;                 // make of the parked car
        string carModel;                // model of the parked car
        string carColor;                // color of the parked car
        string carLicenseNum;           // license number of the parked car
        int numMinutesParked;           // number of minutes the parked car has been parked

    public:
        ParkedCar()                     // default constructor
        {
            carMake = "";
            carModel = "";
            carColor = "";
            carLicenseNum = "";
            numMinutesParked = 0;
        }

        ParkedCar(string cMake, string cModel, string cColor, string cLicenseNum, int cNumMinParked)        // constructor #2
        {
            carMake = cMake;
            carModel = cModel;
            carColor = cColor;
            carLicenseNum = cLicenseNum;
            numMinutesParked = cNumMinParked;
        }

        int getNumParkedMinutes() const               // returns the number of minutes the car has been parked
        {
            return numMinutesParked;
        }

        void print()                      // displays the contents of the car object
        {
            cout << "- Car -\n" << endl;
            cout << "Make: " << carMake << endl;
            cout << "Model: " << carModel << endl;
            cout << "Color: " << carColor << endl;
            cout << "License Number: " << carLicenseNum << endl;
        }
};
/*
End Parked Car Class
*/

/*
****************************************************************
                      PARKING METER CLASS
- Simulates a parking meter.
****************************************************************
*/
class ParkingMeter
{
    private:
        int purchasedParkingMins;                     // minutes of purchased parking time

    public:
        ParkingMeter()                                // default constructor
        {
            purchasedParkingMins = 0;
        }

        ParkingMeter(int purchasedMinutes)            // constructor #2
        {
            purchasedParkingMins = purchasedMinutes;
        }

        int getPurchasedParkingMins() const           // returns the number of purchased minutes for the car to park legally
        {
            return purchasedParkingMins;
        }

        void print()                                  // displays the contents of the meter object
        {
            cout << "- Meter -\n" << endl;
            cout << "Number of minutes purchased : " << purchasedParkingMins << endl;
        }
};
/*
End Parking Meter Class
*/

/*
****************************************************************
                      POLICE OFFICER CLASS
- Simulates a police officer inspecting parked cars.
****************************************************************
*/

class PoliceOfficer
{
    private:
        string lastName;                        // police officer's last name
        string firstName;                       // police officer's first name
        string badgeNum;                        // police officer's badge number

    public:
        PoliceOfficer()                         // default constructor
        {
            lastName = "";
            firstName = "";
            badgeNum = "";
        }

        PoliceOfficer(string lName, string fName, string bNum)         // constructor #2
        {
            lastName = lName;
            firstName = fName;
            badgeNum = bNum;
        }

        bool isTicketNeccessary(ParkedCar& c, ParkingMeter& m)       // determines whether a parked car gets a ticket or not
        {
            if ((m.getPurchasedParkingMins() - c.getNumParkedMinutes()) < 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        void print()                                    // displays the contents of the police officer object
        {
            cout << "- Police Officer -\n" << endl;
            cout << "First Name: " << firstName << endl;
            cout << "Last Name: " << lastName << endl;
            cout << "Badge Number: " << badgeNum << endl;
        }
};
/*
End Police Officer Class
*/

/*
****************************************************************
                      PARKING TICKET CLASS
- Simulates a parking ticket.
****************************************************************
*/
class ParkingTicket
{
    private:
        ParkedCar car;                    // parked car object
        ParkingMeter meter;               // parking meter object
        PoliceOfficer officer;            // police officer object
        int fineAmount;                   // amount of the fine

    public:
        ParkingTicket(ParkedCar &carT, ParkingMeter &meterT, PoliceOfficer &officerT)         // constructor
        {
            car = carT;                              // copies each object passed as an argument into a new object ...
            meter = meterT;
            officer = officerT;
            fineAmount = calcFineAmount();
        }

        int calcFineAmount()               // returns the fine amount
        {
            return (25 + 10 * (ceil((car.getNumParkedMinutes()- meter.getPurchasedParkingMins())/60.0) - 1));
        }

        void print()          // prints the contents of the parking ticket object
        {
            cout << "\n\n***** TICKET INFORMATION *****" << endl;
            cout << "-------------------------------------" << endl;
            car.print();
            cout << "-------------------------------------" << endl;
            officer.print();
            cout << "-------------------------------------" << endl;
            cout << "- Fine -\n\n" << "Amount: $" << fineAmount << endl;
            cout << "-------------------------------------" << endl;
        }
};
/*
End Parking Ticket Class
*/

int main()
{
    string carMake;                        // make of the parked car
    string carModel;                       // model of the parked car
    string carColor;                       // color of the parked car
    string carLicenseNum;                  // license number of the parked car
    int numMinutesParked;                  // number of minutes the parked car has been parked
    int purchasedParkingMins;              // minutes of purchased parking time
    string lastName;                       // police officer's last name
    string firstName;                      // police officer's first name
    string badgeNum;                       // police officer's badge number

    cout << "Enter information for each object below.\n" << endl;
    cout << "CAR:\n" << endl;        // Get car's information ...
    cout << "Make: ";
    cin >> carMake;
    cout << "Model: ";
    cin >> carModel;
    cout << "Color: ";
    cin >> carColor;
    cout << "License Number: ";
    cin >> carLicenseNum;

    do
    {
        cout << "Number of minutes car has been parked: ";
        cin >> numMinutesParked;
    }
    while (numMinutesParked < 0);

    ParkedCar car1(carMake, carModel, carColor, carLicenseNum, numMinutesParked);              // create parked car object "car1"

    cout << "\nMETER:\n" << endl;          // Get meter's information ...

    do
    {
        cout << "Number of minutes purchased: ";
        cin >> purchasedParkingMins;
    }
    while (purchasedParkingMins < 0);

    ParkingMeter meter1(purchasedParkingMins);         // create parking meter object "meter1"

    cout << "\nPOLICE OFFICER:\n" << endl;            // Get police's information ...
    cout << "First Name: ";
    cin >> firstName;
    cout << "Last Name: ";
    cin >> lastName;
    cout << "Badge Number: ";
    cin >> badgeNum;

    PoliceOfficer officer1(lastName, firstName, badgeNum);      // create police officer object "officer1"

    if (officer1.isTicketNeccessary(car1, meter1) == true)        // determine whether or not to issue a ticket ...
    {
        ParkingTicket ticket1(car1, meter1, officer1);           // create ParkingTicket object "ticket1"
        ticket1.print();                                         // display the ticket
    }
    else                                                         // else the car is parked legally ...
    {
        cout << "\n* No ticket issued. *" << endl;
    }

    return 0;
}
