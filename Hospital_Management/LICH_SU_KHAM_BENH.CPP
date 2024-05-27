#ifndef LICH_SU_KHAM_BENH_CPP
#define LICH_SU_KHAM_BENH_CPP
#include "BENH_NHAN.cpp"
#include "NHAN_VIEN_Y_TE.cpp"
#include <sstream>
#include <iomanip>

class LichSuKhamBenh {
private:
    string chanDoan;
    string ngayKham;
    string benhLy;
    string dichVuKham;
    double chiPhiKham;
    int daThanhToan; // 1: Đã thanh toán, 0: Chưa thanh toán
    string maLichSuKhamBenh;
    BenhNhan benhNhan;
    NhanVienYTe nhanVienYTe;
    static int soMaLichSuKhamBenh;

public:
    LichSuKhamBenh();
    LichSuKhamBenh(string chanDoan, string ngayKham, string benhLy, string dichVuKham, double chiPhiKham, int daThanhToan, BenhNhan benhNhan, NhanVienYTe nhanVienYTe);
    void nhap();
    void xuat();
    string getChanDoan();
    string getNgayKham();
    string getBenhLy();
    string getDichVuKham();
    double getChiPhiKham();
    int getDaThanhToan();
    string getMaLichSuKhamBenh();
    BenhNhan getBenhNhan();
    NhanVienYTe getNhanVienYTe();
    void setChanDoan(string chanDoan);
    void setNgayKham(string ngayKham);
    void setBenhLy(string benhLy);
    void setDichVuKham(string dichVuKham);
    void setChiPhiKham(double chiPhiKham);
    void setDaThanhToan(int daThanhToan);
    void setMaLichSuKhamBenh(string maLichSuKhamBenh);
    void setBenhNhan(BenhNhan benhNhan);
    void setNhanVienYTe(NhanVienYTe nhanVienYTe);
    ~LichSuKhamBenh();
};

int LichSuKhamBenh::soMaLichSuKhamBenh = 0;

LichSuKhamBenh::LichSuKhamBenh(){
    stringstream ss;
    ss << setw(5) << setfill('0') << soMaLichSuKhamBenh++;
    this->maLichSuKhamBenh = "LSKB" + ss.str();
    this->chanDoan = "";
    this->ngayKham = "";
    this->benhLy = "";
    this->dichVuKham = "";
    this->chiPhiKham = 0.0;
    this->daThanhToan = 0;
}

LichSuKhamBenh::LichSuKhamBenh(string chanDoan, string ngayKham, string benhLy, string dichVuKham, double chiPhiKham, int daThanhToan, BenhNhan benhNhan, NhanVienYTe nhanVienYTe){
    stringstream ss;
    ss << setw(5) << setfill('0') << soMaLichSuKhamBenh++;
    this->maLichSuKhamBenh = "LSKB" + ss.str();
    this->chanDoan = chanDoan;
    this->ngayKham = ngayKham;
    this->benhLy = benhLy;
    this->dichVuKham = dichVuKham;
    this->chiPhiKham = chiPhiKham;
    this->daThanhToan = daThanhToan;
    this->benhNhan = benhNhan;
    this->nhanVienYTe = nhanVienYTe;
}

void LichSuKhamBenh::nhap() {
    cout << "Nhap chan doan: ";
    fflush(stdin);
    getline(cin, this->chanDoan);
    cout << "Nhap ngay kham: ";
    fflush(stdin);
    getline(cin, this->ngayKham);
    cout << "Nhap benh ly: ";
    fflush(stdin);
    getline(cin, this->benhLy);
    cout << "Nhap dich vu kham: ";
    fflush(stdin);
    getline(cin, this->dichVuKham);
    cout << "Nhap chi phi kham: ";
    cin >> this->chiPhiKham;
    cout << "Nhap da thanh toan (1: Da thanh toan, 0: Chua thanh toan): ";
    cin >> this->daThanhToan;
    stringstream ss;
    ss << setw(5) << setfill('0') << soMaLichSuKhamBenh++;
    this->maLichSuKhamBenh = "LSKB" + ss.str();
}

void LichSuKhamBenh::xuat() {
    cout << "Chan doan: " << this->chanDoan << endl;
    cout << "Ngay kham: " << this->ngayKham << endl;
    cout << "Benh ly: " << this->benhLy << endl;
    cout << "Dich vu kham: " << this->dichVuKham << endl;
    cout << "Chi phi kham: " << this->chiPhiKham << endl;
    cout << "Da thanh toan: " << (this->daThanhToan == 1 ? "Da thanh toan" : "Chua thanh toan") << endl;
    cout << "Ma lich su kham benh: " << this->maLichSuKhamBenh << endl;
    cout << "Thong tin benh nhan: " << endl;
    this->benhNhan.xuat();
    cout << "Thong tin nhan vien y te: " << endl;
    this->nhanVienYTe.xuat();
}

string LichSuKhamBenh::getChanDoan() {
    return this->chanDoan;
}

string LichSuKhamBenh::getNgayKham() {
    return this->ngayKham;
}

string LichSuKhamBenh::getBenhLy() {
    return this->benhLy;
}

string LichSuKhamBenh::getDichVuKham() {
    return this->dichVuKham;
}

double LichSuKhamBenh::getChiPhiKham() {
    return this->chiPhiKham;
}

int LichSuKhamBenh::getDaThanhToan() {
    return this->daThanhToan;
}

string LichSuKhamBenh::getMaLichSuKhamBenh() {
    return this->maLichSuKhamBenh;
}

BenhNhan LichSuKhamBenh::getBenhNhan() {
    return this->benhNhan;
}

NhanVienYTe LichSuKhamBenh::getNhanVienYTe() {
    return this->nhanVienYTe;
}

void LichSuKhamBenh::setChanDoan(string chanDoan) {
    this->chanDoan = chanDoan;
}

void LichSuKhamBenh::setNgayKham(string ngayKham) {
    this->ngayKham = ngayKham;
}

void LichSuKhamBenh::setBenhLy(string benhLy) {
    this->benhLy = benhLy;
}

void LichSuKhamBenh::setDichVuKham(string dichVuKham) {
    this->dichVuKham = dichVuKham;
}

void LichSuKhamBenh::setChiPhiKham(double chiPhiKham) {
    this->chiPhiKham = chiPhiKham;
}

void LichSuKhamBenh::setDaThanhToan(int daThanhToan) {
    this->daThanhToan = daThanhToan;
}

void LichSuKhamBenh::setMaLichSuKhamBenh(string maLichSuKhamBenh) {
    this->maLichSuKhamBenh = maLichSuKhamBenh;
}

void LichSuKhamBenh::setBenhNhan(BenhNhan benhNhan) {
    this->benhNhan = benhNhan;
}

void LichSuKhamBenh::setNhanVienYTe(NhanVienYTe nhanVienYTe) {
    this->nhanVienYTe = nhanVienYTe;
}

LichSuKhamBenh::~LichSuKhamBenh() {
}

#endif
