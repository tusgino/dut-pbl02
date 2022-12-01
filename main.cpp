#include "class/lib.h"

using namespace std;

int main()
{
  QLHoaDon *pHD = new QLHoaDon();

  fstream fileHD;
  fileHD.open("src/components/data/HoaDon.DAT", ios_base::in);
  pHD->docFile(fileHD);
  fileHD.close();
  fileHD.open("src/components/data/HoaDon1.DAT", ios_base::out);
  pHD->ghiFile(fileHD);
  fileHD.close();

  // // QLSanPham *pSP = new QLSanPham();
  // // QLNhanVien *pNV = new QLNhanVien();
  // // QLKhachHang *pKH = new QLKhachHang();
  // // fstream fileSP;
  // // fileSP.open("src/components/data/SanPham.DAT", ios_base::in);
  // // pSP->docFile(fileSP);
  // // fileSP.close();
  // // // p->find();
  // // // p->deleteIndex();
  // // pSP->update();
  // pSP->read();
  // // pSP->read();

  // // // fileSP.open("src/components/data/SanPham1.DAT", ios_base::out);
  // // // p->ghiFile(fileSP);
  // // // fileSP.close();
  // // return 0;
  // QLKhachHang *p = new QLKhachHang();
  // fstream fileKH;
  // fileKH.open("src/components/data/ola.dat", ios_base::in);
  // p->docFile(fileKH);
  // // fileKH.close();
  // // // p->create();
  // p->read();
  // p->deleteIndex();
  // p->read();
  // // // p->find();
  // // // fileKH.open("src/components/data/ola1.dat", ios_base::out);
  // // // p->ghiFile(fileKH);
  // // // fileKH.close();
  // // // p->sortMa();
  // // // // p->create();
  // // // // p->read();
  // // // fileKH.open("src/components/data/ola1.dat", ios_base::out);
  // // // p->ghiFile(fileKH);
  // // // fileKH.close();
  // // // cout << 1;

  // return 0;
  // // Ma ma("A", 67);
  // // cout << string(ma);
}

// #include <iostream>
// // #include "ConsoleTable.h"
// #include "ConsoleTable.cpp"

// int main()
// {

//   ConsoleTable table{"Country", "Capital", "Population", "Area", "Currency"};

//   table.setPadding(2);
//   table.setStyle(0);

//   table += {"Germany", "Berlin", "82,800,000", "357,168 km2", "Euro"};
//   table += {"France", "Paris", "67,201,000", "640,679 km2 ", "Euro"};
//   table += {"South Korea", "Seoul", "51,446,201", "100,210 km2 ", "South Korean Won"};
//   table += {"Australia", "Canberra", "24,877,800", "7,692,024 km2", "Australian Dollar"};
//   table += {"China", "Beijing", "1,403,500,365", "9,596,961 km2", "Yuan"};
//   table += {"Iceland", "Reykjavik", "348,580", "102,775 km2", "Icelandic Krona"};
//   table += {"Netherlands", "Amsterdam", "17,200,671", "41,543 km2", "Euro"};

//   table.updateRow(3, 1, "NEW ENTRY");
//   table.updateHeader(2, "NEW HEADER");

//   table -= 2;
//   table -= 1;
//   table -= 0;
//   table.sort(true);

//   std::cout << table;
//   return 0;
// }