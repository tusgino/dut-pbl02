
#include "..\..\..\Class\QLSanPham.h"
#include <fstream>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

List<SanPham> *QLSanPham::getQLSP()
{
  return this->QLSP;
}

QLSanPham::QLSanPham()
{
  this->QLSP = new List<SanPham>();
  this->n = 0;
}

QLSanPham::~QLSanPham()
{
  this->QLSP->~List();
}

int QLSanPham::getSoLuongSP()
{
  return this->n;
}

void QLSanPham::nhapTuFile(fstream &fileSanPham)
{
  fileSanPham >> this->n;
  fileSanPham.ignore(1);
  for (int i = 0; i < this->n; i++)
  {
    SanPham temp;
    temp.docFile(fileSanPham);
    this->QLSP->push_back(temp);
  }

  fstream fileLoaiSP;
  fileLoaiSP.open("Data/LoaiSanPham.DAT");
  this->getInfoLoaiSP(fileLoaiSP);
  fileLoaiSP.close();
}

void QLSanPham::ghiVaoFile(fstream &fileSanPham)
{
  fileSanPham << this->n << endl;
  Node<SanPham> *pTemp = this->QLSP->getpHead();
  while (pTemp)
  {
    pTemp->getData().ghiFile(fileSanPham);
    pTemp = pTemp->getpNext();
  }
}

void QLSanPham::nhapTuNguoiDung()
{
  cout << "Nhap thong tin san pham:\n";
  for (int i = 1; i <= this->amountLoai; i++)
  {
    cout << i << ". " << loai[i].getName() << endl;
  }
  int temp;
  cout << "Nhap loai san pham: ";
  cin >> temp;
  char keyWordLoaiSP = loai[temp].getKeyWord();
  string maSP;
  maSP = keyWordLoaiSP + to_string(loai[temp].getIDMax() + 1);
  cout << "Nhap ten san pham: ";
  string tenSP;
  fflush(stdin);
  getline(cin, tenSP);
  fflush(stdin);
  string xuatXu;
  cout << "Nhap xuat xu san pham: ";
  getline(cin, xuatXu);
  int soLuongSP;
  cout << "Nhap gia nhap cua san san pham: ";
  long long giaNhapSP;
  cin >> giaNhapSP;
  cout << "Nhap don gia cua san pham: ";
  long long donGiaSP;
  cin >> donGiaSP;
  cout << "Nhap % giam gia cua san pham: ";
  float giamGiaSP;
  cin >> giamGiaSP;
  cout << "Nhap so luong size cua san pham: \n";
  int sizeS, sizeM, sizeL, sizeXL, sizeXXL;
  cout << "Size S: ";
  cin >> sizeS;
  cout << "Size M: ";
  cin >> sizeM;
  cout << "Size L: ";
  cin >> sizeL;
  cout << "Size XL: ";
  cin >> sizeXL;
  cout << "Size XXL: ";
  cin >> sizeXXL;
  soLuongSP = sizeS + sizeM + sizeL + sizeXL + sizeXXL;
  Size sizeTemp(sizeS, sizeM, sizeL, sizeXL, sizeXXL);
  SanPham spTemp(maSP, tenSP, xuatXu, soLuongSP, giaNhapSP, donGiaSP, giamGiaSP, sizeTemp);
  this->QLSP->push_back(spTemp);
  this->n++;
  loai[temp].setIDmax(loai[temp].getIDMax() + 1);
  loai[temp].setAmountProduct(loai[temp].getAmountProduct() + 1);
  QLSanPham::setInfoLoaiSP();
  fstream fileSanPham;
  fileSanPham.open("Data/SanPham.DAT", ios_base::out);
  this->ghiVaoFile(fileSanPham);
  fileSanPham.close();
}

