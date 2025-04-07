#include <iostream>
#include <map>
#include <vector>
#include <ctime>
#include <string>
using namespace std;

struct KhachHang {
    string ten;
    string cccd;
    string soDienThoai;
    string loaiPhong;
    tm checkIn = {};
    tm checkOut = {};
};

struct Phong {
    int soLuong;
    int gia;
};

class Hotel {
private:
    map<string, Phong> danhSachPhong;
    vector<KhachHang> danhSachKhach;
    int dichVuPhong = 350000;

public:
    Hotel() {
        danhSachPhong["Thuong_Lon_2_Doi"] = {5, 1200000};
        danhSachPhong["Thuong_Nho_1_Doi"] = {10, 800000};
        danhSachPhong["Thuong_Nho_2_Don"] = {10, 800000};
        danhSachPhong["VIP"] = {3, 2500000};
    }

    void hienThiPhong() {
        cout << "Danh sach phong:\n";
        for (const auto &p : danhSachPhong) {
            cout << p.first << " - So luong: " << p.second.soLuong 
                 << " - Gia: " << p.second.gia << " VND\n";
        }
        cout << "Dich vu phong: " << dichVuPhong << " VND\n";
    }

    void themKhach() {
        KhachHang khach;
        cout << "Nhap ten khach hang: ";
        cin.ignore();
        getline(cin, khach.ten);
        cout << "Nhap CCCD: ";
        getline(cin, khach.cccd);
        cout << "Nhap so dien thoai: ";
        cin >> khach.soDienThoai;
        cout << "Nhap loai phong muon dat: ";
        cin >> khach.loaiPhong;
        
        if (danhSachPhong[khach.loaiPhong].soLuong > 0) {
            danhSachPhong[khach.loaiPhong].soLuong--;
            cout << "Nhap thoi gian check-in (YYYY MM DD): ";
            cin >> khach.checkIn.tm_year >> khach.checkIn.tm_mon >> khach.checkIn.tm_mday;
            khach.checkIn.tm_year -= 1900;
            khach.checkIn.tm_mon -= 1;
            danhSachKhach.push_back(khach);
            cout << "Dat phong thanh cong!\n";
        } else {
            cout << "Het phong!\n";
        }
    }

    void hienThiKhach() {
        if (danhSachKhach.empty()) {
            cout << "Khong co khach hang nao.\n";
            return;
        }
        cout << "Danh sach khach hang:\n";
        for (const auto &khach : danhSachKhach) {
            cout << "Ten: " << khach.ten << " - CCCD: " << khach.cccd << " - Phong: " << khach.loaiPhong << "\n";
        }
    }

    void checkOut() {
        string cccd;
        cout << "Nhap CCCD khach check-out: ";
        cin >> cccd;

        for (auto it = danhSachKhach.begin(); it != danhSachKhach.end(); ++it) {
            if (it->cccd == cccd) {
                cout << "Nhap thoi gian check-out (YYYY MM DD): ";
                cin >> it->checkOut.tm_year >> it->checkOut.tm_mon >> it->checkOut.tm_mday;
                it->checkOut.tm_year -= 1900;
                it->checkOut.tm_mon -= 1;
                
                time_t checkInTime = mktime(&it->checkIn);
                time_t checkOutTime = mktime(&it->checkOut);
                if (checkOutTime <= checkInTime) {
                    cout << "Loi: Check-out phai sau check-in!\n";
                    return;
                }
                int days = difftime(checkOutTime, checkInTime) / (60 * 60 * 24);
                int tongTien = danhSachPhong[it->loaiPhong].gia * days + dichVuPhong;
                danhSachPhong[it->loaiPhong].soLuong++;
                cout << "Khach " << it->ten << " da check-out. So ngay o: " << days << " - Tong tien: " << tongTien << " VND\n";
                danhSachKhach.erase(it);
                return;
            }
        }
        cout << "Khong tim thay khach hang voi CCCD nay!\n";
    }
};

int main() {
    Hotel khachSan;
    int luaChon;
    do {
        cout << "\nMenu:\n1. Hien thi phong\n2. Them khach hang\n3. Hien thi danh sach khach\n4. Check-out\n5. Thoat\nNhap lua chon: ";
        cin >> luaChon;
        switch (luaChon) {
            case 1:
                khachSan.hienThiPhong();
                break;
            case 2:
                khachSan.themKhach();
                break;
            case 3:
                khachSan.hienThiKhach();
                break;
            case 4:
                khachSan.checkOut();
                break;
            case 5:
                cout << "Thoat chuong trinh.\n";
                break;
            default:
                cout << "Lua chon khong hop le, vui long nhap lai.\n";
        }
    } while (luaChon != 5);
    return 0;
}