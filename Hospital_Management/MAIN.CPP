#include "quan_ly_benh_vien.cpp"

int main() {
    QuanLyBenhVien qlbv;
    int choice;
    double hsl;
    string ma, tenFile;
    KhoaBenhVien *khoa = nullptr;
    Phong* phong = nullptr;
    BenhNhan* benhNhan = nullptr;
    NhanVienYTe* nhanVienYTe = nullptr;
    LichSuKhamBenh* lichSuKhamBenh = nullptr;
    vector<LichSuKhamBenh> lichSuKhamBenhList;
    string maNV, maBN;
    //base data class qlbv
    qlbv.themKhoaBenhVienTuFile("khoa.txt");
    qlbv.themPhongTuFile("phong.txt");
    qlbv.themBenhNhanTuFile("benh_nhan.txt");
    qlbv.themNhanVienYTeTuFile("nhan_vien_y_te.txt");
    qlbv.themLichSuKhamBenhTuFile("lich_su_kham_benh.txt");
    //base data class qlbv
    while (true) {
        cout << "1. ?\n"
             << "2. Xuat\n"
             << "3. Xuat danh sach khoa\n"
             << "4. Xuat danh sach lich su kham benh\n"
             << "5. Tim khoa\n"
             << "6. Tim phong\n"
             << "7. Tim benh nhan\n"
             << "8. Tim nhan vien y te\n"
             << "9. Tim lich su kham benh\n"
             << "10. Them khoa benh vien tu file\n"
             << "11. Them phong tu file\n"
             << "12. Them benh nhan tu file\n"
             << "13. Them nhan vien y te tu file\n"
             << "14. Them lich su kham benh tu file\n"
             << "15. Xoa khoa\n"
             << "16. Xoa phong\n"
             << "17. Xoa benh nhan\n"
             << "18. Xoa nhan vien y te\n"
             << "19. Xoa lich su kham benh\n"
             << "20. Tim lich su kham benh bang ma nhan vien va ma benh nhan\n"
             << "21. Cap nhat thong tin khoa benh vien\n"
             << "22. Cap nhat thong tin phong benh vien\n"
             << "23. Cap nhat thong tin benh nhan\n"
             << "24. Cap nhat thong tin nhan vien y te\n"
             << "25. Cap nhat thong tin lich su kham benh\n"
             << "26. Them khoa benh vien tu ban phim\n"
             << "27. Them phong tu ban phim\n"
             << "28. Them benh nhan tu ban phim\n"
             << "29. Them nhan vien y te tu ban phim\n"
             << "30. Them lich su kham benh tu ban phim\n"
             << "31. Thoat\n"
             << "Nhap lua chon: ";
        cin >> choice;
        cout << "\n\n";
        switch (choice) {
            case 1:
                cout << "Siuuuuuuuuuuuuuuuuuuuuuu";
                break;
            case 2:
                qlbv.xuat();
                break;
            case 3:
                qlbv.xuatDanhSachKhoa();
                break;
            case 4:
                qlbv.xuatDanhSachLichSuKhamBenh();
                break;
            case 5:
                cout << "Nhap ma khoa: ";
                cin >> ma;
                khoa = &qlbv.timKhoa(ma);
                khoa->xuat();
                break;
            case 6:
                cout << "Nhap ma phong: ";
                cin >> ma;
                phong = &qlbv.timPhong(ma);
                phong->xuat();
                break;
            case 7:
                cout << "Nhap ma benh nhan: ";
                cin >> ma;
                benhNhan = &qlbv.timBenhNhan(ma);
                benhNhan->xuat();
                break;
            case 8:
                cout << "Nhap ma nhan vien y te: ";
                cin >> ma;
                nhanVienYTe = &qlbv.timNhanVienYTe(ma);
                nhanVienYTe->xuat();
                break;
            case 9:
                cout << "Nhap ma lich su kham benh: ";
                cin >> ma;
                lichSuKhamBenh = &qlbv.timLichSuKhamBenh(ma);
                lichSuKhamBenh->xuat();
                break;
            case 10:
                cout << "Nhap ten file: ";
                cin >> tenFile;
                qlbv.themKhoaBenhVienTuFile(tenFile);
                break;
            case 11:
                cout << "Nhap ten file: ";
                cin >> tenFile;
                qlbv.themPhongTuFile(tenFile);
                break;
            case 12:
                cout << "Nhap ten file: ";
                cin >> tenFile;
                qlbv.themBenhNhanTuFile(tenFile);
                break;
            case 13:
                cout << "Nhap ten file: ";
                cin >> tenFile;
                qlbv.themNhanVienYTeTuFile(tenFile);
                break;
            case 14:
                cout << "Nhap ten file: ";
                cin >> tenFile;
                qlbv.themLichSuKhamBenhTuFile(tenFile);
                break;
            case 15:
                cout << "Nhap ma khoa: ";
                cin >> ma;
                qlbv.xoaKhoa(ma);
                break;
            case 16:
                cout << "Nhap ma phong: ";
                cin >> ma;
                qlbv.xoaPhong(ma);
                break;
            case 17:
                cout << "Nhap ma benh nhan: ";
                cin >> ma;
                qlbv.xoaBenhNhan(ma);
                break;
            case 18:
                cout << "Nhap ma nhan vien y te: ";
                cin >> ma;
                qlbv.xoaNhanVienYTe(ma);
                break;
            case 19:
                cout << "Nhap ma lich su kham benh: ";
                cin >> ma;
                qlbv.xoaLichSuKhamBenh(ma);
                break;
            case 20:
                cout << "Nhap ma nhan vien: ";
                cin >> maNV;
                cout << "Nhap ma benh nhan: ";
                cin >> maBN;
                lichSuKhamBenhList = qlbv.timLichSuKhamBenh(maBN, maNV);
                for(int i = 0; i < lichSuKhamBenhList.size(); i++){
                    lichSuKhamBenhList[i].xuat();
                }
                break;
            case 21:
                cout << "Nhap ma khoa can cap nhat: ";
                cin >> ma;
                khoa = &qlbv.timKhoa(ma);
                cout << "Chon thong tin can cap nhat: \n"
                     << "1. Ten khoa\n"
                     << "2. So luong phong\n"
                     << "3. Thoat\n"
                     << "Nhap lua chon: ";
                cin >> choice;
                switch (choice) {
                    case 1:
                        cout << "Nhap ten khoa: ";
                        fflush(stdin);
                        getline(cin, ma);
                        khoa->setTenKhoa(ma);
                        break;
                    case 2:
                        cout << "Nhap so luong phong: ";
                        cin >> choice;
                        khoa->setSoLuongPhong(choice);
                        break;
                    case 3:
                        break;
                    default:
                        cout << "Lua chon khong hop le\n";
                        break;
                }
                cout << "Da cap nhat xong!\n";
                break;
            case 22:
                cout << "Nhap ma phong can cap nhat: ";
                cin >> ma;
                phong = &qlbv.timPhong(ma);
                cout << "Chon thong tin can cap nhat: \n"
                     << "1. Ten phong\n"
                     << "2. So giuong\n"
                     << "3. Thoat\n"
                     << "Nhap lua chon: ";
                cin >> choice;
                switch (choice) {
                    case 1:
                        cout << "Nhap ten phong: ";
                        fflush(stdin);
                        getline(cin, ma);
                        phong->setTenPhong(ma);
                        break;
                    case 2:
                        cout << "Nhap so luong giuong: ";
                        cin >> choice;
                        phong->setSoLuongGiuongBenh(choice);
                        break;
                    case 3:
                        break;
                    default:
                        cout << "Lua chon khong hop le\n";
                        break;
                }
                cout << "Da cap nhat xong!\n";
                break;
            case 23:
                cout << "Nhap ma benh nhan can cap nhat: ";
                cin >> ma;
                benhNhan = &qlbv.timBenhNhan(ma);
                cout << "Chon thong tin can cap nhat: \n"
                     << "1. Ho ten\n"
                     << "2. Ngay sinh\n"
                     << "3. So CMND\n"
                     << "4. Dia chi\n"
                     << "5. Gioi tinh\n"
                     << "6. So dien thoai\n"
                     << "7. Email\n"
                     << "8. Dang nam vien\n"
                     << "9. Ho ten than nhan\n"
                     << "10. Ngay sinh than nhan\n"
                     << "11. So CMND than nhan\n"
                     << "12. Dia chi than nhan\n"
                     << "13. Gioi tinh than nhan\n"
                     << "14. So dien thoai than nhan\n"
                     << "15. Email than nhan\n"
                     << "16. Quan he\n"
                     << "17. Thoat\n"
                     << "Nhap lua chon: ";
                cin >> choice;
                switch(choice){
                    case 1:
                        cout << "Nhap ho ten: ";
                        fflush(stdin);
                        getline(cin, ma);
                        benhNhan->setHoTen(ma);
                        break;
                    case 2:
                        cout << "Nhap ngay sinh: ";
                        fflush(stdin);
                        getline(cin, ma);
                        benhNhan->setNgaySinh(ma);
                        break;
                    case 3:
                        cout << "Nhap so CMND: ";
                        fflush(stdin);
                        getline(cin, ma);
                        benhNhan->setSoCMND(ma);
                        break;
                    case 4:
                        cout << "Nhap dia chi: ";
                        fflush(stdin);
                        getline(cin, ma);
                        benhNhan->setDiaChi(ma);
                        break;
                    case 5:
                        cout << "Nhap gioi tinh: ";
                        cin >> choice;
                        benhNhan->setGioiTinh(choice);
                        break;
                    case 6:
                        cout << "Nhap so dien thoai: ";
                        fflush(stdin);
                        getline(cin, ma);
                        benhNhan->setSoDienThoai(ma);
                        break;
                    case 7:
                        cout << "Nhap email: ";
                        fflush(stdin);
                        getline(cin, ma);
                        benhNhan->setEmail(ma);
                        break;
                    case 8:
                        cout << "Nhap dang nam vien (1: Nam vien, 0: Chua nam vien): ";
                        cin >> choice;
                        benhNhan->setDangNamVien(choice);
                        break;
                    case 9:
                        cout << "Nhap ho ten than nhan: ";
                        fflush(stdin);
                        getline(cin, ma);
                        benhNhan->getThanNhan().setHoTen(ma);
                        break;
                    case 10:
                        cout << "Nhap ngay sinh than nhan: ";
                        fflush(stdin);
                        getline(cin, ma);
                        benhNhan->getThanNhan().setNgaySinh(ma);
                        break;
                    case 11:
                        cout << "Nhap so CMND than nhan: ";
                        fflush(stdin);
                        getline(cin, ma);
                        benhNhan->getThanNhan().setSoCMND(ma);
                        break;
                    case 12:
                        cout << "Nhap dia chi than nhan: ";
                        fflush(stdin);
                        getline(cin, ma);
                        benhNhan->getThanNhan().setDiaChi(ma);
                        break;
                    case 13:
                        cout << "Nhap gioi tinh than nhan: ";
                        cin >> choice;
                        benhNhan->getThanNhan().setGioiTinh(choice);
                        break;
                    case 14:
                        cout << "Nhap so dien thoai than nhan: ";
                        fflush(stdin);
                        getline(cin, ma);
                        benhNhan->getThanNhan().setSoDienThoai(ma);
                        break;
                    case 15:
                        cout << "Nhap email than nhan: ";
                        fflush(stdin);
                        getline(cin, ma);
                        benhNhan->getThanNhan().setEmail(ma);
                        break;
                    case 16:
                        cout << "Nhap quan he: ";
                        fflush(stdin);
                        getline(cin, ma);
                        benhNhan->getThanNhan().setQuanHe(ma);
                        break;
                    case 17:
                        break;
                    default:
                        cout << "Lua chon khong hop le\n";
                        break;
                }
                cout << "Da cap nhat xong!\n";
                break;
            case 24:
                cout << "Nhap ma nhan vien y te can cap nhat: ";
                cin >> ma;
                nhanVienYTe = &qlbv.timNhanVienYTe(ma);
                cout << "Chon thong tin can cap nhat: \n"
                     << "1. Ho ten\n"
                     << "2. Ngay sinh\n"
                     << "3. So CMND\n"
                     << "4. Dia chi\n"
                     << "5. Gioi tinh\n"
                     << "6. So dien thoai\n"
                     << "7. Email\n"
                     << "8. Chuc vu\n"
                     << "9. Bang cap\n"
                     << "10. He so luong\n"
                     << "11. Thoat\n"
                     << "Nhap lua chon: ";
                cin >> choice;
                switch(choice){
                    case 1:
                        cout << "Nhap ho ten: ";
                        fflush(stdin);
                        getline(cin, ma);
                        nhanVienYTe->setHoTen(ma);
                        break;
                    case 2:
                        cout << "Nhap ngay sinh: ";
                        fflush(stdin);
                        getline(cin, ma);
                        nhanVienYTe->setNgaySinh(ma);
                        break;
                    case 3:
                        cout << "Nhap so CMND: ";
                        fflush(stdin);
                        getline(cin, ma);
                        nhanVienYTe->setSoCMND(ma);
                        break;
                    case 4:
                        cout << "Nhap dia chi: ";
                        fflush(stdin);
                        getline(cin, ma);
                        nhanVienYTe->setDiaChi(ma);
                        break;
                    case 5:
                        cout << "Nhap gioi tinh: ";
                        cin >> choice;
                        nhanVienYTe->setGioiTinh(choice);
                        break;
                    case 6:
                        cout << "Nhap so dien thoai: ";
                        fflush(stdin);
                        getline(cin, ma);
                        nhanVienYTe->setSoDienThoai(ma);
                        break;
                    case 7:
                        cout << "Nhap email: ";
                        fflush(stdin);
                        getline(cin, ma);
                        nhanVienYTe->setEmail(ma);
                        break;
                    case 8:
                        cout << "Nhap chuc vu: ";
                        fflush(stdin);
                        getline(cin, ma);
                        nhanVienYTe->setChucVu(ma);
                        break;
                    case 9:
                        cout << "Nhap bang cap: ";
                        fflush(stdin);
                        getline(cin, ma);
                        nhanVienYTe->setBangCap(ma);
                        break;
                    case 10:
                        cout << "Nhap he so luong: ";
                        cin >> hsl;
                        nhanVienYTe->setHeSoLuong(hsl);
                        break;
                    case 11:
                        break;
                    default:
                        cout << "Lua chon khong hop le\n";
                        break;
                }
                cout << "Da cap nhat xong!\n";
                break;
            case 25:
                cout << "Nhap ma lich su kham benh can cap nhat: ";
                cin >> ma;
                lichSuKhamBenh = &qlbv.timLichSuKhamBenh(ma);
                cout << "Chon thong tin can cap nhat: \n"
                     << "1. Chan doan\n"
                     << "2. Ngay kham\n"
                     << "3. Benh ly\n"
                     << "4. Dich vu kham\n"
                     << "5. Chi phi kham\n"
                     << "6. Da thanh toan\n"
                     << "7. Ma benh nhan\n"
                     << "8. Ma nhan vien y te\n"
                     << "9. Thoat\n"
                     << "Nhap lua chon: ";
                cin >> choice;
                switch(choice){
                    case 1:
                        cout << "Nhap chan doan: ";
                        fflush(stdin);
                        getline(cin, ma);
                        lichSuKhamBenh->setChanDoan(ma);
                        break;
                    case 2:
                        cout << "Nhap ngay kham: ";
                        fflush(stdin);
                        getline(cin, ma);
                        lichSuKhamBenh->setNgayKham(ma);
                        break;
                    case 3:
                        cout << "Nhap benh ly: ";
                        fflush(stdin);
                        getline(cin, ma);
                        lichSuKhamBenh->setBenhLy(ma);
                        break;
                    case 4:
                        cout << "Nhap dich vu kham: ";
                        fflush(stdin);
                        getline(cin, ma);
                        lichSuKhamBenh->setDichVuKham(ma);
                        break;
                    case 5:
                        cout << "Nhap chi phi kham: ";
                        cin >> hsl;
                        lichSuKhamBenh->setChiPhiKham(hsl);
                        break;
                    case 6:
                        cout << "Nhap da thanh toan (1: Da thanh toan, 0: Chua thanh toan): ";
                        cin >> choice;
                        lichSuKhamBenh->setDaThanhToan(choice);
                        break;
                    case 7:
                        cout << "Nhap ma benh nhan: ";
                        cin >> ma;
                        benhNhan = &qlbv.timBenhNhan(ma);
                        lichSuKhamBenh->setBenhNhan(*benhNhan);
                        break;
                    case 8:
                        cout << "Nhap ma nhan vien y te: ";
                        cin >> ma;
                        nhanVienYTe = &qlbv.timNhanVienYTe(ma);
                        lichSuKhamBenh->setNhanVienYTe(*nhanVienYTe);
                        break;
                    case 9:
                        break;
                    default:
                        cout << "Lua chon khong hop le\n";
                        break;
                }
                cout << "Da cap nhat xong!\n";
                break;
            case 26:
                khoa = new KhoaBenhVien();
                cout << "Nhap thong tin khoa benh vien: \n";
                khoa->nhap();
                qlbv.themKhoaBenhVien(*khoa);
                break;
            case 27:
                phong = new Phong();
                cout << "Nhap thong tin phong: \n";
                phong->nhap();
                cout << "Nhap ma khoa can them phong: ";
                cin >> ma;
                qlbv.themPhong(*phong, ma);
                break;
            case 28:
                benhNhan = new BenhNhan();
                cout << "Nhap thong tin benh nhan: \n";
                benhNhan->nhap();
                cout << "Nhap ma phong can them benh nhan: ";
                cin >> ma;
                qlbv.themBenhNhan(*benhNhan, ma);
                break;
            case 29:
                nhanVienYTe = new NhanVienYTe();
                cout << "Nhap thong tin nhan vien y te: \n";
                nhanVienYTe->nhap();
                cout << "Nhap ma khoa can them nhan vien y te: ";
                cin >> ma;
                qlbv.themNhanVienYTe(*nhanVienYTe, ma);
                break;
            case 30:
                lichSuKhamBenh = new LichSuKhamBenh();
                cout << "Nhap thong tin lich su kham benh: \n";
                lichSuKhamBenh->nhap();
                cout << "Nhap ma benh nhan: ";
                cin >> maBN;
                cout << "Nhap ma nhan vien y te: ";
                cin >> maNV;
                benhNhan = &qlbv.timBenhNhan(maBN);
                nhanVienYTe = &qlbv.timNhanVienYTe(maNV);
                lichSuKhamBenh->setBenhNhan(*benhNhan);
                lichSuKhamBenh->setNhanVienYTe(*nhanVienYTe);
                qlbv.themLichSuKhamBenh(*lichSuKhamBenh);
                break;
            case 31:
                return 0;    
            default:
                cout << "Lua chon khong hop le\n";
                break;
        }
        cout << endl;
    }
    return 0;
}
