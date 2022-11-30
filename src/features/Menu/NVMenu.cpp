#include "../../../class/Menu.h"

NVMenu::NVMenu()
{
}

NVMenu::~NVMenu()
{
}

void NVMenu::printInfo()
{
  cout << "\n\t\t1. Quan li san pham.";
  cout << "\n\t\t2. Quan li hoa don.";
  cout << "\n\t\t3. Quan li khach hang.";
  cout << "\n\t\t4. Dang xuat";
  cout << "\n\t\t5. Thoat khoi chuong trinh.";
}

void NVMenu::quanLiSanPham(QuanLi *admin)
{
  system("cls");
  printUI("Data/Pages/qlsanpham.txt");
  cout << "\n\t\t1. Xuat danh sach san pham.";
  cout << "\n\t\t2. Them san pham.";
  cout << "\n\t\t3. Chinh sua san pham.";
  cout << "\n\t\t4. Xoa san pham.";
  cout << "\n\t\t5. Quay lai.";
  int key = getKey(5);
  switch (key)
  {
  case 1:
  {
    admin->DatabaseSP->xuat();
    system("pause");
    NVMenu::quanLiSanPham(admin);
  }
  break;
  case 2:
  {
    admin->DatabaseSP->nhapTuNguoiDung();
    system("pause");
    NVMenu::quanLiSanPham(admin);
  }
  break;
  case 3:
  {
    admin->DatabaseSP->capNhatDuLieu();
    system("pause");
    NVMenu::quanLiSanPham(admin);
  }
  break;
  case 4:
  {
    admin->DatabaseSP->xoaSanPham();
    system("pause");
    NVMenu::quanLiSanPham(admin);
  }
  break;
  case 5:
    NVMenu::nvMenu(admin);
    break;
  }
}

void NVMenu::quanLiHoaDon(QuanLi *admin)
{
  system("cls");
  printUI("Data/Pages/qlhoadon.txt");
  cout << "\n\t\t1. Them hoa don.";
  cout << "\n\t\t2. Xuat chi tiet hoa don.";
  cout << "\n\t\t3. Quay lai.";
  int key = getKey(3);
  switch (key)
  {
  case 1:
  {
    admin->DatabaseHD->nhapTuNguoiDung();
    system("pause");
    NVMenu::quanLiHoaDon(admin);
  }
  break;
  case 2:
  {
    admin->DatabaseHD->xuatChiTietHoaDon();
    system("pause");
    NVMenu::quanLiHoaDon(admin);
  }
  break;
  case 3:
  {
    NVMenu::nvMenu(admin);
    system("pause");
  }
  }
}

void NVMenu::quanLiKhachHang(QuanLi *admin)
{
  system("cls");
  printUI("Data/Pages/qlkhachhang.txt");
  cout << "\n\t\t1. Xuat danh sach khach hang.";
  cout << "\n\t\t2. Them thong tin khach hang.";
  cout << "\n\t\t3. Chinh sua thong tin khach hang.";
  cout << "\n\t\t4. Tim kiem khach hang.";
  cout << "\n\t\t5. Quay lai.";
  int key = getKey(5);
  switch (key)
  {
  case 1:
  {
    admin->DatabaseKH->inRaManHinh();
    system("pause");
    NVMenu::quanLiKhachHang(admin);
  }
  break;
  case 2:
  {
    admin->DatabaseKH->addKhachHang();
    system("pause");
    NVMenu::quanLiKhachHang(admin);
  }
  break;
  case 3:
  {
    admin->DatabaseKH->chinhSua();
    system("pause");
    NVMenu::quanLiKhachHang(admin);
  }
  break;
  case 4:
  {
    admin->DatabaseKH->timKiemKhachHang();
    system("pause");
    NVMenu::quanLiKhachHang(admin);
  }
  break;
  case 5:
    NVMenu::nvMenu(admin);
    break;
  }
}

void NVMenu::nvMenu(QuanLi *admin)
{
  system("cls");
  printUI("Data/Pages/nhanvien.txt");
  printSuccess("Ban da dang nhap thanh cong!");
  cout << "\n\tVui long chon nhung tac vu de thuc hien";
  NVMenu::printInfo();
  bool check = true;
  while (check)
  {
    int key;
    key = getKey(5);
    switch (key)
    {
    case 1:
    {
      NVMenu::quanLiSanPham(admin);
      system("pause");
      NVMenu::nvMenu(admin);
    }
    break;
    case 2:
    {
      NVMenu::quanLiHoaDon(admin);
      system("pause");
      NVMenu::nvMenu(admin);
    }
    break;
    case 3:
    {
      NVMenu::quanLiKhachHang(admin);
      system("pause");
      NVMenu::nvMenu(admin);
    }
    break;
    case 4:
    {
      admin->nhapFile();
      Menu::login();
    }
    break;
    case 5:
    {
      cout << "Thoat chuong trinh thanh cong\n";
      admin->nhapFile();
      check = false;
    }
    break;
    }
  }
}
