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