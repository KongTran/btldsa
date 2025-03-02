#include <iostream>
#include <string>
using namespace std;

class Hotel {
private:
    int totalRooms;
    string* rooms;

public:
    // Constructor to initialize hotel with total rooms
    Hotel(int total) {
        totalRooms = total;
        rooms = new string[totalRooms];
        for (int i = 0; i < totalRooms; ++i) {
            rooms[i] = ""; // Empty room at the beginning
        }
    }

    // Destructor to free dynamically allocated memory
    ~Hotel() {
        delete[] rooms;
    }     


    

    // Check-in a guest
    void checkIn(const string& guestName) {
        for (int i = 0; i < totalRooms; ++i) {
            if (rooms[i] == "") {
                rooms[i] = guestName;
                cout << "Guest '" << guestName << "' has checked in to room " << i + 1 << ".\n";
                return;
            }
        }
        cout << "No rooms available. Please try again later.\n";
    }

    // Check-out a guest from a specific room
    void checkOut(int roomNumber) {
        if (roomNumber <= 0 || roomNumber > totalRooms) {
            cout << "Invalid room number.\n";
            return;
        }
        if (rooms[roomNumber - 1] == "") {
            cout << "Room " << roomNumber << " is already empty.\n";
        } else {
            cout << "Guest '" << rooms[roomNumber - 1] << "' has checked out from room " << roomNumber << ".\n";
            rooms[roomNumber - 1] = ""; // Free the room
        }
    }

    // Display available rooms
    void showAvailableRooms() {
        cout << "Available rooms:\n";
        for (int i = 0; i < totalRooms; ++i) {
            if (rooms[i] == "") {
                cout << "Room " << i + 1 << " is available.\n";
            }
        }
    }

    // Display occupied rooms
    void showOccupiedRooms() {
        cout << "Occupied rooms:\n";
        for (int i = 0; i < totalRooms; ++i) {
            if (rooms[i] != "") {
                cout << "Room " << i + 1 << " is occupied by " << rooms[i] << ".\n";
            }
        }
    }
};

// Main function to run the program
int main() {
    cout << "Welcome to the Hotel Management System\n";
    Hotel hotel(5);  // Initialize a hotel with 5 rooms

    while (true) {
        cout << "\n1. Check In\n";
        cout << "2. Check Out\n";
        cout << "3. View Available Rooms\n";
        cout << "4. View Occupied Rooms\n";
        cout << "5. Exit\n";
        cout << "Choose an option: ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            cin.ignore(); // To discard the newline character
            string guestName;
            cout << "Enter guest name: ";
            getline(cin, guestName);
            hotel.checkIn(guestName);
        }
        else if (choice == 2) {
            int roomNumber;
            cout << "Enter room number to check out: ";
            cin >> roomNumber;
            hotel.checkOut(roomNumber);
        }
        else if (choice == 3) {
            hotel.showAvailableRooms();
        }
        else if (choice == 4) {
            hotel.showOccupiedRooms();
        }
        else if (choice == 5) {
            cout << "Exiting the Hotel Management System. Goodbye!\n";
            break;
        } 
        else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
