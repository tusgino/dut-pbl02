#include "..\..\..\Class\KhachHang.h"
#include <fstream>
#include <iomanip>
using namespace std;

KhachHang::KhachHang() {}

KhachHang::KhachHang(const KhachHang &kh)
{
    this->diaChiKH = kh.diaChiKH;
    this->hoTenKH = kh.hoTenKH;
    this->maKhachHang = kh.maKhachHang;
    this->soDienThoaiKH = kh.soDienThoaiKH;
    this->gioiTinh = kh.gioiTinh;
}

KhachHang::KhachHang(const int &maKH, const int &gt, const string &tenKH, const string &diaChiKH, const string &soDienThoai)
{
    this->gioiTinh = gt;
    this->diaChiKH = diaChiKH;
    this->maKhachHang = maKH;
    this->hoTenKH = tenKH;
    this->soDienThoaiKH = soDienThoai;
}

const int KhachHang::getGioiTinhKH()
{
    return this->gioiTinh;
}

const int KhachHang::getMaKhachHang()
{
    return this->maKhachHang;
}
const string KhachHang::getHoTenKH()
{
    return this->hoTenKH;
}
const string KhachHang::getSoDienThoaiKH()
{
    return this->soDienThoaiKH;
}
const string KhachHang::getDiaChiKH()
{
    return this->diaChiKH;
}

void KhachHang::setGioiTinhKH(const int &gt)
{
    this->gioiTinh = gt;
}
void KhachHang::setMaKhachHang(const int &makh)
{
    this->maKhachHang = makh;
}
void KhachHang::setHoTenKH(const string &hoten)
{
    this->hoTenKH = hoten;
}
void KhachHang::setSoDienThoaiKH(const string &sdt)
{
    this->soDienThoaiKH = sdt;
}
void KhachHang::setDiaChiKH(const string &diachi)
{
    this->diaChiKH = diachi;
}

void KhachHang::xuat()
{
    cout << setfill('0') << "\tMa khach hang: " << setw(3) << this->maKhachHang << setfill(' ');
    cout << "\tHo ten khach hang: " << this->hoTenKH << endl;
    cout << "\tGioi Tinh: ";
    switch (this->gioiTinh)
    {
    case 1:
        cout << "Nam" << endl;
        break;
    case 2:
        cout << "Nu" << endl;
        break;
    default:
        cout << "Chua xac dinh" << endl;
        break;
    }
    cout << "\tDia chi khach hang: " << this->diaChiKH << endl;
    cout << "\tSo dien thoai khach hang: " << this->soDienThoaiKH << endl;
}

void KhachHang::docFile(fstream &fileKhachHang)
{
    fileKhachHang >> this->maKhachHang;
    fileKhachHang.ignore(1);

    getline(fileKhachHang, this->hoTenKH, '|');
    fileKhachHang >> this->gioiTinh;
    fileKhachHang.ignore(1);
    getline(fileKhachHang, this->diaChiKH, '|');
    getline(fileKhachHang, this->soDienThoaiKH, '|');
}

void KhachHang::ghiFile(fstream &fileKhachHang)
{
    fileKhachHang << this->maKhachHang << "|";
    fileKhachHang << this->hoTenKH << "|";
    fileKhachHang << this->gioiTinh << "|";
    fileKhachHang << this->diaChiKH << "|";
    fileKhachHang << this->soDienThoaiKH << "|" << endl;
}

void KhachHang::xuatThanhBang()
{
    cout << setfill('=') << setw(113) << right << " " << endl;
    cout << "|| " << setfill('0') << setw(4) << this->maKhachHang << setfill(' ') << setw(9) << left << " "
         << "|| " << setw(30) << left << this->hoTenKH << "|| " << setw(13) << left << ((this->gioiTinh == 1) ? "Nam" : (gioiTinh == 2 ? "Nu" : "null")) << "|| " << setw(14) << left << this->soDienThoaiKH << "|| " << setw(25) << left << this->diaChiKH << "||" << endl;
}