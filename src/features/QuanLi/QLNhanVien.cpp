#include "..\..\..\class\QLNhanVien.h"

QLNhanVien::QLNhanVien()
{
    this->dbNV = new List<NhanVien>();
    this->count = 0;
}

QLNhanVien::QLNhanVien(){
    this->dbNV->~List();
}