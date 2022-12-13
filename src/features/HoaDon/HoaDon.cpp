#include "..\..\..\class\HoaDon.h"

HoaDon::HoaDon()
{
  this->listSP = new List<SanPham>();
}

HoaDon::HoaDon(List<SanPham> *listSP, const Ma &maHD, const Ma &maNV, const Ma &maKH, const bool &exported)
{
  this->maHD = maHD;
  this->maNV = maNV;
  this->maKH = maKH;
  this->listSP = listSP;
  this->tongTien = 0;
  this->soLuong = 0;
  this->exported = exported;
  this->ngayHD = Date(0, 0, 0, 0, 0);
}

HoaDon &HoaDon::operator=(const HoaDon &hoadon)
{
  this->maHD = hoadon.maHD;
  this->maNV = hoadon.maNV;
  this->maKH = hoadon.maKH;
  this->tongTien = hoadon.tongTien;
  this->soLuong = hoadon.soLuong;
  this->ngayHD = hoadon.ngayHD;
  this->exported = hoadon.exported;
  Node<SanPham> *pTemp = hoadon.listSP->getpHead();
  this->listSP = new List<SanPham>();
  while (pTemp)
  {
    this->listSP->push_back(pTemp->getData());
    pTemp = pTemp->getpNext();
  }
  return *this;
}

HoaDon::~HoaDon() {}

//--set, get
void HoaDon::setMaHD(const Ma &maHD)
{
  this->maHD = maHD;
}
void HoaDon::setMaNV(const Ma &maNV)
{
  this->maNV = maNV;
}
void HoaDon::setMaKH(const Ma &maKH)
{
  this->maKH = maKH;
}
void HoaDon::setSoLuong(const int &soLuong)
{
  this->soLuong = soLuong;
}
void HoaDon::setTongTien(const ll &tongTien)
{
  this->tongTien = tongTien;
}
void HoaDon::setNgayHD(const Date &ngayHD)
{
  this->ngayHD = ngayHD;
}
void HoaDon::setExported(const bool &exported)
{
  this->exported = exported;
}
void HoaDon::setListSP(List<SanPham> *listSP)
{
  this->listSP = listSP;
}
//-
const Ma &HoaDon::getMaHD()
{
  return this->maHD;
}

const int &HoaDon::getSTT()
{
  return this->maHD.getSoTT();
}
const Ma &HoaDon::getMaNV()
{
  return this->maNV;
}
const Ma &HoaDon::getMaKH()
{
  return this->maKH;
}
const int &HoaDon::getSoLuong()
{
  return this->soLuong;
}
const ll &HoaDon::getTongTienChi()
{
  Node<SanPham> *pTemp = this->listSP->getpHead();
  static ll TTT = 0;
  while (pTemp)
  {
    TTT += pTemp->getData().getGiaNhap();
    pTemp = pTemp->getpNext();
  }
  return TTT;
}
const ll &HoaDon::getTongTien()
{
  return this->tongTien;
}
const Date &HoaDon::getNgayHD()
{
  return this->ngayHD;
}
const bool &HoaDon::getExported()
{
  return this->exported;
}
List<SanPham> *HoaDon::getListSP()
{
  return this->listSP;
}

// Utils

void HoaDon::docFile(fstream &fileIn)
{
  this->maHD.docFile(fileIn);
  this->maNV.docFile(fileIn);
  this->maKH.docFile(fileIn);
  this->ngayHD.docFile(fileIn);
  fileIn >> this->exported;
  fileIn.ignore(1);
  fileIn >> this->soLuong;
  fileIn.ignore(1);

  this->tongTien = 0;
  for (int i = 0; i < this->soLuong; i++)
  {
    SanPham tempSP;
    tempSP.docFile(fileIn);
    this->tongTien += ll(tempSP.getSoLuong() * (1 - float(tempSP.getGiamGia() / 100)) * tempSP.getGiaBan());
    listSP->push_back(tempSP);
  }
}

