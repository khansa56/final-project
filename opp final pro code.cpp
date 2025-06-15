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
//flight class info
class Flight {
	public:
    string flightNum, origin, destination;
    int seatsAvailable;
    float fare;
     //function to set flight's detail
    void setFlight(string fn, string o, string d, int s, float f) {
        flightNum = fn;
        origin = o;
        destination = d;
        seatsAvailable = s;
        fare = f;
    }
    
string toUpperCase(string str) {
    for (size_t i = 0; i < str.length(); ++i) {
        str[i] = toupper(str[i]); // Convert each char to uppercase
    }
    return str;
}
  // function to get flight number and is red-only
    string getFlightNumber() const
	 {
	  return flightNum;
	   }
	   //function to get available seats
    int getSeatsAvailable() 
	{ 
	return seatsAvailable; 
	}
	//function to get flight fare
    float getFare()
	 {
	  return fare;
	   }
	   //function to get seat
    void bookSeat()
	 { 
	flightNum = toUpperCase(flightNum);
	seatsAvailable--;
	 }
	 //function to cacel seat
    void cancelSeat()
	 { 
	flightNum = toUpperCase(flightNum);
	seatsAvailable++;
	 }
	 //function to show flight
    void displayFlight() 
	{
        cout << "Flight: " << flightNum << ", From: " << origin
             << ", To: " << destination << ", Seats: " << seatsAvailable
             << ", Fare: $" << fare << endl;
    }

    // New function: get flight route as string
    string getRoute() {
        return origin + " -> " + destination;
    }

    // New function: check if flight is fully booked
    bool isFull() {
        return seatsAvailable <= 0;
    }
};
 //class represent payment
class Payment {
    string method;
    float amount;
public:
	//function to set payment details
    void setPayment(string m, float a) {
        method = m; 
		amount = a;
    }
    //function to show payment details
    void displayPayment() 
	{
        cout << "Payment Method: " << method << ", Amount: $" << amount << endl;
    }

    // New function: get payment summary
    string paymentSummary() {
        stringstream ss;
        ss << method << " payment of $" << amount;
        return ss.str();
    }
};
int idx = findPassengerIndex(passengers, passengerCount, cancelName);
            if (idx != -1) {
                string flightNum = passengers[idx].getFlightNumber();

                for (int i = idx; i < passengerCount - 1; ++i) {
                    passengers[i] = passengers[i + 1];
                    payments[i] = payments[i + 1];
                    tickets[i] = tickets[i + 1];
                }
                passengerCount--;
                paymentCount--;
                ticketCount--;

                int fIdx = findFlightIndex(flights, flightCount, flightNum);
                if (fIdx != -1) 
				{
                    flights[fIdx].cancelSeat();
                }
                cout << "Booking cancelled.\n";
            }
			 else 
			 {
                cout << "Passenger not found.\n";
            }
        }
        else if (choice == 5) 
		{
            if (passengerCount == 0) 
			{
                cout << "No passengers booked yet.\n";
            }
			 else
			  {
                printDivider();
                for (int i = 0; i < passengerCount; ++i) {
                    passengers[i].displayPassenger();
                }
                printDivider();
            }
        }
        else if (choice == 6)
		 {
            if (paymentCount == 0)
			 {
                cout << "No payments recorded yet.\n";
            }
			 else 
			 {
                printDivider();
                for (int i = 0; i < paymentCount; ++i) {
                    payments[i].displayPayment();
                }
                printDivider();
            }
        }
        else if (choice == 7)
		 {
            if (ticketCount == 0) 
			{
                cout << "No tickets issued yet.\n";
            } else
			 {
                printDivider();
                for (int i = 0; i < ticketCount; ++i) 
				{
                    tickets[i].displayTicket();
                }
                printDivider();
            }
        }
        else if (choice == 8) 
		{
            // Change admin password
            string oldPW, newPW;
            cout << "Enter current admin password: ";
            getline(cin, oldPW);
            cout << "Enter new admin password: ";
            getline(cin, newPW);
            if (admin.changePassword(oldPW, newPW))
			 {
                cout << "Admin password changed successfully.\n";
            }
			 else
			 {
                cout << "Incorrect current password. Password not changed.\n";
            }
        }
        else if (choice == 0)
		 {
            cout << "Thank you for using the Airline Reservation System.\n";
            break;
        }
        else
		 {
            cout << "Invalid choice. Please try again.\n";
        }
    } while (true);

    return 0;
}
