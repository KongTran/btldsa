#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

class Hotel {
private:
    struct Phong {
        int soLuong;
        int gia;
    };
    
    struct KhachHang {
        string ten;
        string soDienThoai;
        string loaiPhong;
    };

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

    bool kiemTraPhongTrong(const string &loaiPhong) {
        return danhSachPhong.count(loaiPhong) && danhSachPhong[loaiPhong].soLuong > 0;
    }

    void datPhong() {
        string ten, sdt, loaiPhong;
        cout << "Nhap ten khach hang: ";
        cin.ignore();
        getline(cin, ten);
        cout << "Nhap so dien thoai: ";
        cin >> sdt;
        cout << "Nhap loai phong muon dat: ";
        cin >> loaiPhong;
        
        if (kiemTraPhongTrong(loaiPhong)) {
            danhSachPhong[loaiPhong].soLuong--;
            danhSachKhach.push_back({ten, sdt, loaiPhong});
            cout << "Dat phong thanh cong cho khach: " << ten << "\n";
        } else {
            cout << "Het phong!\n";
        }
    }

    void huyPhong() {
        string sdt;
        cout << "Nhap so dien thoai cua khach muon huy phong: ";
        cin >> sdt;
        
        for (auto it = danhSachKhach.begin(); it != danhSachKhach.end(); ++it) {
            if (it->soDienThoai == sdt) {
                danhSachPhong[it->loaiPhong].soLuong++;
                cout << "Huy dat phong thanh cong cho khach: " << it->ten << "\n";
                danhSachKhach.erase(it);
                return;
            }
        }
        cout << "Khong tim thay khach hang voi so dien thoai nay!\n";
    }

    void xuatHoaDon() {
        string sdt;
        cout << "Nhap so dien thoai cua khach de xuat hoa don: ";
        cin >> sdt;
        
        for (const auto &khach : danhSachKhach) {
            if (khach.soDienThoai == sdt) {
                int tongTien = danhSachPhong[khach.loaiPhong].gia + dichVuPhong;
                cout << "\nHOA DON\nKhach hang: " << khach.ten << "\nSo dien thoai: " << khach.soDienThoai
                     << "\nLoai phong: " << khach.loaiPhong << "\nTong tien: " << tongTien << " VND\n";
                return;
            }
        }
        cout << "Khong tim thay khach hang voi so dien thoai nay!\n";
    }
};

int main() {
    Hotel khachSan;
    int luaChon;
    do {
        cout << "\nMenu:\n1. Hien thi phong\n2. Dat phong\n3. Huy phong\n4. Xuat hoa don\n5. Thoat\nNhap lua chon: ";
        cin >> luaChon;
        
        switch (luaChon) {
            case 1:
                khachSan.hienThiPhong();
                break;
            case 2:
                khachSan.datPhong();
                break;
            case 3:
                khachSan.huyPhong();
                break;
            case 4:
                khachSan.xuatHoaDon();
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