#include<iostream>
#include<string>
#include<ctime>
using namespace std;
const int maxkhach=100;
int lgkhach=0;
tm checkIn = {}, checkOut = {};
time_t checkInTime, checkOutTime;
struct khach{
    string ten;
    string cccd;
    tm checkIn = {};
};
struct khach khach[maxkhach];
void themkhach(){
    if(lgkhach>=maxkhach){
        cout << "luong khach vuot muc!";
        return;
    }
    cout << "nhap thong tin khach hang:\n";
    cout << "ten: ";
    getline(cin,khach[lgkhach].ten);
    cout << "cccd: ";
    getline(cin,khach[lgkhach].cccd);
    cout << "nhap thoi gian check-in (YYYY MM DD): ";
    cin >> checkIn.tm_year >> checkIn.tm_mon >> checkIn.tm_mday;
    checkIn.tm_year -= 1900; 
    checkIn.tm_mon -= 1;   
    lgkhach++;
}
void hienThiKhach() {
    if (lgkhach == 0) {
        cout << "Chua co khach hang nao trong danh sach.\n";
        return;
    }

    cout << "\nDanh sach khach hang:\n";
    for (int i = 0; i < lgkhach; i++) {
        cout << "Khach " << i + 1 << ": " << khach[i].ten << ", " << khach[i].cccd << "\n";
    }
}
void timKhach(const string &tenCanTim) {
    bool found = false;
    for (int i = 0; i < lgkhach; i++) {
        if (khach[i].ten == tenCanTim) {
            cout << "\nKhach hang tim thay:\n";
            cout << "Ten: " << khach[i].ten
                      << ", cccd: " << khach[i].cccd << "\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Khong tim thay khach hang ten \"" << tenCanTim << "\".\n";
    }
}
void khachchkout(){
        cout << "nhap thoi gian check-out (YYYY MM DD): ";
        cin >> checkOut.tm_year >> checkOut.tm_mon >> checkOut.tm_mday;
        
        checkOut.tm_year -= 1900;
        checkOut.tm_mon -= 1;

        checkInTime = mktime(&checkIn);
        checkOutTime = mktime(&checkOut);
    if (checkOutTime <= checkInTime) {
        cout << "loi: thoi gian check-out phai sau thoi gian check-in !\n";
        return;
    }

    double totalSeconds = difftime(checkOutTime, checkInTime);
    int days = totalSeconds / (60 * 60 * 24);
    
    cout << "\nso ngay o khack san: " << days << "\n";
    lgkhach--;
}
int main(){
    int luaChon;
    string tenCanTim;

    do {
        cout << "\n===== Quan Ly Khach Hang =====\n";
        cout << "1. Them khach hang\n";
        cout << "2. Hien thi danh sach khach hang\n";
        cout << "3. Tim khach hang theo ten\n";
        cout << "4. khach hang check-out\n";
        cout << "5. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> luaChon;
        cin.ignore();

        switch (luaChon) {
            case 1:
                themkhach();
                break;
            case 2:
                hienThiKhach();
                break;
            case 3:
                cout << "Nhap ten khach can tim: ";
                getline(cin, tenCanTim);
                timKhach(tenCanTim);
                break;
            case 4:
                cout << "Nhap ten khach can tim: ";
                getline(cin, tenCanTim);
                timKhach(tenCanTim);
                khachchkout();
                break;
            case 5:
                cout << "Thoat chuong trinh.\n";
                break;
            default:
                cout << "Lua chon khong hop le. Vui long chon lai!\n";
        }
    } while (luaChon != 4);

    return 0;
}

