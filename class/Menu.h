#ifndef __MENU__
#define __MENU__

#include "iostream"
#include <fstream>
#include <conio.h>
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
  QuanLi *quanLi;
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
  static void thongKe(Menu &);
  static void adMenu(Menu &);
};

class NVMenu
{
public:
  NVMenu();
  ~NVMenu();
  static void printInfo();
  static void nvMenu(Menu &);
  static void quanLiSanPham(Menu &);
  static void quanLiHoaDon(Menu &);
  static void quanLiKhachHang(Menu &);
};

#endif