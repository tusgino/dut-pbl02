#include "..\..\..\Class\QLHoaDon.h"

QLHoaDon::QLHoaDon()
{
    this->DSHD = new List<HoaDon>();
    this->soHD = 0;
    this->pKH = nullptr;
    this->pNV = nullptr;
    this->pSP = nullptr;
}

QLHoaDon::QLHoaDon(QLSanPham *SP, QLNhanVien *NV, QLKhachHang *KH)
{
    this->pSP = SP;
    this->pKH = KH;
    this->pNV = NV;

    this->DSHD = new List<HoaDon>();
    this->soHD = 0;
}

QLHoaDon::~QLHoaDon()
{
    this->DSHD->~List();
}

void QLHoaDon::nhapTuFile(fstream &fileHoaDon)
{
    fileHoaDon >> this->soHD;
    fileHoaDon.ignore(1);
    for (int i = 0; i < this->soHD; i++)
    {
        HoaDon pTemp;
        pTemp.setDSSP(this->pSP);
        pTemp.docFileHD(fileHoaDon);
        this->DSHD->push_back(pTemp);
    }
}

void QLHoaDon::ghiVaoFile(fstream &fileHoaDon)
{
    fileHoaDon << this->soHD << endl;
    Node<HoaDon> *pTemp = this->DSHD->getpHead();
    while (pTemp)
    {
        pTemp->getData().ghiFile(fileHoaDon);
        pTemp = pTemp->getpNext();
    }
}

void QLHoaDon::nhapTuNguoiDung()
{
    HoaDon *Add = new HoaDon(this->pSP);
    Add->setDSSP(this->pSP);
    Add->setTongTien(0);

    bool checktrue = false;
    int max = 0, temp;
    while (checktrue == false)
    {
        srand(time(0));
        max = rand() % 1000 + 1;
        checktrue = true;

        Node<HoaDon> *pTemp = this->DSHD->getpHead();
        for (int i = 0; i < this->soHD; i++)
        {
            temp = pTemp->getData().getMaHoaDon();

            if (max == temp)
            {
                checktrue = false;
                break;
            }
            pTemp = pTemp->getpNext();
        }
    }
    Add->setMaHoaDon(max);
    cout << "\tNhan vien dang nhap hoa don co ma la " << this->maDangNhap << endl;
    Add->setMaNV(this->maDangNhap);
    string tempSDT;
    cout << "\tNhap so dien thoai khach hang: ";
    fflush(stdin);
    getline(cin, tempSDT);
    int index = this->pKH->timKiemKHTheoSDT(tempSDT); // Mã khách hàng
    if (index == -1)
    {
        cout << "\tKhong co khach hang co so dien thoai nay\n";
        cout << "\tHay cap nhat so dien thoai\n";
    }
    else
    {
        Add->setMaKH(index);

        Date tempDate;
        // cout << "\tNhap ngay thuc hien hoa don:\n ";
        // cin >> tempDate;
        cout << "Thoi gian hoa don: ";
        Add->setNgayIn(tempDate);
        cout << Add->getNgayIn() << endl;
        int soluong;
        cout << "\tNhap so luong: ";
        cin >> soluong;
        Add->setSoLuong(soluong);
        List<SanPham_HD> *pSPHD = new List<SanPham_HD>();
        for (int i = 0; i < soluong; i++)
        {
            this->pSP->findIndex();
            string maSP;
            cout << "Nhap ma san pham thu " << i + 1 << ":";
            fflush(stdin);
            getline(cin, maSP);
            string size;
            cout << "Nhap size: ";
            fflush(stdin);
            getline(cin, size);
            transform(size.begin(), size.end(), size.begin(), ::toupper);
            cout << "Nhap so luong hang can mua: ";
            int tempsoSP;
            cin >> tempsoSP;

            int soSP = this->pSP->getSoLuongOFSize(maSP, size);
            // cout << soSP << "  " << tempsoSP << endl;
            if (soSP >= tempsoSP)
            {
                SanPham_HD Temp(maSP, size, tempsoSP);
                // Temp.xuatHD();
                pSPHD->push_back(Temp);
                SanPham spTemp = Add->getDSSP()->findSP(Temp.getMaSP());
                Add->setTongTien(Add->getTongTien() + (Temp.getCount() * spTemp.getDonGiaSP() * (1 - spTemp.getGiamGiaSP() / 100)));
            }
            else
            {
                cout << "cook";
                return;
            }
        }
        Add->setSP(pSPHD);
        // cout << Add->getSoLuong();
        // Add->xuat();
        cout << Add->getTongTien() << endl;
        this->DSHD->push_back(*Add);
        this->soHD++;
        fstream fileHoaDon;
        fileHoaDon.open("Data/HoaDon.DAT", ios_base::out);
        this->ghiVaoFile(fileHoaDon);
        fileHoaDon.close();
    }
}

