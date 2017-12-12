// Lab07-Payments.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	string lastName;
	string firstName;
	int quantity;
	double price;
	double totalPayment;
	double totalAmount = 0;

	ifstream payments;

	payments.open("Payments.txt");

	if (!payments)
	{
		cout << endl << "Error opening input file" << endl << endl;
		system("pause");
		return-1;
	}

	cout << fixed << setprecision(2) << endl;

	payments >> lastName;

	while (!payments.eof())
	{
		payments >> firstName >> quantity >> price;
		totalPayment = quantity * price;
		totalAmount += totalPayment;

		cout << setw(4) << quantity << "  @ " << setw(8) << price << setw(12) << totalPayment << "   " << lastName << ", " << firstName << endl;

		payments >> lastName;
	}

	payments.close();

	cout << endl << "     Total Amount:  $" << totalAmount << endl;




	cout << endl;
	system("pause");
	return 0;
}

