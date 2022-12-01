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

// components

void QLSanPham::docFile(fstream &fileIn)
{
  fileIn >> this->count;
  fileIn.ignore(1);
  for (int i = 0; i < this->count; i++)
  {
    SanPham *SP = new SanPham;
    SP->docFile(fileIn);
    fileIn.ignore(1);
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

void QLSanPham::update()
{
  List<SanPham> *tempList = new List<SanPham>();
  tempList = QLSanPham::findList();
  while (1)
  {
    system("cls");
    QLSanPham::readList(tempList);
    printRes("Vui long nhap ma san pham can chinh sua!\n");
    Ma tempMa;
    cin >> tempMa;
    Node<SanPham> *pTemp = tempList->getpHead();
    if (QLSanPham::findIndex(tempList, tempMa) != -1)
    {
      bool check = true;
      while (check)
      {
        system("cls");
        string arr[] = {"Nhap lua chon:", "Chinh sua ten.", "Chinh sua xuat xu", "Chinh sua gia nhap", "Chinh sua gia ban", "Chinh sua giam gia", "Chinh sua size", "Quay lai"};
        printOpt(arr, 7);
        int key = getKey(7);
        SanPham *tempSP = new SanPham;
        switch (key)
        {
        case 1:
        {
          system("cls");
          printRes("Nhap ten can thay doi: ");
          string tempTen;
          string tenSP;
          fflush(stdin);
          getline(cin, tempTen);
          Node<SanPham> *pTemp = this->dbSP->getpHead();
          while (pTemp)
          {
            if (pTemp->getData().getMa() == tempMa)
            {
              tenSP = pTemp->getData().getTen();
              tempSP->setMa(pTemp->getData().getMa());
              tempSP->setSize(pTemp->getData().getSize());
              tempSP->setTen(tempTen);
              tempSP->setXuatXu(pTemp->getData().getXuatXu());
              tempSP->setSoLuong(pTemp->getData().getSoLuong());
              tempSP->setGiaNhap(pTemp->getData().getGiaNhap());
              tempSP->setGiaBan(pTemp->getData().getGiaBan());
              tempSP->setGiamGia(pTemp->getData().getGiamGia());
              pTemp->setData(*tempSP);
            }
            pTemp = pTemp->getpNext();
          }
          string Success = "Da thay doi ten cua san pham " + tenSP + " thanh " + tempTen + " thanh cong!";
          printSuccess(Success);
          char c;
          fflush(stdin);
          c = getchar();
        }
        break;
        case 2:
        {
          system("cls");
          printRes("Nhap xuat xu can thay doi: ");
          string tempXuatXu;
          fflush(stdin);
          getline(cin, tempXuatXu);
          string tenSP;
          Node<SanPham> *pTemp = this->dbSP->getpHead();
          while (pTemp)
          {
            if (pTemp->getData().getMa() == tempMa)
            {
              tenSP = pTemp->getData().getTen();
              tempSP->setMa(pTemp->getData().getMa());
              tempSP->setSize(pTemp->getData().getSize());
              tempSP->setTen(pTemp->getData().getTen());
              tempSP->setXuatXu(tempXuatXu);
              tempSP->setSoLuong(pTemp->getData().getSoLuong());
              tempSP->setGiaNhap(pTemp->getData().getGiaNhap());
              tempSP->setGiaBan(pTemp->getData().getGiaBan());
              tempSP->setGiamGia(pTemp->getData().getGiamGia());
              pTemp->setData(*tempSP);
            }
            pTemp = pTemp->getpNext();
          }
          string Success = "Da thay doi xuat xu cua san pham " + tenSP + " thanh " + tempXuatXu + " thanh cong!";
          printSuccess(Success);
          char c;
          fflush(stdin);
          c = getchar();
        }
        break;
        case 3:
        {
          system("cls");
          printRes("Nhap gia nhap can thay doi: ");
          ll tempGiaNhap;
          cin >> tempGiaNhap;
          string tenSP;
          Node<SanPham> *pTemp = this->dbSP->getpHead();
          while (pTemp)
          {
            if (pTemp->getData().getMa() == tempMa)
            {
              tenSP = pTemp->getData().getTen();
              tempSP->setMa(pTemp->getData().getMa());
              tempSP->setSize(pTemp->getData().getSize());
              tempSP->setTen(pTemp->getData().getTen());
              tempSP->setXuatXu(pTemp->getData().getXuatXu());
              tempSP->setSoLuong(pTemp->getData().getSoLuong());
              tempSP->setGiaNhap(tempGiaNhap);
              tempSP->setGiaBan(pTemp->getData().getGiaBan());
              tempSP->setGiamGia(pTemp->getData().getGiamGia());
              pTemp->setData(*tempSP);
            }
            pTemp = pTemp->getpNext();
          }
          string Success = "Da thay doi gia nhap cua san pham " + tenSP + " thanh " + to_string(tempGiaNhap) + " thanh cong!";
          printSuccess(Success);
          char c;
          fflush(stdin);
          c = getchar();
        }
        break;
        case 4:
        {
          system("cls");
          printRes("Nhap gia ban can thay doi: ");
          ll tempGiaBan;
          cin >> tempGiaBan;
          string tenSP;
          Node<SanPham> *pTemp = this->dbSP->getpHead();
          while (pTemp)
          {
            if (pTemp->getData().getMa() == tempMa)
            {
              tenSP = pTemp->getData().getTen();
              tempSP->setMa(pTemp->getData().getMa());
              tempSP->setSize(pTemp->getData().getSize());
              tempSP->setTen(pTemp->getData().getTen());
              tempSP->setXuatXu(pTemp->getData().getXuatXu());
              tempSP->setSoLuong(pTemp->getData().getSoLuong());
              tempSP->setGiaNhap(pTemp->getData().getGiaNhap());
              tempSP->setGiaBan(tempGiaBan);
              tempSP->setGiamGia(pTemp->getData().getGiamGia());
              pTemp->setData(*tempSP);
            }
            pTemp = pTemp->getpNext();
          }
          string Success = "Da thay doi gia ban cua san pham " + tenSP + " thanh " + to_string(tempGiaBan) + " thanh cong!";
          printSuccess(Success);
          char c;
          fflush(stdin);
          c = getchar();
        }
        break;
        case 5:
        {
          system("cls");
          printRes("Nhap giam gia can thay doi: ");
          int tempGiamGia;
          cin >> tempGiamGia;
          string tenSP;
          Node<SanPham> *pTemp = this->dbSP->getpHead();
          while (pTemp)
          {
            if (pTemp->getData().getMa() == tempMa)
            {
              tenSP = pTemp->getData().getTen();
              tempSP->setMa(pTemp->getData().getMa());
              tempSP->setSize(pTemp->getData().getSize());
              tempSP->setTen(pTemp->getData().getTen());
              tempSP->setXuatXu(pTemp->getData().getXuatXu());
              tempSP->setSoLuong(pTemp->getData().getSoLuong());
              tempSP->setGiaNhap(pTemp->getData().getGiaNhap());
              tempSP->setGiaBan(pTemp->getData().getGiaBan());
              tempSP->setGiamGia(tempGiamGia);
              pTemp->setData(*tempSP);
            }
            pTemp = pTemp->getpNext();
          }
          string Success = "Da thay doi giam gia cua san pham " + tenSP + " thanh " + to_string(tempGiamGia) + " thanh cong!";
          printSuccess(Success);
          char c;
          fflush(stdin);
          c = getchar();
        }
        break;
        case 6:
        {
          while (1)
          {
            system("cls");
            printRes("Vui long nhap size(S/M/L/XL/XXL): ");
            string tempSize;
            fflush(stdin);
            getline(cin, tempSize);
            if (tempSize == "S" || tempSize == "M" || tempSize == "L" || tempSize == "XL" || tempSize == "XXL")
            {
              while (1)
              {
                printRes("Nhap so luong can thay doi: ");
                int tempSoLuong;
                cin >> tempSoLuong;
                if (tempSoLuong >= 0)
                {
                  Node<SanPham> *pTemp = this->dbSP->getpHead();
                  string tenSP;
                  while (pTemp)
                  {
                    if (pTemp->getData().getMa() == tempMa && pTemp->getData().getSize() == tempSize)
                    {
                      tenSP = pTemp->getData().getTen();
                      
                      tempSP->setMa(pTemp->getData().getMa());
                      tempSP->setSize(pTemp->getData().getSize());
                      tempSP->setTen(pTemp->getData().getTen());
                      tempSP->setXuatXu(pTemp->getData().getXuatXu());
                      tempSP->setSoLuong(tempSoLuong);
                      tempSP->setGiaNhap(pTemp->getData().getGiaNhap());
                      tempSP->setGiaBan(pTemp->getData().getGiaBan());
                      tempSP->setGiamGia(pTemp->getData().getGiamGia());
                      pTemp->setData(*tempSP);
                      break;
                    }
                    pTemp = pTemp->getpNext();
                  }
                  string Success = "Thay doi so luong cho size " + tempSize + " cua san pham " + tenSP + " thanh cong!";
                  printSuccess(Success);
                  break;
                }
                else
                {
                  printError("Vui long nhap so luong >= 0!");
                  char c;
                  fflush(stdin);
                  c = getchar();
                }
              }
            }
            else
            {
              printError("Ban da nhap sai Size! Vui long nhap dung(S/M/L/XL/XXL)");
              printRes("Ban co muon tiep tuc khong?(y/n): ");
              char c;
              fflush(stdin);
              c = getchar();
              if (c == 'n')
                break;
            }
            printRes("Ban co muon tiep tuc khong?(y/n): ");
            char c;
            fflush(stdin);
            c = getchar();
            if (c == 'n')
              break;
          }
        }
        break;
        case 7:
          delete tempSP;
          check = false;
          break;
        }
      }
      break;
    }
    else
    {
      printRes("Ban co muon nhap lai khong?(y/n): ");
      char c;
      fflush(stdin);
      c = getchar();
      if (c == 'n')
      {
        break;
      }
    }
  }
}

void QLSanPham::read()
{
  QLSanPham::readList(this->dbSP);
}

void QLSanPham::find()
{
  bool check = true;
  while (check)
  {
    system("cls");
    printRes("Vui long nhap ten san pham can tim: ");
    string tempTenSP;
    fflush(stdin);
    getline(cin, tempTenSP);
    Node<SanPham> *pTemp = this->dbSP->getpHead();
    List<SanPham> *tempList = new List<SanPham>();
    while (pTemp)
    {
      if (findString(pTemp->getData().getTen(), tempTenSP) != -1)
      {
        tempList->push_back(pTemp->getData());
      }
      pTemp = pTemp->getpNext();
    }
    if (tempList->getpHead())
    {
      QLSanPham::readList(tempList);
      check = false;
    }
    else
    {
      string Error = "Khong the tim san pham co ten la '" + tempTenSP + "'";
      printError(Error);
      printRes("Ban co muon nhap lai khong?(y/n): ");
      char c;
      fflush(stdin);
      c = getchar();
      if (c == 'n')
        check = false;
    }
  }
}

void QLSanPham::deleteIndex()
{
  List<SanPham> *tempList = new List<SanPham>();
  tempList = QLSanPham::findList();
  while (1)
  {
    system("cls");
    QLSanPham::readList(tempList);
    printRes("Vui long nhap ma san pham can xoa!\n");
    Ma tempMa;
    cin >> tempMa;
    Node<SanPham> *pTemp = tempList->getpHead();
    bool check = true;
    string warning = "Ban co chac chan muon xoa san pham nay khong?(y/n)";
    printWarning(warning);
    char c;
    fflush(stdin);
    c = getchar();
    if (c == 'y')
    {
      while (pTemp)
      {
        if (pTemp->getData().getMa() == tempMa)
        {
          this->dbSP->deleteNode(QLSanPham::findIndex(this->dbSP, tempMa));
          check = false;
        }
        pTemp = pTemp->getpNext();
      }
      if (check)
      {
        string Error = "Ma san pham khong ton tai!";
        printError(Error);
        printRes("Ban co muon nhap lai khong?(y/n): ");
        char c;
        fflush(stdin);
        c = getchar();
        if (c == 'n')
          break;
      }
      else
        break;
    }
  }
}

// utils

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

void QLSanPham::sortMa(List<SanPham> *listSP)
{
  Node<SanPham> *pBefore = listSP->getpHead();
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

void QLSanPham::readList(List<SanPham> *listSP)
{
  ConsoleTable table{"STT", "Ma San Pham", "Ten San Pham", "Xuat Xu", "Gia Nhap", "Gia Ban", "Giam Gia", "S", "M", "L", "XL", "XXL", "Tong So Luong"};
  table.setPadding(1);
  table.setStyle(0);
  QLSanPham::sortMa(listSP);
  int *arrSize = new int[5];
  for (int i = 0; i <= 5; i++)
  {
    arrSize[i] = 0;
  }
  int cnt = 0;
  Node<SanPham> *pTempBefore = listSP->getpHead();
  Node<SanPham> *pTempAfter = NULL;
  Ma tempMa = pTempBefore->getData().getMa();
  while (pTempBefore)
  {
    pTempAfter = pTempBefore->getpNext();
    if (pTempBefore->getData().getSize() == "S")
    {
      arrSize[0] = pTempBefore->getData().getSoLuong();
    }
    if (pTempBefore->getData().getSize() == "M")
    {
      arrSize[1] = pTempBefore->getData().getSoLuong();
    }
    if (pTempBefore->getData().getSize() == "L")
    {
      arrSize[2] = pTempBefore->getData().getSoLuong();
    }
    if (pTempBefore->getData().getSize() == "XL")
    {
      arrSize[3] = pTempBefore->getData().getSoLuong();
    }
    if (pTempBefore->getData().getSize() == "XXL")
    {
      arrSize[4] = pTempBefore->getData().getSoLuong();
    }
    if (!pTempAfter || pTempAfter->getData().getMa() != tempMa)
    {
      table += {
          to_string(++cnt),
          pTempBefore->getData().getMa(),
          pTempBefore->getData().getTen(),
          pTempBefore->getData().getXuatXu(),
          to_string(pTempBefore->getData().getGiaNhap()),
          to_string(pTempBefore->getData().getGiaBan()),
          to_string(pTempBefore->getData().getGiamGia()),
          to_string(arrSize[0]),
          to_string(arrSize[1]),
          to_string(arrSize[2]),
          to_string(arrSize[3]),
          to_string(arrSize[4]),
          to_string(arrSize[0] + arrSize[1] + arrSize[2] + arrSize[3] + arrSize[4])};
      if (pTempAfter)
        tempMa = pTempAfter->getData().getMa();
      for (int i = 0; i < 5; i++)
      {
        arrSize[i] = 0;
      }
    }
    pTempBefore = pTempBefore->getpNext();
  }

  delete[] arrSize;
  cout << table;
}

List<SanPham> *QLSanPham::findList()
{
  bool check = true;
  while (check)
  {
    system("cls");
    printRes("Vui long nhap ten san pham can tim: ");
    string tempTenSP;
    fflush(stdin);
    getline(cin, tempTenSP);
    Node<SanPham> *pTemp = this->dbSP->getpHead();
    List<SanPham> *tempList = new List<SanPham>();
    while (pTemp)
    {
      if (findString(pTemp->getData().getTen(), tempTenSP) != -1)
      {
        tempList->push_back(pTemp->getData());
      }
      pTemp = pTemp->getpNext();
    }
    if (tempList->getpHead())
    {
      // QLSanPham::readList(tempList);
      return tempList;
    }
    else
    {
      string Error = "Khong the tim san pham co ten la '" + tempTenSP + "'";
      printError(Error);
      printRes("Ban co muon nhap lai khong?(y/n): ");
      char c;
      fflush(stdin);
      c = getchar();
      if (c == 'n')
        check = false;
    }
  }
  return NULL;
}

int QLSanPham::findIndex(List<SanPham> *listSP, const Ma &ma)
{
  Node<SanPham> *pTemp = listSP->getpHead();
  int cnt = 0;
  while (pTemp)
  {
    if (pTemp->getData().getMa() == ma)
      return cnt;
    ++cnt;
    pTemp = pTemp->getpNext();
  }
  printError("Ma san pham khong ton tai!");
  return -1;
}