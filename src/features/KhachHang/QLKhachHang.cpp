#include "..\..\..\Class\QLKhachHang.h"
#include <string.h>
#include <algorithm>
#include <fstream>
QLKhachHang::QLKhachHang()
{
    this->QLKH = new List<KhachHang>();
    this->count = 0;
}

QLKhachHang::~QLKhachHang()
{
    this->QLKH->~List();
}

void QLKhachHang::nhapTuFile(fstream &fileKhachHang)
{
    fileKhachHang >> this->count;
    fileKhachHang.ignore(1);
    for (int i = 0; i < this->count; i++)
    {
        KhachHang temp;
        temp.docFile(fileKhachHang);
        this->QLKH->push_back(temp);
    }
}

void QLKhachHang::ghiVaoFile(fstream &fileKhachHang)
{
    fileKhachHang << this->count << endl;
    Node<KhachHang> *pTemp = this->QLKH->getpHead();
    while (pTemp)
    {
        pTemp->getData().ghiFile(fileKhachHang);
        pTemp = pTemp->getpNext();
    }
}

void QLKhachHang::addKhachHang()
{
    bool checktrue = false;
    // sinh ra ma cua nhan vien
    // int temp;
    int max = 0, temp;
    // for (int i = 0; i < this->n; i++)
    // {
    //     temp = pTemp->getData().getMaNhanVien();

    //     if (max < pTemp->getData().getMaNhanVien() && pTemp->getData().getMaNhanVien() < 2000)
    //         max = pTemp->getData().getMaNhanVien();

    //     pTemp = pTemp->getpNext();
    // }
    while (checktrue == false)
    {
        srand(time(0));
        max = rand() % 1000;
        checktrue = true;

        Node<KhachHang> *pTemp = this->QLKH->getpHead();
        for (int i = 0; i < this->count; i++)
        {
            temp = pTemp->getData().getMaKhachHang();

            if (max == temp)
            {
                checktrue = false;
                break;
            }

            pTemp = pTemp->getpNext();
        }
    }
    string t;
    cout << "\tNhap ten khach hang: ";
    fflush(stdin);
    getline(cin, t);

    cout << "\tNhap gioi tinh: \n";
    cout << "\t1. Nam\n";
    cout << "\t2. Nu\n";
    cout << "\t0. Khac" << endl;
    cout << "\tNhap lua chon cua ban: ";
    int gt;
    cin >> gt;

    cout << "\tNhap dia chi khach hang: ";
    string dc;
    fflush(stdin);
    getline(cin, dc);

    cout << "\tNhap so dien thoai khach hang: ";
    string sdt;
    fflush(stdin);
    getline(cin, sdt);

    KhachHang *pAdd = new KhachHang(max + 1, gt, t, dc, sdt);
    this->QLKH->push_back(*pAdd);
    this->count++;

    cout << "\tBan da them thanh cong\n";
    fstream fileKhachHang;
    fileKhachHang.open("Data/KhachHang.DAT", ios_base::out);
    this->ghiVaoFile(fileKhachHang);
    fileKhachHang.close();
}
void QLKhachHang::timKiemKhachHang()
{
    string str;
    cout << "Nhap ten nhan vien can tim: ";
    fflush(stdin);
    getline(cin, str);
    Node<KhachHang> *pTemp = this->QLKH->getpHead();
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
        string strTemp = pTemp->getData().getHoTenKH();
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
const int QLKhachHang::timKiemKHTheoSDT(const string &sdt)
{
    Node<KhachHang> *pTemp = this->QLKH->getpHead();

    for (int i = 0; i < this->count; i++)
    {
        if (pTemp->getData().getSoDienThoaiKH().compare(sdt) == 0)
        {
            return pTemp->getData().getMaKhachHang();
        }
        pTemp = pTemp->getpNext();
    }
    return -1;
}

void QLKhachHang::chinhSua()
{
    string str;
    cout << "Nhap ten nhan vien can chinh sua: ";
    fflush(stdin);
    getline(cin, str);
    Node<KhachHang> *pTemp = this->QLKH->getpHead();
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
        string strTemp = pTemp->getData().getHoTenKH();
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
            cout << i + 1 << ". ";
            pTemp->getData().xuat();
        }
        i++;
        pTemp = pTemp->getpNext();
    }

    cout << "\t \t Nhap ma khach hang ban muon sua: ";
    int temp;
    cin >> temp;

    pTemp = this->QLKH->getpHead();

    for (int i = 0; i < this->count; i++)
    {
        if (pTemp->getData().getMaKhachHang() == temp)
            break;

        pTemp = pTemp->getpNext();
    }

    if (pTemp == NULL)
    {
        cout << "\t Khong ton tai ma khach hang nay";
    }
    else
    {
        int op;
        bool check = true;
        while (check)
        {
            cout << "\tBan dang chinh sua cho khach hang ma: " << pTemp->getData().getMaKhachHang() << endl;
            pTemp->getData().xuat();
            cout << endl
                 << endl;
            cout << "\tNhap muc muon chinh sua cua khach hang co ma " << temp << endl;
            cout << "\t1. Ho Ten khach hang";
            cout << "\t2. Gioi Tinh";
            cout << "\t3. So dien thoai";
            cout << "\t4. Dia chi";
            cout << "\t5. Xoa khach hang";
            cout << "\t0. Thoat";
            cout << endl
                 << "Ban nhap: ";
            cin >> op;
            switch (op)
            {
            case 1:
            {
                string t;
                cout << "\tNhap ten moi: ";
                cin.ignore();
                getline(cin, t);
                KhachHang *pChange = new KhachHang(pTemp->getData());
                pChange->setHoTenKH(t);
                pTemp->setData(*pChange);
                cout << "\tDa thay doi ten thanh cong: ";
                break;
            }
            case 2:
            {
                int t;
                cout << "\tNhap gioi tinh";
                cout << "\t1. Nam\n";
                cout << "\t2. Nu\n";
                cout << "\t0. Khac" << endl;
                cout << "\tNhap lua chon cua ban: ";
                cin >> t;
                KhachHang *pChange = new KhachHang(pTemp->getData());
                pChange->setGioiTinhKH(t);
                pTemp->setData(*pChange);
                cout << "\tDa thay doi gioi tinh thanh cong: ";
                break;
            }
            case 3:
            {
                string t;
                cout << "\tNhap so dien thoai moi: ";
                fflush(stdin);
                getline(cin, t);

                KhachHang *pChange = new KhachHang(pTemp->getData());
                pChange->setSoDienThoaiKH(t);
                pTemp->setData(*pChange);
                cout << "\tDa thay doi so dien thoai thanh cong: ";
                break;
            }
            case 4:
            {
                string t;
                cout << "\tNhap dia chi moi: ";
                cin.ignore();
                getline(cin, t);
                KhachHang *pChange = new KhachHang(pTemp->getData());
                pChange->setDiaChiKH(t);
                pTemp->setData(*pChange);
                cout << "\tDa thay doi dia chi thanh cong: ";
                break;
            }
            case 5:
            {
                int index;
                Node<KhachHang> *pDel = this->QLKH->getpHead();
                for (int i = 0; i < this->count; i++)
                {
                    if (pDel == pTemp)
                        index = i;
                }

                this->QLKH->deleteNode(index);
                cout << "\tDa xoa nhan vien thanh cong: ";
                break;
            }
            case 0:
            {
                check = false;
                break;
            }
            default:

                cout << "\tBan nhap sai yeu cau: ";
                check = true;
                break;
            }
            fstream fileKhachHang;
            fileKhachHang.open("Data/KhachHang.DAT", ios_base::out);
            this->ghiVaoFile(fileKhachHang);
            fileKhachHang.close();
        }
    }
}

