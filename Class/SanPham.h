#ifndef __SP_H__
#define __SP_H__

#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>
#include "List.h"
#include "..\src\components\utils\List.cpp"
#include "..\src\components\utils\Node.cpp"

typedef long long ll;

using namespace std;

class SanPham
{
private:
  string ten;
  int soLuong;
  ll giaNhap;
  ll giaBan;
  float giamGia;
  string xuatXu;

public:
  SanPham();
  SanPham();
  ~SanPham();
};
#endif