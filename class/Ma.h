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
    const int &getSoTT();

    void setKiTu(const string &);
    void setSoTT(const int &);

    friend ostream &operator<<(ostream &, const Ma &);
    friend istream &operator>>(istream &, Ma &);
    operator string();
    void docFile(fstream &);
    void ghiFile(fstream &);
};

#endif