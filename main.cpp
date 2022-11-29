// #include "features\SanPham\SanPham.cpp"
// #include "features\NhanVien\NhanVien.cpp"
#include "src\features\QuanLi\QLSanPham.cpp"

using namespace std;

int main()
{
  QLSanPham *p = new QLSanPham();
  Ma ma("A", 101);
  Ma ma2("A", 102);
  SanPham p1(ma, "S", "alals", "sfdasd", 15, 142, 214, 2);
  SanPham p2(ma2, "M", "alalasds", "sfdasd", 15, 142, 214, 2);
  // p->dbSP->push_back(p1);
  // p->dbSP->push_back(p2);

  p->create();
  return 0;
}