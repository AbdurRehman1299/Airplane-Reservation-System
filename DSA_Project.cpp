#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
using namespace std;

struct Customer
{
    int customerID;
    string customerName;
    string passportNumber;
    string CNIC;
    Customer *next;
    Customer()
    {
        next = NULL;
    }
};

class CustomerManager
{
    Customer *head;

    void saveToFile()
    {
        ofstream file("customer.txt", ios::app);
        Customer *temp = head;
        while (temp != NULL)
        {
            file << temp->customerID << " " << temp->customerName << " " << temp->passportNumber << " " << temp->CNIC << endl;
            temp = temp->next;
        }
        file.close();
    }

public:
    CustomerManager()
    {
        head = NULL;
    }

    void loadFromFile()
    {
        Customer *temp;
        while (head != NULL)
        {
            temp = head;
            head = head->next;
            delete temp;
        }

        ifstream file("customer.txt");
        if (!file.is_open())
        {
            cout << "Error opening file." << endl;
        }
        else
        {
            int customerID;
            string customerName, passportNumber, CNIC;
            while (file >> customerID >> ws && getline(file, customerName, ' ') && getline(file, passportNumber, ' ') && getline(file, CNIC))
            {
                Customer *newCustomer = new Customer();
                newCustomer->customerID = customerID;
                newCustomer->customerName = customerName;
                newCustomer->passportNumber = passportNumber;
                newCustomer->CNIC = CNIC;
                newCustomer->next = head;
                head = newCustomer;
            }
            file.close();
        }
    }

    void addCustomer()
    {
        int customerID;
        string customerName, passportNumber, CNIC;
        cout << "Enter customer ID: ";
        cin >> customerID;
        cin.ignore();
        cout << "Enter customer name: ";
        getline(cin, customerName);
        cout << "Enter passport number: ";
        getline(cin, passportNumber);
        cout << "Enter CNIC number: ";
        getline(cin, CNIC);

        Customer *newCustomer = new Customer();
        newCustomer->customerID = customerID;
        newCustomer->customerName = customerName;
        newCustomer->passportNumber = passportNumber;
        newCustomer->CNIC = CNIC;
        if (head == NULL)
        {
            head = newCustomer;
        }
        else
        {
            Customer *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newCustomer;
        }
        saveToFile();
        cout << "Customer added successfully." << endl;
    }

    void displayCustomers()
    {
        Customer *temp = head;
        if (head == NULL)
        {
            cout << "No customers found." << endl;
        }
        else
        {
            cout << "===================================================================\n\n";
            cout << "                         Customer List\n\n";
            cout << "===================================================================\n\n";
            cout << left << setw(15) << "Customer ID"
                 << setw(20) << "Customer Name"
                 << setw(20) << "Passport Number"
                 << setw(10) << "Customer CNIC" << endl;
            cout << "-------------------------------------------------------------------\n";
            while (temp != NULL)
            {
                cout << left << setw(15) << temp->customerID
                     << setw(20) << temp->customerName
                     << setw(20) << temp->passportNumber
                     << setw(10) << temp->CNIC << endl;
                temp = temp->next;
            }
        }
    }