void QLHoaDon::setMaDangNhap(const int &ma)
{
    this->maDangNhap = ma;
};

void QLHoaDon::inRaManHinh()
{
    cout << "\tCo tong cong " << setfill('0') << right << setw(2) << this->soHD << " hoa don trong cua hang: " << endl;
    Node<HoaDon> *pTemp = this->DSHD->getpHead();
    int i = 1;
    while (pTemp)
    {
        cout << "Hoa don thu " << i++ << ": \n";
        pTemp->getData().xuat();
        pTemp = pTemp->getpNext();
    }
}

void QLHoaDon::xuatHoaDon(HoaDon tempHoaDon) // xuất 1 hóa đơn ra 1 file trong thư mục HoaDon
{
    string tenFile = "";
    tenFile = "Data/HoaDon/HD" + to_string(tempHoaDon.getMaHoaDon()) + ".txt";
    cout << tenFile << endl;
    fstream fileGhiHD;
    fileGhiHD.open(tenFile, ios_base::out);
    tempHoaDon.ghiFile(fileGhiHD);
    fileGhiHD.close();
    // Thay đổi số liếu sau khi xuất hóa đơn.
    Node<SanPham_HD> *pTemp = tempHoaDon.getSP()->getpHead();
    for (int i = 0; i < tempHoaDon.getSoLuong(); i++)
    {
        pSP->capNhatDuLieuSP(pTemp->getData().getMaSP(), pTemp->getData().getSize(), pTemp->getData().getCount());
        pTemp = pTemp->getpNext();
    }
    fstream fileSanPham;
    fileSanPham.open("Data/SanPham.DAT", ios_base::out);
    pSP->ghiVaoFile(fileSanPham);
    fileSanPham.close();
}

void QLHoaDon::xuatChiTietHoaDon()
{
    string tempSDT;
    cout << "Nhap so dien thoai khach hang : ";
    fflush(stdin);
    getline(cin, tempSDT);
    int tempMaKH = this->pKH->timKiemKHTheoSDT(tempSDT);

    if (tempMaKH == -1)
    {
        // cout << "cook\n";
        return;
    }
    else
    {
        Node<HoaDon> *pTemp = this->DSHD->getpHead();
        while (pTemp)
        {
            if (pTemp->getData().getMaKH() == tempMaKH)
            {
                // pTemp->getData().xuat();
                cout << "\tMa hoa don: " << pTemp->getData().getMaHoaDon();
                cout << "\tMa nhan vien: " << pTemp->getData().getMaNV();
                cout << "\tMa khach hang: " << pTemp->getData().getMaKH();
                cout << "\tNgay thuc hien hoa don: " << pTemp->getData().getNgayIn();
            }

            pTemp = pTemp->getpNext();
        }
    }
    cout << "Nhap ma hoa don muon xuat vao file:";
    int tempMaHD;
    cin >> tempMaHD;

    Node<HoaDon> *pTemp = this->DSHD->getpHead();
    while (pTemp)
    {
        if (pTemp->getData().getMaHoaDon() == tempMaHD)
        {
            this->xuatHoaDon((pTemp->getData()));
            break;
            // cout << "okla";
        }

        pTemp = pTemp->getpNext();
    }
}

void QLHoaDon::thongKeTheoNgay(Date &date, long long &TT)
{
    cout << "Thong ke hoa don ngay: " << date.getNgay() << "/" << date.getThang() << "/" << date.getNam() << endl;
    Node<HoaDon> *pTemp = this->DSHD->getpHead();
    long long tongTien = 0;
    while (pTemp)
    {
        Date dateTemp = pTemp->getData().getNgayIn();
        if (date == dateTemp)
        {
            pTemp->getData().xuatInfo();
            tongTien += pTemp->getData().getTongTien();
        }
        pTemp = pTemp->getpNext();
    }
    cout << "\n\t\tTong doanh thu ngay: " << date.getNgay() << "/" << date.getThang() << "/" << date.getNam() << ": " << tongTien << "\n";
    TT += tongTien;
}

