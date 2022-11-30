#ifndef __QLSP_H__
#define __QLSP_H__

#include "SanPham.h"
// #include "..\src\features\QuanLi\QuanLi.cpp"
#include "QuanLi.h"

class QLSanPham : public QuanLi
{
  int count;
  List<SanPham> *dbSP;

public:
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