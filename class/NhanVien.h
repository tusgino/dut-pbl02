#ifndef __NV_H__
#define __NV_H__

#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>

#include "Ma.h"

class NhanVien
{
private:
  Ma ma;
  string ten;
  string soDienThoai;
  int caLam;
  int gioiTinh;
  string diaChi;
  string matKhau;

public:
  // init
  NhanVien();
  NhanVien(const Ma &, const string &, const string &, const int &, const int &, const string &, const string &);
  ~NhanVien();
  // set, get
  void setMa(const Ma &);
  void setTen(const string &);
  void setSoDienThoai(const string &);
  void setCaLam(const int &);
  void setGioiTinh(const int &);
  void setDiaChi(const string &);
  void setMatKhau(const string &);
  string getChucVu();
  Ma getMa();
  string getTen();
  string getSoDienThoai();
  int getcaLam();
  int getGioiTinh();
  string getDiaChi();
  string getMatKhau();

  void docFile(fstream &);
  void ghiFile(fstream &);
  void nhap();
  void xuatFullInfo();
};

#endif