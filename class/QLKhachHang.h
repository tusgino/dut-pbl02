// #include "Sample.h"
#ifndef __QLKH_H__
#define __QLKH_H__

#include "KhachHang.h"
// #include "..\src\features\QuanLi\QuanLi.cpp"
#include "QuanLi.h"

class QLKhachHang : public QuanLi
{
    List<KhachHang> *dbKH;
    int count;

public:
    QLKhachHang();
    ~QLKhachHang();

    void docFile(fstream &);
    void ghiFile(fstream &);
    void create();      // Nhap tu nguoi dung
    void update();      // Chinh sua
    void read();        // Xuat ra man hinh
    void find();        // Tim Kiem
    void deleteIndex(); // Xoa

    int findBySDT(const string &);
    void xuatFile(fstream &);
    Ma findKH(const string &);
    string findKH(const Ma &);
    void sortMa();
    void create(const string &, Ma &);
    void sort();
};
#endif