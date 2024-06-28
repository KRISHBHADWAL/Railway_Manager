#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

// Train class definition
class Train {
public:
    int id;
    string name;
    string source;
    string destination;
    string departure_time;
    string arrival_time;
    int total_seats;
    int available_seats;

    Train(int id, string name, string source, string destination, string departure_time, string arrival_time, int total_seats) {
        this->id = id;
        this->name = name;
        this->source = source;
        this->destination = destination;
        this->departure_time = departure_time;
        this->arrival_time = arrival_time;
        this->total_seats = total_seats;
        this->available_seats = total_seats;
    }

    void displayTrainInfo() const {
        cout << "Train ID: " << id << "\nName: " << name << "\nSource: " << source << "\nDestination: " << destination
             << "\nDeparture Time: " << departure_time << "\nArrival Time: " << arrival_time 
             << "\nTotal Seats: " << total_seats << "\nAvailable Seats: " << available_seats << endl;
    }
};

// Booking class definition
class Booking {
public:
    int booking_id;
    int train_id;
    string passenger_name;
    int seat_number;

    Booking(int booking_id, int train_id, string passenger_name, int seat_number) {
        this->booking_id = booking_id;
        this->train_id = train_id;
        this->passenger_name = passenger_name;
        this->seat_number = seat_number;
    }

    void displayBookingInfo() const {
        cout << "Booking ID: " << booking_id << "\nTrain ID: " << train_id << "\nPassenger Name: " << passenger_name 
             << "\nSeat Number: " << seat_number << endl;
    }
};

// Railway Management System class definition
class RailwayManagementSystem {
private:
    vector<Train> trains;
    vector<Booking> bookings;
    map<int, int> trainBookingCounter; // Train ID -> Number of Bookings

public:
    void addTrain() {
        int id, total_seats;
        string name, source, destination, departure_time, arrival_time;
        
        cout << "Enter Train ID: ";
        cin >> id;
        cout << "Enter Train Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Source: ";
        getline(cin, source);
        cout << "Enter Destination: ";
        getline(cin, destination);
        cout << "Enter Departure Time: ";
        getline(cin, departure_time);
        cout << "Enter Arrival Time: ";
        getline(cin, arrival_time);
        cout << "Enter Total Seats: ";
        cin >> total_seats;

        Train new_train(id, name, source, destination, departure_time, arrival_time, total_seats);
        trains.push_back(new_train);
        trainBookingCounter[id] = 0;

        cout << "Train added successfully!" << endl;
    }

    void displayAllTrains() const {
        for (const auto& train : trains) {
            train.displayTrainInfo();
            cout << "---------------------" << endl;
        }
    }

    void bookTicket() {
        int train_id;
        string passenger_name;
        
        cout << "Enter Train ID: ";
        cin >> train_id;
        cout << "Enter Passenger Name: ";
        cin.ignore();
        getline(cin, passenger_name);

        for (auto& train : trains) {
            if (train.id == train_id && train.available_seats > 0) {
                int seat_number = train.total_seats - train.available_seats + 1;
                int booking_id = bookings.size() + 1;
                Booking new_booking(booking_id, train_id, passenger_name, seat_number);
                bookings.push_back(new_booking);
                train.available_seats--;
                trainBookingCounter[train_id]++;
                cout << "Ticket booked successfully!" << endl;
                new_booking.displayBookingInfo();
                return;
            }
        }
        cout << "Booking failed. Either the train ID is incorrect or there are no available seats." << endl;
    }

    void displayAllBookings() const {
        for (const auto& booking : bookings) {
            booking.displayBookingInfo();
            cout << "---------------------" << endl;
        }
    }

    void viewTrainSchedule() const {
        int train_id;
        cout << "Enter Train ID: ";
        cin >> train_id;
        for (const auto& train : trains) {
            if (train.id == train_id) {
                train.displayTrainInfo();
                return;
            }
        }
        cout << "Train not found." << endl;
    }

    void menu() {
        while (true) {
            cout << "\nRailway Management System\n";
            cout << "1. Add Train\n";
            cout << "2. View All Trains\n";
            cout << "3. Book Ticket\n";
            cout << "4. View All Bookings\n";
            cout << "5. View Train Schedule\n";
            cout << "6. Exit\n";
            cout << "Enter your choice: ";
            int choice;
            cin >> choice;

            switch (choice) {
                case 1:
                    addTrain();
                    break;
                case 2:
                    displayAllTrains();
                    break;
                case 3:
                    bookTicket();
                    break;
                case 4:
                    displayAllBookings();
                    break;
                case 5:
                    viewTrainSchedule();
                    break;
                case 6:
                    cout << "Exiting the system. Goodbye!" << endl;
                    return;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        }
    }
};

// Main function
int main() {
    RailwayManagementSystem rms;
    rms.menu();
    return 0;
}
