#include "src/features/QuanLi/QLKhachHang.cpp"
#include "src/features/QuanLi/QLNhanVien.cpp"
#include "src/features/QuanLi/QLSanPham.cpp"

using namespace std;

int main()
{
  QLSanPham *p = new QLSanPham();
  fstream fileSP;
  fileSP.open("src/components/data/SanPham.DAT", ios_base::in);
  p->docFile(fileSP);
  fileSP.close();
  // p->find();
  // p->deleteIndex();
  p->update();
  p->read();

  // fileSP.open("src/components/data/SanPham1.DAT", ios_base::out);
  // p->ghiFile(fileSP);
  // fileSP.close();
  return 0;
  // QLKhachHang *p = new QLKhachHang();
  // fstream fileKH;
  // fileKH.open("src/components/data/ola.dat", ios_base::in);
  // p->docFile(fileKH);
  // fileKH.close();
  // p->create();
  // p->read();
  // p->deleteIndex();
  // p->find();
  // fileKH.open("src/components/data/ola1.dat", ios_base::out);
  // p->ghiFile(fileKH);
  // fileKH.close();
  // p->sortMa();
  // // p->create();
  // // p->read();
  // fileKH.open("src/components/data/ola1.dat", ios_base::out);
  // p->ghiFile(fileKH);
  // fileKH.close();
  // cout << 1;

  return 0;
  // Ma ma("A", 67);
  // cout << string(ma);
}