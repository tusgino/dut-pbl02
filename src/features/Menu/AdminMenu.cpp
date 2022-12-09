#include "..\..\..\class\Menu.h"

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

// void AdminMenu::printInfoThongKe()
// {
//   printUI("Data/Pages/thongke.txt");
//   cout << "\n\t\t1. Thong ke hoa don.";
//   cout << "\n\t\t2. Thong ke nhan vien.";
//   cout << "\n\t\t3. Quay lai";
// }

void AdminMenu::quanLiNhanVien(Menu &menu)
{
  bool check = true;
  while (check)
  {
    system("cls");
    // printUI("Data/Pages/qlnhanvien.txt");
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
      menu.DatabaseNV->read();
      char c;
      fflush(stdin);
      c = getchar();
    }
    break;
    case 2:
    {
      menu.DatabaseNV->create();
      char c;
      fflush(stdin);
      c = getchar();
    }
    break;
    case 3:
    {
      menu.DatabaseNV->find();
      char c;
      fflush(stdin);
      c = getchar();
    }
    break;
    case 4:
    {
      menu.DatabaseNV->update();
      char c;
      fflush(stdin);
      c = getchar();
    }
    break;
    case 5:
    {
      menu.DatabaseNV->deleteIndex();
      char c;
      fflush(stdin);
      c = getchar();
    }
    break;
    case 6:
    {
      check = false;
    }
    break;
    }
  }
}

void AdminMenu::quanLiSanPham(Menu &menu)
{
  bool check = true;
  while (check)
  {
    system("cls");
    // printUI("Data/Pages/qlsanpham.txt");
    cout << "\n\t\t1. Xuat danh sach san pham.";
    cout << "\n\t\t2. Them san pham.";
    cout << "\n\t\t3. Chinh sua san pham.";
    cout << "\n\t\t4. Tim kiem san pham.";
    cout << "\n\t\t5. Xoa san pham.";
    cout << "\n\t\t6. Quay lai.";
    int key = getKey(6);
    switch (key)
    {
    case 1:
    {
      menu.DatabaseSP->read();
      char c;
      fflush(stdin);
      c = getchar();
    }
    break;
    case 2:
    {
      menu.DatabaseSP->create();
      char c;
      fflush(stdin);
      c = getchar();
    }
    break;
    case 3:
    {
      menu.DatabaseSP->update();
      char c;
      fflush(stdin);
      c = getchar();
    }
    break;
    case 4:
    {
      menu.DatabaseSP->find();
      char c;
      fflush(stdin);
      c = getchar();
    }
    break;
    case 5:
    {
      menu.DatabaseSP->deleteIndex();
      char c;
      fflush(stdin);
      c = getchar();
    }
    break;
    case 6:
      check = false;
      break;
    }
  }
}

void AdminMenu::quanLiHoaDon(Menu &menu)
{
  bool check = true;
  while (check)
  {
    system("cls");
    // printUI("Data/Pages/qlhoadon.txt");
    cout << "\n\t\t1. Xuat danh sach hoa don.";
    cout << "\n\t\t2. Them hoa don.";
    cout << "\n\t\t3. Chinh sua hoa don.";
    cout << "\n\t\t4. Xuat chi tiet hoa don.";
    cout << "\n\t\t5. Xoa hoa don.";
    cout << "\n\t\t6. Quay lai.";
    int key = getKey(4);
    switch (key)
    {
    case 1:
    {
      menu.DatabaseHD->read();
      char c;
      fflush(stdin);
      c = getchar();
    }
    break;
    case 2:
    {
      menu.DatabaseHD->create();
      char c;
      fflush(stdin);
      c = getchar();
    }
    break;
    case 3:
    {
      menu.DatabaseHD->update();
      char c;
      fflush(stdin);
      c = getchar();
    }
    break;
    case 4:
    {
      // menu.DatabaseHD->Xuat();
      char c;
      fflush(stdin);
      c = getchar();
    }
    break;
    case 5:
    {
      menu.DatabaseHD->deleteIndex();
      char c;
      fflush(stdin);
      c = getchar();
    }
    break;
    case 6:
      check = false;
      break;
    }
  }
}

void AdminMenu::quanLiKhachHang(Menu &menu)
{
  bool check = true;
  while (check)
  {
    system("cls");
    // printUI("Data/Pages/qlkhachhang.txt");
    cout << "\n\t\t1. Xuat danh sach khach hang.";
    cout << "\n\t\t2. Them thong tin khach hang.";
    cout << "\n\t\t3. Chinh sua thong tin khach hang.";
    cout << "\n\t\t4. Tim kiem khach hang.";
    cout << "\n\t\t5. Xoa khach hang.";
    cout << "\n\t\t6. Quay lai.";
    int key = getKey(6);
    switch (key)
    {
    case 1:
    {
      menu.DatabaseKH->read();
      char c;
      fflush(stdin);
      c = getchar();
    }
    break;
    case 2:
    {
      menu.DatabaseKH->create();
      char c;
      fflush(stdin);
      c = getchar();
    }
    break;
    case 3:
    {
      menu.DatabaseKH->update();
      char c;
      fflush(stdin);
      c = getchar();
    }
    break;
    case 4:
    {
      menu.DatabaseKH->find();
      char c;
      fflush(stdin);
      c = getchar();
    }
    break;
    case 5:
    {
      menu.DatabaseKH->deleteIndex();
      char c;
      fflush(stdin);
      c = getchar();
    }
    break;
    case 6:
      check = false;
      break;
    }
  }
}

// void AdminMenu::thongKe(QuanLi *admin)
// {
//   system("cls");
//   printUI("Data/Pages/thongke.txt");
//   cout << "\n\t\t1. Thong ke hoa don.";
//   cout << "\n\t\t2. Thong ke san pham.";
//   cout << "\n\t\t3. Quay lai.";
//   int key = getKey(3);
//   switch (key)
//   {
//   case 1:
//   {
//     admin->DatabaseHD->thongKe();
//     system("pause");
//     AdminMenu::thongKe(admin);
//   }
//   break;
//   case 2:
//   {
//     admin->DatabaseHD->thongKeSanPham();
//     system("pause");
//     AdminMenu::thongKe(admin);
//   }
//   break;
//   case 3:
//     AdminMenu::adMenu(admin);
//     break;
//   }
// }

void AdminMenu::adMenu(Menu &menu)
{
  bool check = true;
  while (check)
  {
    system("cls");
    // printUI("Data/Pages/quanli.txt");
    printSuccess("Ban da dang nhap thanh cong!");
    cout << "\n\tVui long chon nhung tac vu de thuc hien";
    AdminMenu::printInfo();
    int key;
    key = getKey(7);
    switch (key)
    {
    case 1:
    {
      AdminMenu::quanLiNhanVien(menu);
    }
    break;
    case 2:
    {
      AdminMenu::quanLiSanPham(menu);
    }
    break;
    case 3:
    {
      AdminMenu::quanLiHoaDon(menu);
    }
    break;
    case 4:
    {
      AdminMenu::quanLiKhachHang(menu);
    }
    break;
    case 5:
    {
      // AdminMenu::thongKe();
    }
    break;
    case 7:
    {
      // admin->nhapFile();
      menu.setLog(false);
      check = false;
      return;
    }
    break;
    case 6:
    {
      // admin->nhapFile();
      // Menu::login();
      check = false;
    }
    break;
    }
  }
}
