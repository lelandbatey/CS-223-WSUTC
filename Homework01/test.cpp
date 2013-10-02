#include <string>
#include <iostream>
#include <sstream>

using namespace std;

int main()
{
	int number = 123;
	string text = "456";
	stringstream ss;

	cin >> text;
	// text = "456";
	// number = stoi(number);
	if (text == "END")
	{
		cout << "You typed END!!" << endl;
	} else {
		ss << text;
		ss >> number;
	}

	cout << number << endl;

	return 0;
}

