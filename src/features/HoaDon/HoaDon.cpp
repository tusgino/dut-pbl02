#include "..\..\..\Class\HoaDon.h"

HoaDon::HoaDon()
{
}

HoaDon::HoaDon(QLSanPham *p, const int &manv, const int &makh)
{
    this->maNV = manv;
    this->maKH = makh;
    this->sp = new List<SanPham_HD>();
    this->soLuong = 0;
    this->TongTien = 0;
    this->DSSP = p;
}

List<SanPham_HD> *HoaDon::getSP()
{
    return this->sp;
}

const int &HoaDon::getMaHoaDon()
{
    return this->maHoaDon;
}
const int &HoaDon::getSoLuong()
{
    return this->soLuong;
}
const long long &HoaDon::getTongTien()
{
    this->TongTien = 0;
    Node<SanPham_HD> *pTemp = this->sp->getpHead();
    while (pTemp)
    {
        SanPham spTemp = this->DSSP->findSP(pTemp->getData().getMaSP());
        this->TongTien += (pTemp->getData().getCount() * spTemp.getDonGiaSP() * (1 - spTemp.getGiamGiaSP() / 100));
        pTemp = pTemp->getpNext();
    }
    return this->TongTien;
}

const Date &HoaDon::getNgayIn()
{
    return this->ngayIn;
}

QLSanPham *HoaDon::getDSSP()
{
    return this->DSSP;
}

void HoaDon::setSP(List<SanPham_HD> *p)
{
    this->sp = p;
}

void HoaDon::setMaHoaDon(const int &mahd)
{
    this->maHoaDon = mahd;
}
void HoaDon::setMaNV(const int &maNV)
{
    this->maNV = maNV;
}
void HoaDon::setMaKH(const int &maKH)
{
    this->maKH = maKH;
}
int HoaDon::getMaNV()
{
    return this->maNV;
}
int HoaDon::getMaKH()
{
    return this->maKH;
}
void HoaDon::setSoLuong(const int &soluong)
{
    this->soLuong = soluong;
}
void HoaDon::setTongTien(const long long &tongtien)
{
    this->TongTien = tongtien;
}

void HoaDon::setNgayIn(const Date &date)
{
    this->ngayIn = date;
}
void HoaDon::setDSSP(QLSanPham *p)
{
    this->DSSP = p;
}

void HoaDon::docFileHD(fstream &fileHoaDon)
{
    fileHoaDon >> this->maHoaDon;
    fileHoaDon.ignore(1);
    fileHoaDon >> this->maNV;
    fileHoaDon.ignore(1);
    fileHoaDon >> this->maKH;
    fileHoaDon.ignore(1);
    int nam, thang, ngay, gio, phut;
    fileHoaDon >> gio;
    fileHoaDon.ignore(1);
    fileHoaDon >> phut;
    fileHoaDon.ignore(1);
    fileHoaDon >> ngay;
    fileHoaDon.ignore(1);
    fileHoaDon >> thang;
    fileHoaDon.ignore(1);
    fileHoaDon >> nam;
    fileHoaDon.ignore(1);
    Date temp(gio, phut, ngay, thang, nam);
    this->ngayIn = temp;
    fileHoaDon >> this->soLuong;
    fileHoaDon.ignore(1);
    List<SanPham_HD> *SPTemp = new List<SanPham_HD>();
    this->TongTien = 0;
    for (int i = 0; i < this->soLuong; i++)
    {
        string maSP;
        string size;
        int soLuongSP;
        getline(fileHoaDon, maSP, '|');
        getline(fileHoaDon, size, '|');
        fileHoaDon >> soLuongSP;
        fileHoaDon.ignore(1);
        SanPham_HD p1(maSP, size, soLuongSP);
        SanPham spTemp = this->DSSP->findSP(maSP);
        this->TongTien += soLuongSP * spTemp.getDonGiaSP() * (1 - float(spTemp.getGiamGiaSP() / 100));
        SPTemp->push_back(p1);
    }
    this->sp = SPTemp;
}

void HoaDon::ghiFile(fstream &fileHoaDon)
{
    fileHoaDon << this->maHoaDon << "|";
    fileHoaDon << this->maNV << "|";
    fileHoaDon << this->maKH << "|";
    this->ngayIn.ghiFile(fileHoaDon);
    fileHoaDon << this->soLuong << "|";
    Node<SanPham_HD> *pTemp = this->sp->getpHead();
    while (pTemp)
    {
        pTemp->getData().ghiFile(fileHoaDon);
        pTemp = pTemp->getpNext();
    }
    fileHoaDon << endl;
}

void HoaDon::xuatInfo()
{
    cout << "|" << setw(5) << left << this->maHoaDon << "|" << this->maKH << "|" << this->TongTien << endl;
}

void HoaDon::xuat()
{
    cout << "\tMa hoa don: " << this->maHoaDon;
    cout << "\tMa nhan vien: " << this->maNV;
    cout << "\tMa khach hang: " << this->maKH;
    cout << "\n\tNgay thuc hien hoa don: " << this->ngayIn;
    cout << "\tDanh sach hang hoa bao gom " << setfill('0') << setw(2) << right << this->soLuong << " hang muc:\n";
    // cout << "STT" << setw() <<
    Node<SanPham_HD> *pTemp = this->sp->getpHead();
    int i = 0;
    // this->TongTien = 0;
    cout << setfill('-') << setw(120) << right << "-\n"
         << setfill(' ');
    cout << "||" << setw(3) << left << "STT "
         << "||"
         << "Ma san pham "
         << "||" << setw(31) << left << "Ten san pham "
         << "||"
         << "Size "
         << "||"
         << "So luong "
         << "||" << setw(10) << left << "Don gia"
         << "||"
         << "Discount "
         << "||" << setw(21) << left << "Thanh Tien"
         << "||" << endl;
    cout << setfill('-') << setw(120) << right << "-\n"
         << setfill(' ');
    while (pTemp)
    {
        SanPham spTemp = this->DSSP->findSP(pTemp->getData().getMaSP());
        cout << "||" << setw(4) << left << ++i << "|| " << setfill(' ') << setw(11) << left << pTemp->getData().getMaSP() << "|| " << setw(30) << left << spTemp.getTenSP() << "|| " << setw(4) << left << pTemp->getData().getSize() << "|| " << setw(8) << left << pTemp->getData().getCount() << "|| " << setw(9) << left << spTemp.getDonGiaSP() << "|| " << setfill('0') << setw(2) << right << spTemp.getGiamGiaSP() << "%" << setfill(' ') << setw(8) << right << "|| " << setw(20) << left << size_t(pTemp->getData().getCount() * spTemp.getDonGiaSP() * (1 - spTemp.getGiamGiaSP() / 100)) << "||" << endl;
        // this->TongTien += (pTemp->getData().getCount() * spTemp.getDonGiaSP() * (1 - spTemp.getGiamGiaSP() / 100));
        pTemp = pTemp->getpNext();
    }
    cout << setfill('-') << setw(120) << right << "-\n"
         << setfill(' ');
    cout << "||" << setw(47) << right << "TONG TIEN:" << setfill(' ') << setw(48) << right << "|| " << this->TongTien << ((this->TongTien < 1000000) ? setw(16) : setw(15)) << right << "||" << endl;

    cout << setfill('-') << setw(120) << right << "-\n"
         << setfill(' ');
}