#ifndef __KH_H__
#define __KH_H__

#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>
// #include "..\src\components\utils\List.cpp"
// #include "..\src\components\utils\Node.cpp"
#include "..\src\components\utils\components.cpp"
#include "..\src\components\utils\Ma.cpp"

class KhachHang
{
private:
  Ma ma;
  string ten;
  string soDienThoai;
  string diaChi;
  string email;
  int gioiTinh;

public:
  // Init
  KhachHang();
  KhachHang(const Ma &, const string &, const string &, const string &, const string &, const int &);
  ~KhachHang();
  // Set, get
  void setMa(const Ma &);
  void setTen(const string &);
  void setSoDienThoai(const string &);
  void setDiaChi(const string &);
  void setGioiTinh(const int &);
  void setEmail(const string &);
  Ma getMa();
  const string &getTen();
  const string &getSoDienThoai();
  const string &getDiaChi();
  const int &getGioiTinh();
  const string &getEmail();
  void docFile(fstream &);
  void ghiFile(fstream &);
}

#endif