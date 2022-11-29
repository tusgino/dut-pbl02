
#include "..\..\..\Class\LoaiSanPham.h"
#include <fstream>
#include <string>

using namespace std;

loaiSanPham::loaiSanPham()
{
  this->idMax = 0;
}

loaiSanPham::~loaiSanPham() {}

void loaiSanPham::setName(string name)
{
  this->name = name;
}

void loaiSanPham::setKeyWord(char keyWord)
{
  this->keyWord = keyWord;
}

void loaiSanPham::setIDmax(int idMax)
{
  this->idMax = idMax;
}

int loaiSanPham::getIDMax()
{
  return this->idMax;
}

void loaiSanPham::setAmountProduct(int amountProduct)
{
  this->amountProduct = amountProduct;
}

int loaiSanPham::getAmountProduct()
{
  return this->amountProduct;
}

char loaiSanPham::getKeyWord()
{
  return this->keyWord;
}

string loaiSanPham::getName()
{
  return this->name;
}

void loaiSanPham::readFromFile(fstream &fileIn)
{
  getline(fileIn, this->name, '|');
  loaiSanPham::setKeyWord(name.at(0));
  fileIn >> this->amountProduct;
  fileIn.ignore(1);
  fileIn >> this->idMax;
  fileIn.ignore(1);
}

void loaiSanPham::writeToFile(fstream &fileOut)
{
  fileOut << this->name << "|" << this->amountProduct << "|" << this->idMax << endl;
}
