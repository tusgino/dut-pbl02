#include "..\..\..\class\HoaDon.h"

HoaDon::HoaDon()
{
  this->listSP = new List<SanPham>();
}

HoaDon::HoaDon(List<SanPham> *listSP, const Ma &maHD, const Ma &maNV, const Ma &maKH)
{
  this->maHD = maHD;
  this->maNV = maNV;
  this->maKH = maKH;
  this->listSP = listSP;
  this->tongTien = 0;
  this->soLuong = 0;
  this->ngayHD = Date(0, 0, 0, 0, 0);
}

HoaDon::~HoaDon() {}

//--set, get
void HoaDon::setMaHD(const Ma &maHD)
{
  this->maHD = maHD;
}
void HoaDon::setMaNV(const Ma &maNV)
{
  this->maNV = maNV;
}
void HoaDon::setMaKH(const Ma &maKH)
{
  this->maKH = maKH;
}
void HoaDon::setsoLuong(const int &soLuong)
{
  this->soLuong = soLuong;
}
void HoaDon::setTongTien(const ll &tongTien)
{
  this->tongTien = tongTien;
}
void HoaDon::setNgayHD(const Date &ngayHD)
{
  this->ngayHD = ngayHD;
}
void HoaDon::setListSP(List<SanPham> *listSP)
{
  this->listSP = listSP;
}
//-
const Ma &HoaDon::getMaHD()
{
  return this->maHD;
}

const int &HoaDon::getSTT()
{
  return this->maHD.getSoTT();
}
const Ma &HoaDon::getMaNV()
{
  return this->maNV;
}
const Ma &HoaDon::getMaKH()
{
  return this->maKH;
}
const int &HoaDon::getSoLuong()
{
  return this->soLuong;
}
const ll &HoaDon::getTongTien()
{
  return this->tongTien;
}
const Date &HoaDon::getNgayHD()
{
  return this->ngayHD;
}
List<SanPham> *HoaDon::getListSP()
{
  return this->listSP;
}

// Utils

void HoaDon::docFile(fstream &fileIn)
{
  this->maHD.docFile(fileIn);
  this->maNV.docFile(fileIn);
  this->maKH.docFile(fileIn);
  this->ngayHD.docFile(fileIn);
  fileIn >> this->soLuong;
  fileIn.ignore(1);
  for (int i = 0; i < this->soLuong; i++)
  {
    SanPham tempSP;
    tempSP.docFile(fileIn);
    listSP->push_back(tempSP);
  }
}

void HoaDon::ghiFile(fstream &fileOut)
{
  this->maHD.ghiFile(fileOut);
  this->maNV.ghiFile(fileOut);
  this->maKH.ghiFile(fileOut);
  this->ngayHD.ghiFile(fileOut);
  fileOut << this->soLuong << "|";
  Node<SanPham> *pTemp = listSP->getpHead();
  while (pTemp)
  {
    pTemp->getData().ghiFile(fileOut);
    pTemp = pTemp->getpNext();
  }
}

void HoaDon::xuat()
{
  cout << center << "+------------------------------------------------+\n";
  cout << center << "|              THONG TIN HOA DON                 |\n";
  cout << center << "| Ma nhan vien: " << this->maNV << "                           |\n";
  cout << center << "| Ma khach hang: " << this->maKH << "                          |\n";
  cout << center << "| Ngay thuc hien hoa don: " << this->ngayHD << "      |\n";
  cout << center << "+------------------------------------------------+\n";

  ConsoleTable table = {"STT", "Ma san pham", "Ten san pham", "Size", "Don gia", "So luong", "Giam gia (%)", "Thanh tien"};
  int cnt = 0;
  Node<SanPham> *pTemp = this->listSP->getpHead();
  this->tongTien = 0;
  while (pTemp)
  {
    table += {to_string(++cnt), string(pTemp->getData().getMa()), pTemp->getData().getTen(), pTemp->getData().getSize(), to_string(pTemp->getData().getGiaBan()), to_string(pTemp->getData().getSoLuong()), to_string(pTemp->getData().getGiamGia()), to_string(ll(pTemp->getData().getSoLuong() * (1 - pTemp->getData().getGiamGia() / 100) * pTemp->getData().getGiaBan()))};
    this->tongTien += ll(pTemp->getData().getSoLuong() * (1 - pTemp->getData().getGiamGia() / 100) * pTemp->getData().getGiaBan());
    pTemp = pTemp->getpNext();
  }
  cout << center << "Don hang nay bao gom: " << cnt << " san pham\n";

  cout << table;

  cout << center << "\n\t\tTHANH TIEN: " << this->tongTien;
}
