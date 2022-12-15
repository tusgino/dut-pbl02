#include "..\..\..\class\QLHoaDon.h"

QLHoaDon::QLHoaDon()
{
  this->pNV = new QLNhanVien();
  this->pKH = new QLKhachHang();
  this->pSP = new QLSanPham();
  this->listHD = new List<HoaDon>();
  this->count = 0;
}

QLHoaDon::QLHoaDon(QLNhanVien *NV, QLKhachHang *KH, QLSanPham *SP, const Ma &maNhanVien)
{
  this->pNV = NV;
  this->pKH = KH;
  this->pSP = SP;
  this->maNhanVien = maNhanVien;
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

void QLHoaDon::setMaDangNhap(const Ma &ma)
{
  this->maNhanVien = ma;
}

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
  Ma tempMaNV = this->maNhanVien;
  Ma tempMaKH;
  while (true)
  {
    system("cls");
    printUI("src/components/data/Pages/qlhoadon.txt");
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
        pKH->create(tempSDT, tempMaKH);
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
      printUI("src/components/data/Pages/qlhoadon.txt");
      pSP->readList(tempList);
      try
      {
        Ma tempMa;
        printRes("Nhap ma san pham muon them vao danh sach: ");
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
            if (tempSP.getSoLuong() - tempSoLuong < 0)
              throw string("So luong san pham vua nhap lon hon so luong trong kho");
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
  HoaDon tempHD(listSP, tempMaHD, tempMaNV, tempMaKH, false);
  listHD->push_back(tempHD);
  this->count++;
  fstream fileHoaDon;
  fileHoaDon.open("src/components/data/HoaDon.DAT", ios_base::out);
  QLHoaDon::ghiFile(fileHoaDon);
  fileHoaDon.close();
}

void QLHoaDon::update()
{
  List<HoaDon> *listTemp = new List<HoaDon>();
  ConsoleTable table{"STT", "Ma hoa don", "Ten Khach Hang", "Ngay tao hoa don", "Tong Tien"};
  while (true)
  {
    system("cls");
    printUI("src/components/data/Pages/qlhoadon.txt");
    string tempSDT;
    Ma tempMaKH;
    try
    {
      printRes("Nhap so dien thoai khach hang: ");
      fflush(stdin);
      getline(cin, tempSDT);
      tempMaKH = pKH->findKH(tempSDT);
      if (tempMaKH.getSoTT() == -1)
        throw string("Khong tim thay khach hang!");
    }
    catch (const string error)
    {
      printError(error);
      return;
    }
    Node<HoaDon> *pTemp = this->listHD->getpHead();
    int cnt = 0;
    while (pTemp)
    {
      Ma temp = pTemp->getData().getMaKH();
      if (temp == tempMaKH)
      {
        string tempTen = this->pKH->findKH(tempMaKH);
        Date tempNgay = pTemp->getData().getNgayHD();
        Ma tempMaHD = pTemp->getData().getMaHD();
        table += {to_string(++cnt), string(tempMaHD), tempTen, string(tempNgay), to_string(pTemp->getData().getTongTien())};
        listTemp->push_back(pTemp->getData());
      }
      pTemp = pTemp->getpNext();
    }
    if (cnt == 0)
    {
      cout << "\n\tKhach hang co " << tempSDT << " chua mua san pham nao";
    }
    else
    {
      cout << "\n\tKhach hang co " << tempSDT << " da mua " << cnt << " lan.\n";
      cout << table;
    }
    break;
  }

  while (true)
  {
    printRes("Nhap ma hoa don can chinh sua: ");
    Ma temp;
    cin >> temp;
    try
    {
      Node<HoaDon> *pTemp = listTemp->getpHead();
      int cntHD = 0;
      while (pTemp)
      {
        Ma tempMa = pTemp->getData().getMaHD();
        cout << (temp == tempMa) << endl;
        if (temp == tempMa)
        {
          Node<HoaDon> *pTemp1 = this->listHD->getpHead();
          int cnt = 0;
          while (pTemp1)
          {
            Ma maListRoot = pTemp1->getData().getMaHD();
            cout << (maListRoot == tempMa) << endl;
            if (maListRoot == temp)
            {
              cout << "Alo";
              HoaDon tempRepair = pTemp1->getData();
              while (tempRepair.getSoLuong() != 0)
              {
                system("cls");
                printUI("src/components/data/Pages/qlhoadon.txt");
                tempRepair.xuat();
                string arr[] = {"Ban muon lam gi: ", "Them san pham", "Xoa san pham", "Thoat"};
                printOpt(arr, 3);
                int key = getKey(3);
                switch (key)
                {
                case 1:
                {
                  List<SanPham> *listSP = new List<SanPham>();
                  listSP = tempRepair.getListSP();
                  int cnt = 0;
                  bool check = true;
                  while (true)
                  {
                    List<SanPham> *tempList = new List<SanPham>();
                    tempList = this->pSP->findList();
                    while (true)
                    {
                      system("cls");
                      printUI("src/components/data/Pages/qlhoadon.txt");
                      pSP->readList(tempList);
                      try
                      {
                        Ma tempMa;
                        printRes("Nhap ma san pham muon them vao danh sach: ");
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
                            cnt++;
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
                      break;
                  }
                  // tempRepair.setListSP(listSP);
                  tempRepair.tinhTongTien();
                  tempRepair.setSoLuong(tempRepair.getSoLuong() + cnt);
                  tempRepair.xuat();
                  pTemp1->setData(tempRepair);
                  fstream fileHoaDon;
                  fileHoaDon.open("src/components/data/HoaDon.DAT", ios_base::out);
                  QLHoaDon::ghiFile(fileHoaDon);
                  fileHoaDon.close();
                }
                break;
                case 2:
                {
                  List<SanPham> *listSP = new List<SanPham>();
                  listSP = tempRepair.getListSP();
                  int cnt = 0;
                  bool check = true;
                  while (check)
                  {
                    system("cls");
                    printUI("src/components/data/Pages/qlhoadon.txt");
                    tempRepair.xuat();
                    printRes("\nNhap so thu tu san pham can xoa: ");
                    int i;
                    while (true)
                    {
                      try
                      {
                        cin >> i;
                        if (i < 0 || i > tempRepair.getSoLuong())
                          throw string("So thu tu khong hop le!");
                        break;
                      }
                      catch (const string &e)
                      {
                        printError(e);
                      }
                    }
                    int index = 0;
                    Node<SanPham> *pTemp = listSP->getpHead();
                    while (pTemp)
                    {
                      if (i - 1 == index)
                      {
                        {
                          string arr[] = {"Ban muon xoa: ", "So luong san pham", "Toan bo san pham", "Thoat"};
                          printOpt(arr, 3);
                        }
                        int key = getKey(3);
                        switch (key)
                        {
                        case 1:
                        {
                          while (true)
                          {
                            try
                            {
                              SanPham tempSP = pTemp->getData();
                              printRes("Nhap so luong san pham muon xoa: ");
                              int j;
                              cin >> j;
                              if (tempSP.getSoLuong() - j == 0)
                              {
                                printWarning("San pham ban vua xoa co so luong = 0!");
                                printRes("\nBan co chac chan muon xoa " + to_string(j) + " san pham nay khong? (y/n): ");
                                char c;
                                c = getchar();
                                if (c == 'n')
                                  break;
                              }
                              if (j < 0 || j > pTemp->getData().getSoLuong())
                                throw string("So luong muon xoa khong hop le!");
                              tempSP.setSoLuong(tempSP.getSoLuong() - j);
                              pTemp->setData(tempSP);

                              if (tempSP.getSoLuong() == 0)
                              {
                                cnt++;
                                listSP->deleteNode(i - 1);
                              }
                              break;
                            }
                            catch (const string &e)
                            {
                              printError(e);
                              char c;
                              fflush(stdin);
                              c = getchar();
                            }
                          }
                          check = false;
                        }
                        break;
                        case 2:
                        {
                          printWarning("San pham ban vua xoa co so luong = 0!");
                          printRes("\nBan co chac chan muon xoa san pham nay khong? (y/n): ");
                          char c;
                          fflush(stdin);
                          c = getchar();
                          if (c == 'n')
                            break;
                          listSP->deleteNode(i - 1);
                          cnt++;
                          check = false;
                        }
                        break;
                        case 3:
                        {
                          check = false;
                          break;
                        }
                        break;
                        }
                        tempRepair.tinhTongTien();
                        tempRepair.setSoLuong(tempRepair.getSoLuong() - cnt);
                        pTemp1->setData(tempRepair);
                      }
                      index++;
                      pTemp = pTemp->getpNext();
                    }
                    if (tempRepair.getSoLuong() == 0)
                    {
                      check = false;
                      break;
                    }
                  }
                  if (tempRepair.getSoLuong() == 0)
                  {
                    printWarning("Hoa don nay da het san pham! Ban co muon xoa Hoa Don nay khong? (y/n)");
                    char c;
                    fflush(stdin);
                    c = getchar();
                    if (c == 'y')
                    {
                      this->listHD->deleteNode(cntHD);
                      this->count--;
                    }
                    break;
                  }
                  fstream fileHoaDon;
                  fileHoaDon.open("src/components/data/HoaDon.DAT", ios_base::out);
                  QLHoaDon::ghiFile(fileHoaDon);
                  fileHoaDon.close();
                }
                break;
                case 3:
                {
                  return;
                }
                break;
                default:
                  break;
                }
              }
              return;
            }
            ++cnt;
            pTemp1 = pTemp1->getpNext();
          }
          return;
        }
        cntHD++;
        pTemp = pTemp->getpNext();
      }
      throw string("Ma hoa don ban dang muon xoa khong hop le! Vui long thu lai");
    }
    catch (const string &e)
    {
      printError(e);
      char c;
      fflush(stdin);
      c = getchar();
    }
  }
}

void QLHoaDon::read()
{
  while (true)
  {
    system("cls");
    printUI("src/components/data/Pages/qlhoadon.txt");
    string arr[] = {"Xem hoa don theo: ", "Ngay", "Thang", "Nam", "Thoat"};
    printOpt(arr, 4);
    int key = getKey(4);
    switch (key)
    {
      // Theo ngày
    case 1:
    {
      ConsoleTable table{"STT", "Ma Hoa Don", "Ma Nhan Vien", "Ma Khach Hang", "Ngay Tao Hoa Don", "Tinh trang", "Tong Tien"};
      Date tempNgay;
      cin >> tempNgay;
      Node<HoaDon> *pTemp = this->listHD->getpHead();
      int cnt = 0;
      while (pTemp)
      {
        Date tempDate = pTemp->getData().getNgayHD();
        if (tempDate == tempNgay)
        {
          Ma tempMaHD = pTemp->getData().getMaHD();
          Ma tempMaNV = pTemp->getData().getMaNV();
          Ma tempMaKH = pTemp->getData().getMaKH();
          string tinhTrang = (pTemp->getData().getExported() ? "Da xuat" : "Chua xuat");
          table += {to_string(++cnt), string(tempMaHD), string(tempMaNV), string(tempMaKH), string(tempDate), tinhTrang, to_string(pTemp->getData().getTongTien())};
        }
        pTemp = pTemp->getpNext();
      }
      if (cnt == 0)
      {
        cout << "\n\tDanh sach nay khong co hoa don nao!";
      }
      else
      {
        cout << "\n\tDanh sach nay co " << cnt << " hoa don.\n";
        cout << table;
      }
      char c;
      fflush(stdin);
      c = getchar();
    }
    break;
    // Theo tháng
    case 2:
    {
      ConsoleTable table{"STT", "Ma Hoa Don", "Ma Nhan Vien", "Ma Khach Hang", "Ngay Tao Hoa Don", "Tinh trang", "Tong Tien"};
      Date tempNgay;
      tempNgay.nhapThang();
      Node<HoaDon> *pTemp = this->listHD->getpHead();
      int cnt = 0;
      while (pTemp)
      {
        Date tempDate = pTemp->getData().getNgayHD();
        if (tempDate.getThang() == tempNgay.getThang() && tempDate.getNam() == tempNgay.getNam())
        {
          Ma tempMaHD = pTemp->getData().getMaHD();
          Ma tempMaNV = pTemp->getData().getMaNV();
          Ma tempMaKH = pTemp->getData().getMaKH();
          string tinhTrang = (pTemp->getData().getExported() ? "Da xuat" : "Chua xuat");
          table += {to_string(++cnt), string(tempMaHD), string(tempMaNV), string(tempMaKH), string(tempDate), tinhTrang, to_string(pTemp->getData().getTongTien())};
        }
        pTemp = pTemp->getpNext();
      }
      if (cnt == 0)
      {
        cout << "\n\tDanh sach nay khong co hoa don nao!";
      }
      else
      {
        cout << "\n\tDanh sach nay co " << cnt << " hoa don.\n";
        cout << table;
      }
      char c;
      fflush(stdin);
      c = getchar();
    }
    break;
      // Theo năm
    case 3:
    {
      ConsoleTable table{"STT", "Ma Hoa Don", "Ma Nhan Vien", "Ma Khach Hang", "Ngay Tao Hoa Don", "Tinh trang", "Tong Tien"};
      Date tempNgay;
      tempNgay.nhapNam();
      Node<HoaDon> *pTemp = this->listHD->getpHead();
      int cnt = 0;
      while (pTemp)
      {
        Date tempDate = pTemp->getData().getNgayHD();
        if (tempDate.getNam() == tempNgay.getNam())
        {
          Ma tempMaHD = pTemp->getData().getMaHD();
          Ma tempMaNV = pTemp->getData().getMaNV();
          Ma tempMaKH = pTemp->getData().getMaKH();
          string tinhTrang = (pTemp->getData().getExported() ? "Da xuat" : "Chua xuat");
          table += {to_string(++cnt), string(tempMaHD), string(tempMaNV), string(tempMaKH), string(tempDate), tinhTrang, to_string(pTemp->getData().getTongTien())};
        }
        pTemp = pTemp->getpNext();
      }
      if (cnt == 0)
      {
        cout << "\n\tDanh sach nay khong co hoa don nao!";
      }
      else
      {
        cout << "\n\tDanh sach nay co " << cnt << " hoa don.\n";
        cout << table;
      }
      char c;
      fflush(stdin);
      c = getchar();
    }
    break;
    case 4:
    {
      return;
    }
    break;
    }
  }
}

void QLHoaDon::deleteIndex()
{
  List<HoaDon> *listTemp = new List<HoaDon>();
  ConsoleTable table{"STT", "Ma hoa don", "Ten Khach Hang", "Ngay tao hoa don", "Tong Tien"};
  while (true)
  {
    system("cls");
    printUI("src/components/data/Pages/qlhoadon.txt");
    string tempSDT;
    Ma tempMaKH;
    try
    {
      printRes("Nhap so dien thoai khach hang: ");
      fflush(stdin);
      getline(cin, tempSDT);
      tempMaKH = pKH->findKH(tempSDT);
      if (tempMaKH.getSoTT() == -1)
        throw string("Khong tim thay khach hang!");
    }
    catch (const string error)
    {
      printError(error);
      return;
    }
    Node<HoaDon> *pTemp = this->listHD->getpHead();
    int cnt = 0;
    while (pTemp)
    {
      Ma temp = pTemp->getData().getMaKH();
      if (temp == tempMaKH)
      {
        string tempTen = this->pKH->findKH(tempMaKH);
        Date tempNgay = pTemp->getData().getNgayHD();
        Ma tempMaHD = pTemp->getData().getMaHD();
        table += {to_string(++cnt), string(tempMaHD), tempTen, string(tempNgay), to_string(pTemp->getData().getTongTien())};
        listTemp->push_back(pTemp->getData());
      }
      pTemp = pTemp->getpNext();
    }
    if (cnt == 0)
    {
      cout << "\n\tKhach hang co " << tempSDT << " chua mua san pham nao";
    }
    else
    {
      cout << "\n\tKhach hang co " << tempSDT << " da mua " << cnt << " lan.\n";
      cout << table;
    }
    break;
  }

  while (true)
  {
    printRes("Nhap ma hoa don can xoa: ");
    Ma temp;
    cin >> temp;
    try
    {
      Node<HoaDon> *pTemp = listTemp->getpHead();
      while (pTemp)
      {
        Ma tempMa = pTemp->getData().getMaHD();
        if (temp == tempMa && pTemp->getData().getExported() == false)
        {
          Node<HoaDon> *pTemp1 = this->listHD->getpHead();
          int cnt = 0;
          while (pTemp1)
          {
            tempMa = pTemp1->getData().getMaHD();
            if (tempMa == temp)
            {
              pTemp1->getData().xuat();
              printWarning("Ban co chac chan muon xoa hoa don nay khong? (y/n): ");
              printRes("\nNhap lua chon: ");
              char c;
              fflush(stdin);
              c = getchar();
              if (c == 'n')
                break;
              this->listHD->deleteNode(cnt);
              this->count--;
              printSuccess("Xoa hoa don thanh cong!");
              fstream fileHoaDon;
              fileHoaDon.open("src/components/data/HoaDon.DAT", ios_base::out);
              QLHoaDon::ghiFile(fileHoaDon);
              fileHoaDon.close();
              return;
            }
            ++cnt;
            pTemp1 = pTemp1->getpNext();
          }
        }
        else if (pTemp->getData().getExported())
        {
          throw string("Hoa don nay da xuat! khong the xoa");
        }
        pTemp = pTemp->getpNext();
      }
      throw string("Ma hoa don ban dang muon xoa khong hop le! Vui long thu lai");
    }
    catch (const string &e)
    {
      printError(e);
      char c;
      printRes("Ban co muon xoa hoa don khac khong? (y/n): ");
      fflush(stdin);
      c = getchar();
      if (c == 'n')
        return;
    }
  }
}

void QLHoaDon::find()
{
  while (true)
  {
    system("cls");
    printUI("src/components/data/Pages/qlhoadon.txt");
    ConsoleTable table{"STT", "Ma hoa don", "Ten Khach Hang", "Ngay tao hoa don", "Tinh trang", "Tong Tien"};
    string tempSDT;
    Ma tempMaKH;
    try
    {
      printRes("Nhap so dien thoai khach hang: ");
      fflush(stdin);
      getline(cin, tempSDT);
      tempMaKH = pKH->findKH(tempSDT);
      if (tempMaKH.getSoTT() == -1)
        throw string("Khong tim thay khach hang!");
    }
    catch (const string error)
    {
      printError(error);
      char c;
      fflush(stdin);
      c = getchar();
      continue;
    }
    Node<HoaDon> *pTemp = this->listHD->getpHead();
    int cnt = 0;
    while (pTemp)
    {
      Ma temp = pTemp->getData().getMaKH();
      if (temp == tempMaKH)
      {
        string tempTen = this->pKH->findKH(tempMaKH);
        Date tempNgay = pTemp->getData().getNgayHD();
        Ma tempMaHD = pTemp->getData().getMaHD();
        string tinhTrang = (pTemp->getData().getExported() ? "Da xuat" : "Chua xuat");
        table += {to_string(++cnt), string(tempMaHD), tempTen, string(tempNgay), tinhTrang, to_string(pTemp->getData().getTongTien())};
      }
      pTemp = pTemp->getpNext();
    }
    if (cnt == 0)
    {
      cout << "\n\tKhach hang co " << tempSDT << " chua mua san pham nao";
    }
    else
    {
      cout << "\n\tKhach hang co " << tempSDT << " da mua " << cnt << " lan.\n";
      cout << table;
    }
    printRes("Co muon tim lai khach hang khac khong? (y/n): ");
    char c;
    c = getchar();
    if (c == 'n')
      break;
  }
}

void QLHoaDon::xuatFile()
{
  printRes("Nhap thong tin hoa don can xuat: \n");
  QLHoaDon::find();
  while (true)
  {
    Ma tempMa;
    printRes("Nhap ma hoa don can xuat file: ");
    cin >> tempMa;
    try
    {
      Node<HoaDon> *pTemp = this->listHD->getpHead();
      while (pTemp)
      {
        Ma temp = pTemp->getData().getMaHD();
        if (temp == tempMa)
        {
          system("cls");
          printUI("src/components/data/Pages/qlhoadon.txt");
          if (pTemp->getData().getExported())
          {
            pTemp->getData().xuat();
            throw string("Hoa don nay da duoc xuat!");
          }
          pTemp->getData().xuat();
          Node<SanPham> *tempSP = pTemp->getData().getListSP()->getpHead();
          while (tempSP)
          {
            pSP->setSLSize(tempSP->getData().getMa(), tempSP->getData().getSize(), tempSP->getData().getSoLuong());
            tempSP = tempSP->getpNext();
          }
          printRes("\nBan co muon xuat hoa don nay khong?(y/n): ");
          char c;
          fflush(stdin);
          c = getchar();
          if (c == 'n')
          {
            return;
          }
          // Xuat hoa don ra file
          fstream fileHoaDon;
          string src = "src/components/data/HoaDon/" + string(tempMa) + ".DAT";
          fileHoaDon.open(src, ios_base::out);
          pTemp->getData().xuatFile(fileHoaDon);
          static HoaDon tempHD = pTemp->getData();
          tempHD.setExported(true);
          pTemp->setData(tempHD);
          fileHoaDon.close();
          // Ghi lai du lieu
          fileHoaDon.open("src/components/data/HoaDon.DAT", ios_base::out);
          QLHoaDon::ghiFile(fileHoaDon);
          fileHoaDon.close();
          fstream fileSanPham;
          fileSanPham.open("src/components/data/SanPham.DAT", ios_base::out);
          pSP->ghiFile(fileSanPham);
          fileSanPham.close();
          printSuccess("Da xuat hoa don thanh cong!");
          return;
        }
        pTemp = pTemp->getpNext();
      }
      if (!pTemp)
      {
        throw string("Khong tim thay ma hoa don! Vui long thu lai");
      }
    }
    catch (const string &e)
    {
      printError(e);
      char c;
      fflush(stdin);
      c = getchar();
    }
  }
}

// Utils
//- Tìm mã HD lớn nhất để tạo mã HD
void QLHoaDon::statisticalByDate()
{
  Date tempNgay;
  cin >> tempNgay;
  int hddx = 0;
  int hd = 0;
  ll tongTienChi = 0;
  ll tongTienThu = 0;
  Node<HoaDon> *pTemp = this->listHD->getpHead();
  while (pTemp)
  {
    Date ngay = pTemp->getData().getNgayHD();
    if (tempNgay == ngay && pTemp->getData().getExported())
    {
      tongTienChi += pTemp->getData().getTongTienChi();
      tongTienThu += pTemp->getData().getTongTien();
      hddx++;
    }
    hd++;
    pTemp = pTemp->getpNext();
  }

  cout << "\n\tThong tin thong ke ngay: " << tempNgay.getNgay() << "/" << tempNgay.getThang() << "/" << tempNgay.getNam() << " :";
  cout << "\n\t Hoa don da xuat trong ngay/tong so hoa dong trong ngay: " << hddx << "/" << hd;
  cout << "\n\tTong so tien chi: " << tongTienChi;
  cout << "\n\t Tong so tien thu: " << tongTienThu;
  cout << "\n\t Loi nhuan: " << tongTienThu - tongTienChi;
};

void QLHoaDon::statisticalByMonth()
{
  Date tempNgay;
  tempNgay.nhapThang();
  int hddx = 0;
  int hd = 0;
  ll tongTienChi = 0;
  ll tongTienThu = 0;
  Node<HoaDon> *pTemp = this->listHD->getpHead();
  while (pTemp)
  {
    Date ngay = pTemp->getData().getNgayHD();
    if (tempNgay.getThang() == ngay.getThang() && tempNgay.getNam() == ngay.getNam() && pTemp->getData().getExported())
    {
      tongTienChi += pTemp->getData().getTongTienChi();
      tongTienThu += pTemp->getData().getTongTien();
      hddx++;
    }
    hd++;
    pTemp = pTemp->getpNext();
  }

  cout << "\n\tThong tin thong ke thang: " << tempNgay.getThang() << "/" << tempNgay.getNam() << " :";
  cout << "\n\t Hoa don da xuat trong thang/tong so hoa don trong thang: " << hddx << "/" << hd;
  cout << "\n\tTong so tien chi: " << tongTienChi;
  cout << "\n\t Tong so tien thu: " << tongTienThu;
  cout << "\n\t Loi nhuan: " << tongTienThu - tongTienChi;
};

void QLHoaDon::statisticalByYear()
{
  Date tempNgay;
  tempNgay.nhapNam();
  int hddx = 0;
  int hd = 0;
  ll tongTienChi = 0;
  ll tongTienThu = 0;
  Node<HoaDon> *pTemp = this->listHD->getpHead();
  while (pTemp)
  {
    Date ngay = pTemp->getData().getNgayHD();
    if (tempNgay.getNam() == ngay.getNam() && pTemp->getData().getExported())
    {
      tongTienChi += pTemp->getData().getTongTienChi();
      tongTienThu += pTemp->getData().getTongTien();
      hddx++;
    }
    hd++;
    pTemp = pTemp->getpNext();
  }

  cout << "\n\tThong tin thong ke nam " << tempNgay.getNam() << " :";
  cout << "\n\t Hoa don da xuat trong nam/tong so hoa don trong nam: " << hddx << "/" << hd;
  cout << "\n\tTong so tien chi: " << tongTienChi;
  cout << "\n\t Tong so tien thu: " << tongTienThu;
  cout << "\n\t Loi nhuan: " << tongTienThu - tongTienChi;
};

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