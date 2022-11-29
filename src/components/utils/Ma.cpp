#include "..\..\..\Class\Ma.h"
#include <iomanip>
Ma::Ma(const string kitu, const int soTT) : kiTu(kitu), soTT(soTT){};

Ma::~Ma(){};

const string &Ma::getKiTu()
{
    return this->kiTu;
}
const int &Ma::getsoTT()
{
    return this->soTT;
}

void Ma::setKiTu(const string &kitu)
{
    this->kiTu = kitu;
}
void Ma::setsoTT(const int &soTT)
{
    this->soTT = soTT;
}

ostream &operator<<(ostream &o, const Ma &ma)
{
    o << ma.kiTu << setfill('0') << setw(4) << ma.soTT;

    return o;
};
istream &operator>>(istream &i, Ma &ma)
{
    string temp;
    fflush(stdin);
    getline(cin, temp); // A101
    string tempKT, tempSoTT;
    // xử lí chuỗi tách phần ma với số ra


};