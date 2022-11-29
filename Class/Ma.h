#include <iostream>
#include <string>
#include <iomanip>
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
};