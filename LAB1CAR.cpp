#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Car class declaration.

class Car 
{
    private:
    // member variables
    int yearModel;
    string make;
    int speed;

    public:
    Car(int carYearModel, string carMake, int carSpeed)
    { yearModel = carYearModel;
      make = carMake;
      speed = carSpeed; }

    void accelerate(int mph)
    { speed += mph; }
    void brake(int mph)
    { speed -= mph; }

    int getSpeed () const
    { return speed; }
};

int main()
{
    int count;
    Car honda(2005, "Accord", 0);

    cout << "The starting speed is "  
     << honda.getSpeed() << endl << endl;

    cout << "We will now accelerate by 5 mph, 5 times.\n";
    system ("pause");

    for ( count = 0; count < 5; count++)
    {
        honda.accelerate(5);
        cout << "Speed is now: " << honda.getSpeed() 
             << " mph." << endl;
    }

    system ("pause");

    cout << endl << "Now we will brake by 5 mph, 5 times. \n";
    system ("pause");

    for ( count = 0; count < 5; count++)
    {
        honda.brake(5);
        cout << "Speed is now: " << honda.getSpeed() 
             << " mph." << endl;
    }

    system ("pause");

    return 0;
}
