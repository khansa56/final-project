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
/class to represent ticket 
class Ticket {
    string ticketNum, flightNum, passengerName;
public:
	//function to set ticket details
    void setTicket(string tNum, string fNum, string pName) {
        ticketNum = tNum;
		 flightNum = fNum;
		  passengerName = pName;
    }
    //function to show ticket details
    void displayTicket()
	 {
        cout << "Ticket: " << ticketNum << ", Flight: " << flightNum
             << ", Passenger: " << passengerName << endl;
    }

    // New function: get ticket info string
    string ticketInfo() {
        return "Ticket #" + ticketNum + " for " + passengerName + " on flight " + flightNum;
    }
};
 //class represent admin inherits from person
class Admin:public Person {
    string username, password;
public:
	//function to set admin info
    void setAdmin(string u, string p)
	 {
        username = u; 
		password = p;
    }
    //function for admin login
    bool login(string u, string p)
	 {
        return username == u && password == p;
    }
    
    // New function: change admin password
    bool changePassword(string oldP, string newP) {
        if (password == oldP) 
		{
            password = newP;
            return true;
        }
        return false;
    }
};
//function to display menu
void displayMenu() {
    cout << "\n===== Airline Reservation Menu =====\n";
    cout << "1. Admin Login\n2. Show Flights\n3. Book Flight\n4. Cancel Booking\n";
    cout << "5. Show Passengers\n6. Show Payments\n7. Show Tickets\n8. Change Admin Password\n0. Exit\n";
    cout << "Enter choice: ";
}
//function to print divider
void printDivider() {
    cout << "-------------------------------------------\n";
}

