#include<iostream>
#include<string>
using namespace std;

class Ma{ // A101
    string kiTu;
    int soTT;

    public:
    Ma(const string = "", const int = 0);
    ~Ma();
    const string& getKiTu();
    const int& getsoTT();

    void setKiTu(const string& );
    void setsoTT(const int& );
    

    friend ostream& operator <<(ostream&, const Ma&);
    friend istream& operator >>(istream&, Ma&);
    

};