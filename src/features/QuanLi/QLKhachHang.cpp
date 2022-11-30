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
    KhachHang _KHAdd;
    int soTT = this->dbKH->getpHead()->getData().getMa().getSoTT();
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
    _KHAdd.nhap(); // Nhập từ phím

    this->dbKH->push_back(_KHAdd);
    this->count++;
}

void QLKhachHang::update()
{
    string _sdt;
    cout << "Nhap so dien thoai can tim: ";
    fflush(stdin);
    getline(cin, _sdt);
    // Tìm kiếm khách hàng
    QLKhachHang::findBySDT(_sdt);
}

void QLKhachHang::find()
{

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

        printError("Khong ton tai so dien thoai nay");
    }

    {
        string str;
        cout << "Nhap ten khach hang cang tim";
        fflush(stdin);
        getline(cin, str);
        for (auto &c : str)
            c = toupper(c);
        int strLength = str.length();
        char strSub[strLength + 1];
        strcpy(strSub, str.c_str());

        Node<KhachHang> *pTemp = this->dbKH->getpHead();
        while (pTemp)
            ;
        {
            string strTemp = pTemp->getData().getTen();
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
                pTemp->getData().xuat();
            }

            pTemp = pTemp->getpNext();
        }
    }
}

int QLKhachHang::findBySDT(const string &sdt)
{

}
