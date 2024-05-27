#ifndef QUANLYBENHVIEN_CPP
#define QUANLYBENHVIEN_CPP
#include "KHOA_BENH_VIEN.cpp"
#include "LICH_SU_KHAM_BENH.cpp"
#include "fstream"

class QuanLyBenhVien {
    vector<KhoaBenhVien> danhSachKhoa;
    vector<LichSuKhamBenh> danhSachLichSuKhamBenh;
    public:
    QuanLyBenhVien();
    void xuat();
    void xuatDanhSachKhoa();
    void xuatDanhSachLichSuKhamBenh();
    vector<KhoaBenhVien> getDanhSachKhoa();
    vector<LichSuKhamBenh> getDanhSachLichSuKhamBenh();
    KhoaBenhVien& timKhoa(string maKhoa);
    Phong& timPhong(string maPhong);
    BenhNhan& timBenhNhan(string maBenhNhan);
    NhanVienYTe& timNhanVienYTe(string maNhanVienYTe);
    LichSuKhamBenh& timLichSuKhamBenh(string maLichSuKhamBenh);
    vector<LichSuKhamBenh> timLichSuKhamBenh(string maBenhNhan, string maNhanVienYTe);
    void themKhoaBenhVienTuFile(string tenFile);
    void themPhongTuFile(string tenFile);
    void themBenhNhanTuFile(string tenFile);
    void themNhanVienYTeTuFile(string tenFile);
    void themLichSuKhamBenhTuFile(string tenFile);
    void xoaKhoa(string maKhoa);
    void xoaPhong(string maPhong);
    void xoaBenhNhan(string maBenhNhan);
    void xoaNhanVienYTe(string maNhanVienYTe);
    void xoaLichSuKhamBenh(string maLichSuKhamBenh);
    void themKhoaBenhVien(KhoaBenhVien& khoa);
    void themPhong(Phong& phong, string maKhoa);
    void themBenhNhan(BenhNhan& benhNhan, string maPhong);
    void themNhanVienYTe(NhanVienYTe& nhanVienYTe, string maKhoa);
    void themLichSuKhamBenh(LichSuKhamBenh& lichSuKhamBenh);
    ~QuanLyBenhVien();
};

QuanLyBenhVien::QuanLyBenhVien(){
}

void QuanLyBenhVien::xuat(){
    this->xuatDanhSachKhoa();
    cout << endl;
    this->xuatDanhSachLichSuKhamBenh();
}

void QuanLyBenhVien::xuatDanhSachKhoa(){
    for(int i = 0; i < this->danhSachKhoa.size(); i++){
        this->danhSachKhoa[i].xuat();
        cout << endl;
    }
}

void QuanLyBenhVien::xuatDanhSachLichSuKhamBenh(){
    for(int i = 0; i < this->danhSachLichSuKhamBenh.size(); i++){
        this->danhSachLichSuKhamBenh[i].xuat();
        cout << endl;
    }
}

vector<KhoaBenhVien> QuanLyBenhVien::getDanhSachKhoa(){
    return this->danhSachKhoa;
}

vector<LichSuKhamBenh> QuanLyBenhVien::getDanhSachLichSuKhamBenh(){
    return this->danhSachLichSuKhamBenh;
}

KhoaBenhVien& QuanLyBenhVien::timKhoa(string maKhoa){
    for(int i = 0; i < this->danhSachKhoa.size(); i++){
        if(this->danhSachKhoa[i].getMaKhoa() == maKhoa){
            return this->danhSachKhoa[i];
        }
    }
    throw "Khong tim thay khoa";
}

Phong& QuanLyBenhVien::timPhong(string maPhong){
    for(int i = 0; i < this->danhSachKhoa.size(); i++){
        for(int j = 0; j < this->danhSachKhoa[i].getPhong().size(); j++){
            if(this->danhSachKhoa[i].getPhong()[j].getMaPhong() == maPhong){
                return this->danhSachKhoa[i].getPhong()[j];
            }
        }
    }
    throw "Khong tim thay phong";
}

