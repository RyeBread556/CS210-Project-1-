//============================================================================
// Name
// Author      : Ryan Erno
// Version     :
// Copyright   : Your copyright notice
// Description : ChadaTech Clock Project
//============================================================================

#include <iostream>
using namespace std;

//global variables to call upon.
int hours = 0;
int minutes = 0;
int seconds = 0;

string timePeriodGet (int hours){ //determination of am or pm.
	if (hours >= 12) {
		return "P.M";
	}
	else {
		return "A.M.";
	}
}



void clock12(int hours, int minutes, int seconds) { // 12 hour clock setup

string timePeriod = timePeriodGet(hours);
int displayHours = hours % 12;
if(displayHours == 0) displayHours = 12;

cout << "12 hour clock format";
if(hours < 10)
cout <<  "0";

cout << hours << ":";

if(minutes < 10)
cout <<  "0";

cout << minutes << ":";

if(seconds < 10)
cout << "0";

 cout << seconds << " " << timePeriod << endl;
}




void clock24(int hours, int minutes, int seconds) { // 24 hour clock setup.
	cout << "24 hour clock format";
	if(hours < 10)
	cout <<  "0";

	cout << hours << ":";

	if(minutes < 10)
	cout <<  "0";

	cout << minutes << ":";

	if(seconds < 10)
	cout << "0";

	 cout << seconds << endl;
	}


void AddOneHour() { // function to add one hour.
	hours = (hours + 1) % 24;
}



void AddOneMinute() { // function to add one minute.
minutes = (minutes + 1) % 60;
if(seconds == 0){
AddOneHour();
}
}






void AddOneSecond() { // function for one second.
	seconds =(seconds + 1) % 60;
		if(seconds == 0) {
		AddOneMinute();
}
}
}


char menuDisplay() {
	// displays the menu to user to make choices
	cout << "____________________________";
	cout << "Press '1' to add one hour";
	cout << "Press '2' to add one minute";
	cout << "Press '3' to add one second";
	cout << "Press '4' to exit menu.";
	cout << "____________________________";

	char userInput;
	cin >> userInput;
	return userInput;
}
int min() {

// time input from user for initial time.

cout << "Provide initial hours 1-24";
		cin >> hours;
cout << "Provide initial minutes 0-59";
		cin >> minutes;
cout << "Provide initial seconds 0-59";
		cin >> seconds;


	while(true) {

	clock12( hours,  minutes,  seconds); // calls to clocks functions.

	clock24( hours,  minutes,  seconds);

	char userInput = menuDisplay();

		switch(userInput) { //switch statement provides choice outcome.

		case '1':
			AddOneHour();
			break;

		case '2':
			AddOneMinute();
			break;

		case '3':
			AddOneSecond();
			break;

		case '4':
			cout << "Exiting Program." << endl;
			return 0;
		default:
			cout << "input not valid" << endl;
		}
	}
	return 0;
}
