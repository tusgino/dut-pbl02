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
  void docFile(fstream &);
  void ghiFile(fstream &);
  void create(); // Nhap tu nguoi dung
  // void update();      // Chinh sua
  void read(); // Xuat ra man hinh
  // void find();        // Tim Kiem
  void deleteIndex(); // Xoa
  void Delete();

  // components
  void sortMa();
  int findMaMax();
};

#endif