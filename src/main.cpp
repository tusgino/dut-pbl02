#include "features\SanPham\SanPham.cpp"

using namespace std;

int main()
{
  SanPham tempSP;
  fstream temp;
  fstream temp1;
  temp.open("components/data/temp.data", ios_base::in);
  tempSP.docFile(temp);
  temp.close();
  tempSP.Xuat();
  return 0;
}