void HoaDon::ghiFile(fstream &fileOut)
{
  this->maHD.ghiFile(fileOut);
  this->maNV.ghiFile(fileOut);
  this->maKH.ghiFile(fileOut);
  this->ngayHD.ghiFile(fileOut);
  fileOut << int(this->exported) << "|";
  fileOut << this->soLuong << "|";
  Node<SanPham> *pTemp = listSP->getpHead();
  while (pTemp)
  {
    pTemp->getData().ghiFile(fileOut);
    pTemp = pTemp->getpNext();
  }
}

void HoaDon::xuat()
{
  cout << center << "+------------------------------------------------+\n";
  cout << center << "|              THONG TIN HOA DON                 |\n";
  cout << center << "| Ma nhan vien: " << this->maNV << "                           |\n";
  cout << center << "| Ma khach hang: " << this->maKH << "                          |\n";
  cout << center << "| Ngay thuc hien hoa don: " << this->ngayHD << "      |\n";
  cout << center << "+------------------------------------------------+\n";

  ConsoleTable table = {"STT", "Ma san pham", "Ten san pham", "Size", "Don gia", "So luong", "Giam gia (%)", "Thanh tien"};
  int cnt = 0;
  Node<SanPham> *pTemp = this->listSP->getpHead();
  this->tongTien = 0;
  while (pTemp)
  {
    table += {to_string(++cnt), string(pTemp->getData().getMa()), pTemp->getData().getTen(), pTemp->getData().getSize(), to_string(pTemp->getData().getGiaBan()), to_string(pTemp->getData().getSoLuong()), to_string(pTemp->getData().getGiamGia()), to_string(ll(pTemp->getData().getSoLuong() * (1 - (float)pTemp->getData().getGiamGia() / 100) * pTemp->getData().getGiaBan()))};
    this->tongTien += ll(pTemp->getData().getSoLuong() * (1 - (float)pTemp->getData().getGiamGia() / 100) * pTemp->getData().getGiaBan());
    pTemp = pTemp->getpNext();
  }
  cout << center << "Don hang nay bao gom: " << cnt << " san pham\n";

  cout << table;

  cout << center << "\n\t\tTHANH TIEN: " << this->tongTien;
}

void HoaDon::xuatFile(fstream &fileHD)
{
  Date ngayX;
  fileHD << center << "+------------------------------------------------+\n";
  fileHD << center << "|              THONG TIN HOA DON                 |\n";
  fileHD << center << "| Ma nhan vien: " << this->maNV << "                           |\n";
  fileHD << center << "| Ma khach hang: " << this->maKH << "                          |\n";
  fileHD << center << "| Ngay tao hoa don: " << this->ngayHD << "            |\n";
  fileHD << center << "| Ngay xuat hoa don: " << ngayX << "           |\n";
  fileHD << center << "+------------------------------------------------+\n";
  ConsoleTable table = {"STT", "Ma san pham", "Ten san pham", "Size", "Don gia", "So luong", "Giam gia (%)", "Thanh tien"};
  int cnt = 0;
  Node<SanPham> *pTemp = this->listSP->getpHead();
  this->tongTien = 0;
  while (pTemp)
  {
    table += {to_string(++cnt), string(pTemp->getData().getMa()), pTemp->getData().getTen(), pTemp->getData().getSize(), to_string(pTemp->getData().getGiaBan()), to_string(pTemp->getData().getSoLuong()), to_string(pTemp->getData().getGiamGia()), to_string(ll(pTemp->getData().getSoLuong() * (1 - (float)pTemp->getData().getGiamGia() / 100) * pTemp->getData().getGiaBan()))};
    this->tongTien += ll(pTemp->getData().getSoLuong() * (1 - (float)pTemp->getData().getGiamGia() / 100) * pTemp->getData().getGiaBan());
    pTemp = pTemp->getpNext();
  }
  fileHD << center << "Don hang nay bao gom: " << cnt << " san pham\n";

  table.xuatFile(fileHD);

  fileHD << center << "\n\t\tTHANH TIEN: " << this->tongTien;
  this->exported = true;
}

void HoaDon::tinhTongTien()
{
  this->tongTien = 0;
  Node<SanPham> *pTemp = this->listSP->getpHead();
  while (pTemp)
  {
    this->tongTien += ll(pTemp->getData().getSoLuong() * (1 - (float)pTemp->getData().getGiamGia() / 100) * pTemp->getData().getGiaBan());
    pTemp = pTemp->getpNext();
  }
}