BenhNhan& QuanLyBenhVien::timBenhNhan(string maBenhNhan){
    for(int i = 0; i < this->danhSachKhoa.size(); i++){
        for(int j = 0; j < this->danhSachKhoa[i].getPhong().size(); j++){
            for(int k = 0; k < this->danhSachKhoa[i].getPhong()[j].getBenhNhan().size(); k++){
                if(this->danhSachKhoa[i].getPhong()[j].getBenhNhan()[k].getMaBenhNhan() == maBenhNhan){
                    return this->danhSachKhoa[i].getPhong()[j].getBenhNhan()[k];
                }
            }
        }
    }
    throw "Khong tim thay benh nhan";
}

NhanVienYTe& QuanLyBenhVien::timNhanVienYTe(string maNhanVienYTe){
    for(int i = 0; i < this->danhSachKhoa.size(); i++){
        for(int j = 0; j < this->danhSachKhoa[i].getNhanVienYTe().size(); j++){
            if(this->danhSachKhoa[i].getNhanVienYTe()[j].getMaNhanVien() == maNhanVienYTe){
                return this->danhSachKhoa[i].getNhanVienYTe()[j];
            }
        }
    }
    throw "Khong tim thay nhan vien y te";
}

LichSuKhamBenh& QuanLyBenhVien::timLichSuKhamBenh(string maLichSuKhamBenh){
    for(int i = 0; i < this->danhSachLichSuKhamBenh.size(); i++){
        if(this->danhSachLichSuKhamBenh[i].getMaLichSuKhamBenh() == maLichSuKhamBenh){
            return this->danhSachLichSuKhamBenh[i];
        }
    }
    throw "Khong tim thay lich su kham benh";
}

vector<LichSuKhamBenh> QuanLyBenhVien::timLichSuKhamBenh(string maBenhNhan, string maNhanVienYTe){
    vector<LichSuKhamBenh> result;
    for(int i = 0; i < this->danhSachLichSuKhamBenh.size(); i++){
        if(this->danhSachLichSuKhamBenh[i].getBenhNhan().getMaBenhNhan() == maBenhNhan && this->danhSachLichSuKhamBenh[i].getNhanVienYTe().getMaNhanVien() == maNhanVienYTe){
            result.push_back(this->danhSachLichSuKhamBenh[i]);
        }
    }
    return result;
}

void QuanLyBenhVien::themKhoaBenhVienTuFile(string tenFile){
    fstream file;
    file.open(tenFile, ios::in);
    if(file.is_open()){
        string tenKhoa;
        string soLuongPhongStr;
        int soLuongPhong;
        while(getline(file, tenKhoa) && getline(file, soLuongPhongStr)){
            soLuongPhong = stoi(soLuongPhongStr);
            KhoaBenhVien khoa(tenKhoa, soLuongPhong);
            this->danhSachKhoa.push_back(khoa);
        }
        file.close();
    }
}

void QuanLyBenhVien::themPhongTuFile(string tenFile){
    fstream file;
    file.open(tenFile, ios::in);
    if(file.is_open()){
        string maKhoa;
        string tenPhong;
        string soLuongGiuongBenhStr;
        int soLuongGiuongBenh;
        while(getline(file, tenPhong) && getline(file, soLuongGiuongBenhStr) && getline(file, maKhoa)){
            soLuongGiuongBenh = stoi(soLuongGiuongBenhStr); 
            Phong phong(tenPhong, soLuongGiuongBenh);
            KhoaBenhVien& khoa = this->timKhoa(maKhoa);
            khoa.addPhong(phong);
        }
        file.close();
    }
}

