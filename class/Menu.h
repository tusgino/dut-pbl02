#ifndef __MENU__
#define __MENU__

#include "iostream"
#include <fstream>
#include "QLSanPham.h"
#include "QLNhanVien.h"
#include "QLKhachHang.h"
#include "QLHoaDon.h"

class Menu
{

  int checkRole;
  bool log;

public:
  QLNhanVien *DatabaseNV;
  QLSanPham *DatabaseSP;
  QLKhachHang *DatabaseKH;
  QLHoaDon *DatabaseHD;
  Menu();
  ~Menu();
  void setLog(const bool &);
  void checkLogin();
  void login();
};

class AdminMenu
{
public:
  AdminMenu();
  ~AdminMenu();
  static void printInfo();
  // static void printInfoThongKe();
  static void quanLiNhanVien(Menu &);
  static void quanLiSanPham(Menu &);
  static void quanLiHoaDon(Menu &);
  static void quanLiKhachHang(Menu &);
  // static void thongKe();
  static void adMenu(Menu &);
};

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