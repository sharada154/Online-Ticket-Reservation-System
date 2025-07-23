#include <iostream>
#include <fstream>
using namespace std;

class Ticket {
    string name;
    int age;
    float price;
    string eventName;

public:
    void getDetails() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter age: ";
        cin >> age;

        cout << "Select event:\n1. Concert\n2. Movie\nEnter choice: ";
        int choice;
        cin >> choice;
        eventName = (choice == 1) ? "Concert" : "Movie";
    }

    void calculatePrice() {
        if (age < 5) price = 0;
        else if (age <= 18) price = 50;
        else if (age <= 60) price = 100;
        else price = 70;
    }

    bool simulatePayment() {
        string confirm;
        cout << "Ticket Price is Rs. " << price << endl;
        cout << "Proceed to payment? (yes/no): ";
        cin >> confirm;
        return (confirm == "yes");
    }

    void saveToFile() {
        ofstream file("tickets.txt", ios::app);
        file << name << " " << age << " " << eventName << " Rs." << price << "\n";
        file.close();
    }

    void bookTicket() {
        getDetails();
        calculatePrice();
        if (simulatePayment()) {
            saveToFile();
            cout << "Booking successful! Ticket saved.\n";
        } else {
            cout << "Booking cancelled.\n";
        }
    }
};

int main() {
    Ticket t;
    t.bookTicket();
    return 0;
}
