#include "..\..\..\class\QLNhanVien.h"

QLNhanVien::QLNhanVien()
{
    this->dbNV = new List<NhanVien>();
    this->count = 0;
}

QLNhanVien::~QLNhanVien()
{
    this->dbNV->~List();
}

void QLNhanVien::docFile(fstream &fileIn)
{
    fileIn >> this->count;
    fileIn.ignore(1);
    for (int i = 0; i < this->count; i++)
    {
        NhanVien *NV = new NhanVien;
        NV->docFile(fileIn);
        fileIn.ignore(1);
        this->dbNV->push_back(*NV);
        delete NV;
    }
}

void QLNhanVien::ghiFile(fstream &fileOut)
{
    fileOut << this->count << endl;
    Node<NhanVien> *pTemp = this->dbNV->getpHead();
    while (pTemp)
    {
        pTemp->getData().ghiFile(fileOut);
        fileOut << endl;
        pTemp = pTemp->getpNext();
    }
}

void QLNhanVien::create()
{
    while (true)
    {
        {
            string arr[] = {"Nhap chuc vu cua nhan vien muon them", "Quan li", "Nhan vien", "Quay lai"};
            printOpt(arr, 3);
        }
        int key = getKey(3);
        switch (key)
        {
        case 1:
        {
            NhanVien _NVAdd;
            int soTT = 0;
            {
                Node<NhanVien> *pTemp = this->dbNV->getpHead();
                while (pTemp)
                {
                    soTT = (pTemp->getData().getMa().getKiTu() == "NV" && pTemp->getData().getMa().getSoTT() > soTT) ? pTemp->getData().getMa().getSoTT() : soTT;
                    pTemp = pTemp->getpNext();
                }
            }
            Ma tempMa("NV", soTT + 1);
            _NVAdd.setMa(tempMa);
            _NVAdd.nhap();

            this->dbNV->push_back(_NVAdd);
            this->count++;
            printSuccess("Ban da them thanh cong mot nhan vien!");
        }
        break;
        case 2:
        {
            NhanVien _NVAdd;
            int soTT = 0;
            {
                Node<NhanVien> *pTemp = this->dbNV->getpHead();
                while (pTemp)
                {
                    soTT = (pTemp->getData().getMa().getKiTu() == "QL" && pTemp->getData().getMa().getSoTT() > soTT) ? pTemp->getData().getMa().getSoTT() : soTT;
                    pTemp = pTemp->getpNext();
                }
            }
            Ma tempMa("QL", soTT + 1);
            _NVAdd.setMa(tempMa);
            _NVAdd.nhap();

            this->dbNV->push_back(_NVAdd);
            this->count++;
            printSuccess("Ban da them thanh cong mot quan li!");
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
}

void QLNhanVien::update()
{

    {
        string temp;
        printRes("Nhap ma hoac so dien thoai cua nhan vien muon thay doi thong tin");
        fflush(stdin);
        getline(cin, temp);
        bool checkMa = false, checkSDT = false;
        Node<NhanVien> *pTemp = this->dbNV->getpHead();
        while (pTemp)
        {
            if (string(pTemp->getData().getMa()) == temp)
            {
                checkMa = true;
                break;
            }
            pTemp = pTemp->getpNext();
        }
        pTemp = this->dbNV->getpHead();
        while (pTemp)
        {
            if ((pTemp->getData().getSoDienThoai()) == temp)
            {
                checkSDT = true;
                break;
            }
            pTemp = pTemp->getpNext();
        }

        pTemp = this->dbNV->getpHead();
        while (pTemp)
        {
            if (string(pTemp->getData().getMa()) == temp)
            {
                checkMa == true;
                break;
            }
            pTemp = pTemp->getpNext();
        }

        if (checkMa == true)
        {
            printSuccess("Da tim thay nhan vien co ma nay");
        }
        else if (checkMa == true)
        {
            printSuccess("Da tim thay nhan vien co so dien thoai nay");
        }
        NhanVien _NVRepair = pTemp->getData();
        while (true)
        {
            // pTemp->getData().xuatFullInfo();
            _NVRepair.xuatFullInfo();

            {
                string arr[] = {"Nhap thong tin can chinh sua", "Ten nhan vien", "Chuc vu", "So dien thoai", "Dia chi", "Ca lam", "Gioi tinh", "Quay lai"};

                printOpt(arr, 7);
            }

            int key = getKey(7);
            switch (key)
            {
            case 1:
            {
                cout << "Nhap ten nhan vien nay: ";
                string temp;
                fflush(stdin);
                getline(cin, temp);
                if (temp.length() == 0)
                {
                    printError("Ten nhan vien ko the de trong");
                }
                else
                {
                    _NVRepair.setTen(temp);
                    pTemp->setData(_NVRepair);

                    printSuccess("Ban da thay doi ten thanh cong cua nhan vien nay");
                }
            }
            break;
            case 2:
            {
                // NhanVien _NVRepair;
                // _NVRepair = pTemp->getData();
                if (_NVRepair.getMa().getKiTu() == "NV")
                {
                    Ma _maTemp("QL", pTemp->getData().getMa().getSoTT());
                    // _NVRepair.setMa(_maTemp);
                    Node<NhanVien> *pFind = this->dbNV->getpHead();
                    bool checkMa = true;
                    while (pFind)
                    {
                        if (pFind->getData().getMa() == _maTemp)
                        {
                            checkMa = false;
                            break;
                        }
                        pFind = pFind->getpNext();
                    }
                    if (checkMa == false)
                    {
                        int soTT = 0;
                        while (pFind)
                        {
                            if (pFind->getData().getMa().getKiTu() == "QL" && pFind->getData().getMa().getSoTT() >= soTT)
                            {
                                soTT = pFind->getData().getMa().getSoTT();
                            }
                            pFind = pFind->getpNext();
                        }
                        _maTemp.setSoTT(soTT + 1);
                    }
                    _NVRepair.setMa(_maTemp);
                    pTemp->setData(_NVRepair);
                    printSuccess("Da thay doi chuc vu thanh cong");
                }
                else
                {
                    Ma _maTemp("NV", pTemp->getData().getMa().getSoTT());
                    // _NVRepair.setMa(_maTemp);
                    Node<NhanVien> *pFind = this->dbNV->getpHead();
                    bool checkMa = true;
                    while (pFind)
                    {
                        if (pFind->getData().getMa() == _maTemp)
                        {
                            checkMa = false;
                            break;
                        }
                        pFind = pFind->getpNext();
                    }
                    if (checkMa == false)
                    {
                        int soTT = 0;
                        while (pFind)
                        {
                            if (pFind->getData().getMa().getKiTu() == "NV" && pFind->getData().getMa().getSoTT() >= soTT)
                            {
                                soTT = pFind->getData().getMa().getSoTT();
                            }
                            pFind = pFind->getpNext();
                        }
                        _maTemp.setSoTT(soTT + 1);
                    }
                    _NVRepair.setMa(_maTemp);
                    pTemp->setData(_NVRepair);
                    printSuccess("Da thay doi chuc vu thanh cong");
                }
            }
            break;
            case 3:
            {
                string _tempSDT;
                cout << "Nhap so dien thoai muon thay doi";
                fflush(stdin);
                getline(cin, _tempSDT);

                // NhanVien _NVRepair;
                // _NVRepair = pTemp->getData();
                if (_tempSDT.length() == 0)
                {
                    printError("So dien thoai khong the de trong. Vui long thu lai");
                }
                else
                {
                    _NVRepair.setSoDienThoai(_tempSDT);
                    pTemp->setData(_NVRepair);

                    printSuccess("Ban da thay doi so dien thoai cua nhan vien nay");
                }
                break;
            }
            case 4:
            {
                string _tempDiaChi;
                cout << "Nhap dia chi muon thay doi";
                fflush(stdin);
                getline(cin, _tempDiaChi);

                // NhanVien _NVRepair;
                // _NVRepair = pTemp->getData();
                if (_tempDiaChi.length() == 0)
                {
                    _tempDiaChi = "(null)";
                }
                _NVRepair.setDiaChi(_tempDiaChi);
                pTemp->setData(_NVRepair);
                printSuccess("Ban da thay doi dia chi cua nhan vien nay");
            }
            break;
            case 5:
            {
                // NhanVien _NVRepair;
                // _NVRepair = pTemp->getData();
                {
                    string arr[] = {"Nhap ca lam: ", "07h00 den 11h30", "13h30 den 18h00", "18h30 den 23h00"};
                    printOpt(arr, 3);

                    int key = getKey(3);
                    switch (key)
                    {
                    case 1:
                    case 2:
                    case 3:
                        _NVRepair.setCaLam(key);
                        break;
                    default:
                        _NVRepair.setCaLam(-1);
                        break;
                    }
                    pTemp->setData(_NVRepair);
                    printSuccess("Ban da thay doi ca lam cua nhan vien nay");
                }
            }
            break;
            case 6:
            {
                // NhanVien _NVRepair;
                // _NVRepair = pTemp->getData();
                {
                    string arr[] = {"Nhap gioi tinh", "Nam", "Nu", "Khac"};
                    printOpt(arr, 3);
                }
                int key = getKey(3);
                switch (key)
                {
                case 1:
                case 2:
                case 3:
                    _NVRepair.setGioiTinh(key);
                    break;
                default:
                    _NVRepair.setGioiTinh(-1);
                    break;
                }
                pTemp->setData(_NVRepair);
                printSuccess("Ban da thay doi gioi tinh cua nhan vien nay");
            }
            break;
            case 7:
                return;
                break;
            default:
                break;
            }
        }
    }
}

void QLNhanVien::read()
{
    if (this->dbNV->getpHead() == nullptr)
    {
        printError("Danh sach khach hang dang rong. Vui long them du lieu");
    }
    ConsoleTable table{"STT", "Ma nhan vien", "Ten nhan vien", "Dia chi", "So dien thoai"};
    Node<NhanVien> *pTemp = this->dbNV->getpHead();
    table.setPadding(2);
    table.setStyle(0);
    int cnt = 0;
    while (pTemp)
    {

        // pTemp->getData().xuatFullInfo();

        table += {to_string(++cnt), string(pTemp->getData().getMa()), pTemp->getData().getTen(), pTemp->getData().getDiaChi(), pTemp->getData().getSoDienThoai()};

        pTemp = pTemp->getpNext();
    }
    std::cout << table;
}

void QLNhanVien::sortMa()
{
    Node<NhanVien> *pBefore = this->dbNV->getpHead();
    Node<NhanVien> *pAfter = pBefore->getpNext();
    while (pBefore)
    {
        pAfter = pBefore->getpNext();
        while (pAfter)
        {
            if (pBefore->getData().getMa() >= pAfter->getData().getMa())
            {
                NhanVien pTemp = pBefore->getData();
                pBefore->setData(pAfter->getData());
                pAfter->setData(pTemp);
            }
            pAfter = pAfter->getpNext();
        }
        pBefore = pBefore->getpNext();
    }
    printSuccess("Da sap xep thanh cong!");
}

int QLNhanVien::findBySDT(const string &_sdt)
{
    int index = 0;
    Node<NhanVien> *pTemp = this->dbNV->getpHead();
    while (pTemp)
    {
        if (pTemp->getData().getSoDienThoai() == _sdt)
        {
            return index;
        }
        index++;
        pTemp = pTemp->getpNext();
    }
    return -1;
}

int QLNhanVien::findByMa(const string &_ma)
{
    int index = 0;
    Node<NhanVien> *pTemp = this->dbNV->getpHead();
    while (pTemp)
    {
        if (string(pTemp->getData().getMa()) == _ma)
        {
            return index;
        }
        index++;
        pTemp = pTemp->getpNext();
    }
    return -1;
}

void QLNhanVien::find()
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

            Node<NhanVien> *pTemp = this->dbNV->getpHead();
            while (pTemp)
            {
                if (pTemp->getData().getSoDienThoai() == _sdt)
                {
                    pTemp->getData().xuatFullInfo();
                    pauseScreen();
                    return;
                }
                pTemp = pTemp->getpNext();
            }

            printError("Khong tim thay Nhan vien nao so dien thoai nay");
        }
        break;
        case 2:
        {
            string str;
            printRes("Nhap ten khach hang can tim: ");
            // cin.ignore(1);
            fflush(stdin);
            getline(cin, str);
            Node<NhanVien> *pTemp = this->dbNV->getpHead();

            ConsoleTable table{"STT", "Ma nhan vien", "Ten nhan vien", "Dia chi", "So dien thoai"};
            int cnt = 0;
            table.setPadding(2);
            table.setStyle(0);
            while (pTemp)
            {
                if (findString(pTemp->getData().getTen(), str) != -1)
                {
                    // pTemp->getData().xuatFullInfo();

                    table += {to_string(++cnt), string(pTemp->getData().getMa()), pTemp->getData().getTen(), pTemp->getData().getDiaChi(), pTemp->getData().getSoDienThoai()};
                }
                pTemp = pTemp->getpNext();
            }
            std::cout << table;
            return;
        }
        break;
        case 0:
            return;
        default:
            printError("Ban nhap sai yeu cau. Vui long thu lai");
            // system("pause");
            break;
        }
    }
}

