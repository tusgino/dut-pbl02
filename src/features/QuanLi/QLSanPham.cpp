#include "..\..\..\class\QLSanPham.h"

using namespace std;

void QLSanPham::docFile(fstream &fileIn)
{
  fileIn >> this->count;
  fileIn.ignore(1);
  for (int i = 0; i < this->count; i++)
  {
    SanPham *SP = new SanPham;
    SP->docFile(fileIn);
    this->dbSP->push_back(*SP);
    delete SP;
  }
}

void QLSanPham::ghiFile(fstream &fileOut)
{
  fileOut << this->count << endl;
  Node<SanPham> *pTemp = this->dbSP->getpHead();
  while (pTemp)
  {
    pTemp->getData().ghiFile(fileOut);
    fileOut << endl;
    pTemp = pTemp->getpNext();
  }
}

void QLSanPham::create()
{
  printRes("Vui long chon loai san pham:");
  string arr[] = {"Ao", "Quan"};
  printOpt(arr);
  int key = getKey(2);
  string kiTu = "A";
  if (key == 2)
    kiTu = "Q";
  Node<SanPham> *pTemp = this->dbSP->getpHead();
  int maMax = pTemp->getData().getSTT();
  while (pTemp)
  {
    int tempSTT = pTemp->getData().getSTT();
    if (maMax < tempSTT)
      maMax = tempSTT;
    pTemp = pTemp->getpNext();
  }
  Ma tempMa(kiTu, maMax + 1);
  printRes("Nhap ten san pham: ");
  string tempTen;
  fflush(stdin);
  getline(cin, tempTen);
  printRes("Nhap xuat xu san pham: ");
  string tempXuatXu;
  fflush(stdin);
  getline(cin, tempXuatXu);
  ll tempGiaNhap;
  printRes("Nhap gia nhap san pham: ");
  cin >> tempGiaNhap;
  ll tempGiaBan;
  printRes("Nhap gia ban san pham: ");
  cin >> tempGiaBan;
  float tempGiamGia;
  printRes("Nhap giam gia san pham: ");
  cin >> tempGiamGia;
}