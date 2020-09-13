#include <iostream>
using namespace std; 

int main()
{
	int year;
	bool isLeapYear;

	cout << "Enter the year: ";
	cin >> year;
	isLeapYear = ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));

	if (isLeapYear) {
		cout << year << " is leap year" << endl;
	}
	else {
		cout << year << " is not leap year" << endl;
	}

	return 0;
}
