// #include "Sample.h"
#ifndef __QLKH_H__
#define __QLKH_H__

#include "..\src\components\utils\List.cpp"
#include "..\src\components\utils\Node.cpp"
#include "..\src\features\NhanVien\NhanVien.cpp"
#include "..\src\features\QuanLi\QuanLi.cpp"

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
    void sortMa();
};

#endif