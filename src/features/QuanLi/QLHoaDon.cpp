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
  Ma tempMaKH;
  while (true)
  {
    system("cls");
    string tempSDT;
    try
    {
      printRes("Nhap so dien thoai khach hang: ");
      fflush(stdin);
      getline(cin, tempSDT);
      tempMaKH = pKH->findKH(tempSDT);
      if (tempMaKH.getSoTT() == -1)
        throw string("Khong tim thay khach hang!");
      break;
    }
    catch (const string error)
    {
      printError(error);
      printRes("Ban co muon them khach hang nay vao trong danh sach khong? (y/n): ");
      char c;
      fflush(stdin);
      c = getchar();
      if (c == 'y')
      {
        pKH->create(tempSDT);
        break;
      }
      return;
    }
  }
  int cnt = 0;
  bool check = true;
  List<SanPham> *listSP = new List<SanPham>();
  while (check)
  {
    List<SanPham> *tempList = new List<SanPham>();
    tempList = this->pSP->findList();
    while (true)
    {
      system("cls");
      pSP->readList(tempList);
      try
      {
        Ma tempMa;
        cin >> tempMa;
        int index = this->pSP->findIndex(tempList, tempMa);
        if (index == -1)
          throw string("Khong tim thay ma san pham trong danh sach tren!");
        while (true)
        {
          try
          {
            string tempSize;
            while (true)
            {
              try
              {
                printRes("Nhap size: ");
                fflush(stdin);
                getline(cin, tempSize);
                if (tempSize != "S" && tempSize != "M" && tempSize != "L" && tempSize != "XL" && tempSize != "XXL")
                  throw string("Nhap size khong hop le!");
                break;
              }
              catch (const string &e)
              {
                printError(e);
                printRes("Hay nhap lai size!");
                char c;
                c = getchar();
              }
            }
            printRes("Nhap so luong san pham can them: ");
            int tempSoLuong;
            cin >> tempSoLuong;
            if (tempSoLuong < 0)
              throw string("So luong san pham can > 0");
            SanPham tempSP;
            tempSP = this->pSP->findSP(tempList, tempMa, tempSize);
            tempSP.setSoLuong(tempSoLuong);
            listSP->push_back(tempSP);
            break;
          }
          catch (const string error)
          {
            printError(error);
          }
        }
        printRes("Ban co muon them san pham nao trong danh sach tren khong? (y/n): ");
        char c;
        fflush(stdin);
        c = getchar();
        if (c == 'n')
          break;
      }
      catch (const string &e)
      {
        printError(e);
        printRes("Ban co muon thu lai khong? (y/n): ");
        char c;
        fflush(stdin);
        c = getchar();
        if (c == 'n')
          break;
      }
    }
    printRes("Ban co muon them san pham khac khong? (y/n): ");
    char c;
    fflush(stdin);
    c = getchar();
    if (c == 'n')
      check = false;
  }
  HoaDon tempHD(listSP, tempMaHD, tempMaNV, tempMaKH);
  listHD->push_back(tempHD);
  this->count++;
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