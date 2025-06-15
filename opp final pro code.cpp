#include <iostream>
 //library for various operations on strings
#include <string>
 //conversation between string to other datatypes
#include <sstream>
using namespace std;
   //class to represent person
class Person {
protected:
    string name, email, phone;
public:
	//function to set person details
    void setPerson(string n, string e, string p) {
        name = n; 
		email = e; 
		phone = p;
    }
    //function to get person details and are read-only
    string getName() const 
	{ 
	return name;
	 }
};
  //passenger class inherits from person
class Passenger : public Person {
    string flightNum, seatNum;
public:
	//function to set passenger details
    void setPassengerDetails(string n, string e, string p, string fNum, string sNum) {
        setPerson(n, e, p);                     //call the person's set function
        flightNum = fNum;
		 seatNum = sNum;
    }
    //function to show passenger
    void displayPassenger() {
        cout << "Name: " << name << ", Email: " << email << ", Phone: " << phone
             << ", Flight: " << flightNum << ", Seat: " << seatNum << endl;
    }
    //person to get flight number
    string getFlightNumber()
	 {
	  return flightNum; 
	  }

    // New function: format passenger info summary
    string passengerSummary() 
	{
        stringstream ss;
        ss << name << " (" << email << ", " << phone << "), Flight: " << flightNum << ", Seat: " << seatNum;
        return ss.str();
    }};
do {
        displayMenu();

        int choice;
        cin >> choice;
        cin.ignore(); // to consume newline

        if (choice == 1)
		 {
            string username, password;
            cout << "Enter username: "; 
			getline(cin, username);
            cout << "Enter password: ";
			
			 getline(cin, password);
            if (admin.login(username, password))
			 {
                cout << "Admin login successful!\n";
            }
			 else
			  {
                cout << "Invalid username or password.\n";
            }
        }
        else if (choice == 2)
		 {
            cout << "\nAvailable Flights:\n";
            printDivider();
            for (int i = 0; i < flightCount; ++i)
			 {
                flights[i].displayFlight();
            }
            printDivider();
        }
        else if (choice == 3)
		 {
            string name, email, phone, flightNum;
            cout << "Enter Name: "; 
			getline(cin, name);
            cout << "Enter Email: ";
			 getline(cin, email);
            cout << "Enter Phone: ";
			 getline(cin, phone);
            cout << "Enter Flight Number: ";
			 getline(cin, flightNum);

            int idx = findFlightIndex(flights, flightCount, flightNum);
            if (idx != -1 && !flights[idx].isFull()) 
			{
                flights[idx].bookSeat();
                stringstream ss;
               ss << ((passengerCount % 30) + 1);
                string seatNum = "S" + ss.str();

                passengers[passengerCount].setPassengerDetails(name, email, phone, flightNum, seatNum);
                payments[paymentCount].setPayment("Credit Card", flights[idx].getFare());
			
                 ss << "T" << (ticketCount + 1);
                string ticketID = ss.str();
                tickets[ticketCount].setTicket(ss.str(), flightNum, name);
                passengerCount++;
                paymentCount++;
                ticketCount++;
                cout << "Booking successful! Your seat number is " << seatNum << ".\n";
            } 
			else
			 {
                cout << "Flight not found or no seats available.\n";
            }
        }
        else if (choice == 4) 
		{
            string cancelName;
            cout << "Enter passenger name to cancel: ";
            getline(cin, cancelName);