void QLSanPham::capNhatDuLieu()
{
  QLSanPham::findIndex();
  int pos = -1;
  Node<SanPham> *pTemp = this->QLSP->getpHead();
  string temp;
  cout << "Nhap ma san pham muon chinh sua: ";
  fflush(stdin);
  getline(cin, temp);
  for (int i = 0; i < this->n; i++)
  {
    if (pTemp->getData().getMaSP().compare(temp) == 0)
    {
      pos = i;
      break;
    }
    pTemp = pTemp->getpNext();
  }

  if (pos != -1)
  {
    cout << "\t\tTon tai ma san pham " << temp << endl;
    bool check = true;
    while (check)
    {
      int op;
      cout << "\t\t====MENU=====";
      cout << "\n0. Thoat chuong trinh";
      cout << "\n1. Chinh sua ten.";
      cout << "\n2. Chinh sua so luong.";
      cout << "\n3. Chinh sua don gia.";
      cout << "\nNhap thong tin can sua: ";
      cin >> op;
      string str;
      long long number;
      Node<SanPham> *p;
      SanPham spTemp;
      switch (op)
      {
      case 1:
      {

        cout << "Nhap ten thay the: ";
        fflush(stdin);
        getline(cin, str);
        // thay doi ten cho sp
        spTemp.setMaSP(pTemp->getData().getMaSP());
        spTemp.setTenSP(str);
        spTemp.setXuatXu(pTemp->getData().getXuatXu());
        spTemp.setSoLuongSP(pTemp->getData().getSoLuongSP());
        spTemp.setGiaNhapSP(pTemp->getData().getGiaNhapSP());
        spTemp.setDonGiaSP(pTemp->getData().getDonGiaSP());
        spTemp.setGiamGiaSP(pTemp->getData().getGiamGiaSP());
        spTemp.setSizeSP(pTemp->getData().getSize());
        pTemp->setData(spTemp);
        fstream fileSanPham;
        fileSanPham.open("Data/SanPham.DAT", ios_base::out);
        this->ghiVaoFile(fileSanPham);
        fileSanPham.close();
        break;
      }
      case 2:
      {
        do
        {
          cout << "Nhap so luong thay the: ";
          cin >> number;
          if (number < 0)
            cout << "Vui long nhap lai so luong > 0.";
        } while (number < 0);
        // thay doi so luong cho sp
        spTemp.setMaSP(pTemp->getData().getMaSP());
        spTemp.setTenSP(pTemp->getData().getTenSP());
        spTemp.setXuatXu(pTemp->getData().getXuatXu());
        spTemp.setSoLuongSP(number);
        spTemp.setGiaNhapSP(pTemp->getData().getGiaNhapSP());
        spTemp.setDonGiaSP(pTemp->getData().getDonGiaSP());
        spTemp.setGiamGiaSP(pTemp->getData().getGiamGiaSP());
        spTemp.setSizeSP(pTemp->getData().getSize());
        pTemp->setData(spTemp);
        fstream fileSanPham;
        fileSanPham.open("Data/SanPham.DAT", ios_base::out);
        this->ghiVaoFile(fileSanPham);
        fileSanPham.close();
        break;
      }
      case 3:
      {

        do
        {
          cout << "Nhap so luong thay the: ";
          cin >> number;
          if (number < 0)
            cout << "Vui long nhap lai don gia > 0.";
        } while (number < 0);
        // thay doi don gia cho sp
        spTemp.setMaSP(pTemp->getData().getMaSP());
        spTemp.setTenSP(pTemp->getData().getTenSP());
        spTemp.setXuatXu(pTemp->getData().getXuatXu());
        spTemp.setSoLuongSP(pTemp->getData().getSoLuongSP());
        spTemp.setGiaNhapSP(pTemp->getData().getGiaNhapSP());
        spTemp.setDonGiaSP(number);
        spTemp.setGiamGiaSP(pTemp->getData().getGiamGiaSP());
        spTemp.setSizeSP(pTemp->getData().getSize());
        pTemp->setData(spTemp);
        fstream fileSanPham;
        fileSanPham.open("Data/SanPham.DAT", ios_base::out);
        this->ghiVaoFile(fileSanPham);
        fileSanPham.close();
        break;
      }
      case 0:
        return;
        break;
      default:
        cout << "\tBan nhap sai lua chon. Vui long thu lai " << endl;
        break;
      }
    }
  }
  else
  {
    cout << "\tKhong ton tai san pham nao co ma " << temp << endl;
  }
}

