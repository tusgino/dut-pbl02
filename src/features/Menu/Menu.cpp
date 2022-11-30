#include "../../../class/Menu.h"
// #include "AdminMenu.cpp"
// #include "NVMenu.cpp"
Menu::Menu()
{
}

Menu::~Menu()
{
}

void Menu::login()
{
    QLKhachHang *user = new quanLiKhachHang();
    // QuanLi *user;
    // user = new QuanLi();
    // user->dangNhap();
    // int role = user->getRole();
    // switch (role)
    // {
    // case 1:
    //     NVMenu::nvMenu(user);
    //     break;
    // case 2:
    //     AdminMenu::adMenu(user);
    //     break;
    // case 3:
    //     AdminMenu::adMenu(user);
    //     break;
    // }
    system("pause");
}