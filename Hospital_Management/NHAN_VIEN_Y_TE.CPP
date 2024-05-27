#ifndef NHANVIENYTE_CPP
#define NHANVIENYTE_CPP
#include "NGUOI.cpp"
#include <iomanip>

class NhanVienYTe : public Nguoi{
    protected:
    string maNhanVien;
    string chucVu;
    string bangCap;
    double heSoLuong;
    static int soMaNhanVien;
    public:
    NhanVienYTe();
    NhanVienYTe(string hoTen, string ngaySinh, string soCMND, string diaChi, int gioiTinh, string soDienThoai, string email, string chucVu, string bangCap, double heSoLuong);
    void nhap();
    void xuat();
    string getMaNhanVien();
    string getChucVu();
    string getBangCap();
    double getHeSoLuong();
    void setChucVu(string chucVu);
    void setBangCap(string bangCap);
    void setHeSoLuong(double heSoLuong);
    ~NhanVienYTe();
};

int NhanVienYTe::soMaNhanVien = 0;

NhanVienYTe::NhanVienYTe() : Nguoi(){
    stringstream ss;
    ss << setw(5) << setfill('0') << soMaNhanVien++;
    this->maNhanVien = "NV" + ss.str();
    this->chucVu = "";
    this->bangCap = "";
    this->heSoLuong = 0;
}

NhanVienYTe::NhanVienYTe(string hoTen, string ngaySinh, string soCMND, string diaChi, int gioiTinh, string soDienThoai, string email, string chucVu, string bangCap, double heSoLuong) : Nguoi(hoTen, ngaySinh, soCMND, diaChi, gioiTinh, soDienThoai, email){
    stringstream ss;
    ss << setw(5) << setfill('0') << soMaNhanVien++;
    this->maNhanVien = "NV" + ss.str();
    this->chucVu = chucVu;
    this->bangCap = bangCap;
    this->heSoLuong = heSoLuong;
}

void NhanVienYTe::nhap(){
    Nguoi::nhap();
    cout << "Nhap chuc vu: ";
    fflush(stdin);
    getline(cin, this->chucVu);
    cout << "Nhap bang cap: ";
    fflush(stdin);
    getline(cin, this->bangCap);
    cout << "Nhap he so luong: ";
    cin >> this->heSoLuong;
}

void NhanVienYTe::xuat(){
    Nguoi::xuat();
    cout << "Ma nhan vien: " << this->maNhanVien << endl;
    cout << "Chuc vu: " << this->chucVu << endl;
    cout << "Bang cap: " << this->bangCap << endl;
    cout << "He so luong: " << this->heSoLuong << endl;
}

string NhanVienYTe::getMaNhanVien(){
    return this->maNhanVien;
}

string NhanVienYTe::getChucVu(){
    return this->chucVu;
}

string NhanVienYTe::getBangCap(){
    return this->bangCap;
}

double NhanVienYTe::getHeSoLuong(){
    return this->heSoLuong;
}

void NhanVienYTe::setChucVu(string chucVu){
    this->chucVu = chucVu;
}

void NhanVienYTe::setBangCap(string bangCap){
    this->bangCap = bangCap;
}

void NhanVienYTe::setHeSoLuong(double heSoLuong){
    this->heSoLuong = heSoLuong;
}

NhanVienYTe::~NhanVienYTe(){
}

#endif