void QLSanPham::capNhatDuLieuSP(const string &ma, const string &size, const int &slSize)
{
  Node<SanPham> *pTemp = this->QLSP->getpHead();

  while (pTemp)
  {
    if (pTemp->getData().getMaSP().compare(ma) == 0)
    {
      SanPham spTemp;
      // Sua size
      Size sizeTemp;
      sizeTemp.setSize(pTemp->getData().getSize());
      if (size.compare("S") == 0)
        sizeTemp.setS(sizeTemp.getS() - slSize);
      else if (size.compare("M") == 0)
        sizeTemp.setM(sizeTemp.getM() - slSize);
      else if (size.compare("L") == 0)
        sizeTemp.setL(sizeTemp.getL() - slSize);
      else if (size.compare("XL") == 0)
        sizeTemp.setXL(sizeTemp.getXL() - slSize);
      else if (size.compare("XXL") == 0)
        sizeTemp.setXXL(sizeTemp.getXXL() - slSize);
      // Gan vao SPTemp
      spTemp.setMaSP(pTemp->getData().getMaSP());
      spTemp.setTenSP(pTemp->getData().getTenSP());
      spTemp.setXuatXu(pTemp->getData().getXuatXu());
      spTemp.setSoLuongSP(pTemp->getData().getSoLuongSP());
      spTemp.setGiaNhapSP(pTemp->getData().getGiaNhapSP());
      spTemp.setDonGiaSP(pTemp->getData().getDonGiaSP());
      spTemp.setGiamGiaSP(pTemp->getData().getGiamGiaSP());
      spTemp.setSizeSP(sizeTemp);
      // Thay doi San Pham hien tai.
      pTemp->setData(spTemp);
      break;
    }
    pTemp = pTemp->getpNext();
  }
};

void QLSanPham::findIndex()
{
  string str;
  cout << "Nhap ten san pham can tim: ";
  cin.ignore();
  getline(cin, str);
  Node<SanPham> *pTemp = this->QLSP->getpHead();
  int i = 0;
  // chuyen string thanh char* va ghi hoa
  for (auto &c : str)
    c = toupper(c);
  int strLength = str.length();
  char strSub[strLength + 1];
  strcpy(strSub, str.c_str());
  // Tim
  while (pTemp != NULL)
  {
    string strTemp = pTemp->getData().getTenSP();
    // chuyen string thanh char* va ghi hoa
    for (auto &c : strTemp)
      c = toupper(c);
    int strTempLength = strTemp.length();
    char strParent[strTempLength + 1];
    strcpy(strParent, strTemp.c_str());
    // Tim chuoi strSub trong strParent
    char *first;
    first = strstr(strParent, strSub);
    if (first)
    {
      cout << i << ". ";
      pTemp->getData().xuat();
    }
    i++;
    pTemp = pTemp->getpNext();
  }
}

void QLSanPham::getInfoLoaiSP(fstream &fileLoaiSP)
{
  fileLoaiSP >> this->amountLoai;
  fileLoaiSP.ignore(1);
  for (int i = 1; i <= this->amountLoai; i++)
  {
    loaiSanPham temp;
    temp.readFromFile(fileLoaiSP);
    loai[i] = temp;
    cout << loai[i].getName();
  }
}

void QLSanPham::setInfoLoaiSP()
{
  fstream fileLoaiSP;
  fileLoaiSP.open("Data/LoaiSanPham.DAT");
  fileLoaiSP << this->amountLoai << endl;
  for (int i = 1; i <= this->amountLoai; i++)
  {
    loai[i].writeToFile(fileLoaiSP);
  }
  fileLoaiSP.close();
}

void QLSanPham::xuat()
{
  Node<SanPham> *pTemp = this->QLSP->getpHead();
  cout << "|| Ma san pham "
       << "|| " << setw(29) << left << "Ten san pham"
       << "|| " << setw(9) << left << "Xuat xu"
       << "||"
       << "Tong so luong trong kho"
       << "|| "
       << "Gia nhap/sp"
       << "|| "
       << "Gia ban/sp"
       << "|| "
       << "Discount"
       << "|| " << setw(10) << right << "Size" << setw(11) << "||" << endl;
  cout << "||" << setw(16) << right << "|| " << setw(32) << right << "|| " << setw(12) << right << "|| " << setw(25) << right << "|| " << setw(14) << "|| " << setw(13) << "|| " << setw(11) << "|| " << setw(2) << left << "S"
       << "| " << setw(2) << "M"
       << "| " << setw(2) << "L"
       << "| "
       << "XL"
       << "| "
       << "XXL"
       << "||" << endl;
  while (pTemp)
  {
    pTemp->getData().xuatThanhBang();
    pTemp = pTemp->getpNext();
  }
}

SanPham QLSanPham::findSP(const string &ma)
{
  static SanPham pRac;
  Node<SanPham> *pTemp = this->QLSP->getpHead();
  while (pTemp)
  {
    string strTemp = pTemp->getData().getMaSP();
    if (strTemp.compare(ma) == 0)
    {
      return pTemp->getData();
    }
    // pTemp->setpNext(pTemp->getpNext());
    pTemp = pTemp->getpNext();
  }
  return pRac;
}

