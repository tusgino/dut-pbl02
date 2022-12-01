#include "..\..\..\class\QLKhachHang.h"

QLKhachHang::QLKhachHang()
{
    this->dbKH = new List<KhachHang>();
    this->count = 0;
}

QLKhachHang::~QLKhachHang()
{
    this->dbKH->~List();
}

void QLKhachHang::docFile(fstream &fileIn)
{
    fileIn >> this->count;
    fileIn.ignore(1);
    for (int i = 0; i < this->count; i++)
    {
        KhachHang *KH = new KhachHang;
        KH->docFile(fileIn);
        this->dbKH->push_back(*KH);
        delete KH;
    }
}

void QLKhachHang::ghiFile(fstream &fileOut)
{
    fileOut << this->count << endl;
    Node<KhachHang> *pTemp = this->dbKH->getpHead();
    while (pTemp)
    {
        pTemp->getData().ghiFile(fileOut);
        fileOut << endl;
        pTemp = pTemp->getpNext();
    }
}

void QLKhachHang::create()
{
    string _sdt;
    cout << "Nhap so dien thoai can tim: ";
    fflush(stdin);
    getline(cin, _sdt);
    int index = QLKhachHang::findBySDT(_sdt);
    if (index == -1)
    {
        KhachHang _KHAdd;
        int soTT = 0;
        // Tìm soTT của MaKH lớn nhất để sinh mã
        {
            Node<KhachHang> *pTemp = this->dbKH->getpHead();
            while (pTemp)
            {
                soTT = (pTemp->getData().getMa().getSoTT() > soTT) ? pTemp->getData().getMa().getSoTT() : soTT;
                pTemp = pTemp->getpNext();
            }
        }
        Ma tempMa("KH", soTT + 1);
        _KHAdd.setMa(tempMa);
        _KHAdd.setSoDienThoai(_sdt);
        _KHAdd.nhap(); // Nhập từ phím

        this->dbKH->push_back(_KHAdd);
        this->count++;
    }
    else
    {
        printError("So dien thoai nay da ton tai");
    }
}
void QLKhachHang::read()
{
    ConsoleTable table{"STT", "Ma khach hang", "Ten khach hang", "Dia chi", "So dien thoai"};
    Node<KhachHang> *pTemp = this->dbKH->getpHead();
    table.setPadding(2);
    table.setStyle(3);
    int cnt = 0;
    while (pTemp)
    {

        // pTemp->getData().xuatFullInfo();

        table += {to_string(++cnt), string(pTemp->getData().getMa()), pTemp->getData().getTen(), pTemp->getData().getDiaChi(), pTemp->getData().getSoDienThoai()};

        pTemp = pTemp->getpNext();
    }
    std::cout << table;
}
void QLKhachHang::update()
{
    string _sdt;
    cout << "Nhap so dien thoai can tim: ";
    fflush(stdin);
    getline(cin, _sdt);
    // Tìm kiếm khách hàng
    int index = QLKhachHang::findBySDT(_sdt);
    if (index == -1)
    {
        printError("Khong tim thay KHACH HANG da dang ki so dien thoai nay");
    }
    else
    {
        Node<KhachHang> *pTemp = this->dbKH->getpHead();
        for (int i = 0; i < index; i++)
        {
            pTemp = pTemp->getpNext();
        }
        while (true)
        {
            cout << "THONG TIN CUA KHACH HANG: " << endl;
            pTemp->getData().xuatFullInfo();

            {
                string arr[] = {"Cac lua chon de chinh sua",
                                "Ho ten ",
                                "Gioi Tinh",
                                "So dien thoai",
                                "Dia chi",
                                "Email", "Thoat chuong trinh"};
                printOpt(arr, 6);
            }
            int key = getKey(6);
            switch (key)
            {
            case 1:
            {
                string tempTen;
                cout << "Nhap ten moi: ";
                fflush(stdin);
                getline(cin, tempTen);

                if (tempTen.length() == 0)
                {
                    printError("Ten khach hang khong duoc de trong vui long thu lai");
                }
                else
                {
                    KhachHang _KH_repair = pTemp->getData();
                    _KH_repair.setTen(tempTen);

                    pTemp->setData(_KH_repair);
                    printSuccess("Da doi thong tin thanh cong!");
                }
            }
            break;
            case 2:
            {
                {
                    string arr[] = {"Nhap gioi tinh moi",
                                    "Nam",
                                    "Nu",
                                    "Khac", "Quay lai"};
                    printOpt(arr, 3);
                }
                int key = getKey(3);

                switch (key)
                {
                case 1:
                case 2:
                case 3:
                {
                    KhachHang _KH_repair = pTemp->getData();
                    _KH_repair.setGioiTinh(key);

                    pTemp->setData(_KH_repair);
                    printSuccess("Da doi thong tin thanh cong!");
                }
                break;
                case 4:
                    break;
                default:
                    printError("Ban nhap sai yeu cau. Vui long thu lai");
                    break;
                }
            }
            break;
            case 3:
            {
                string tempSDT;
                cout << "Nhap so dien thoai moi: ";
                fflush(stdin);
                getline(cin, tempSDT);

                if (tempSDT.length() == 0)
                {
                    printError("So dien thoai khach hang khong duoc de trong vui long thu lai");
                }
                else
                {
                    KhachHang _KH_repair = pTemp->getData();
                    _KH_repair.setSoDienThoai(tempSDT);

                    pTemp->setData(_KH_repair);
                    printSuccess("Da doi thong tin thanh cong!");
                }
            }
            break;
            case 4:
            {
                string tempDiaChi;
                cout << "Nhap dia chi moi: ";
                fflush(stdin);
                getline(cin, tempDiaChi);

                if (tempDiaChi.length() == 0)
                {
                    tempDiaChi = "(null)";
                    // printError("So dien thoai khach hang khong duoc de trong vui long thu lai");
                }

                KhachHang _KH_repair = pTemp->getData();
                _KH_repair.setDiaChi(tempDiaChi);

                pTemp->setData(_KH_repair);
                printSuccess("Da doi thong tin thanh cong!");
            }
            break;
            case 5:
            {
                string tempEmail;
                cout << "Nhap email moi: ";
                fflush(stdin);
                getline(cin, tempEmail);

                if (tempEmail.length() == 0)
                {
                    tempEmail = "(null)";
                    // printError("So dien thoai khach hang khong duoc de trong vui long thu lai");
                }

                KhachHang _KH_repair = pTemp->getData();
                _KH_repair.setEmail(tempEmail);

                pTemp->setData(_KH_repair);
                printSuccess("Da doi thong tin thanh cong!");
            }
            break;
            case 6:
                return;
            default:
                printError("Ban nhap sai yeu cau. Vui long thu lai");
                system("pause");
                break;
            }
        }
    }
}
void QLKhachHang::find()
{
    while (true)
    {
        {
            string arr[] = {"Cac lua chon de tim kiem",
                            "Tim kiem theo so dien thoai",
                            "Tim kiem theo ten"};
            printOpt(arr, 2);
        }
        int key = getKey(2);
        switch (key)
        {
        case 1:
        {
            string _sdt;
            cout << "Nhap so dien thoai can tim: ";
            fflush(stdin);
            getline(cin, _sdt);

            Node<KhachHang> *pTemp = this->dbKH->getpHead();
            while (pTemp)
            {
                if (pTemp->getData().getSoDienThoai() == _sdt)
                {
                    pTemp->getData().xuatFullInfo();
                    return;
                }
                pTemp = pTemp->getpNext();
            }

            printError("Khong tim thay KHACH HANG da dang ki so dien thoai nay");
        }
        break;
        case 2:
        {
            string str;
            cout << "Nhap ten khach hang cang tim: ";
            cin.ignore(1);
            fflush(stdin);
            getline(cin, str);
            Node<KhachHang> *pTemp = this->dbKH->getpHead();

            ConsoleTable table{"Ma khach hang", "Ten khach hang", "Dia chi", "So dien thoai"};

            table.setPadding(2);
            table.setStyle(0);
            while (pTemp)
            {
                if (findString(pTemp->getData().getTen(), str) != -1)
                {
                    // pTemp->getData().xuatFullInfo();

                    table += {string(pTemp->getData().getMa()), pTemp->getData().getTen(), pTemp->getData().getDiaChi(), pTemp->getData().getSoDienThoai()};
                }
                pTemp = pTemp->getpNext();
            }
            std::cout << table;
        }
        break;
        case 0:
            return;
        default:
            printError("Ban nhap sai yeu cau. Vui long thu lai");
            system("pause");
            break;
        }
    }
}

