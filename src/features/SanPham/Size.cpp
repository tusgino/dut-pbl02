#include "..\..\..\Class\Size.h"
#include <iostream>
#include <fstream>

using namespace std;

Size::Size() {}
Size::Size(int S, int M, int L, int XL, int XXL)
{
  this->S = S;
  this->M = M;
  this->L = L;
  this->XL = XL;
  this->XXL = XXL;
}
Size::~Size() {}
void Size::setS(int S)
{
  this->S = S;
}
void Size::setM(int M)
{
  this->M = M;
}
void Size::setL(int L)
{
  this->L = L;
}
void Size::setXL(int XL)
{
  this->XL = XL;
}
void Size::setXXL(int XXL)
{
  this->XXL = XXL;
}
void Size::setAll(int S, int M, int L, int XL, int XXL)
{
  this->S = S;
  this->M = M;
  this->L = L;
  this->XL = XL;
  this->XXL = XXL;
}
void Size::setSize(const Size &size)
{
  this->S = size.S;
  this->M = size.M;
  this->L = size.L;
  this->XL = size.XL;
  this->XXL = size.XXL;
}
int Size::getS()
{
  return this->S;
}
int Size::getM()
{
  return this->M;
}
int Size::getL()
{
  return this->L;
}
int Size::getXL()
{
  return this->XL;
}
int Size::getXXL()
{
  return this->XXL;
}
void Size::xuat()
{
  // cout << setfill('-') << setw(20) << " " << endl << setfill(' ');
  cout << this->S << "|" << setw(3)
       << this->M << "|" << setw(3)
       << this->L << "|" << setw(3)
       << this->XL << "|" << setw(3)
       << this->XXL << "||";
}

void Size::ghiFile(fstream &fileOut)
{
  fileOut << this->S << "|";
  fileOut << this->M << "|";
  fileOut << this->L << "|";
  fileOut << this->XL << "|";
  fileOut << this->XXL << endl;
}