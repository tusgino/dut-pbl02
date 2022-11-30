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

void NhanVien::nhap()
{
  cout << "Nhan vien hay Quan li dang nhap du lieu co ma la: " << this->ma << endl;
  cout << "Nhap ten nhan vien nay: ";
  fflush(stdin);
  getline(cin, this->ten);
  while (true)
  {
    cout << "Nhap so dien thoai nhan vien nay: ";
    fflush(stdin);
    getline(cin, this->soDienThoai);
    if (this->soDienThoai.length() == 0)
    {
      printError("So dien thoai khong the de trong!");
    }
    else
    {
      break;
    }
  }
  {
    string arr[] = {"Nhap gioi tinh", "Nam", "Nu", "Khac"};
    printOpt(arr, 3);
  }
  int key = getKey(3);
  switch (key)
  {
  case 1:
  case 2:
  case 3:
    this->gioiTinh = key;
    break;
  default:
    this->gioiTinh = -1;
    break;
  }

  cout << "Nhap dia chi:";
  fflush(stdin);
  getline(cin, this->diaChi);
  if (this->diaChi.length() == 0)
  {
    this->diaChi = "(null)";
  }

  {
    string arr[] = {"Nhap ca lam: ", "07h00 den 11h30", "13h30 den 18h00", "18h30 den 23h00"};
    printOpt(arr, 3);

    int key = getKey(3);
    switch (key)
    {
    case 1:
    case 2:
    case 3:
      this->caLam = key;
      break;
    default:
      this->caLam = -1;
      break;
    }
  }
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