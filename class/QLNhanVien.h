// #include "Sample.h"
#ifndef __QLNV_H__
#define __QLNV_H__
#include "NhanVien.h"
// #include "..\src\features\QuanLi\QuanLi.cpp"
#include "QuanLi.h"

class QLNhanVien : public QuanLi
{
    List<NhanVien> *dbNV;
    int count;

public:
    QLNhanVien();
    ~QLNhanVien();

    void docFile(fstream &);
    void ghiFile(fstream &);
    void create();      // Nhap tu nguoi dung
    void update();      // Chinh sua
    void read();        // Xuat ra man hinh
    void find();        // Tim Kiem
    void deleteIndex(); // Xoa
    int findBySDT(const string &);
    int findByMa(const string &);
    void sortMa();
};

#endif