#include "..\..\..\class\QLNhanVien.h"

QLNhanVien::QLNhanVien()
{
    this->dbNV = new List<NhanVien>();
    this->count = 0;
}

QLNhanVien::QLNhanVien()
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
            printOpt(arr, 2);
        }
        int key = getKey(2);
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
        string arr[] = {"Nhap lua chon cua ban"};
    }
}

void QLNhanVien::read(){
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