// Additional helper function to find flight index by flight number
int findFlightIndex(const Flight flights[], int flightCount, const string &flightNum) {
    for (int i = 0; i < flightCount; i++) {
        if (flights[i].getFlightNumber() == flightNum) {
            return i;
        }
    }
    return -1; // ? Correctly placed outside the loop
}
// Additional helper function to find passenger index by name
int findPassengerIndex(const Passenger passengers[], int passengerCount, const string& name) {
    for (int i = 0; i < passengerCount; i++)
        if (passengers[i].getName() == name)
            return i;
    return -1;
}
//main function
int main() 
{
	//declaring arrays for flights,passengers,payments,tickets
    Flight flights[100];           // Increased capacity for flights
    Passenger passengers[200];     // Increased capacity for passengers
    Payment payments[200];          //increased capacity for payments
    Ticket tickets[200];            //increased capacity for tickets
    //initialize counters for flights,passengers,payments
    int flightCount = 0, passengerCount = 0, paymentCount = 0, ticketCount = 0;
    //set admin credentials
    Admin admin;
    admin.setAdmin("Areeba", "123");

    // Original flights
    flights[0].setFlight("AA101", "KARACHI", "ISLAMABAD", 5, 250.0);
    flights[1].setFlight("AA102", "LAHORE", "MULTAN", 3, 230.0);
    flightCount = 2;

    // Additional flights added without modifying original code logic
    flights[2].setFlight("AA103", "ISLAMABAD", "KARACHI", 4, 300.0);
    flights[3].setFlight("AA104", "MULTAN", "LAHORE", 2, 220.0);
    flights[4].setFlight("AA105", "KARACHI", "PESHAWAR", 6, 270.0);
    flights[5].setFlight("AA106", "LAHORE", "QUETTA", 5, 250.0);
    flights[6].setFlight("AA107", "PESHAWAR", "ISLAMABAD", 7, 200.0);
    flights[7].setFlight("AA108", "QUETTA", "KARACHI", 3, 320.0);
    flights[8].setFlight("AA109", "ISLAMABAD", "LAHORE", 4, 280.0);
    flights[9].setFlight("AA110", "MULTAN", "PESHAWAR", 2, 210.0);
    flights[10].setFlight("AA111", "KARACHI", "LAHORE", 5, 260.0);
    flights[11].setFlight("AA112", "ISLAMABAD", "QUETTA", 3, 330.0);
    flights[12].setFlight("AA113", "PESHAWAR", "MULTAN", 6, 270.0);
    flights[13].setFlight("AA114", "LAHORE", "KARACHI", 4, 260.0);
    flights[14].setFlight("AA115", "QUETTA", "ISLAMABAD", 3, 310.0);
    flights[15].setFlight("AA116", "MULTAN", "LAHORE", 7, 220.0);
    flights[16].setFlight("AA117", "KARACHI", "PESHAWAR", 5, 270.0);
    flights[17].setFlight("AA118", "ISLAMABAD", "MULTAN", 4, 280.0);
    flights[18].setFlight("AA119", "PESHAWAR", "KARACHI", 6, 250.0);
    flights[19].setFlight("AA120", "LAHORE", "QUETTA", 3, 300.0);
    flights[20].setFlight("AA121", "KARACHI", "ISLAMABAD", 8, 245.0);
    flights[21].setFlight("AA122", "MULTAN", "LAHORE", 5, 210.0);
    flights[22].setFlight("AA123", "ISLAMABAD", "PESHAWAR", 7, 295.0);
    flights[23].setFlight("AA124", "QUETTA", "MULTAN", 4, 330.0);
    flights[24].setFlight("AA125", "LAHORE", "KARACHI", 6, 260.0);
    flights[25].setFlight("AA126", "ISLAMABAD", "LAHORE", 5, 275.0);
    flights[26].setFlight("AA127", "PESHAWAR", "QUETTA", 4, 310.0);
    flights[27].setFlight("AA128", "KARACHI", "MULTAN", 7, 260.0);
    flights[28].setFlight("AA129", "MULTAN", "ISLAMABAD", 3, 280.0);
    flights[29].setFlight("AA130", "LAHORE", "PESHAWAR", 6, 250.0);
    flights[30].setFlight("AA131", "KARACHI", "QUETTA", 5, 320.0);
    flights[31].setFlight("AA132", "ISLAMABAD", "LAHORE", 4, 285.0);
    flights[32].setFlight("AA133", "PESHAWAR", "MULTAN", 6, 270.0);
    flights[33].setFlight("AA134", "KARACHI", "LAHORE", 5, 310.0);
    flights[34].setFlight("AA135", "MULTAN", "LAHORE", 3, 220.0);
    flights[35].setFlight("AA136", "LAHORE", "ISLAMABAD", 7, 270.0);
    flights[36].setFlight("AA137", "PESHAWAR", "KARACHI", 4, 260.0);
    flights[37].setFlight("AA138", "QUETTA", "MULTAN", 5, 300.0);
    flights[38].setFlight("AA139", "KARACHI", "LAHORE", 6, 255.0);
    flights[39].setFlight("AA140", "ISLAMABAD", "QUETTA", 5, 315.0);
    flights[40].setFlight("AA141", "MULTAN", "PESHAWAR", 7, 230.0);
    flights[41].setFlight("AA142", "LAHORE", "KARACHI", 6, 260.0);
    flights[42].setFlight("AA143", "ISLAMABAD", "MULTAN", 4, 270.0);
    flights[43].setFlight("AA144", "PESHAWAR", "LAHORE", 5, 280.0);
    flights[44].setFlight("AA145", "KARACHI", "ISLAMABAD", 3, 240.0);
    flights[45].setFlight("AA146", "MULTAN", "QUETTA", 4, 290.0);
    flights[46].setFlight("AA147", "LAHORE", "PESHAWAR", 5, 265.0);
    flights[47].setFlight("AA148", "ISLAMABAD", "KARACHI", 6, 275.0);
    flights[48].setFlight("AA149", "QUETTA", "LAHORE", 3, 310.0);
    flights[49].setFlight("AA150", "PESHAWAR", "MULTAN", 5, 270.0);

    flightCount = 50;
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
