#ifndef PHONG_CPP
#define PHONG_CPP
#include "NHAN_VIEN_Y_TE.cpp"
#include "BENH_NHAN.cpp"
#include <vector>
#include <sstream>
#include <iomanip>

class Phong {
private:
    static int soLuongBenhNhanDangNamVien;
    string maPhong;
    static int soMaPhong;
    string tenPhong;
    vector<NhanVienYTe> nhanVienYTe; // Danh sach nhan vien y te cham soc benh nhan
    vector<BenhNhan> benhNhan;
    int soLuongGiuongBenh; // So luong giuong benh cua phong tuc la so luong benh nhan toi da co the cham soc trong phong
public:
    Phong();
    Phong(string tenPhong, int soLuongGiuongBenh);
    void nhap();
    void xuat();
    string getMaPhong();
    string getTenPhong();
    vector<NhanVienYTe>& getNhanVienYTe();
    vector<BenhNhan>& getBenhNhan();
    int getSoLuongGiuongBenh();
    void setMaPhong(string maPhong);
    void setTenPhong(string tenPhong);
    void setNhanVienYTe(vector<NhanVienYTe> nhanVienYTe);
    void setBenhNhan(vector<BenhNhan> benhNhan);
    void setSoLuongGiuongBenh(int soLuongGiuongBenh);
    void addBenhNhan(BenhNhan benhNhan);
    void addNhanVienYTe(NhanVienYTe nhanVienYTe);
    bool kiemTraPhongDay();
    void xoaBenhNhan(string maBenhNhan);
    ~Phong();
};

int Phong::soMaPhong = 0;
int Phong::soLuongBenhNhanDangNamVien = 0;

Phong::Phong(){
    stringstream ss;
    ss << setw(5) << setfill('0') << soMaPhong++;
    this->maPhong = "P" + ss.str();
    this->tenPhong = "";
    this->soLuongGiuongBenh = 0;
}

Phong::Phong(string tenPhong, int soLuongGiuongBenh){
    stringstream ss;
    ss << setw(5) << setfill('0') << soMaPhong++;
    this->maPhong = "P" + ss.str();
    this->tenPhong = tenPhong;
    this->soLuongGiuongBenh = soLuongGiuongBenh;
}

void Phong::nhap() {
    stringstream ss;
    ss << setw(5) << setfill('0') << soMaPhong++;
    this->maPhong = "P" + ss.str();
    cout << "Nhap ten phong: ";
    fflush(stdin);
    getline(cin, this->tenPhong);
    cout << "Nhap so luong giuong benh: ";
    cin >> this->soLuongGiuongBenh;
    cout << "Nhap danh sach nhan vien y te: " << endl;
    int n;
    cout << "Nhap so luong nhan vien y te: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        NhanVienYTe nhanVienYTe;
        nhanVienYTe.nhap();
        this->nhanVienYTe.push_back(nhanVienYTe);
    }
} // khong nhap benh nhan vi phong chua co benh nhan va se them benh nhan sau

void Phong::xuat() {
    cout << "Ma phong: " << this->maPhong << endl;
    cout << "Ten phong: " << this->tenPhong << endl;
    cout << "So luong giuong benh: " << this->soLuongGiuongBenh << endl;
    cout << "Danh sach nhan vien y te: " << endl;
    for (int i = 0; i < this->nhanVienYTe.size(); i++) {
        this->nhanVienYTe[i].xuat();
    }
    cout << "Danh sach benh nhan: " << endl;
    for (int i = 0; i < this->benhNhan.size(); i++) {
        this->benhNhan[i].xuat();
    }
}

string Phong::getMaPhong() {
    return this->maPhong;
}

string Phong::getTenPhong() {
    return this->tenPhong;
}

vector<NhanVienYTe>& Phong::getNhanVienYTe() {
    return this->nhanVienYTe;
}

vector<BenhNhan>& Phong::getBenhNhan() {
    return this->benhNhan;
}

int Phong::getSoLuongGiuongBenh() {
    return this->soLuongGiuongBenh;
}

void Phong::setMaPhong(string maPhong) {
    this->maPhong = maPhong;
}

void Phong::setTenPhong(string tenPhong) {
    this->tenPhong = tenPhong;
}

void Phong::setNhanVienYTe(vector<NhanVienYTe> nhanVienYTe) {
    this->nhanVienYTe = nhanVienYTe;
}

void Phong::setBenhNhan(vector<BenhNhan> benhNhan) {
    this->benhNhan = benhNhan;
}

void Phong::setSoLuongGiuongBenh(int soLuongGiuongBenh) {
    this->soLuongGiuongBenh = soLuongGiuongBenh;
}

void Phong::addBenhNhan(BenhNhan benhNhan) {
    if (this->benhNhan.size() < this->soLuongGiuongBenh){
        this->benhNhan.push_back(benhNhan);
        if (benhNhan.getDangNamVien() == 1) soLuongBenhNhanDangNamVien++;
    }
    else cout << "Phong da day" << endl;
}

void Phong::addNhanVienYTe(NhanVienYTe nhanVienYTe) {
    this->nhanVienYTe.push_back(nhanVienYTe);
}

bool Phong::kiemTraPhongDay() {
    return this->soLuongGiuongBenh = soLuongBenhNhanDangNamVien;
}

void Phong::xoaBenhNhan(string maBenhNhan) {
    for (int i = 0; i < this->benhNhan.size(); i++) {
        if (this->benhNhan[i].getMaBenhNhan() == maBenhNhan) {
            this->benhNhan.erase(this->benhNhan.begin() + i);
            return;
        }
    }
}

Phong::~Phong() {
}

#endif