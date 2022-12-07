#ifndef __HoaDon_H__
#define __HoaDon_H__

#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>

#include "SanPham.h"
#include "Ma.h"
#include "Date.h"
#include "QLSanPham.h"

class HoaDon
{
  Ma maHD, maNV, maKH;
  int soLuong;
  ll tongTien;
  Date ngayHD;
  List<SanPham> *listSP;

public:
  HoaDon();
  HoaDon(List<SanPham> *, const Ma &, const Ma &, const Ma &);
  ~HoaDon();

  //--set, get
  void setMaHD(const Ma &);
  void setMaNV(const Ma &);
  void setMaKH(const Ma &);
  void setSoLuong(const int &);
  void setTongTien(const ll &);
  void setNgayHD(const Date &);
  void setListSP(List<SanPham> *);
  //-
  const Ma &getMaHD();
  const int &getSTT();
  const Ma &getMaNV();
  const Ma &getMaKH();
  const int &getSoLuong();
  const ll &getTongTien();
  const Date &getNgayHD();
  List<SanPham> *getListSP();

  // Utils
  void docFile(fstream &);
  void ghiFile(fstream &);
  void xuat();
  void xuatFile(fstream &); // xuat full hoa don
  void tinhTongTien();
  HoaDon &operator=(const HoaDon &);
};

#endif
