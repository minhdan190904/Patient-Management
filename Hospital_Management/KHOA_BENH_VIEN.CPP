#ifndef KHOABENHVIEN_CPP
#define KHOABENHVIEN_CPP
#include "NHAN_VIEN_Y_TE.cpp"
#include "PHONG.cpp"
#include <vector>
#include <sstream>
#include <iomanip>

class KhoaBenhVien {
private:
    string maKhoa;
    static int soMaKhoa;
    string tenKhoa;
    vector<NhanVienYTe> nhanVienYTe;
    vector<Phong> phong;
    int soLuongPhong; // So luong phong cua khoa benh vien toi da co the co
public:
    KhoaBenhVien();
    KhoaBenhVien(string tenKhoa, int soLuongPhong);
    void nhap();
    void xuat();
    string getMaKhoa();
    string getTenKhoa();
    vector<NhanVienYTe>& getNhanVienYTe();
    vector<Phong>& getPhong();
    int getSoLuongPhong();
    void setMaKhoa(string maKhoa);
    void setTenKhoa(string tenKhoa);
    void setNhanVienYTe(vector<NhanVienYTe> nhanVienYTe);
    void setPhong(vector<Phong> phong);
    void setSoLuongPhong(int soLuongPhong);
    void addPhong(Phong phong);
    bool kiemTraSoPhongDay();
    void xoaPhong(string maPhong);
    void addNhanVienYTe(NhanVienYTe nhanVienYTe);
    void xoaNhanVienYTe(string maNhanVien);
    ~KhoaBenhVien();
};

int KhoaBenhVien::soMaKhoa = 0;

KhoaBenhVien::KhoaBenhVien(){
    stringstream ss;
    ss << setw(5) << setfill('0') << soMaKhoa++;
    this->maKhoa = "K" + ss.str();
    this->tenKhoa = "";
    this->soLuongPhong = 0;
}

KhoaBenhVien::KhoaBenhVien(string tenKhoa, int soLuongPhong){
    stringstream ss;
    ss << setw(5) << setfill('0') << soMaKhoa++;
    this->maKhoa = "K" + ss.str();
    this->tenKhoa = tenKhoa;
    this->soLuongPhong = soLuongPhong;
}

void KhoaBenhVien::nhap() {
    stringstream ss;
    ss << setw(5) << setfill('0') << soMaKhoa++;
    this->maKhoa = "K" + ss.str();
    cout << "Nhap ten khoa: ";
    fflush(stdin);
    getline(cin, this->tenKhoa);
    cout << "Nhap so luong phong: ";
    cin >> this->soLuongPhong;
}// se them nhan vien y te va phong sau

void KhoaBenhVien::xuat() {
    cout << "Ma khoa: " << this->maKhoa << endl;
    cout << "Ten khoa: " << this->tenKhoa << endl;
    cout << "So luong phong: " << this->soLuongPhong << endl;
    cout << "Danh sach nhan vien y te: " << endl;
    for (int i = 0; i < this->nhanVienYTe.size(); i++) {
        this->nhanVienYTe[i].xuat();
    }
    cout << "Danh sach phong: " << endl;
    for (int i = 0; i < this->phong.size(); i++) {
        this->phong[i].xuat();
    }
}

string KhoaBenhVien::getMaKhoa() {
    return this->maKhoa;
}

string KhoaBenhVien::getTenKhoa() {
    return this->tenKhoa;
}

vector<NhanVienYTe>& KhoaBenhVien::getNhanVienYTe() {
    return this->nhanVienYTe;
}

vector<Phong>& KhoaBenhVien::getPhong() {
    return this->phong;
}

int KhoaBenhVien::getSoLuongPhong() {
    return this->soLuongPhong;
}

void KhoaBenhVien::setMaKhoa(string maKhoa) {
    this->maKhoa = maKhoa;
}

void KhoaBenhVien::setTenKhoa(string tenKhoa) {
    this->tenKhoa = tenKhoa;
}

void KhoaBenhVien::setNhanVienYTe(vector<NhanVienYTe> nhanVienYTe) {
    this->nhanVienYTe = nhanVienYTe;
}

void KhoaBenhVien::setPhong(vector<Phong> phong) {
    this->phong = phong;
}

void KhoaBenhVien::setSoLuongPhong(int soLuongPhong) {
    this->soLuongPhong = soLuongPhong;
}

void KhoaBenhVien::addPhong(Phong phong) {
    if(this->phong.size() < this->soLuongPhong) this->phong.push_back(phong);
    else cout << "Khoa benh vien da day phong" << endl;
}

bool KhoaBenhVien::kiemTraSoPhongDay() {
    return this->phong.size() == this->soLuongPhong;
}

void KhoaBenhVien::xoaPhong(string maPhong) {
    for (int i = 0; i < this->phong.size(); i++) {
        if (this->phong[i].getMaPhong() == maPhong) {
            this->phong.erase(this->phong.begin() + i);
            return;
        }
    }
}

void KhoaBenhVien::addNhanVienYTe(NhanVienYTe nhanVienYTe) {
    this->nhanVienYTe.push_back(nhanVienYTe);
}

void KhoaBenhVien::xoaNhanVienYTe(string maNhanVien) {
    for (int i = 0; i < this->nhanVienYTe.size(); i++) {
        if (this->nhanVienYTe[i].getMaNhanVien() == maNhanVien) {
            this->nhanVienYTe.erase(this->nhanVienYTe.begin() + i);
            return;
        }
    }
}

KhoaBenhVien::~KhoaBenhVien() {
}

#endif