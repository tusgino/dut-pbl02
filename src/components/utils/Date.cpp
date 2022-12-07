#include "..\..\..\class\Date.h"
#include <iomanip>

Date::Date()
{
    time_t baygio = time(0);

    // cout << "So giay ke tu 1/1/1970 la: " << baygio << endl;

    tm *ltm = localtime(&baygio);

    // in cac thanh phan cua cau truc tm struct.
    // cout << "Nam: " << 1900 + ltm->tm_year << endl;
    this->nam = 1900 + ltm->tm_year;
    // cout << "Thang: " << 1 + ltm->tm_mon << endl;
    this->thang = 1 + ltm->tm_mon;
    // cout << "Ngay: " << ltm->tm_mday << endl;
    this->ngay = ltm->tm_mday;
    // cout << "Thoi gian: " << 1 + ltm->tm_hour << ":";
    this->gio = ltm->tm_hour;
    // cout << 1 + ltm->tm_min << ":";
    this->phut = ltm->tm_min;
};

Date::Date(const Date &date)
{
    *this = date;
}

Date::Date(const int &gio, const int &phut, const int &ngay, const int &thang, const int &nam)
{
    this->nam = nam;
    this->thang = thang;
    this->ngay = ngay;
    this->gio = gio;
    this->phut = phut;
}

const int &Date::getPhut()
{
    return this->phut;
}
const int &Date::getGio()
{
    return this->gio;
}
const int &Date::getNgay()
{
    return this->ngay;
}
const int &Date::getThang()
{
    return this->thang;
}
const int &Date::getNam()
{
    return this->nam;
}

void Date::setNgay(const int &ngay)
{
    this->ngay = ngay;
}

void Date::setThang(const int &thang)
{
    this->thang = thang;
}

void Date::setNam(const int &nam)
{
    this->nam = nam;
}

void Date::ghiFile(fstream &fileOut)
{
    fileOut << setfill('0') << setw(2) << right << this->gio << ":" << setw(2) << right << this->phut << "  " << setw(2) << this->ngay << "/" << setw(2) << this->thang << "/" << this->nam << "|";
}

void Date::docFile(fstream &fileIn)
{
    fileIn >> this->gio;
    fileIn.ignore(1);
    fileIn >> this->phut;
    fileIn.ignore(1);
    fileIn >> this->ngay;
    fileIn.ignore(1);
    fileIn >> this->thang;
    fileIn.ignore(1);
    fileIn >> this->nam;
    fileIn.ignore(1);
}

istream &operator>>(istream &ip, Date &date)
{
    fflush(stdin);
    do
    {
        do
        {
            cout << "\tNhap ngay: ";
            ip >> date.ngay;
        } while (date.ngay < 1 || date.ngay > 31);
        do
        {
            cout << "\tNhap thang: ";
            ip >> date.thang;
        } while (date.thang < 1 || date.thang > 12);
        do
        {
            cout << "\tNhap nam: ";
            ip >> date.nam;
        } while (date.nam < 1);
        if (!check(date))
        {
            cout << "\tVui long nhap lai ngay!\n";
        }
    } while (check(date) != true);
    return ip;
}

ostream &operator<<(ostream &op, const Date &date)
{
    op << setfill('0') << setw(2) << right << date.gio << ":" << setw(2) << right << date.phut << "  " << setw(2) << date.ngay << "/" << setw(2) << date.thang << "/" << date.nam << setfill(' ');
    return op;
}

const bool Date::operator>=(const Date &date)
{
    if (!check(date))
        return false;
    if (this->nam > date.nam)
        return true;
    if (this->nam < date.nam)
        return false;
    if (this->nam == date.nam)
    {
        if (this->thang > date.thang)
            return true;
        if (this->thang < date.thang)
            return false;
        if (this->thang == date.thang)
        {
            if (this->ngay >= date.ngay)
                return true;
            if (this->ngay < date.ngay)
                return false;
        }
    }
    return false;
}

const bool Date::operator<=(const Date &date)
{
    if (!check(date))
        return false;
    if (this->nam < date.nam)
        return true;
    if (this->nam > date.nam)
        return false;
    if (this->nam == date.nam)
    {
        if (this->thang < date.thang)
            return true;
        if (this->thang > date.thang)
            return false;
        if (this->thang == date.thang)
        {
            if (this->ngay <= date.ngay)
                return true;
            if (this->ngay > date.ngay)
                return false;
        }
    }
    return false;
}

const bool Date::operator==(const Date &date)
{
    if (date.nam == this->nam && date.thang == this->thang && date.ngay == this->ngay)
    {
        return true;
    }
    return false;
}

const bool check(const Date &date)
{
    static int namNhuan[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    static int namKhongNhuan[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (date.nam % 4 == 0 || (date.nam % 100 == 0 && date.nam % 4 != 0))
    {
        if (date.ngay > namNhuan[date.thang])
            return false;
    }
    else
    {
        if (date.ngay > namKhongNhuan[date.thang])
            return false;
    }

    return true;
}

Date::operator std::string()
{
    string tempDate = (this->gio < 10 ? "0" + to_string(this->gio) : to_string(this->gio)) + ":" + (this->phut < 10 ? "0" + to_string(this->phut) : to_string(this->phut)) + " " + (this->ngay < 10 ? "0" + to_string(this->ngay) : to_string(this->ngay)) + "/" + (this->thang < 10 ? "0" + to_string(this->thang) : to_string(this->thang)) + "/" + to_string(this->nam);
    return tempDate;
}

void fix(Date &date)
{
    static int namNhuan[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    static int namKhongNhuan[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (date.nam % 4 == 0 || (date.nam % 100 == 0 && date.nam % 4 != 0))
    {
        if (date.ngay > namNhuan[date.thang])
        {
            date.ngay -= namNhuan[date.thang];
            date.thang++;
        }
    }
    else
    {
        if (date.ngay > namKhongNhuan[date.thang])
        {
            date.ngay -= namKhongNhuan[date.thang];
            date.thang++;
        }
    }

    if (date.thang > 12)
    {
        date.thang -= 12;
        date.nam++;
    }
}

Date Date::operator++(int)
{
    Date before(*this);

    this->ngay++;
    if (!check(*this))
        fix(*this);

    return before;
}

void Date::nhapThang()
{
    fflush(stdin);
    do
    {
        do
        {
            cout << "\tNhap thang: ";
            cin >> this->thang;
        } while (this->thang < 1 || this->thang > 12);
        do
        {
            cout << "\tNhap nam: ";
            cin >> this->nam;
        } while (this->nam < 1);
        if (!check(*this))
        {
            cout << "\tVui long nhap lai thang!\n";
        }
    } while (check(*this) != true);
}
void Date::nhapNam()
{
    fflush(stdin);
    do
    {
        do
        {
            cout << "\tNhap nam: ";
            cin >> this->nam;
        } while (this->nam < 1);
        if (!check(*this))
        {
            cout << "\tVui long nhap lai nam!\n";
        }
    } while (check(*this) != true);
}