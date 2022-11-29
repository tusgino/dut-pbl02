#include "..\..\..\class\KhachHang.h"

using namespace std;

KhachHang::KhachHang() {}
KhachHang::KhachHang(const Ma &ma, const string &ten, const string &soDienThoai, const string &diaChi, const string &email, const int &gioiTinh)
{
  this->ma = ma;
  this->ten = ten;
  this->soDienThoai = soDienThoai;
  this->diaChi = diaChi;
  this->email = email;
  this->gioiTinh = gioiTinh;
}
KhachHang::~KhachHang() {}

void KhachHang::docFile(fstream &fileIn)
{
  this->ma.docFile(fileIn);
  getline(fileIn, this->ten, '|');
  getline(fileIn, this->soDienThoai, '|');
  getline(fileIn, this->diaChi, '|');
  getline(fileIn, this->email, '|');
  fileIn >> this->gioiTinh;
  fileIn.ignore(1);
}
void KhachHang::ghiFile(fstream &fileOut)
{
  this->ma.ghiFile(fileOut);
  fileOut << this->ten << "|";
  fileOut << this->soDienThoai << "|";
  fileOut << this->diaChi << "|";
  fileOut << this->email << "|";
  fileOut << this->gioiTinh << "|";
}