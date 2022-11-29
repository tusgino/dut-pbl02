#include "..\..\..\class\NhanVien.h"

using namespace std;

NhanVien::NhanVien() {}
NhanVien::NhanVien(const Ma &ma, const string &ten, const string &soDienThoai, const int &caLam, const int &gioiTinh, const string &diaChi, const string &matKhau)
{
  this->ma = ma;
  this->ten = ten;
  this->soDienThoai = soDienThoai;
  this->caLam = caLam;
  this->gioiTinh = gioiTinh;
  this->diaChi = diaChi;
  this->matKhau = matKhau;
}
NhanVien::~NhanVien(){};

void NhanVien::docFile(fstream &fileIn)
{
  this->ma.docFile(fileIn);
  getline(fileIn, this->ten, '|');
  getline(fileIn, this->soDienThoai, '|');
  fileIn >> this->caLam;
  fileIn.ignore(1);
  fileIn >> this->gioiTinh;
  fileIn.ignore(1);
  getline(fileIn, this->diaChi, '|');
  getline(fileIn, this->matKhau, '|');
}

void NhanVien::ghiFile(fstream &fileOut)
{
  this->ma.ghiFile(fileOut);
  fileOut << this->ten << "|";
  fileOut << this->soDienThoai << "|";
  fileOut << this->caLam << "|";
  fileOut << this->gioiTinh << "|";
  fileOut << this->diaChi << "|";
  fileOut << this->matKhau << "|";
}

void NhanVien::setMa(const Ma &ma)
{
  this->ma = ma;
}
void NhanVien::setTen(const string &ten)
{
  this->ten = ten;
}
void NhanVien::setSoDienThoai(const string &sdt)
{
  this->soDienThoai = sdt;
}
void NhanVien::setCaLam(const int &calam)
{
  this->caLam = calam;
}
void NhanVien::setGioiTinh(const int &gioitinh)
{
  this->gioiTinh = gioitinh;
}
void NhanVien::setDiaChi(const int &diachi)
{
  this->diaChi = diachi;
}
void NhanVien::setMatKhau(const int &matkhau)
{
  this->matKhau = matkhau;
}
string NhanVien::getChucVu()
{
  return this->ma.getKiTu();
}
Ma NhanVien::getMa()
{
  return this->ma;
}
string NhanVien::getTen()
{
  return this->ten;
}
string NhanVien::getSoDienThoai()
{
  return this->soDienThoai;
}
int NhanVien::getcaLam()
{
  return this->caLam;
}
int NhanVien::getGioiTinh()
{
  return this->gioiTinh;
}
string NhanVien::getDiaChi()
{
  return this->diaChi;
}
string NhanVien::getMatKhau()
{
  return this->matKhau;
}