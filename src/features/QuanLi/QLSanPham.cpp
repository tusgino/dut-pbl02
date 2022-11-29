#include "..\..\..\class\QLSanPham.h"

using namespace std;

QLSanPham::QLSanPham()
{
  this->dbSP = new List<SanPham>();
  this->count = 0;
}

QLSanPham::~QLSanPham()
{
  this->dbSP->~List();
}
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
  string arr[] = {
      "Vui long chon loai san pham:",
      "Ao",
      "Quan"};
  printOpt(arr, 2);
  int key = getKey(2);
  string kiTu = "A";
  if (key == 2)
    kiTu = "Q";
  cout << kiTu;
  Node<SanPham> *pTemp = this->dbSP->getpHead();
  int maMax = 0;
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
  string arr1[] = {"Chon size va nhap so luong: ", "S", "M", "L", "XL", "XXL", "Thoat."};
  bool arrCheck[] = {
      false,
      true,
      true,
      true,
      true,
      true};
  bool check = true;
  List<SanPham> *tempList = new List<SanPham>();
  while (check)
  {
    system("cls");
    printOpt(arr1, 6);
    int key = getKey(6);
    if (key == 6)
      break;
    string tempSize = arr1[key];
    if (!arrCheck[key])
    {
      printWarning("Ban da co size nay roi!");

      string arr3[] = {"Ban muon?: ", "Thay doi so luong.", "Them vao so luong da co.", "Quay lai"};
      printOpt(arr3, 3);
      int key = getKey(2);
      if (key == 1)
      {
        Node<SanPham> *pTemp = tempList->getpHead();
        while (pTemp)
        {
          if (tempSize == pTemp->getData().getSize())
          {
            int tempSoLuong;
            string warning = "So luong hien tai cua size " + tempSize + " la: " + to_string(pTemp->getData().getSoLuong());
            printWarning(warning);
            printRes("Nhap so luong: ");
            cin >> tempSoLuong;
            SanPham tempSP(tempMa, tempSize, tempTen, tempXuatXu, tempSoLuong, tempGiaNhap, tempGiaBan, tempGiamGia);
            pTemp->setData(tempSP);
          }
          pTemp = pTemp->getpNext();
        }
      }
      if (key == 2)
      {
        Node<SanPham> *pTemp = tempList->getpHead();
        while (pTemp)
        {
          if (tempSize == pTemp->getData().getSize())
          {
            int tempSoLuong;
            string warning = "So luong hien tai cua size " + tempSize + " la: " + to_string(pTemp->getData().getSoLuong());
            printWarning(warning);
            printRes("Nhap so luong: ");
            cin >> tempSoLuong;
            SanPham tempSP(tempMa, tempSize, tempTen, tempXuatXu, pTemp->getData().getSoLuong() + tempSoLuong, tempGiaNhap, tempGiaBan, tempGiamGia);
            pTemp->setData(tempSP);
          }
          pTemp = pTemp->getpNext();
        }
      }
    }
    else
    {
      int tempSoLuong;
      printRes("Nhap so luong: ");
      cin >> tempSoLuong;
      SanPham tempSP(tempMa, tempSize, tempTen, tempXuatXu, tempSoLuong, tempGiaNhap, tempGiaBan, tempGiamGia);
      tempList->push_back(tempSP);
      arrCheck[key] = false;
      this->count++;
    }
  }
  Node<SanPham> *pTemp1 = tempList->getpHead();
  while (pTemp1)
  {
    this->dbSP->push_back(pTemp1->getData());
    pTemp1 = pTemp1->getpNext();
  }
  fstream fileSanPham;
  fileSanPham.open("src/components/data/SanPham.DAT", ios_base::out);
  QLSanPham::ghiFile(fileSanPham);
  fileSanPham.close();
}