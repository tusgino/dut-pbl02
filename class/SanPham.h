#ifndef __SP_H__
#define __SP_H__

#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>

#include "Ma.h"

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
  int giamGia;
  string xuatXu;
  string size;

public:
  // Init
  SanPham();
  SanPham(const Ma &, const string &, const string &, const string &, const int &, const ll &, const ll &, const int &);
  ~SanPham();
  // Set, Get
  void setMa(const Ma &);
  void setSize(const string &);
  void setTen(const string &);
  void setXuatXu(const string &);
  void setSoLuong(const ll &);
  void setGiaNhap(const ll &);
  void setGiaBan(const ll &);
  void setGiamGia(const int &);
  string getLoaiSP();
  int getSTT();
  Ma getMa();
  string getSize();
  string getTen();
  string getXuatXu();
  int getSoLuong();
  ll getGiaNhap();
  ll getGiaBan();
  int getGiamGia();
  // Utils
  void docFile(fstream &);
  void ghiFile(fstream &);
  void Xuat();
};
#endif