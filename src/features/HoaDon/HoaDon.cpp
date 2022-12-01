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
  fileOut << endl;
}
