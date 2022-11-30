#include "..\..\..\class\SanPham.h"

using namespace std;

//@ Init

SanPham::SanPham() {}
SanPham::SanPham(const Ma &ma, const string &size, const string &ten, const string &xuatXu, const int &soLuong, const ll &giaNhap, const ll &giaBan, const int &giamGia)
{
  this->ma = ma;
  this->size = size;
  this->ten = ten;
  this->xuatXu = xuatXu;
  this->soLuong = soLuong;
  this->giaNhap = giaNhap;
  this->giaBan = giaBan;
  this->giamGia = giamGia;
}
SanPham::~SanPham() {}

//@ set, get

void SanPham::setMa(const Ma &ma)
{
  this->ma = ma;
}
void SanPham::setSize(const string &size)
{
  this->size = size;
}
void SanPham::setTen(const string &ten)
{
  this->ten = ten;
}
void SanPham::setXuatXu(const string &xuatXu)
{
  this->xuatXu = xuatXu;
}
void SanPham::setSoLuong(const ll &soLuong)
{
  this->soLuong = soLuong;
}
void SanPham::setGiaNhap(const ll &giaNhap)
{
  this->giaNhap = giaNhap;
}
void SanPham::setGiaBan(const ll &giaBan)
{
  this->giaBan = giaBan;
}
void SanPham::setGiamGia(const int &giamGia)
{
  this->giamGia = giamGia;
}
string SanPham::getLoaiSP()
{
  if (this->ma.getKiTu() == "A")
    return "Ao";
  return "Quan";
}
int SanPham::getSTT()
{
  return this->ma.getSoTT();
}
Ma SanPham::getMa()
{
  return this->ma;
}
string SanPham::getSize()
{
  return this->size;
}
string SanPham::getTen()
{
  return this->ten;
}
string SanPham::getXuatXu()
{
  return this->xuatXu;
}
int SanPham::getSoLuong()
{
  return this->soLuong;
}
ll SanPham::getGiaNhap()
{
  return this->giaNhap;
}
ll SanPham::getGiaBan()
{
  return this->giaBan;
}
int SanPham::getGiamGia()
{
  return this->giamGia;
}

// @Utils

void SanPham::docFile(fstream &fileIn)
{
  this->ma.docFile(fileIn);
  getline(fileIn, this->size, '|');
  getline(fileIn, this->ten, '|');
  getline(fileIn, this->xuatXu, '|');
  fileIn >> this->soLuong;
  fileIn.ignore(1);
  fileIn >> giaNhap;
  fileIn.ignore(1);
  fileIn >> giaBan;
  fileIn.ignore(1);
  fileIn >> giamGia;
  fileIn.ignore(2);
}

void SanPham::ghiFile(fstream &fileOut)
{
  this->ma.ghiFile(fileOut);
  fileOut << this->size << "|";
  fileOut << this->ten << "|";
  fileOut << this->xuatXu << "|";
  fileOut << this->soLuong << "|";
  fileOut << this->giaNhap << "|";
  fileOut << this->giaBan << "|";
  fileOut << this->giamGia << "|";
}

void SanPham::Xuat()
{
  cout << this->ma << "|";
  cout << this->size << "|";
  cout << this->ten << "|";
  cout << this->xuatXu << "|";
  cout << this->soLuong << "|";
  cout << this->giaNhap << "|";
  cout << this->giaBan << "|";
  cout << this->giamGia << "|";
}