void QLNhanVien::deleteIndex()
{
    string temp;
    printRes("Nhap ma hoac so dien thoai cua nhan vien muon xoa");
    fflush(stdin);
    getline(cin, temp);
    bool checkMa = false, checkSDT = false;
    Node<NhanVien> *pTemp = this->dbNV->getpHead();
    while (pTemp)
    {
        if (string(pTemp->getData().getMa()) == temp)
        {
            checkMa == true;
            break;
        }
        pTemp = pTemp->getpNext();
    }
    pTemp = this->dbNV->getpHead();
    while (pTemp)
    {
        if ((pTemp->getData().getSoDienThoai()) == temp)
        {
            checkSDT = true;
            break;
        }
        pTemp = pTemp->getpNext();
    }

    pTemp = this->dbNV->getpHead();
    while (pTemp)
    {
        if (string(pTemp->getData().getMa()) == temp)
        {
            checkMa = true;
            break;
        }
        pTemp = pTemp->getpNext();
    }

    if (checkMa == true)
    {
        printSuccess("Da tim thay nhan vien co ma nay");
        int index = QLNhanVien::findByMa(temp);
        // cout << index;
        if (false)
        {
        }
        else
        {
            // Node<NhanVien> *pTemp = this->dbNV->getpHead();
            Node<NhanVien> *pTemp = this->dbNV->getpHead();
            while (pTemp)
            {
                if (string(pTemp->getData().getMa()) == temp)
                {
                    break;
                }
                pTemp = pTemp->getpNext();
            }

            printWarning("Ban se xoa nhan vien nay!");
            cout << endl
                 << endl;

            pTemp->getData().xuatFullInfo();

            printRes("Ban co chac chan khong?(y/n): ");
            char c;
            fflush(stdin);
            c = getchar();

            if (c == 'y' || c == 'Y')
            {
                this->dbNV->deleteNode(index);
                printSuccess("Da xoa thanh cong!");
            }
            else
            {
                return;
            }
        }
    }
    else if (checkSDT == true)
    {
        printSuccess("Da tim thay nhan vien co so dien thoai nay");
        int index = QLNhanVien::findBySDT(temp);
        if (index == -1)
        {
            printError("Khong tim thay Nhan vien nao co so dien thoai nay");
        }
        else
        {
            if (false)
            {
            }
            else
            {
                Node<NhanVien> *pTemp = this->dbNV->getpHead();
                while (true)
                {

                    if (pTemp->getData().getSoDienThoai() == temp)
                    {
                        break;
                    }
                    pTemp = pTemp->getpNext();
                }
                printWarning("Ban se xoa nhan vien nay!");
                cout << endl
                     << endl;

                pTemp->getData().xuatFullInfo();

                printRes("Ban co chac chan khong?(y/n): ");
                char c;
                fflush(stdin);
                c = getchar();

                if (c == 'y' || c == 'Y')
                {
                    this->dbNV->deleteNode(index);
                    printSuccess("Da xoa thanh cong!");
                }
                else
                {
                    return;
                }
            }
        }
    }
    else
    {
        printError("Khong tim thay nhan vien co ma hoac so dien thoai nay. Vui long thu lai!");
    }
}