
#include "..\..\..\Class\QLNhanVien.h"
#include <fstream>
#include <string.h>
#include <algorithm>
#include <iostream>

using namespace std;

QLNhanVien::QLNhanVien()
{
    this->QLNV = new List<NhanVien>();
    this->n = 0;
}

QLNhanVien::~QLNhanVien()
{
    this->QLNV->~List();
}

void QLNhanVien::nhapTuFile(fstream &fileNhanVien)
{
    fileNhanVien >> this->n;
    fileNhanVien.ignore(1);
    for (int i = 0; i < this->n; i++)
    {
        NhanVien temp;
        temp.docFile(fileNhanVien);
        this->QLNV->push_back(temp);
    }
}

void QLNhanVien::ghiVaoFile(fstream &fileNhanVien)
{
    fileNhanVien << this->n << endl;
    Node<NhanVien> *pTemp = this->QLNV->getpHead();
    while (pTemp)
    {
        pTemp->getData().ghiFile(fileNhanVien);
        pTemp = pTemp->getpNext();
    }
}

void QLNhanVien::addNhanVien()
{

    cout << "\tNhap chuc vu cua nhan vien muon them: " << endl;
    cout << "\t1. Nhan Vien" << endl;
    cout << "\t2. Quan li" << endl;
    cout << "\tNhap lua chon cua ban: ";
    int op;
    cin >> op;

    switch (op)
    {
    case 1:
    {
        bool checktrue = false;
        // sinh ra ma cua nhan vien
        // int temp;
        int max = 0, temp;
        while (checktrue == false)
        {
            srand(time(0));
            max = 1001 + rand() % 999;
            checktrue = true;
            Node<NhanVien> *pTemp = this->QLNV->getpHead();
            for (int i = 0; i < this->n; i++)
            {
                temp = pTemp->getData().getMaNhanVien();

                if (max == temp)
                {
                    checktrue = false;
                    break;
                }

                pTemp = pTemp->getpNext();
            }
        }
        string t;
        cout << "\tNhap ten: ";
        cin.ignore();
        getline(cin, t);

        cout << "\tNhap gioi tinh: \n";
        cout << "\t1. Nam\n";
        cout << "\t2. Nu\n";
        cout << "\t0. Khac" << endl;
        cout << "\tNhap lua chon cua ban: ";
        int gt;
        cin >> gt;

        cout << "\tNhap ca lam: ";
        cin.ignore();
        string ca;
        getline(cin, ca);
        cout << "\tNhap dia chi: ";
        string dc;
        fflush(stdin);
        getline(cin, dc);
        cout << "\tNhap mat khau: ";
        string mk;
        fflush(stdin);
        getline(cin, mk);
        NhanVien pAdd = NhanVien(max, t, gt, op, ca, dc, mk);
        this->QLNV->push_back(pAdd);
        this->n++;
        cout << "\tBan da cap nhat thanh cong !!!\n";
        fstream fileNhanVien;
        fileNhanVien.open("Data/NhanVien.DAT", ios_base::out);
        this->ghiVaoFile(fileNhanVien);
        fileNhanVien.close();
        break;
    }
    case 2:
    {
        // sinh ra ma cua nhan vien
        bool checktrue = false;
        // sinh ra ma cua nhan vien
        // int temp;
        int max = 0, temp;
        while (checktrue == false)
        {
            srand(time(0));
            max = 2001 + rand() % 999;
            checktrue = true;
            Node<NhanVien> *pTemp = this->QLNV->getpHead();
            for (int i = 0; i < this->n; i++)
            {
                temp = pTemp->getData().getMaNhanVien();

                if (max == temp)
                {
                    checktrue = false;
                    break;
                }

                pTemp = pTemp->getpNext();
            }
        }
        string t;
        cout << "\tNhap ten: ";
        cin.ignore();
        getline(cin, t);

        cout << "\tNhap gioi tinh: \n";
        cout << "\t1. Nam\n";
        cout << "\t2. Nu\n";
        cout << "\t0. Khac" << endl;
        cout << "\tNhap lua chon cua ban: ";

        int gt;
        cin >> gt;

        cout << "\tNhap ca lam: ";
        cin.ignore();
        string ca;
        getline(cin, ca);
        cout << "\tNhap dia chi: ";
        string dc;
        fflush(stdin);
        getline(cin, dc);
        cout << "\tNhap mat khau: ";
        string mk;
        fflush(stdin);
        getline(cin, mk);
        NhanVien pAdd = NhanVien(max + 1, t, gt, op, ca, dc, mk);
        this->QLNV->push_back(pAdd);
        this->n++;
        cout << "\tBan da cap nhat thanh cong !!!\n";
        fstream fileNhanVien;
        fileNhanVien.open("Data/NhanVien.DAT", ios_base::out);
        this->ghiVaoFile(fileNhanVien);
        fileNhanVien.close();
        break;
    }
    default:
        break;
    }
}

