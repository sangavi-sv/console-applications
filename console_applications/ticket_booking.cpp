#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Coach {
public:
    string type;
    vector<bool> seats;
    int waitingList;
    const int maxSeats = 60;
    const int maxWaitlist = 10;

    Coach() {
        type = "";
        waitingList = 0;
        seats.resize(maxSeats, false);
    }

    void setType(string coachType) {
        type = coachType;
    }

    bool bookTicket() {
        for (int i = 0; i < maxSeats; ++i) {
            if (!seats[i]) {
                seats[i] = true; 
                cout << "Ticket booked in " << type << " coach, seat number: " << (i + 1) << endl;
                return true;
            }
        }
        if (waitingList < maxWaitlist) {
            waitingList++;
            cout << "No seats available. Added to waiting list. Current waiting list count: " << waitingList << endl;
            return true;
        }
        cout << "Booking failed! No seats and waiting list full." << endl;
        return false;
    }

    bool cancelTicket(int seatNumber) {
        if (seatNumber < 1 || seatNumber > maxSeats) {
            cout << "Invalid seat number." << endl;
            return false;
        }
        if (seats[seatNumber - 1]) {
            seats[seatNumber - 1] = false;
            cout << "Ticket cancelled for seat number: " << seatNumber << endl;
            if (waitingList > 0) {
                waitingList--; 
                cout << "One ticket from waiting list has been confirmed." << endl;
            }
            return true;
        }
        cout << "No booking found for seat number: " << seatNumber << endl;
        return false;
    }

    void checkStatus() {
        cout << type << " coach status: " << endl;
        for (int i = 0; i < maxSeats; ++i) {
            cout << "Seat " << (i + 1) << ": " << (seats[i] ? "Booked" : "Available") << endl;
        }
        cout << "Current waiting list: " << waitingList << endl;
    }
};

class RailwayReservation {
private:
    Coach acCoach;
    Coach nonAcCoach;
    Coach seaterCoach;

public:
    RailwayReservation() {
        acCoach.setType("AC");
        nonAcCoach.setType("Non AC");
        seaterCoach.setType("Seater");
    }

    void bookTicket() {
        int choice;
        cout << "Select coach type:\n1. AC\n2. Non AC\n3. Seater\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: acCoach.bookTicket(); break;
            case 2: nonAcCoach.bookTicket(); break;
            case 3: seaterCoach.bookTicket(); break;
            default: cout << "Invalid choice." << endl;
        }
    }

    void cancelTicket() {
        int choice, seatNumber;
        cout << "Select coach type:\n1. AC\n2. Non AC\n3. Seater\nEnter your choice: ";
        cin >> choice;
        cout << "Enter seat number to cancel: ";
        cin >> seatNumber;

        switch (choice) {
            case 1: acCoach.cancelTicket(seatNumber); break;
            case 2: nonAcCoach.cancelTicket(seatNumber); break;
            case 3: seaterCoach.cancelTicket(seatNumber); break;
            default: cout << "Invalid choice." << endl;
        }
    }

    void checkStatus() {
        int choice;
        cout << "Select coach type:\n1. AC\n2. Non AC\n3. Seater\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: acCoach.checkStatus(); break;
            case 2: nonAcCoach.checkStatus(); break;
            case 3: seaterCoach.checkStatus(); break;
            default: cout << "Invalid choice." << endl;
        }
    }
};

int main() {
    RailwayReservation reservation;
    int option;

    do {
        cout << "\nRailway Reservation System\n";
        cout << "1. Book Ticket\n";
        cout << "2. Cancel Ticket\n";
        cout << "3. Check Status\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> option;

        switch (option) {
            case 1: reservation.bookTicket(); break;
            case 2: reservation.cancelTicket(); break;
            case 3: reservation.checkStatus(); break;
            case 4: cout << "Exiting..." << endl; break;
            default: cout << "Invalid choice." << endl;
        }
    } while (option != 4);

    return 0;
}
