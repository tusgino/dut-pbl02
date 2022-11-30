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
  int maMax = this->findMaMax();
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
  int tempGiamGia;
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

void QLSanPham::read()
{
  ConsoleTable table{"STT", "Ma San Pham", "Ten San Pham", "Xuat Xu", "Gia Nhap", "Gia Ban", "Giam Gia", "S", "M", "L", "XL", "XXL", "Tong So Luong"};

  table.setPadding(1);
  table.setStyle(0);
  Node<SanPham> *pTemp = this->dbSP->getpHead();
  Node<SanPham> *pTempBF = this->dbSP->getpHead();
  QLSanPham::sortMa();
  Ma tempMa = pTemp->getData().getMa();
  int *arrSize = new int[5];
  for (int i = 0; i <= 5; i++)
  {
    arrSize[i] = 0;
  }
  int cnt = 0;
  while (pTemp)
  {
    if (pTemp->getData().getMa() != tempMa)
    {
      table += {
          to_string(++cnt),
          pTempBF->getData().getMa(),
          pTempBF->getData().getTen(),
          pTempBF->getData().getXuatXu(),
          to_string(pTempBF->getData().getGiaNhap()),
          to_string(pTempBF->getData().getGiaBan()),
          to_string(pTempBF->getData().getGiamGia()),
          to_string(arrSize[0]),
          to_string(arrSize[1]),
          to_string(arrSize[2]),
          to_string(arrSize[3]),
          to_string(arrSize[4]),
          to_string(arrSize[0] + arrSize[1] + arrSize[2] + arrSize[3] + arrSize[4])};
      tempMa = pTemp->getData().getMa();
      for (int i = 0; i < 5; i++)
      {
        arrSize[i] = 0;
      }
    }
    if (pTemp->getData().getSize() == "S")
    {
      arrSize[0] = pTemp->getData().getSoLuong();
    }
    if (pTemp->getData().getSize() == "M")
    {
      arrSize[1] = pTemp->getData().getSoLuong();
    }
    if (pTemp->getData().getSize() == "L")
    {
      arrSize[2] = pTemp->getData().getSoLuong();
    }
    if (pTemp->getData().getSize() == "XL")
    {
      arrSize[3] = pTemp->getData().getSoLuong();
    }
    if (pTemp->getData().getSize() == "XXL")
    {
      arrSize[4] = pTemp->getData().getSoLuong();
    }
    pTempBF = pTemp;
    pTemp = pTemp->getpNext();
  }
  table += {
      to_string(++cnt),
      pTempBF->getData().getMa(),
      pTempBF->getData().getTen(),
      pTempBF->getData().getXuatXu(),
      to_string(pTempBF->getData().getGiaNhap()),
      to_string(pTempBF->getData().getGiaBan()),
      to_string(pTempBF->getData().getGiamGia()),
      to_string(arrSize[0]),
      to_string(arrSize[1]),
      to_string(arrSize[2]),
      to_string(arrSize[3]),
      to_string(arrSize[4]),
      to_string(arrSize[0] + arrSize[1] + arrSize[2] + arrSize[3] + arrSize[4])};
  delete[] arrSize;
  cout << table;
}

// components

int QLSanPham::findMaMax()
{
  Node<SanPham> *pTemp = this->dbSP->getpHead();
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

void QLSanPham::sortMa()
{
  Node<SanPham> *pBefore = this->dbSP->getpHead();
  Node<SanPham> *pAfter = pBefore->getpNext();
  while (pBefore)
  {
    pAfter = pBefore->getpNext();
    while (pAfter)
    {
      if (pBefore->getData().getMa() >= pAfter->getData().getMa())
      {
        SanPham pTemp = pBefore->getData();
        pBefore->setData(pAfter->getData());
        pAfter->setData(pTemp);
      }
      pAfter = pAfter->getpNext();
    }
    pBefore = pBefore->getpNext();
  }
}