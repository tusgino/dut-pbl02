// #include "features\SanPham\SanPham.cpp"
// #include "features\NhanVien\NhanVien.cpp"
#include "features\QuanLi\QLSanPham.cpp"

using namespace std;

int main()
{
  // NhanVien tempNV;
  // fstream temp;
  // fstream temp1;
  // temp.open("components/data/ola.dat", ios_base::in);
  // tempNV.docFile(temp);
  // temp.close();
  // temp1.open("components/data/ola1.dat", ios_base::out);
  // tempNV.ghiFile(temp1);
  // temp1.close();
  // tempSP.Xuat();
  // QuanLi *p;
  // p = new QLKhachHang();

  // QLKhachHang *qlkh = new QLKhachHang();
  fstream temp;
  temp.open("components/data/ola.dat", ios_base::in);
  // qlkh->docFile(temp);

  QuanLi *p = new QLSanPham();
  p->create();
  // p->docFile(temp);
  // temp.close();
  // fstream temp1;
  // temp1.open("components/data/ola1.dat", ios_base::out);
  // p->ghiFile(temp1);
  // temp1.close();

  return 0;
}