void QLNhanVien::TimKiemNhanVien()
{
    string str;
    cout << "Nhap ten nhan vien can tim: ";
    cin.ignore();
    getline(cin, str);
    Node<NhanVien> *pTemp = this->QLNV->getpHead();
    int i = 1;
    // // chuyen string thanh char* va ghi hoa
    // for (auto &c : str)
    //     c = toupper(c);
    // int strLength = str.length();
    // char strSub[strLength + 1];
    // strcpy(strSub, str.c_str());
    // Tim
    while (pTemp != NULL)
    {
        string strTemp = pTemp->getData().getHoTenNV();

        // // chuyen string thanh char* va ghi hoa
        // for (auto &c : strTemp)
        //     c = toupper(c);
        // int strTempLength = strTemp.length();
        // char strParent[strTempLength + 1];
        // strcpy(strParent, strTemp.c_str());
        // // Tim chuoi strSub trong strParent
        // char *first;
        // first = strstr(strParent, strSub);
        // if (first)
        // {
        //     cout << i++ << ". ";
        //     pTemp->getData().xuat();
        //     cout << endl;
        // }
        if (findString(strTemp, str) != -1)
        {
            cout << i++ << ". ";
            pTemp->getData().xuat();
            cout << endl;
        }
        pTemp = pTemp->getpNext();
    }
}

void QLNhanVien::xoaNhanVien()
{
    this->TimKiemNhanVien();
    int temp;
    cout << "\tNhap ma nhan vien muon xoa: ";
    cin >> temp;
    int index = -1;
    Node<NhanVien> *pTemp = this->QLNV->getpHead();

    for (int i = 0; i < this->n; i++)
    {
        if (pTemp->getData().getMaNhanVien() == temp)
        {
            index = i;
            break;
        }
        pTemp = pTemp->getpNext();
    }

    if (index == -1)
    {
        cout << "Khong ton tai ma nhan vien " << temp << "nay\n";
    }
    else
    {
        printWarning("Ban co chan chan muon xoa nhan vien nay khong? (y/n): ");
        char c;
        fflush(stdin);
        c = getchar();
        if (c == 'y')
        {
            this->n--;
            this->QLNV->deleteNode(index);
            cout << "Da xoa thanh cong nhan vien co ma la " << temp << endl;
            fstream fileNhanVien;
            fileNhanVien.open("Data/NhanVien.DAT", ios_base::out);
            this->ghiVaoFile(fileNhanVien);
            fileNhanVien.close();
        }
    }
    // system("pause");
}

