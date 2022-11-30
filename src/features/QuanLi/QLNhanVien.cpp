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
                soTT = (pTemp->getData().getMa().getSoTT() > soTT) ? pTemp->getData().getMa().getSoTT() : soTT;
                pTemp = pTemp->getpNext();
            }
        }
        Ma tempMa("NV", soTT + 1);
        _NVAdd.setMa(tempMa);
        _NVAdd.nhap();

        this->dbNV->push_back(_NVAdd);
        this->count++;
    }
    break;
    case 2:
    {
    }
    break;
    case 3:
    {
    }
    break;
    default:
        break;
    }
}