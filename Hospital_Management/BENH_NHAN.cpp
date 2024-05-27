#ifndef BENHNHAN_CPP
#define BENHNHAN_CPP
#include "NGUOI.CPP"
#include "THAN_NHAN.CPP"
#include <iomanip>

class BenhNhan : public Nguoi {
protected:
    string maBenhNhan;
    ThanNhan thanNhan;
    static int soMaBenhNhan;
    int dangNamVien; // 1: Dang nam vien, 0: Da ra vien
public:
    BenhNhan();
    BenhNhan(string hoTen, string ngaySinh, string soCMND, string diaChi, int gioiTinh, 
              string soDienThoai, string email, int dangNamVien, ThanNhan thanNhan);
    void nhap();
    void xuat();
    string getMaBenhNhan();
    int getDangNamVien();
    void setDangNamVien(int dangNamVien);
    ThanNhan getThanNhan();
    void setThanNhan(ThanNhan thanNhan);
    ~BenhNhan();
};

int BenhNhan::soMaBenhNhan = 0;

BenhNhan::BenhNhan() : Nguoi(){
    stringstream ss;
    ss << setw(5) << setfill('0') << soMaBenhNhan++;
    this->maBenhNhan = "BN" + ss.str();
    this->thanNhan = ThanNhan();
}

BenhNhan::BenhNhan(string hoTen, string ngaySinh, string soCMND, string diaChi, int gioiTinh, 
                   string soDienThoai, string email, int dangnamVien, ThanNhan thanNhan) : 
                   Nguoi(hoTen, ngaySinh, soCMND, diaChi, gioiTinh, soDienThoai, email){
    stringstream ss;
    ss << setw(5) << setfill('0') << soMaBenhNhan++;
    this->maBenhNhan = "BN" + ss.str();
    this->thanNhan = thanNhan;
    this->dangNamVien = dangNamVien;
}

void BenhNhan::nhap(){
    Nguoi::nhap();
    cout << "Nhap trang thai cua benh nhan (1: Dang nam vien, 0: Da ra vien): ";
    this->thanNhan.nhap();
}

void BenhNhan::xuat(){
    Nguoi::xuat();
    cout << "Ma benh nhan: " << this->maBenhNhan << endl;
    cout << "Dang nam vien: " << (this->dangNamVien == 1 ? "Dang nam vien" : "Da ra vien") << endl;
    cout << "Than nhan cua benh nhan nay la:\n";
    this->thanNhan.xuat();
}

string BenhNhan::getMaBenhNhan(){
    return this->maBenhNhan;
}

ThanNhan BenhNhan::getThanNhan(){
    return this->thanNhan;
}

void BenhNhan::setThanNhan(ThanNhan thanNhan){
    this->thanNhan = thanNhan;
}

int BenhNhan::getDangNamVien(){
    return this->dangNamVien;
}

void BenhNhan::setDangNamVien(int dangNamVien){
    this->dangNamVien = dangNamVien;
}

BenhNhan::~BenhNhan(){
}

#endif