void QLKhachHang::sortAZ()
{
    Node<KhachHang> *pTemp1 = this->QLKH->getpHead();
    Node<KhachHang> *pTemp2 = nullptr;
    KhachHang Temp;

    for (; pTemp1 != nullptr; pTemp1 = pTemp1->getpNext())
    {
        for (pTemp2 = pTemp1->getpNext(); pTemp2 != nullptr; pTemp2 = pTemp2->getpNext())
        {
            if (pTemp1->getData().getHoTenKH().compare(pTemp2->getData().getHoTenKH()) != 0)
            {
                Temp = pTemp1->getData();
                pTemp1->setData(pTemp2->getData());
                pTemp2->setData(Temp);
            }
        }
    }
}
void QLKhachHang::sortID()
{
    Node<KhachHang> *pTemp1 = this->QLKH->getpHead();
    Node<KhachHang> *pTemp2 = nullptr;
    KhachHang Temp;

    for (; pTemp1 != nullptr; pTemp1 = pTemp1->getpNext())
    {
        for (pTemp2 = pTemp1->getpNext(); pTemp2 != nullptr; pTemp2 = pTemp2->getpNext())
        {
            // cout << pTemp1->getData().getMaNhanVien() << " " << pTemp2->getData().getMaNhanVien() << endl;
            if (pTemp1->getData().getMaKhachHang() > pTemp2->getData().getMaKhachHang())
            {
                Temp = pTemp1->getData();
                pTemp1->setData(pTemp2->getData());
                pTemp2->setData(Temp);
            }
        }
    }
}

void QLKhachHang::inRaManHinh()
{
    Node<KhachHang> *pTemp = this->QLKH->getpHead();
    cout << setfill('=') << setw(113) << " " << endl;
    cout << setfill(' ') << "|| " << setw(13) << left << "Ma khach hang"
         << "|| " << setw(30) << left << "Ho ten khach hang"
         << "|| " << setw(13) << left << "Gioi tinh"
         << "|| " << setw(14) << left << "So dien thoai"
         << "|| " << setw(25) << left << "Dia chi khach hang"
         << "||" << endl;
    while (pTemp != nullptr)
    {
        pTemp->getData().xuatThanhBang();
        // cout << endl;
        pTemp = pTemp->getpNext();
    }
    cout << setfill('=') << setw(113) << right << " " << endl;
}
