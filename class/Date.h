#ifndef __DATE_H__
#define __DATE_H__
#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;
class Date
{
  int gio;
  int phut;
  int ngay;
  int thang;
  int nam;

public:
  Date();
  Date(const Date &);
  // Phut:Gio Nam/Thang/Ngay
  Date(const int &, const int &, const int &, const int & = 1, const int & = 1);

  const int &getPhut();
  const int &getGio();
  const int &getNgay();
  const int &getThang();
  const int &getNam();

  void setNgay(const int &);
  void setThang(const int &);
  void setNam(const int &);
  void ghiFile(fstream &);
  void docFile(fstream &);

  friend istream &operator>>(istream &, Date &);
  friend ostream &operator<<(ostream &, const Date &);
  const bool operator<=(const Date &);
  const bool operator>=(const Date &);
  const bool operator==(const Date &);
  friend const bool check(const Date &);
  friend void fix(Date &);
  Date operator++(int);
};

#endif