void QLSanPham::sortAZ()
{
  Node<SanPham> *pTemp1 = this->QLSP->getpHead();
  Node<SanPham> *pTemp2 = nullptr;

  SanPham temp;
  for (; pTemp1 != nullptr; pTemp1 = pTemp1->getpNext())
  {
    for (pTemp2 = pTemp1->getpNext(); pTemp2 != nullptr; pTemp2 = pTemp2->getpNext())
    {
      if (pTemp1->getData().getMaSP().compare(pTemp2->getData().getMaSP()) != 0)
      {
        temp = pTemp1->getData();
        pTemp1->setData(pTemp2->getData());
        pTemp2->setData(temp);
      }
    }
  }
}

const int QLSanPham::getSoLuongOFSize(const string &ma, const string &size)
{
  Node<SanPham> *pTemp = this->QLSP->getpHead();
  // cout << size;
  // cout << " " << pTemp->getData().getMaSP().compare(ma);
  for (int i = 0; i < this->n; i++)
  {
    if (pTemp->getData().getMaSP().compare(ma) == 0)
    {
      if (size.compare("S") == 0)
        return pTemp->getData().getSize().getS();
      else if (size.compare("M") == 0)
        return pTemp->getData().getSize().getM();
      else if (size.compare("L") == 0)
        return pTemp->getData().getSize().getL();
      else if (size.compare("XL") == 0)
        return pTemp->getData().getSize().getXL();
      else if (size.compare("XXL") == 0)
        return pTemp->getData().getSize().getXXL();
      else
        return -1;
    }
    pTemp = pTemp->getpNext();
  }

  return -1;
}