void QLNhanVien::ChinhSua()
{
    string str;
    cout << "Nhap ten nhan vien can chinh sua: ";
    cin.ignore();
    getline(cin, str);
    Node<NhanVien> *pTemp = this->QLNV->getpHead();
    int i = 1;
    // chuyen string thanh char* va ghi hoa
    for (auto &c : str)
        c = toupper(c);
    int strLength = str.length();
    char strSub[strLength + 1];
    strcpy(strSub, str.c_str());
    // Tim
    int j = 1;
    while (pTemp != NULL)
    {
        string strTemp = pTemp->getData().getHoTenNV();
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
            cout << j++ << ". ";
            pTemp->getData().xuat();
        }
        i++;
        pTemp = pTemp->getpNext();
    }

    cout << "\t \t Nhap ma nhan vien ban muon sua: ";
    int temp;
    cin >> temp;
    Node<NhanVien> *pTemp2 = this->QLNV->getpHead();

    for (int i = 0; i < this->n; i++)
    {
        if (pTemp2->getData().getMaNhanVien() == temp)
            break;
        pTemp2 = pTemp2->getpNext();
    }

    if (pTemp2 == NULL)
        cout << "\t Khong ton tai ma nhan vien nay";
    else
    {
        int op;
        bool check = true;
        while (check)
        {

            cout << "\tNhap muc muon chinh sua cua nhan vien co ma " << temp << endl;
            cout << "\t1. Ho Ten Nhan Vien";
            cout << "\t2. Gioi Tinh";
            cout << "\t3. Ca Lam Viec";
            cout << "\t4. Mat khau";
            cout << "\t5. Xoa nhan vien";
            cout << "\t0. Thoat";
            // cin.ignore();
            cout << "\n\tNhap lua chon: ";
            cin >> op;
            switch (op)
            {
            case 1:
            {
                string t;
                cout << "\tNhap ten moi: ";
                cin.ignore();
                getline(cin, t);
                NhanVien *pChange = new NhanVien(pTemp2->getData());
                pChange->setHoTenNV(t);
                pTemp2->setData(*pChange);
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
                NhanVien *pChange = new NhanVien(pTemp2->getData());
                pChange->setGioiTinh(t);
                pTemp2->setData(*pChange);
                cout << "\tDa thay doi gioi tinh thanh cong: ";
                break;
            }
            case 3:
            {
                string t;
                cout << "\tNhap ca lam viec moi: ";
                cin.ignore();
                getline(cin, t);

                NhanVien *pChange = new NhanVien(pTemp2->getData());
                pChange->setCaLamViec(t);
                pTemp2->setData(*pChange);
                cout << "\tDa thay ca lam viec thanh cong: ";
                break;
            }
            case 4:
            {
                string t;
                cout << "\tNhap mat khau moi: ";
                cin.ignore();
                getline(cin, t);
                NhanVien *pChange = new NhanVien(pTemp2->getData());
                pChange->setMatKhau(t);
                pTemp2->setData(*pChange);
                cout << "\tDa thay doi mat khau thanh cong: ";
                fstream fileNhanVien;
                break;
            }
            case 5:
            {
                int index;
                Node<NhanVien> *pDel = this->QLNV->getpHead();
                for (int i = 0; i < this->n; i++)
                {
                    if (pDel == pTemp)
                        index = i;
                }

                this->QLNV->deleteNode(index);
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
                break;
            }
            fstream fileNhanVien;
            fileNhanVien.open("Data/NhanVien.DAT", ios_base::out);
            this->ghiVaoFile(fileNhanVien);
            fileNhanVien.close();
        }
    }
}

void QLNhanVien::sortAZ()
{
    Node<NhanVien> *pTemp1 = this->QLNV->getpHead();
    Node<NhanVien> *pTemp2 = nullptr;
    NhanVien Temp;

    for (; pTemp1 != nullptr; pTemp1 = pTemp1->getpNext())
    {
        for (pTemp2 = pTemp1->getpNext(); pTemp2 != nullptr; pTemp2 = pTemp2->getpNext())
        {
            if (pTemp1->getData().getHoTenNV().compare(pTemp2->getData().getHoTenNV()) != 0)
            {
                Temp = pTemp1->getData();
                pTemp1->setData(pTemp2->getData());
                pTemp2->setData(Temp);
            }
        }
    }
}

void QLNhanVien::sortID()
{
    Node<NhanVien> *pTemp1 = this->QLNV->getpHead();
    Node<NhanVien> *pTemp2 = nullptr;
    NhanVien Temp;

    for (; pTemp1 != nullptr; pTemp1 = pTemp1->getpNext())
    {
        for (pTemp2 = pTemp1->getpNext(); pTemp2 != nullptr; pTemp2 = pTemp2->getpNext())
        {
            // cout << pTemp1->getData().getMaNhanVien() << " " << pTemp2->getData().getMaNhanVien() << endl;
            if (pTemp1->getData().getMaNhanVien() > pTemp2->getData().getMaNhanVien())
            {
                Temp = pTemp1->getData();
                pTemp1->setData(pTemp2->getData());
                pTemp2->setData(Temp);
            }
        }
    }
}

void QLNhanVien::inRaManHinh()
{
    Node<NhanVien> *pTemp = this->QLNV->getpHead();
    cout << setfill('=') << setw(125) << " " << endl;
    cout << setfill(' ') << "|| " << setw(13) << left << "Ma nhan vien"
         << "|| " << setw(30) << left << "Ho ten nhan vien"
         << "|| " << setw(13) << left << "Gioi tinh"
         << "|| " << setw(9) << left << "Chuc vu"
         << "|| " << setw(14) << left << "Ca lam viec"
         << "|| " << setw(25) << left << "Dia chi nhan vien"
         << "||" << endl;
    while (pTemp != nullptr)
    {
        pTemp->getData().xuatthanhbang();
        // cout << endl;
        pTemp = pTemp->getpNext();
    }
    cout << setfill('=') << setw(125) << right << " " << endl;
}
