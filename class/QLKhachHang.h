// #include "Sample.h"
#ifndef __QLKH_H__
#define __QLKH_H__

#include "..\src\components\utils\List.cpp"
#include "..\src\components\utils\Node.cpp"
#include "..\src\features\KhachHang\KhachHang.cpp"
#include "..\src\features\QuanLi\QuanLi.cpp"

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
    // void read();        // Xuat ra man hinh
    void find();        // Tim Kiem
    // void deleteIndex(); // Xoa
    int findBySDT(const string& );
};

#endif