void QLHoaDon::thongKe()
{
    bool check = true;
    while (check)
    {
        system("cls");
        cout << "\n\t\t1. Thong ke theo ngay.";
        cout << "\n\t\t2. Thong ke trong khoang thoi gian.";
        cout << "\n\t\t3. Quay lai.";
        int key = getKey(3);
        switch (key)
        {
        case 1:
        {
            system("cls");
            cout << "\n\tNhap ngay can thong ke: \n";
            Date date(0, 0, 0, 0, 0);
            cin >> date;
            long long tongTien = 0;
            system("cls");
            this->thongKeTheoNgay(date, tongTien);
            system("pause");
            QLHoaDon::thongKe();
        }
        break;
        case 2:
        {
            system("cls");
            cout << "\n\tNhap ngay bat dau: \n";
            Date startDate(0, 0, 0, 0, 0);
            cin >> startDate;
            system("cls");
            cout << "\n\tNhap ngay ket thuc: \n";
            Date endDate(0, 0, 0, 0, 0);
            cin >> endDate;
            Date date(startDate);
            system("cls");
            cout << "Thong ke hoa don tu ngay: " << startDate.getNgay() << "/" << startDate.getThang() << "/" << startDate.getNam() << " den ngay: " << endDate.getNgay() << "/" << endDate.getThang() << "/" << endDate.getNam() << "\n";
            long long tongTien = 0;
            while (date <= endDate)
            {
                this->thongKeTheoNgay(date, tongTien);
                date++;
            }
            cout << "Tong doanh thu tu ngay: " << startDate.getNgay() << "/" << startDate.getThang() << "/" << startDate.getNam() << " den ngay: " << endDate.getNgay() << "/" << endDate.getThang() << "/" << endDate.getNam() << " la: " << tongTien << endl;
        }
        break;
        case 3:
            check = false;
            break;
        }
    }
}

void QLHoaDon::thongKeNhanVienThang(Date &date)
{
}

void QLHoaDon::thongKeNhanVien()
{
    system("cls");
    bool check = true;
    while (check)
    {
        cout << "\n\t\t1.Xuat danh sach nhan vien ban hang tot nhat theo thang.";
        cout << "\n\t\t2.Xuat danh sach nhan vien ban hang tot nhat theo khoang thoi gian";
        cout << "\n\t\t3.Quay lai.";
        int key = getKey(3);
        switch (key)
        {
        case 1:
        {
            cout << "\n\tNhap thang can thong ke: ";
            int thang, nam;
            cout << "\n\t Nhap thang: ";
            cin >> thang;
            cout << "\n\t Nhap nam: ";
            cin >> nam;
            Date date(0, 0, 0, thang, nam);
        }
        break;
        case 2:
        {
        }
        break;
        case 3:
            check = false;
            break;
        }
    }
}

const int QLHoaDon::checkSP(const string &maSP, string arr[])
{
    for (int i = 0; i < this->pSP->getSoLuongSP() + 1; i++)
    {
        if (arr[i] == "NULL")
            return -1;
        if (arr[i] == maSP)
            return i;
    }
    return -1;
}

void QLHoaDon::thongKeSanPhamNgay(Date &date, string arrMa[], int soLuongMa[], int i)
{
    cout << date << endl;
    Node<HoaDon> *pTemp = this->DSHD->getpHead();
    while (pTemp)
    {
        Date dateTemp = pTemp->getData().getNgayIn();
        if (date == dateTemp)
        {
            List<SanPham_HD> *dsTemp = new List<SanPham_HD>();
            dsTemp = pTemp->getData().getSP();
            Node<SanPham_HD> *pTemp2 = dsTemp->getpHead();
            while (pTemp2)
            {
                int index = checkSP(pTemp2->getData().getMaSP(), arrMa);
                if (index >= 0)
                {
                    soLuongMa[index] += pTemp2->getData().getCount();
                }
                else
                {
                    arrMa[i] = pTemp2->getData().getMaSP();
                    soLuongMa[i++] = pTemp2->getData().getCount();
                }
                pTemp2 = pTemp2->getpNext();
            }
        }
        pTemp = pTemp->getpNext();
    }
}

