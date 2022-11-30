#include "../../../class/Menu.h"

AdminMenu::AdminMenu()
{
}

AdminMenu::~AdminMenu()
{
}

void AdminMenu::printInfo()
{
  cout << "\n\t\t1. Quan li nhan vien.";
  cout << "\n\t\t2. Quan li san pham.";
  cout << "\n\t\t3. Quan li hoa don.";
  cout << "\n\t\t4. Quan li khach hang.";
  cout << "\n\t\t5. Thong ke.";
  cout << "\n\t\t6. Dang xuat";
  cout << "\n\t\t7. Thoat khoi chuong trinh.";
}

void AdminMenu::printInfoThongKe()
{
  printUI("Data/Pages/thongke.txt");
  cout << "\n\t\t1. Thong ke hoa don.";
  cout << "\n\t\t2. Thong ke nhan vien.";
  cout << "\n\t\t3. Quay lai";
}

void AdminMenu::quanLiNhanVien(QuanLi *admin)
{
  system("cls");
  printUI("Data/Pages/qlnhanvien.txt");
  cout << "\n\t\t1. Xuat danh sach nhan vien.";
  cout << "\n\t\t2. Them nhan vien.";
  cout << "\n\t\t3. Tim kiem nhan vien.";
  cout << "\n\t\t4. Chinh sua nhan vien";
  cout << "\n\t\t5. Xoa nhan vien.";
  cout << "\n\t\t6. Quay lai.";
  int key = getKey(6);
  switch (key)
  {
  case 1:
  {
    admin->DatabaseNV->inRaManHinh();
    system("pause");
    AdminMenu::quanLiNhanVien(admin);
  }
  break;
  case 2:
  {
    admin->DatabaseNV->addNhanVien();
    system("pause");
    AdminMenu::quanLiNhanVien(admin);
  }
  break;
  case 3:
  {
    admin->DatabaseNV->TimKiemNhanVien();
    system("pause");
    AdminMenu::quanLiNhanVien(admin);
  }
  break;
  case 4:
  {
    admin->DatabaseNV->ChinhSua();
    system("pause");
    AdminMenu::quanLiNhanVien(admin);
  }
  break;
  case 5:
  {
    admin->DatabaseNV->xoaNhanVien();
    system("pause");
    AdminMenu::quanLiNhanVien(admin);
  }
  break;
  case 6:
    AdminMenu::adMenu(admin);
    break;
  }
}

void AdminMenu::quanLiSanPham(QuanLi *admin)
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
    AdminMenu::quanLiSanPham(admin);
  }
  break;
  case 2:
  {
    admin->DatabaseSP->nhapTuNguoiDung();
    system("pause");
    AdminMenu::quanLiSanPham(admin);
  }
  break;
  case 3:
  {
    admin->DatabaseSP->capNhatDuLieu();
    system("pause");
    AdminMenu::quanLiSanPham(admin);
  }
  break;
  case 4:
  {
    admin->DatabaseSP->xoaSanPham();
    system("pause");
    AdminMenu::quanLiSanPham(admin);
  }
  break;
  case 5:
    AdminMenu::adMenu(admin);
    break;
  }
}

void AdminMenu::quanLiHoaDon(QuanLi *admin)
{
  system("cls");
  printUI("Data/Pages/qlhoadon.txt");
  cout << "\n\t\t1. Xuat danh sach hoa don.";
  cout << "\n\t\t2. Them hoa don.";
  cout << "\n\t\t3. Xuat chi tiet hoa don.";
  cout << "\n\t\t4. Quay lai.";
  int key = getKey(4);
  switch (key)
  {
  case 1:
  {
    admin->DatabaseHD->inRaManHinh();
    system("pause");
    AdminMenu::quanLiHoaDon(admin);
  }
  break;
  case 2:
  {
    admin->DatabaseHD->nhapTuNguoiDung();
    system("pause");
    AdminMenu::quanLiHoaDon(admin);
  }
  break;
  case 3:
  {
    admin->DatabaseHD->xuatChiTietHoaDon();
    system("pause");
    AdminMenu::quanLiHoaDon(admin);
  }
  break;
  case 4:
  {
    AdminMenu::adMenu(admin);
    system("pause");
  }
  }
}

void AdminMenu::quanLiKhachHang(QuanLi *admin)
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
    AdminMenu::quanLiKhachHang(admin);
  }
  break;
  case 2:
  {
    admin->DatabaseKH->addKhachHang();
    system("pause");
    AdminMenu::quanLiKhachHang(admin);
  }
  break;
  case 3:
  {
    admin->DatabaseKH->chinhSua();
    system("pause");
    AdminMenu::quanLiKhachHang(admin);
  }
  break;
  case 4:
  {
    admin->DatabaseKH->timKiemKhachHang();
    system("pause");
    AdminMenu::quanLiKhachHang(admin);
  }
  break;
  case 5:
    AdminMenu::adMenu(admin);
    break;
  }
}

void AdminMenu::thongKe(QuanLi *admin)
{
  system("cls");
  printUI("Data/Pages/thongke.txt");
  cout << "\n\t\t1. Thong ke hoa don.";
  cout << "\n\t\t2. Thong ke san pham.";
  cout << "\n\t\t3. Quay lai.";
  int key = getKey(3);
  switch (key)
  {
  case 1:
  {
    admin->DatabaseHD->thongKe();
    system("pause");
    AdminMenu::thongKe(admin);
  }
  break;
  case 2:
  {
    admin->DatabaseHD->thongKeSanPham();
    system("pause");
    AdminMenu::thongKe(admin);
  }
  break;
  case 3:
    AdminMenu::adMenu(admin);
    break;
  }
}

void AdminMenu::adMenu(QuanLi *admin)
{
  system("cls");
  printUI("Data/Pages/quanli.txt");
  printSuccess("Ban da dang nhap thanh cong!");
  cout << "\n\tVui long chon nhung tac vu de thuc hien";
  AdminMenu::printInfo();
  bool check = true;
  while (check)
  {
    int key;
    key = getKey(7);
    switch (key)
    {
    case 1:
    {
      AdminMenu::quanLiNhanVien(admin);
      system("pause");
      AdminMenu::adMenu(admin);
    }
    break;
    case 2:
    {
      AdminMenu::quanLiSanPham(admin);
      system("pause");
      AdminMenu::adMenu(admin);
    }
    break;
    case 3:
    {
      AdminMenu::quanLiHoaDon(admin);
      system("pause");
      AdminMenu::adMenu(admin);
    }
    break;
    case 4:
    {
      AdminMenu::quanLiKhachHang(admin);
      system("pause");
      AdminMenu::adMenu(admin);
    }
    break;
    case 5:
    {
      AdminMenu::thongKe(admin);
      system("pause");
      AdminMenu::adMenu(admin);
    }
    break;
    case 6:
    {
      admin->nhapFile();
      Menu::login();
    }
    break;
    case 7:
    {
      cout << "Thoat chuong trinh thanh cong\n";
      admin->nhapFile();
      check = false;
      return;
    }
    break;
    }
  }
}
