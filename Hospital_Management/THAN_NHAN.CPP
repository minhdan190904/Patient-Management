#ifndef THANNHAN_CPP
#define THANNHAN_CPP
#include "NGUOI.cpp"

class ThanNhan : public Nguoi{
    protected:
    string quanHe;
    public:
    ThanNhan();
    ThanNhan(string hoTen, string ngaySinh, string soCMND, string diaChi, int gioiTinh, string soDienThoai, string email, string quanHe);
    void nhap();
    void xuat();
    string getQuanHe();
    void setQuanHe(string quanHe);
    ~ThanNhan();
};

ThanNhan::ThanNhan() : Nguoi(){
    this->quanHe = "";
}

ThanNhan::ThanNhan(string hoTen, string ngaySinh, string soCMND, string diaChi, int gioiTinh, string soDienThoai, string email, string quanHe) : Nguoi(hoTen, ngaySinh, soCMND, diaChi, gioiTinh, soDienThoai, email){
    this->quanHe = quanHe;
}

void ThanNhan::nhap(){
    Nguoi::nhap();
    cout << "Nhap quan he: ";
    fflush(stdin);
    getline(cin, this->quanHe);
}

void ThanNhan::xuat(){
    Nguoi::xuat();
    cout << "Quan he: " << this->quanHe << endl;
}

string ThanNhan::getQuanHe(){
    return this->quanHe;
}

void ThanNhan::setQuanHe(string quanHe){
    this->quanHe = quanHe;
}

ThanNhan::~ThanNhan(){
}

#endif