void QLHoaDon::thongKeSanPham()
{
    bool check = true;
    while (check)
    {
        system("cls");
        cout << "\n\t\t1. Xuat danh sach san pham ban trong ngay.";
        cout << "\n\t\t2. Xuat danh sach san pham ban trong thang.";
        cout << "\n\t\t3. Quay lai.";
        int key = getKey(3);
        switch (key)
        {
        case 1:
        {
            system("cls");
            cout << "\n\tNhap ngay can thong ke: \n";
            Date date(0, 0, 0, 0, 0);
            cin >> date;
            system("cls");
            string arrMa[this->pSP->getSoLuongSP() + 1];
            int soLuongMa[this->pSP->getSoLuongSPs() + 1];
            for (int i = 0; i < this->pSP->getSoLuongSP() + 1; i++)
            {
                arrMa[i] = "NULL";
                soLuongMa[i] = 0;
            }
            int i = 0;
            this->thongKeSanPhamNgay(date, arrMa, soLuongMa, i);
            long long totalPrices = 0;
            long long totalPricesIn = 0;
            for (int i = 0; i < this->pSP->getSoLuongSP() + 1; i++)
            {
                if (arrMa[i] == "NULL")
                    break;
                long long pricesSP = 0;
                long long pricesSPIn = 0;
                List<SanPham> *listSP = pSP->getQLSP();
                Node<SanPham> *spTemp = listSP->getpHead();
                while (spTemp)
                {
                    if (spTemp->getData().getMaSP() == arrMa[i])
                    {
                        pricesSP = (spTemp->getData().getDonGiaSP() * (1 - spTemp->getData().getGiamGiaSP() / 100) * soLuongMa[i]);
                        pricesSPIn = spTemp->getData().getGiaNhapSP() * soLuongMa[i];
                        totalPrices += pricesSP;
                        totalPricesIn += pricesSPIn;
                    }
                    spTemp = spTemp->getpNext();
                }
                cout << arrMa[i] << " - " << soLuongMa[i] << " - " << pricesSP << endl;
            }
            cout << "Tong doanh thu: " << totalPrices << endl;
            cout << "Tong loi nhuan: " << totalPrices - totalPricesIn << endl;
            system("pause");
            QLHoaDon::thongKeSanPham();
        }
        break;
        case 2:
        {
            system("cls");
            int thang, nam;
            cout << "\n\tNhap thang can thong ke: \n";
            do
            {
                cout << "\tNhap thang: ";
                cin >> thang;
            } while (thang < 1 || thang > 12);
            do
            {
                cout << "\tNhap nam: ";
                cin >> nam;
            } while (nam < 1);
            Date date(0, 0, 0, thang, nam);
            Node<HoaDon> *pTemp = this->DSHD->getpHead();
            string arrMa[this->pSP->getSoLuongSP() + 1];
            int soLuongMa[this->pSP->getSoLuongSP() + 1];
            bool check[32];
            for (int i = 0; i < 32; i++)
            {
                check[i] = true;
            }
            for (int i = 0; i < this->pSP->getSoLuongSP() + 1; i++)
            {
                arrMa[i] = "NULL";
                soLuongMa[i] = 0;
            }
            int j = 0;
            while (pTemp)
            {
                Date dateTemp = pTemp->getData().getNgayIn();
                if (date.getThang() == dateTemp.getThang() && date.getNam() == dateTemp.getNam() && check[dateTemp.getNgay()])
                {
                    check[dateTemp.getNgay()] = false;
                    this->thongKeSanPhamNgay(dateTemp, arrMa, soLuongMa, j);
                }
                pTemp = pTemp->getpNext();
            }
            long long totalPrices = 0;
            long long totalPricesIn = 0;
            for (int i = 0; i < this->pSP->getSoLuongSP() + 1; i++)
            {
                if (arrMa[i] == "NULL")
                    break;
                long long pricesSP = 0;
                long long pricesSPIn = 0;
                List<SanPham> *listSP = pSP->getQLSP();
                Node<SanPham> *spTemp = listSP->getpHead();
                while (spTemp)
                {
                    if (spTemp->getData().getMaSP() == arrMa[i])
                    {
                        pricesSP = (spTemp->getData().getDonGiaSP() * (1 - spTemp->getData().getGiamGiaSP() / 100) * soLuongMa[i]);
                        pricesSPIn = spTemp->getData().getGiaNhapSP() * soLuongMa[i];
                        totalPrices += pricesSP;
                        totalPricesIn += pricesSPIn;
                    }
                    spTemp = spTemp->getpNext();
                }
                cout << arrMa[i] << " - " << soLuongMa[i] << " - " << pricesSP << endl;
            }
            cout << "Tong doanh thu: " << totalPrices << endl;
            cout << "Tong loi nhuan: " << totalPrices - totalPricesIn << endl;
            system("pause");
            QLHoaDon::thongKeSanPham();
        }
        break;
        case 3:
            check = false;
            break;
        }
    }
}
