
#include "..\..\..\Class\NhanVien.h"
#include <fstream>
#include <iomanip>
using namespace std;

NhanVien::NhanVien()
{
}

NhanVien::NhanVien(const int &manv, const string &hotennv, const int &gioitinh, const int &chucvu, const string &calam, const string &diachi, const string &matkhau)
{
    this->tenNhanVien = hotennv;
    this->maNhanVien = manv;
    this->gioiTinh = gioitinh;
    this->caLamViec = calam;
    this->chucVu = chucvu;
    this->diaChi = diachi;
    this->matKhau = matkhau;
}
NhanVien::~NhanVien()
{
}

const int &NhanVien::getMaNhanVien()
{
    return this->maNhanVien;
}

const string &NhanVien::getHoTenNV()
{
    return this->tenNhanVien;
}

const string &NhanVien::getCaLamViec()
{
    return this->caLamViec;
};

const int &NhanVien::getChucVu()
{
    return this->chucVu;
};
const string &NhanVien::getMatKhau()
{
    return this->matKhau;
};

void NhanVien::setMaNhanVien(const int &manv)
{
    this->maNhanVien = manv;
};
void NhanVien::setHoTenNV(string hotennv)
{
    this->tenNhanVien = hotennv;
};

void NhanVien::setCaLamViec(const string &calam)
{
    this->caLamViec = calam;
}

void NhanVien::setGioiTinh(const int &temp)
{
    this->gioiTinh = temp;
}

void NhanVien::setChucVu(const int &chucvu)
{
    this->chucVu = chucvu;
};
void NhanVien::setMatKhau(const string &matkhau)
{
    this->matKhau = matkhau;
};
void NhanVien::setDiaChi(const string &diachi)
{
    this->diaChi = diaChi;
}
void NhanVien::xuat()
{
    cout << "\tHo va ten: " << this->tenNhanVien << endl;
    cout << "\tMa nhan vien: " << this->maNhanVien << endl;
    cout << "\tChuc vu: ";
    switch (this->chucVu)
    {
    case 2:
        cout << "Quan Li" << endl;
        break;
    case 1:
        cout << "Nhan Vien" << endl;
        break;
    default:
        cout << "Chua xac dinh" << endl;
        break;
    }
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
    cout << "\tCa lam viec: ";
    cout << this->caLamViec << endl;
    cout << "\tDia Chi: " << this->diaChi << endl;
}

void NhanVien::docFile(fstream &fileIn)
{
    fileIn >> this->maNhanVien;
    fileIn.ignore(1);

    getline(fileIn, this->tenNhanVien, '|');

    fileIn >> this->gioiTinh;
    fileIn.ignore(1);

    fileIn >> this->chucVu;
    fileIn.ignore(1);

    getline(fileIn, this->caLamViec, '|');
    getline(fileIn, this->diaChi, '|');
    getline(fileIn, this->matKhau, '|');

    // fileIn.ignore(1);
}

void NhanVien::ghiFile(fstream &fileOut)
{
    fileOut << this->maNhanVien << "|";
    fileOut << this->tenNhanVien << "|";
    fileOut << this->gioiTinh << "|";
    fileOut << this->chucVu << "|";
    fileOut << this->caLamViec << "|";
    fileOut << this->diaChi << "|";
    fileOut << this->matKhau << "|" << endl;
}

void NhanVien::xuatthanhbang()
{
    cout << setfill('=') << setw(125) << right << " " << endl;
    cout << setfill(' ') << "|| " << setw(13) << left << this->maNhanVien << "|| " << setw(30) << left << this->tenNhanVien << "|| " << setw(13) << left << ((gioiTinh == 1) ? "Nam" : (gioiTinh == 2 ? "Nu" : "null")) << "|| " << setw(9) << left << ((chucVu == 1) ? "Nhan Vien" : "Quan Li") << "|| " << setw(14) << left << this->caLamViec << "|| " << setw(25) << left << this->diaChi << "||" << endl;
}