int QLKhachHang::findBySDT(const string &sdt)
{
    int index = 0;
    Node<KhachHang> *pTemp = this->dbKH->getpHead();
    while (pTemp)
    {
        if (pTemp->getData().getSoDienThoai() == sdt)
        {
            return index;
        }
        index++;
        pTemp = pTemp->getpNext();
    }
    return -1;
}

const Ma QLKhachHang::findBySDTReturnMa(const string &sdt){
    static Ma _maRac("null", -1); // Mã rác
    Node<KhachHang> *pTemp = this->dbKH->getpHead();
    while (pTemp)
    {
        if (pTemp->getData().getSoDienThoai() == sdt)
        {
            return pTemp->getData().getMa();
        }
        // index++;
        pTemp = pTemp->getpNext();
    }

    return _maRac;
}

void xuatFile()
{
    fstream fileXuatKH;
    fileXuatKH.open("/src/components/data/file_KH.DAT");
}

void QLKhachHang::sortMa()
{
    Node<KhachHang> *pBefore = this->dbKH->getpHead();
    Node<KhachHang> *pAfter = pBefore->getpNext();
    while (pBefore)
    {
        pAfter = pBefore->getpNext();
        while (pAfter)
        {
            if (pBefore->getData().getMa() >= pAfter->getData().getMa())
            {
                KhachHang pTemp = pBefore->getData();
                pBefore->setData(pAfter->getData());
                pAfter->setData(pTemp);
            }
            pAfter = pAfter->getpNext();
        }
        pBefore = pBefore->getpNext();
    }
    printSuccess("Da sap xep thanh cong!");
}

void QLKhachHang::deleteIndex()
{
    string _sdt;
    cout << "Nhap so dien thoai can tim: ";
    fflush(stdin);
    getline(cin, _sdt);

    int index = QLKhachHang::findBySDT(_sdt);
    if (index == -1)
    {
        printError("Khong tim thay KHACH HANG da dang ki so dien thoai nay");
    }
    else
    {
        if (false)
        {
        }
        else
        {
            Node<KhachHang> *pTemp = this->dbKH->getpHead();
            while (true)
            {

                if (pTemp->getData().getSoDienThoai() == _sdt)
                {
                    break;
                }
                pTemp = pTemp->getpNext();
            }
            printWarning("Ban se xoa khach hang nay!");
            cout << endl << endl;

            pTemp->getData().xuatFullInfo();

            printRes("Ban co chac chan khong?(y: dong y/'ki tu bat ki': huy): ");
            char c;
            fflush(stdin);
            c = getchar();

            if (c == 'y' || c == 'Y')
            {
                this->dbKH->deleteNode(index);
                printSuccess("Da xoa thanh cong!");
            }
            else
            {
                return;
            }
        }
    }
}