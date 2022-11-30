#ifndef __MENU__
#define __MENU__

#include "iostream"
#include <fstream>
#include "QuanLi.h"
#include "QLSanPham.h"
#include "QLNhanVien.h"
#include "QLKhachHang.h"

#include "..\src\features\QuanLi\QuanLi.cpp"
#include "..\src\features\QuanLi\QLNhanVien.cpp"
#include "..\src\features\QuanLi\QLSanPham.cpp"
#include "..\src\features\QuanLi\QLKhachHang.cpp"

class Menu
{
public:
  Menu();
  ~Menu();
  static void login();
};

// class AdminMenu
// {
// public:
//   AdminMenu();
//   ~AdminMenu();
//   static void printInfo();
//   static void printInfoThongKe();
//   static void adMenu(QuanLi *);
//   static void quanLiNhanVien(QuanLi *);
//   static void quanLiSanPham(QuanLi *);
//   static void quanLiHoaDon(QuanLi *);
//   static void quanLiKhachHang(QuanLi *);
//   static void thongKe(QuanLi *);
// };

// class NVMenu
// {
// public:
//   NVMenu();
//   ~NVMenu();
//   static void printInfo();
//   static void nvMenu(QuanLi *);
//   static void quanLiSanPham(QuanLi *);
//   static void quanLiHoaDon(QuanLi *);
//   static void quanLiKhachHang(QuanLi *);
// };

#endif