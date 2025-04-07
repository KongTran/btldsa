#include <iostream>
#include <ctime>
using namespace std;
int main() {
    tm checkIn = {}, checkOut = {};
    time_t checkInTime, checkOutTime;

    // Get Check-in Date and Time
    cout << "nhap thoi gian check-in (YYYY MM DD): ";
    cin >> checkIn.tm_year >> checkIn.tm_mon >> checkIn.tm_mday;
    
    // Convert input to correct format
    checkIn.tm_year -= 1900; // Year since 1900
    checkIn.tm_mon -= 1;     // Month (0-11)

    // Get Check-out Date and Time
    cout << "nhap thoi gian check-out (YYYY MM DD): ";
    cin >> checkOut.tm_year >> checkOut.tm_mon >> checkOut.tm_mday;
    
    // Convert input to correct format
    checkOut.tm_year -= 1900;
    checkOut.tm_mon -= 1;

    // Convert to time_t
    checkInTime = mktime(&checkIn);
    checkOutTime = mktime(&checkOut);

    // Validate input
    if (checkOutTime <= checkInTime) {
        cout << "loi: thoi gian check-out phai sau thoi gian check-in !\n";
        return 1;
    }

    // Calculate time difference
    double totalSeconds = difftime(checkOutTime, checkInTime);
    int days = totalSeconds / (60 * 60 * 24);
    
    // Display time spent
    cout << "\nso ngay o khack san: " << days << "\n";
    return 0;
}