void QLSanPham::xoaSanPham()
{
  this->findIndex();
  int index = -1;
  string temp;
  cout << "\tNhap ma san pham can xoa: ";
  fflush(stdin);
  getline(cin, temp);
  Node<SanPham> *pTemp = this->QLSP->getpHead();
  for (int i = 0; i < this->n; i++)
  {
    if (pTemp->getData().getMaSP().compare(temp) == 0)
    {
      index = i;
      break;
    }
    pTemp = pTemp->getpNext();
  }

  if (index == -1)
  {
    cout << "\tKhong ton tai san pham co ma san pham la " << temp << endl;
  }
  else
  {
    cout << "\t\tTon tai san pham co ma la " << temp << endl;
    cout << "\t1. Xoa toan bo san pham" << endl;
    cout << "\t2. Xoa so luong cua san pham" << endl;
    cout << "\t3. Quay lai" << endl;

    int op1;
    cout << "\tNhap lua chon cua ban: ";
    cin >> op1;

    switch (op1)
    {
    case 1:
    {
      printWarning("Ban co chan chan muon xoa san pham nay khong? (y/n): ");
      char c;
      fflush(stdin);
      c = getchar();
      if (c == 'y')
      {
        this->QLSP->deleteNode(index);
        this->n--;
        for (int i = 1; i <= this->amountLoai; i++)
        {
          if (temp[0] == loai[i].getKeyWord())
          {
            loai[i].setAmountProduct(loai[i].getAmountProduct() - 1);
            QLSanPham::setInfoLoaiSP();
            break;
          }
        }
        fstream fileSanPham;
        fileSanPham.open("Data/SanPham.DAT", ios_base::out);
        this->ghiVaoFile(fileSanPham);
        fileSanPham.close();
        cout << "\tDa xoa san pham co ma " << temp << endl;
      }
      break;
    }
    case 2:
    {
      cout << "\tSo luong san pham theo tung size\n";
      cout << "\t1. S (so luong " << pTemp->getData().getSize().getS() << ")\n";
      cout << "\t2. M (so luong " << pTemp->getData().getSize().getM() << ")\n";
      cout << "\t3. L (so luong " << pTemp->getData().getSize().getL() << ")\n";
      cout << "\t4. XL (so luong " << pTemp->getData().getSize().getXL() << ")\n";
      cout << "\t5. XXL (so luong " << pTemp->getData().getSize().getXXL() << ")\n";
      cout << "\t0. Thoat" << endl;
      cout << "\tChon size muon chinh sua";
      int opSize, newCount;
      cin >> opSize;
      Size tempSize;
      SanPham tempSP;
      switch (opSize)
      {
      case 1:
      {
        cout << "\tNhap so luong muon bot:";
        cin >> newCount;
        if (newCount > pTemp->getData().getSize().getS())
        {
          cout << "\tSo luong ban nhap khong hop le vui long thu lai";
          // system("pause");
        }
        else
        {
          // pTemp->getData().getSize().setS(pTemp->getData().getSize().getS() - newCount);
          tempSize = pTemp->getData().getSize();
          tempSize.setS(pTemp->getData().getSize().getS() - newCount);
          tempSP = pTemp->getData();
          tempSP.setSizeSP(tempSize);
          pTemp->setData(tempSP);
          cout << "\tDa xoa thanh cong " << endl;
          // system("pause");
        }
        fstream fileSanPham;
        fileSanPham.open("Data/SanPham.DAT", ios_base::out);
        this->ghiVaoFile(fileSanPham);
        fileSanPham.close();
        break;
      }
      case 2:
      {
        cout << "\tNhap so luong muon bot:";
        cin >> newCount;
        if (newCount > pTemp->getData().getSize().getM())
        {
          cout << "\tSo luong ban nhap khong hop le vui long thu lai";
          // system("pause");
        }
        else
        {
          tempSize = pTemp->getData().getSize();
          tempSize.setM(pTemp->getData().getSize().getM() - newCount);
          tempSP = pTemp->getData();
          tempSP.setSizeSP(tempSize);
          pTemp->setData(tempSP);
          cout << "\tDa xoa thanh cong " << endl;
          // system("pause");
        }
        fstream fileSanPham;
        fileSanPham.open("Data/SanPham.DAT", ios_base::out);
        this->ghiVaoFile(fileSanPham);
        fileSanPham.close();
        break;
      }
      case 3:
      {
        cout << "\tNhap so luong muon bot:";
        cin >> newCount;
        if (newCount > pTemp->getData().getSize().getL())
        {
          cout << "\tSo luong ban nhap khong hop le vui long thu lai";
          // system("pause");
        }
        else
        {
          // pTemp->getData().getSize().setS(pTemp->getData().getSize().getS() - newCount);
          tempSize = pTemp->getData().getSize();
          tempSize.setS(pTemp->getData().getSize().getL() - newCount);
          tempSP = pTemp->getData();
          tempSP.setSizeSP(tempSize);
          pTemp->setData(tempSP);
          cout << "\tDa xoa thanh cong " << endl;
          // system("pause");
        }
        fstream fileSanPham;
        fileSanPham.open("Data/SanPham.DAT", ios_base::out);
        this->ghiVaoFile(fileSanPham);
        fileSanPham.close();
        break;
      }
      case 4:
      {
        cout << "\tNhap so luong muon bot:";
        cin >> newCount;
        if (newCount > pTemp->getData().getSize().getXL())
        {
          cout << "\tSo luong ban nhap khong hop le vui long thu lai";
          // system("pause");
        }
        else
        {
          tempSize = pTemp->getData().getSize();
          tempSize.setM(pTemp->getData().getSize().getXL() - newCount);
          tempSP = pTemp->getData();
          tempSP.setSizeSP(tempSize);
          pTemp->setData(tempSP);
          cout << "\tDa xoa thanh cong " << endl;
          // system("pause");
        }
        fstream fileSanPham;
        fileSanPham.open("Data/SanPham.DAT", ios_base::out);
        this->ghiVaoFile(fileSanPham);
        fileSanPham.close();
        break;
      }
      case 5:
      {
        cout << "\tNhap so luong muon bot:";
        cin >> newCount;
        if (newCount > pTemp->getData().getSize().getXXL())
        {
          cout << "\tSo luong ban nhap khong hop le vui long thu lai";
          // system("pause");
        }
        else
        {
          tempSize = pTemp->getData().getSize();
          tempSize.setM(pTemp->getData().getSize().getXXL() - newCount);
          tempSP = pTemp->getData();
          tempSP.setSizeSP(tempSize);
          pTemp->setData(tempSP);
          cout << "\tDa xoa thanh cong " << endl;
          // system("pause");
        }
        fstream fileSanPham;
        fileSanPham.open("Data/SanPham.DAT", ios_base::out);
        this->ghiVaoFile(fileSanPham);
        fileSanPham.close();
        break;
      }
      case 0:
      {
        return;
      }
      default:
      {
        cout << "\tLua chon cua ban khong hop le." << endl;
        break;
      }
      }
    }
    case 3:
    {
      return;
    }
    break;
    }
  }
}

void QLSanPham::thongKe()
{
}