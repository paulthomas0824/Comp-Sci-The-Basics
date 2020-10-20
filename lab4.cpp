//#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <conio.h>
using namespace std;
ofstream outfile;
class bankGeneric {
public:
	double balance;
	int deposits = 0;
	int withdrawals = 0;
	double interest_rate_annual;
	double service_charge = 0;
	bankGeneric();
	void deposit(double amt);
	void withdraw(double amt);
	void calcInt();
	virtual void monthlyProc();
};
class Savings :public bankGeneric {
	bool status; //False=Inactive=0 True=Active=1
public:
	void withdraw(double amt);
	void deposit(double amt);
	void monthlyProc();
};
class checking :public bankGeneric {
public:
	void withdraw(double amt);
	void monthlyProc();
};
bankGeneric::bankGeneric() {
	cout << "Enter the balance and the interest rate, separated by a space." << endl;
	cin >> balance;
	cin >> interest_rate_annual;
}
void bankGeneric::deposit(double amt) {
	balance += amt;
	deposits++;
}
void bankGeneric::withdraw(double amt) {
	balance -= amt;
	withdrawals++;
}
void bankGeneric::calcInt() {
	double monthly_interest_rate = interest_rate_annual / 12;
	double monthly_interest = balance*monthly_interest_rate;
	balance = balance + monthly_interest;
}
void bankGeneric::monthlyProc() {
	calcInt();
	balance -= service_charge;
	withdrawals = 0;
	deposits = 0;
	service_charge = 0;
}
void Savings::withdraw(double amt) {
	if (status == 0)
		cout << "Sorry, you will not be able to withdraw, balance too low." << endl;
	if (status) {
		bankGeneric::withdraw(amt);
	}
	if (balance < 25)
		status = 0;
}
void Savings::deposit(double amt) {
	if (amt + balance > 25) {
		status = 1;
		bankGeneric::deposit(amt);
	}
}
void Savings::monthlyProc() {
	if (withdrawals > 4) {
		service_charge = withdrawals - 4;
	}
	if (balance < 25)
		status = 0;
	cout << "Service Charges:   " << service_charge << endl;
	outfile << "Service Charges:   " << service_charge << endl;
	bankGeneric::monthlyProc();
}
void checking::withdraw(double amt) {
	if (balance - amt < 0) {
		balance -= 15;
		service_charge += 15;
	}
	bankGeneric::withdraw(amt);
}
void checking::monthlyProc() {
	service_charge += 5 + .1*withdrawals;
	cout << "Service Charges:   " << service_charge << endl;
	outfile << "Service Charges:   " << service_charge << endl;
	bankGeneric::monthlyProc();
}
void Menu(Savings& S, checking& C) {
	int selection = 0;
	while (selection != 6) {
		cout << "********BANK ACCOUNT MENU********" << endl << endl << endl;
		cout << "1. Savings Account Deposit" << endl;
		cout << "2. Checking Account Deposit" << endl;
		cout << "3. Savings Account Withdrawal" << endl;
		cout << "4. Checking Account Withdrawal" << endl;
		cout << "5. Update and Display Account Statistics" << endl;
		cout << "6. Exit" << endl << endl << endl;
		cout << "Your choice, please (1-6) ";
		cin >> selection;
		double deposit, withdraw;
		switch (selection) {
		case 1:
			cout << "Enter amount to deposit: " << endl;
			cin >> deposit;
			S.deposit(deposit);
			cout << "Your balance is " << fixed << setprecision(2) << S.balance << endl;
			break;
		case 2:
			cout << "Enter amount to deposit: " << endl;
			cin >> deposit;
			C.deposit(deposit);
			cout << "Your balance is " << fixed << setprecision(2) << C.balance << endl;
			break;
		case 3:
			cout << "Enter amount to withdraw: " << endl;
			cin >> withdraw;
			S.withdraw(withdraw);
			cout << "Your balance is " << fixed << setprecision(2) << S.balance << endl;
			break;
		case 4:
			cout << "Enter amount to withdraw: " << endl;
			cin >> withdraw;
			C.withdraw(withdraw);
			cout << "Your balance is " << fixed << setprecision(2) << C.balance << endl;
			break;
		case 5:
			cout << "SAVINGS ACCOUNT MONTHLY STATISTICS:" << endl;
			outfile << "SAVINGS ACCOUNT MONTHLY STATISTICS:" << endl;
			cout << "Withdrawals:   " << S.withdrawals << endl;
			outfile << "Withdrawals:   " << S.withdrawals << endl;
			cout << "Deposits:   " << S.deposits << endl;
			outfile << "Deposits:   " << S.deposits << endl;
			S.monthlyProc();
			cout << "Ending Balance:   " << fixed << setprecision(2) << S.balance << endl;
			outfile << "Ending Balance:   " << fixed << setprecision(2) << S.balance << endl;
			cout << "Press a key to continue..." << endl << endl;
			_getch();
			cout << "CHECKING ACCOUNT MONTHLY STATISTICS:" << endl;
			outfile << "CHECKING ACCOUNT MONTHLY STATISTICS:" << endl;
			cout << "Withdrawals:   " << C.withdrawals << endl;
			outfile << "Withdrawals:   " << C.withdrawals << endl;
			cout << "Deposits:   " << C.deposits << endl;
			outfile << "Deposits:   " << C.deposits << endl;
			C.monthlyProc();
			cout << "Ending Balance:   " << fixed << setprecision(2) << C.balance << endl;
			outfile << "Ending Balance:   " << fixed << setprecision(2) << C.balance << endl;
			cout << "Press a key to continue..." << endl << endl;
			_getch();
			break;
		}
	}

}
int main()
{
	outfile.open("bankOutput.txt");
	Savings S;
	checking C;
	Menu(S, C);
	outfile.close();
	return 0;
}