void QuanLyBenhVien::themBenhNhanTuFile(string tenFile){
    fstream file;
    file.open(tenFile, ios::in);
    if(file.is_open()){
        string hoTenBenhNhan, ngaySinhBenhNhan, soCMNDBenhNhan, diaChiBenhNhan, soDienThoaiBenhNhan, emailBenhNhan;
        string hoTenThanNhan, ngaySinhThanNhan, soCMNDThanNhan, diaChiThanNhan, soDienThoaiThanNhan, emailThanNhan, quanHe;
        string gioiTinhBenhNhanStr, gioiTinhThanNhanStr, dangNamVienStr, maPhong;
        int gioiTinhBenhNhan, gioiTinhThanNhan, dangNamVien;
        while(getline(file, hoTenBenhNhan) && getline(file, ngaySinhBenhNhan) && getline(file, soCMNDBenhNhan) && getline(file, diaChiBenhNhan) 
        && getline(file, gioiTinhBenhNhanStr) && getline(file, soDienThoaiBenhNhan) && getline(file, emailBenhNhan) && getline(file, dangNamVienStr)
        && getline(file, hoTenThanNhan) && getline(file, ngaySinhThanNhan) && getline(file, soCMNDThanNhan) && getline(file, diaChiThanNhan) 
        && getline(file, gioiTinhThanNhanStr) && getline(file, soDienThoaiThanNhan) && getline(file, emailThanNhan) && getline(file, quanHe) && getline(file, maPhong)){
            gioiTinhBenhNhan = stoi(gioiTinhBenhNhanStr);
            gioiTinhThanNhan = stoi(gioiTinhThanNhanStr);
            dangNamVien = stoi(dangNamVienStr);
            ThanNhan thanNhan(hoTenThanNhan, ngaySinhThanNhan, soCMNDThanNhan, diaChiThanNhan, gioiTinhThanNhan, soDienThoaiThanNhan, emailThanNhan, quanHe);
            BenhNhan benhNhan(hoTenBenhNhan, ngaySinhBenhNhan, soCMNDBenhNhan, diaChiBenhNhan, gioiTinhBenhNhan, soDienThoaiBenhNhan, emailBenhNhan, dangNamVien, thanNhan);
            Phong& phong = this->timPhong(maPhong);
            phong.addBenhNhan(benhNhan);
        }
        file.close();
    }
}

// NhanVienYTe::NhanVienYTe(string hoTen, string ngaySinh, string soCMND, string diaChi, int gioiTinh, string soDienThoai, string email, string chucVu, string bangCap, double heSoLuong) : Nguoi(hoTen, ngaySinh, soCMND, diaChi, gioiTinh, soDienThoai, email){

void QuanLyBenhVien::themNhanVienYTeTuFile(string tenFile){
    fstream file;
    file.open(tenFile, ios::in);
    if(file.is_open()){
        string hoTenNhanVienYTe, ngaySinhNhanVienYTe, soCMNDNhanVienYTe, diaChiNhanVienYTe, soDienThoaiNhanVienYTe, emailNhanVienYTe;
        string chucVu, bangCap, heSoLuongStr, maKhoa, gioiTinhNhanVienYTeStr;
        int gioiTinhNhanVienYTe;
        double heSoLuong;
        while(getline(file, hoTenNhanVienYTe) && getline(file, ngaySinhNhanVienYTe) && getline(file, soCMNDNhanVienYTe) && getline(file, diaChiNhanVienYTe) 
        && getline(file, gioiTinhNhanVienYTeStr) && getline(file, soDienThoaiNhanVienYTe) && getline(file, emailNhanVienYTe) && getline(file, chucVu)
        && getline(file, bangCap) && getline(file, heSoLuongStr) && getline(file, maKhoa)){
            heSoLuong = stod(heSoLuongStr);
            gioiTinhNhanVienYTe = stoi(gioiTinhNhanVienYTeStr);
            NhanVienYTe nhanVienYTe(hoTenNhanVienYTe, ngaySinhNhanVienYTe, soCMNDNhanVienYTe, diaChiNhanVienYTe, gioiTinhNhanVienYTe, soDienThoaiNhanVienYTe, emailNhanVienYTe, chucVu, bangCap, heSoLuong);
            KhoaBenhVien& khoa = this->timKhoa(maKhoa);
            khoa.addNhanVienYTe(nhanVienYTe);
        }
        file.close();
    }
}
//  LichSuKhamBenh(string chanDoan, string ngayKham, string benhLy, string dichVuKham, double chiPhiKham, int daThanhToan, BenhNhan benhNhan, NhanVienYTe nhanVienYTe);
void QuanLyBenhVien::themLichSuKhamBenhTuFile(string tenFile){
    fstream file;
    file.open(tenFile, ios::in);
    if(file.is_open()){
        string chanDoan, ngayKham, benhLy, dichVuKham, chiPhiKhamStr, daThanhToanStr, maBenhNhan, maNhanVienYTe;
        double chiPhiKham;
        int daThanhToan;
        while(getline(file, chanDoan) && getline(file, ngayKham) && getline(file, benhLy) && getline(file, dichVuKham)
        && getline(file, chiPhiKhamStr) && getline(file, daThanhToanStr) && getline(file, maBenhNhan) && getline(file, maNhanVienYTe)){
            chiPhiKham = stod(chiPhiKhamStr);
            daThanhToan = stoi(daThanhToanStr);
            BenhNhan& benhNhan = this->timBenhNhan(maBenhNhan);
            NhanVienYTe& nhanVienYTe = this->timNhanVienYTe(maNhanVienYTe);
            LichSuKhamBenh lichSuKhamBenh(chanDoan, ngayKham, benhLy, dichVuKham, chiPhiKham, daThanhToan, benhNhan, nhanVienYTe);
            this->danhSachLichSuKhamBenh.push_back(lichSuKhamBenh);
        }
        file.close();
    }
}

