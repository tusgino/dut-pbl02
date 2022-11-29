
#include "..\..\..\Class\SanPham.h"
#include <fstream>
#include <string.h>
#include <iomanip>

SanPham::SanPham() {}
SanPham::SanPham(string maSP, string tenSP, string xuatXu, int soLuongSP, long long giaNhapSP, long long donGiaSP, float giamGiaSP, Size size)
{
  this->maSP = maSP;
  this->tenSP = tenSP;
  this->soLuongSP = soLuongSP;
  this->giaNhapSP = giaNhapSP;
  this->donGiaSP = donGiaSP;
  this->giamgiaSP = giamGiaSP;
  this->size = size;
  this->xuatXu = xuatXu;
}
SanPham::~SanPham() {}
void SanPham::setMaSP(string maSP)
{
  this->maSP = maSP;
}
void SanPham::setTenSP(string tenSP)
{
  this->tenSP = tenSP;
}
void SanPham::setSoLuongSP(int soLuongSP)
{
  this->soLuongSP = soLuongSP;
}
void SanPham::setDonGiaSP(long long donGiaSP)
{
  this->donGiaSP = donGiaSP;
}
void SanPham::setGiaNhapSP(long long giaNhapSP)
{
  this->giaNhapSP = giaNhapSP;
}
void SanPham::setGiamGiaSP(float giamGiaSP)
{
  this->giamgiaSP = giamGiaSP;
}
void SanPham::setSizeSP(Size size)
{
  this->size = size;
}
void SanPham::setXuatXu(string xuatXu)
{
  this->xuatXu = xuatXu;
}
string SanPham::getMaSP()
{
  return this->maSP;
}
string SanPham::getTenSP()
{
  return this->tenSP;
}
string SanPham::getXuatXu()
{
  return this->xuatXu;
}
int SanPham::getSoLuongSP()
{
  return this->soLuongSP;
}
long long SanPham::getDonGiaSP()
{
  return this->donGiaSP;
}
long long SanPham::getGiaNhapSP()
{
  return this->giaNhapSP;
}
float SanPham::getGiamGiaSP()
{
  return this->giamgiaSP;
}
Size SanPham::getSize()
{
  return this->size;
}

void SanPham::docFile(fstream &fileIn)
{
  getline(fileIn, this->maSP, '|');
  getline(fileIn, this->tenSP, '|');
  getline(fileIn, this->xuatXu, '|');
  fileIn >> this->soLuongSP;
  fileIn.ignore(1);
  fileIn >> this->giaNhapSP;
  fileIn.ignore(1);
  fileIn >> this->donGiaSP;
  fileIn.ignore(1);
  fileIn >> this->giamgiaSP;
  fileIn.ignore(1);
  int S, M, L, XL, XXL;
  fileIn >> S;
  fileIn.ignore(1);
  fileIn >> M;
  fileIn.ignore(1);
  fileIn >> L;
  fileIn.ignore(1);
  fileIn >> XL;
  fileIn.ignore(1);
  fileIn >> XXL;
  fileIn.ignore(1);
  this->size.setAll(S, M, L, XL, XXL);
}

void SanPham::ghiFile(fstream &fileOut)
{
  fileOut << this->maSP << "|";
  fileOut << this->tenSP << "|";
  fileOut << this->xuatXu << "|";
  fileOut << this->soLuongSP << "|";
  fileOut << this->giaNhapSP << "|";
  fileOut << this->donGiaSP << "|";
  fileOut << this->giamgiaSP << "|";
  this->size.ghiFile(fileOut);
}

void SanPham::xuat()
{
  cout << this->maSP << "|"
       << this->tenSP << "|"
       << this->xuatXu << "|"
       << this->soLuongSP << "|"
       << this->giaNhapSP << "|"
       << this->donGiaSP << "|"
       << this->giamgiaSP << "|";
  this->size.xuat();
  cout << endl;
}

void SanPham::xuatThanhBang()
{
  // setfill(' ');
  // cin.ignore();
  cout << setfill('-') << setw(145) << " " << endl
       << setfill(' ');

  cout << "||" << setw(13) << left << this->maSP << "||" << setw(30) << left << this->tenSP << "|| " << setw(9) << left << this->xuatXu << "||" << setw(23) << left << this->soLuongSP << "|| " << setw(11) << left << this->giaNhapSP << "|| " << setw(10) << left << this->donGiaSP << "|| " << setfill('0') << setw(2) << left << this->giamgiaSP << setfill(' ') << "%" << setw(9) << right << "|| ";
  this->size.xuat();
  cout << endl;
}
