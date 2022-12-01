#include "..\..\..\class\QLHoaDon.h"

QLHoaDon::QLHoaDon()
{
  this->pNV = new QLNhanVien();
  this->pKH = new QLKhachHang();
  this->pSP = new QLSanPham();
  this->listHD = new List<HoaDon>();
  this->count = 0;
}

QLHoaDon::QLHoaDon(QLNhanVien *NV, QLKhachHang *KH, QLSanPham *SP)
{
  this->pNV = NV;
  this->pKH = KH;
  this->pSP = SP;
  this->listHD = new List<HoaDon>();
  this->count = 0;
}

QLHoaDon::~QLHoaDon() {}

void QLHoaDon::docFile(fstream &fileIn)
{
  fileIn >> this->count;
  fileIn.ignore(1);
  for (int i = 0; i < this->count; i++)
  {
    HoaDon tempHD;
    tempHD.docFile(fileIn);
    fileIn.ignore(1);
    this->listHD->push_back(tempHD);
  }
}
void QLHoaDon::ghiFile(fstream &fileOut)
{
  fileOut << this->count << endl;
  Node<HoaDon> *pTemp = this->listHD->getpHead();
  while (pTemp)
  {
    pTemp->getData().ghiFile(fileOut);
    fileOut << endl;
    pTemp = pTemp->getpNext();
  }
}

void QLHoaDon::create()
{
  int maMax = QLHoaDon::findMaMax();
  Ma tempMaHD("HD", maMax + 1);
  Ma tempMaNV("NV", 101); //@ Fix
  printRes(" ");
}

// Utils

const int QLHoaDon::findMaMax()
{
  Node<HoaDon> *pTemp = this->listHD->getpHead();
  int maMax = 0;
  while (pTemp)
  {
    int tempSTT = pTemp->getData().getSTT();
    if (maMax < tempSTT)
      maMax = tempSTT;
    pTemp = pTemp->getpNext();
  }
  return maMax;
}