void QuanLyBenhVien::xoaKhoa(string maKhoa){
    for(int i = 0; i < this->danhSachKhoa.size(); i++){
        if(this->danhSachKhoa[i].getMaKhoa() == maKhoa){
            this->danhSachKhoa.erase(this->danhSachKhoa.begin() + i);
            return;
        }
    }
}

void QuanLyBenhVien::xoaPhong(string maPhong){
    for(int i = 0; i < this->danhSachKhoa.size(); i++){
        this->danhSachKhoa[i].xoaPhong(maPhong);
    }
}

void QuanLyBenhVien::xoaBenhNhan(string maBenhNhan){
    for(int i = 0; i < this->danhSachKhoa.size(); i++){
        for(int j = 0; j < this->danhSachKhoa[i].getPhong().size(); j++){
            this->danhSachKhoa[i].getPhong()[j].xoaBenhNhan(maBenhNhan);
        }
    }
}

void QuanLyBenhVien::xoaNhanVienYTe(string maNhanVienYTe){
    for(int i = 0; i < this->danhSachKhoa.size(); i++){
        this->danhSachKhoa[i].xoaNhanVienYTe(maNhanVienYTe);
    }
}

void QuanLyBenhVien::xoaLichSuKhamBenh(string maLichSuKhamBenh){
    for(int i = 0; i < this->danhSachLichSuKhamBenh.size(); i++){
        if(this->danhSachLichSuKhamBenh[i].getMaLichSuKhamBenh() == maLichSuKhamBenh){
            this->danhSachLichSuKhamBenh.erase(this->danhSachLichSuKhamBenh.begin() + i);
            return;
        }
    }
}

void QuanLyBenhVien::themKhoaBenhVien(KhoaBenhVien& khoa){
    this->danhSachKhoa.push_back(khoa);
}

void QuanLyBenhVien::themPhong(Phong& phong, string maKhoa){
    KhoaBenhVien& khoa = this->timKhoa(maKhoa);
    khoa.addPhong(phong);
}

void QuanLyBenhVien::themBenhNhan(BenhNhan& benhNhan, string maPhong){
    Phong& phong = this->timPhong(maPhong);
    phong.addBenhNhan(benhNhan);
}

void QuanLyBenhVien::themNhanVienYTe(NhanVienYTe& nhanVienYTe, string maKhoa){
    KhoaBenhVien& khoa = this->timKhoa(maKhoa);
    khoa.addNhanVienYTe(nhanVienYTe);
}

void QuanLyBenhVien::themLichSuKhamBenh(LichSuKhamBenh& lichSuKhamBenh){
    this->danhSachLichSuKhamBenh.push_back(lichSuKhamBenh);
}

QuanLyBenhVien::~QuanLyBenhVien(){
    this->danhSachKhoa.clear();
    this->danhSachLichSuKhamBenh.clear();
}

#endif