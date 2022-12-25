#include "..\..\..\class\Menu.h"

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

void NVMenu::quanLiSanPham(Menu &menu)
{
  menu.quanLi = menu.DatabaseSP;
  bool check = true;
  while (check)
  {
    system("cls");
    printUI("src/components/data/Pages/qlsanpham.txt");
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
      menu.quanLi->read();
      char c;
      fflush(stdin);
      c = getchar();
    }
    break;
    case 2:
    {
      menu.quanLi->create();
      char c;
      fflush(stdin);
      c = getchar();
    }
    break;
    case 3:
    {
      menu.quanLi->update();
      char c;
      fflush(stdin);
      c = getchar();
    }
    break;
    case 4:
    {
      menu.quanLi->find();
      char c;
      fflush(stdin);
      c = getchar();
    }
    break;
    case 5:
    {
      menu.quanLi->deleteIndex();
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

void NVMenu::quanLiHoaDon(Menu &menu)
{
  bool check = true;
  while (check)
  {
    system("cls");
    printUI("src/components/data/Pages/qlhoadon.txt");
    cout << "\n\t\t1. Xuat danh sach hoa don.";
    cout << "\n\t\t2. Them hoa don.";
    cout << "\n\t\t3. Chinh sua hoa don.";
    cout << "\n\t\t4. Xuat chi tiet hoa don.";
    cout << "\n\t\t5. Xoa hoa don.";
    cout << "\n\t\t6. Quay lai.";
    int key = getKey(6);
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
      menu.DatabaseHD->xuatFile();
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

void NVMenu::quanLiKhachHang(Menu &menu)
{
  menu.quanLi = menu.DatabaseKH;
  bool check = true;
  while (check)
  {
    menu.quanLi->sort();
    system("cls");
    printUI("src/components/data/Pages/qlkhachhang.txt");
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
      menu.quanLi->read();
      char c;
      fflush(stdin);
      c = getchar();
    }
    break;
    case 2:
    {
      menu.quanLi->create();
      char c;
      fflush(stdin);
      c = getchar();
    }
    break;
    case 3:
    {
      menu.quanLi->update();
      char c;
      fflush(stdin);
      c = getchar();
    }
    break;
    case 4:
    {
      menu.quanLi->find();
      char c;
      fflush(stdin);
      c = getchar();
    }
    break;
    case 5:
    {
      menu.quanLi->deleteIndex();
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

void NVMenu::nvMenu(Menu &menu)
{
  bool check = true;
  while (check)
  {
    system("cls");
    printUI("src/components/data/Pages/quanli.txt");
    printSuccess("Ban da dang nhap thanh cong!");
    cout << "\n\tVui long chon nhung tac vu de thuc hien";
    NVMenu::printInfo();
    int key;
    key = getKey(5);
    switch (key)
    {
    case 1:
    {
      NVMenu::quanLiSanPham(menu);
    }
    break;
    case 2:
    {
      NVMenu::quanLiHoaDon(menu);
    }
    break;
    case 3:
    {
      NVMenu::quanLiKhachHang(menu);
    }
    break;
      break;
    case 5:
    {
      // admin->nhapFile();
      menu.setLog(false);
      check = false;
      return;
    }
    break;
    case 4:
    {
      // admin->nhapFile();
      // Menu::login();
      check = false;
    }
    break;
    }
  }
}
