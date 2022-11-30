#ifndef __QLKH_H__
#define __QLKH_H__

#include "..\src\components\utils\List.cpp"
#include "..\src\components\utils\Node.cpp"
#include "..\src\features\SanPham\SanPham.cpp"
#include "..\src\features\QuanLi\QuanLi.cpp"

class QLSanPham : public QuanLi
{
  int count;

public:
  List<SanPham> *dbSP;
  QLSanPham();
  ~QLSanPham();

  // components

  void docFile(fstream &);
  void ghiFile(fstream &);
  void create();      // Nhap tu nguoi dung
  void update();      // Chinh sua
  void read();        // Xuat ra man hinh
  void find();        // Tim Kiem
  void deleteIndex(); // Xoa

  // utils

  void sortMa(List<SanPham> *);   // sap xep list tang dan theo ma san pham
  int findMaMax();                // Tim ma so lon nhat hien tai de tao ma san pham khong bi trung
  void readList(List<SanPham> *); // in danh sach san pham ra man hinh
  List<SanPham> *findList();      // Tim va tra ve danh sach san pham
  int findIndex(List<SanPham> *, const Ma &);
};

#endif