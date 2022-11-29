#ifndef __SP_H__
#define __SP_H__

#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>
// #include "..\src\components\utils\List.cpp"
// #include "..\src\components\utils\Node.cpp"
#include "..\src\components\utils\components.cpp"
#include "..\src\components\utils\Ma.cpp"

typedef long long ll;

using namespace std;

class SanPham
{
private:
  Ma ma;
  string ten;
  int soLuong;
  ll giaNhap;
  ll giaBan;
  float giamGia;
  string xuatXu;
  char size;

public:
  // Init
  SanPham();
  SanPham(const Ma &, const char &, const string &, const string &, const int &, const ll &, const ll &, const float &);
  ~SanPham();
  // Set, Get
  void setMa(const Ma &);
  void setSize(const char &);
  void setTen(const string &);
  void setXuatXu(const string &);
  void setSoLuong(const ll &);
  void setGiaNhap(const ll &);
  void setGiaBan(const ll &);
  void setGiamGia(const float &);
  string getLoaiSP();
  int getSTT();
  Ma getMa();
  char getSize();
  string getTen();
  string getXuatXu();
  int getSoLuong();
  ll getGiaNhap();
  ll getGiaBan();
  float getGiamGia();
  // Utils
  void docFile(fstream &);
  void ghiFile(fstream &);
  void Xuat();
};
#endif