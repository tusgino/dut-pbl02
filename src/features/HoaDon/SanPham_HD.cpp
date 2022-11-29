#include "..\..\..\Class\SanPham_HD.h"

SanPham_HD::SanPham_HD(){};

SanPham_HD::SanPham_HD(const string &ma, const string &size, const int &dem)
{
    this->maSP = ma;
    this->size = size;
    this->count = dem;
}

SanPham_HD::~SanPham_HD() {}

const string &SanPham_HD::getMaSP()
{
    return this->maSP;
}
const string &SanPham_HD::getSize()
{
    return this->size;
}

const int &SanPham_HD::getCount()
{
    return this->count;
}

void SanPham_HD::setMaSP(const string &ma)
{
    this->maSP = ma;
}

void SanPham_HD::setSize(const string &size)
{
    this->size = size;
}

void SanPham_HD::setCount(const int &c)
{
    this->count = c;
}

void SanPham_HD::xuatHD()
{
    cout << this->maSP << " " << this->count << " " << this->size << endl;
}

void SanPham_HD::ghiFile(fstream &fileOut)
{
    fileOut << this->maSP << "|" << this->size << "|" << this->count << "|";
}