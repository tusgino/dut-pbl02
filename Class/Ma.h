#ifndef __Ma_H__
#define __Ma_H__

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "..\src\components\utils\components.cpp"
using namespace std;

class Ma
{
    string kiTu;
    int soTT;

public:
    Ma(const string = "", const int = 0);
    ~Ma();
    const string &getKiTu();
    const int &getsoTT();

    void setKiTu(const string &);
    void setsoTT(const int &);

    friend ostream &operator<<(ostream &, const Ma &);
    friend istream &operator>>(istream &, Ma &);

    void docFile(fstream &);
    void ghiFile(fstream &);
};

#endif