    Customer *findCustomerByPassport(string passportNumber)
    {
        Customer *temp = head;
        while (temp != NULL)
        {
            if (temp->passportNumber == passportNumber)
            {
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }
};

struct Flight
{
    string flightID;
    string destination, departureTime;
    int availableSeats, maxSeats;
    Flight *next;
    Flight()
    {
        next = NULL;
    }
};

class FlightManager
{
    Flight *head;
    void saveToFile()
    {
        ofstream file("flight.txt", ios::app);
        Flight *temp = head;
        while (temp != NULL)
        {
            file << temp->flightID << " " << temp->destination << " " << temp->departureTime << " " << temp->availableSeats << " " << temp->maxSeats << endl;
            temp = temp->next;
        }
        file.close();
    }

public:
    FlightManager()
    {
        head = NULL;
    }

    void loadFromFile()
    {
        Flight *temp;
        while (head != NULL)
        {
            temp = head;
            head = head->next;
            delete temp;
        }

        ifstream file("flight.txt");
        if (!file.is_open())
        {
            cout << "Error opening file." << endl;
        }
        else
        {
            string flightID, destination, departureTime;
            int availableSeats, maxSeats;
            while (file >> flightID >> ws && getline(file, destination, ' ') && getline(file, departureTime, ' ') && file >> availableSeats >> maxSeats)
            {
                Flight *newFlight = new Flight();
                newFlight->flightID = flightID;
                newFlight->destination = destination;
                newFlight->departureTime = departureTime;
                newFlight->availableSeats = availableSeats;
                newFlight->maxSeats = maxSeats;
                newFlight->next = head;
                head = newFlight;
            }
            file.close();
        }
    }

    void addFlight()
    {
        string flightID, destination, departureTime;
        int maxSeats;
        cout << "Enter flight ID: ";
        cin >> flightID;
        cin.ignore();
        cout << "Enter destination: ";
        getline(cin, destination);
        cout << "Enter departure time: ";
        getline(cin, departureTime);
        cout << "Enter maximum seats: ";
        cin >> maxSeats;
        Flight *newFlight = new Flight();
        newFlight->flightID = flightID;
        newFlight->destination = destination;
        newFlight->departureTime = departureTime;
        newFlight->availableSeats = maxSeats;
        newFlight->maxSeats = maxSeats;
        if (head == NULL)
        {
            head = newFlight;
        }
        else
        {
            Flight *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newFlight;
        }
        saveToFile();
        cout << "Flight added successfully." << endl;
    }

    void displayFlights()
    {
        Flight *temp = head;
        if (head == NULL)
        {
            cout << "No flights found." << endl;
        }
        else
        {
            cout << "================================================================\n\n";
            cout << "                         Flight List\n\n";
            cout << "================================================================\n\n";
            cout << left << setw(15) << "Flight ID"
                 << setw(20) << "Destination"
                 << setw(20) << "Departure Time"
                 << setw(10) << "Seats (Available/Total)" << endl;
            cout << "-----------------------------------------------------------------\n";
            while (temp != NULL)
            {
                cout << left << setw(15) << temp->flightID
                     << setw(20) << temp->destination
                     << setw(20) << temp->departureTime
                     << temp->availableSeats << "/" << temp->maxSeats << endl;
                temp = temp->next;
            }
        }
    }

    Flight *findFlight(string flightID)
    {
        Flight *temp = head;
        while (temp != NULL)
        {
            if (temp->flightID == flightID)
            {
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }

    void bookSeat(string flightID, string passportNumber, string destination, CustomerManager &customerManager)
    {
        Flight *flight = findFlight(flightID);
        if (flight == NULL)
        {
            cout << "Flight not found." << endl;
        }
        else if (flight->destination != destination)
        {
            cout << "Destination does not match the flight details." << endl;
        }
        Customer *customer = customerManager.findCustomerByPassport(passportNumber);
        if (customer == NULL)
        {
            cout << "Customer with passport number " << passportNumber << " not found\n";
        }
        else if (flight->availableSeats > 0)
        {
            flight->availableSeats--;
            saveToFile();
            cout << "Seat booked successfully for " << customer->customerName << endl;
        }
        else
        {
            cout << "No available seats" << endl;
        }
    }

    void cancelSeats(string flightID, string passportNumber, string destination, CustomerManager &customerManager)
    {
        Flight *flight = findFlight(flightID);
        if (flight == NULL)
        {
            cout << "Flight not found." << endl;
        }
        else if (flight->destination != destination)
        {
            cout << "Destination does not match the flight details." << endl;
        }
        Customer *customer = customerManager.findCustomerByPassport(passportNumber);
        if (customer == NULL)
        {
            cout << "Customer with passport number " << passportNumber << " not found\n";
        }
        else if (flight->availableSeats < flight->maxSeats)
        {
            flight->availableSeats++;
            saveToFile();
            cout << "Seat cancelled successfully for " << customer->customerName << endl;
        }
        else
        {
            cout << "No available seats to cancel" << endl;
        }
    }
};

int main()
{
    CustomerManager customerManager;
    customerManager.loadFromFile();
    FlightManager flightManager;
    flightManager.loadFromFile();
    int choice;
    do
    {
        system("clear");
        cout << "================================================================\n\n";
        cout << "                  Airline Management System\n\n";
        cout << "================================================================\n";
        cout << endl;
        cout << "1. Add Customer" << endl;
        cout << "2. Display Customers" << endl;
        cout << "3. Add Flight" << endl;
        cout << "4. Display Flights" << endl;
        cout << "5. Book Seat" << endl;
        cout << "6. Cancel Seat" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice (1-7): ";
        cin >> choice;
        cin.ignore();
        system("clear");
        if (choice == 1)
        {
            cout << "=== Add Customer ===\n\n";
            customerManager.addCustomer();
            cout << "\nPress Enter to return to the main menu...";
            cin.get();
            cout << endl;
        }
        else if (choice == 2)
        {
            customerManager.displayCustomers();
            cout << "\nPress Enter to return to the main menu...";
            cin.get();
            cout << endl;
        }
        else if (choice == 3)
        {
            cout << "=== Add Flight ===\n\n";
            flightManager.addFlight();
            cout << "\nPress Enter to return to the main menu...";
            cin.get();
            cout << endl;
        }
        else if (choice == 4)
        {
            flightManager.displayFlights();
            cout << "\nPress Enter to return to the main menu...";
            cin.get();
            cout << endl;
        }
        else if (choice == 5)
        {
            cout << "=== Book Seat ===\n\n";
            string flightID, passportNumber, destination;
            cout << "Enter flight ID: ";
            getline(cin, flightID);
            cout << "Enter passport number: ";
            getline(cin, passportNumber);
            cout << "Enter destination: ";
            getline(cin, destination);
            flightManager.bookSeat(flightID, passportNumber, destination, customerManager);
            cout << endl;
            cout << "\nPress Enter to return to the main menu...";
            cin.get();
        }
        else if (choice == 6)
        {
            cout << "=== Cancel Seat ===\n\n";
            string flightID, passportNumber, destination;
            cout << "Enter flight ID: ";
            getline(cin, flightID);
            cout << "Enter passport number: ";
            getline(cin, passportNumber);
            cout << "Enter destination: ";
            getline(cin, destination);
            flightManager.cancelSeats(flightID, passportNumber, destination, customerManager);
            cout << endl;
            cout << "\nPress Enter to return to the main menu...";
            cin.get();
        }
        else if (choice == 7)
        {
            cout << "Exiting the program. Thank you for using Airline Management System" << endl;
            break;
        }
        else
        {
            cout << "Invalid choice. Please try again." << endl;
            cout << "\nPress Enter to return to the main menu...";
            cin.get();
            cout << endl;
        }
    } while (choice != 7);
    return 0;
}