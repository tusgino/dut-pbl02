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
  fileIn.ignore(2);
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
void KhachHang::nhap()
{
  cout << "Khach hang co ma la" << this->ma << endl;
  cout << "Nhap ten khach hang: ";
  fflush(stdin);
  getline(cin, this->ten);
  cout << "Nhap so dien thoai: " << this->soDienThoai;
  // fflush(stdin);
  // getline(cin, this->soDienThoai);
  cout << "Nhap dia chi: ";
  fflush(stdin);
  getline(cin, this->diaChi);
  cout << "Nhap email: ";
  fflush(stdin);
  getline(cin, this->email);
  cout << "Nhap gioi tinh: ";
  cin >> this->gioiTinh;
}
void KhachHang::xuat()
{
}
void KhachHang::chinhSua()
{
}

void KhachHang::xuatFullInfo()
{
  cout << "+--------------------------------------------------------+\n";
  cout << "| " << setw(25) << right << "Ma khach hang: " << this->ma << setw(26) << right << "|\n";
  cout << "| " << setw(25) << right << "Ho ten khach hang: " << setw(30) << left << this->ten << "|\n";
  cout << "| " << setw(25) << right << "So dien thoai: " << setw(30) << left << this->soDienThoai << "|\n";
  cout << "| " << setw(25) << right << "Dia chi: " << setw(30) << left << this->diaChi << "|\n";
  cout << "| " << setw(25) << right << "Email: " << setw(30) << left << this->email << "|\n";
  switch (this->gioiTinh)
  {
  case 1:
    cout << "| " << setw(25) << right << "Gioi tinh: " << setw(30) << left << "Nam"
         << "|\n";

    break;
  case 2:
    cout << "| " << setw(25) << right << "Gioi tinh: " << setw(30) << left << "Nu"
         << "|\n";

    break;
  case 3:
    cout << "| " << setw(25) << right << "Gioi tinh: " << setw(30) << left << "Khac"
         << "|\n";

    break;
  default:
    cout << "| " << setw(25) << right << "Gioi tinh: " << setw(30) << left << "(null)"
         << "|\n";

    break;
  }
  cout << "+--------------------------------------------------------+\n";
}
void KhachHang::setMa(const Ma &ma)
{
  this->ma = ma;
}
void KhachHang::setTen(const string &ten)
{
  this->ten = ten;
}
void KhachHang::setSoDienThoai(const string &sdt)
{
  this->soDienThoai = sdt;
}
void KhachHang::setDiaChi(const string &diachi)
{
  this->diaChi = diachi;
}
void KhachHang::setGioiTinh(const int &gioitinh)
{
  this->gioiTinh = gioitinh;
}
void KhachHang::setEmail(const string &email)
{
  this->email = email;
}
Ma KhachHang::getMa()
{
  return this->ma;
}
const string &KhachHang::getTen()
{
  return this->ten;
}
const string &KhachHang::getSoDienThoai()
{
  return this->soDienThoai;
}
const string &KhachHang::getDiaChi()
{
  return this->diaChi;
}
const int &KhachHang::getGioiTinh()
{
  return this->gioiTinh;
}
const string &KhachHang::getEmail()
{
  return this->email;
}