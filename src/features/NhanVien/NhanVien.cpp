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
  cout << endl;
  cout << "\tNhan vien hay Quan li dang nhap du lieu co ma la: " << this->ma << endl;
  cout << "\tNhap ten nhan vien nay: ";
  fflush(stdin);
  getline(cin, this->ten);
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

  cout << "\tNhap dia chi:";
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
  cout << "\tNhap mat khau:";
  fflush(stdin);
  getline(cin, this->matKhau);
  if (this->matKhau.length() == 0)
  {
    cout << "Vi mat khau ban nhap la rong nen he thong se dat mat khau mac dinh cho nguoi dung la \"1\"" << endl;
    this->matKhau = "1";
  }
}

void NhanVien::xuatFullInfo()
{
  cout << center << "+--------------------------------------------------------+\n";
  cout << center << "| " << setw(25) << right << "Ma nhan vien: " << this->ma << setw(26) << right << "|\n";
  cout << center << "| " << setw(25) << right << "Ho ten nhan vien: " << setw(30) << left << this->ten << "|\n";
  if (this->ma.getKiTu() == "NV")
  {
    cout << center << "| " << setw(25) << right << "Chuc vu: " << setw(30) << left << "Nhan vien"
       << "|\n";
  }
  else
  {
    cout << center << "| " << setw(25) << right << "Chuc vu: " << setw(30) << left << "Quan li"
         << "|\n";
  }
  cout << center << "| " << setw(25) << right << "So dien thoai: " << setw(30) << left << this->soDienThoai << "|\n";
  cout << center << "| " << setw(25) << right << "Dia chi: " << setw(30) << left << this->diaChi << "|\n";
  // cout << "| " << setw(25) << right << "Email: " << setw(30) << left << this->email << "|\n";
  switch (this->caLam)
  {
  case 1:
    cout << center << "| " << setw(25) << right << "Ca lam: " << setw(30) << left << "07h00 den 11h30"
         << "|\n";

    break;
  case 2:
    cout << center << "| " << setw(25) << right << "Ca lam: " << setw(30) << left << "13h30 den 18h00"
         << "|\n";

    break;
  case 3:
    cout << center << "| " << setw(25) << right << "Ca lam: " << setw(30) << left << "18h30 den 23h00"
         << "|\n";

    break;
  default:
    cout << center << "| " << setw(25) << right << "Ca lam: " << setw(30) << left << "(null)"
         << "|\n";

    break;
  }
  switch (this->gioiTinh)
  {
  case 1:
    cout << center << "| " << setw(25) << right << "Gioi tinh: " << setw(30) << left << "Nam"
         << "|\n";

    break;
  case 2:
    cout << center << "| " << setw(25) << right << "Gioi tinh: " << setw(30) << left << "Nu"
         << "|\n";

    break;
  case 3:
    cout << center << "| " << setw(25) << right << "Gioi tinh: " << setw(30) << left << "Khac"
         << "|\n";

    break;
  default:
    cout << center << "| " << setw(25) << right << "Gioi tinh: " << setw(30) << left << "(null)"
         << "|\n";

    break;
  }
  cout << center << "+--------------------------------------------------------+\n";
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
void NhanVien::setDiaChi(const string &diachi)
{
  this->diaChi = diachi;
}
void NhanVien::setMatKhau(const string &matkhau)
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