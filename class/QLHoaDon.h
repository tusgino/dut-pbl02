#ifndef _QLHD__H_
#define _QLHD__H_

#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>

#include "HoaDon.h"
#include "QLNhanVien.h"
#include "QLSanPham.h"
#include "QLKhachHang.h"
#include "QuanLi.h"

using namespace std;

class QLHoaDon : public QuanLi
{
  QLKhachHang *pKH;
  QLNhanVien *pNV;
  QLSanPham *pSP;
  List<HoaDon> *listHD;
  int count;

public:
  QLHoaDon();
  QLHoaDon(QLNhanVien *, QLKhachHang *, QLSanPham *);
  ~QLHoaDon();

  // components

  void docFile(fstream &);
  void ghiFile(fstream &);
  void create(); // Nhap tu nguoi dung
  // void update();      // Chinh sua
  void read(); // Xuat ra man hinh
  void find(); // Tim Kiem
  // void deleteIndex(); // Xoa
  const int findMaMax();
  // utils
};

#endif
