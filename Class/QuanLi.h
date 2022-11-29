#ifndef __QL_H__
#define __QL_H__

#include <fstream>
using namespace std;

class QuanLi
{
public:
    virtual void docFile(fstream &) = 0;
    virtual void ghiFile(fstream &);
    virtual void create();      // Nhap tu nguoi dung
    virtual void update();      // Chinh sua
    virtual void read();        // Xuat ra man hinh
    virtual void find();        // Tim Kiem
    virtual void deleteIndex(); // Xoa
};

#endif