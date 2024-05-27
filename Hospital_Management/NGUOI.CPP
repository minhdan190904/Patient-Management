#ifndef NGUOI_CPP
#define NGUOI_CPP
#include "iostream"
#include "string"
using namespace std;

class Nguoi{
    protected:
	string hoTen;
    string ngaySinh;
    string soCMND;
    string diaChi;
    int gioiTinh; // 1: Nam, 0: Nu
    string soDienThoai;
    string email;
public:
    Nguoi();
    Nguoi(string hoTen, string ngaySinh, string soCMND, string diaChi, int gioiTinh, string soDienThoai, string email);
    void nhap();
    void xuat();
    string getHoTen();
    string getNgaySinh();
    string getSoCMND();
    string getDiaChi();
    int getGioiTinh();
    string getSoDienThoai();
    string getEmail();
    void setHoTen(string hoTen);
    void setNgaySinh(string ngaySinh);
    void setSoCMND(string soCMND);
    void setDiaChi(string diaChi);
    void setGioiTinh(int gioiTinh);
    void setSoDienThoai(string soDienThoai);
    void setEmail(string email);
    ~Nguoi();
};

Nguoi::Nguoi(){
    this->hoTen = "";
    this->ngaySinh = "";
    this->soCMND = "";
    this->diaChi = "";
    this->gioiTinh = 1;
    this->soDienThoai = "";
    this->email = "";
}

Nguoi::Nguoi(string hoTen, string ngaySinh, string soCMND, string diaChi, int gioiTinh, string soDienThoai, string email){
    this->hoTen = hoTen;
    this->ngaySinh = ngaySinh;
    this->soCMND = soCMND;
    this->diaChi = diaChi;
    this->gioiTinh = gioiTinh;
    this->soDienThoai = soDienThoai;
    this->email = email;
}

void Nguoi::nhap(){
    cout << "Nhap ho ten: ";
    fflush(stdin);
    getline(cin, this->hoTen);
    cout << "Nhap ngay sinh: ";
    cin >> this->ngaySinh;
    cout << "Nhap so CMND: ";
    cin >> this->soCMND;
    cout << "Nhap dia chi: ";
    fflush(stdin);
    getline(cin, this->diaChi);
    cout << "Nhap gioi tinh (1: Nam, 0: Nu): ";
    cin >> this->gioiTinh;
    cout << "Nhap so dien thoai: ";
    cin >> this->soDienThoai;
    cout << "Nhap email: ";
    cin >> this->email;
}

void Nguoi::xuat(){
    cout << "Ho ten: " << this->hoTen << endl;
    cout << "Ngay sinh: " << this->ngaySinh << endl;
    cout << "So CMND: " << this->soCMND << endl;
    cout << "Dia chi: " << this->diaChi << endl;
    if(this->gioiTinh == 1){
        cout << "Gioi tinh: Nam" << endl;
    }else{  
        cout << "Gioi tinh: Nu" << endl;
    }
    cout << "So dien thoai: " << this->soDienThoai << endl;
    cout << "Email: " << this->email << endl;
}

string Nguoi::getHoTen(){
    return this->hoTen;
}

string Nguoi::getNgaySinh(){
    return this->ngaySinh;
}

string Nguoi::getSoCMND(){
    return this->soCMND;
}

string Nguoi::getDiaChi(){
    return this->diaChi;
}

int Nguoi::getGioiTinh(){
    return this->gioiTinh;
}

string Nguoi::getSoDienThoai(){
    return this->soDienThoai;
}

string Nguoi::getEmail(){
    return this->email;
}

void Nguoi::setHoTen(string hoTen){
    this->hoTen = hoTen;
}

void Nguoi::setNgaySinh(string ngaySinh){
    this->ngaySinh = ngaySinh;
}

void Nguoi::setSoCMND(string soCMND){
    this->soCMND = soCMND;
}

void Nguoi::setDiaChi(string diaChi){
    this->diaChi = diaChi;
}

void Nguoi::setGioiTinh(int gioiTinh){
    this->gioiTinh = gioiTinh;
}

void Nguoi::setSoDienThoai(string soDienThoai){
    this->soDienThoai = soDienThoai;
}

void Nguoi::setEmail(string email){
    this->email = email;
}

Nguoi::~Nguoi(){
}

#endif