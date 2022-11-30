#include "..\..\..\class\Ma.h"

using namespace std;

Ma::Ma(const string kitu, const int soTT) : kiTu(kitu), soTT(soTT){};

Ma::~Ma(){};

const string &Ma::getKiTu()
{
    return this->kiTu;
}
const int &Ma::getSoTT()
{
    return this->soTT;
}

void Ma::setKiTu(const string &kitu)
{
    this->kiTu = kitu;
}
void Ma::setSoTT(const int &soTT)
{
    this->soTT = soTT;
}

ostream &operator<<(ostream &o, const Ma &ma)
{
    o << ma.kiTu << setfill('0') << setw(4) << ma.soTT << setfill(' ');
    return o;
};
istream &operator>>(istream &i, Ma &ma)
{
    string tempKT = "", tempSoTT = "";
    while (1)
    {
        string temp;
        printRes("Nhap ma: ");
        fflush(stdin);
        getline(cin, temp); // A101
        tempKT = "", tempSoTT = "";
        // xử lí chuỗi tách phần ma với số ra
        bool check = true;
        for (auto &c : temp)
        {
            if (int(c) >= 48 && int(c) <= 57)
            {
                tempSoTT += c;
                check = false;
            }
            else
            {
                if (check)
                    tempKT += c;
                else
                {
                    tempSoTT = "-1";
                    break;
                }
            }
        }
        if (stoi(tempSoTT) != -1)
            break;
        else
        {
            printError("Ban da nhap sai dinh dang ma! Vui long nhap lai");
            char c;
            c = getchar();
        }
    }
    ma.kiTu = tempKT;
    ma.soTT = stoi(tempSoTT);
    return i;
};

void Ma::docFile(fstream &fileIn)
{
    getline(fileIn, this->kiTu, '|');
    fileIn >> this->soTT;
    fileIn.ignore(1);
}

void Ma::ghiFile(fstream &fileOut)
{
    fileOut << this->kiTu << "|" << setfill('0') << setw(4) << this->soTT << "|";
}

Ma::operator std::string()
{
    string res;
    res += this->kiTu;
    string temp;
    int tempSoTT = this->soTT;
    int cnt = 0;
    while (tempSoTT > 0)
    {
        cnt++;
        tempSoTT /= 10;
    }
    for (int i = 0; i < 4 - cnt; i++)
    {
        res += '0';
    }
    res += to_string(this->soTT);

    return res;
}

const bool Ma::operator>=(const Ma &ma)
{
    int comp = this->kiTu.compare(ma.kiTu);
    if (comp == 0)
    {
        return (this->soTT >= ma.soTT);
    }
    else if (comp < 0)
        return false;
    else
        return true;
}
const bool Ma::operator!=(const Ma &ma)
{
    int comp = this->kiTu.compare(ma.kiTu);
    if (comp == 0 && (this->soTT == ma.soTT))
    {
        return false;
    }
    return true;
}