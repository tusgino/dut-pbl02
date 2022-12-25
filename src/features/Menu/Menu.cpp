#include "..\..\..\class\Menu.h"
Menu::Menu()
{
    this->log = true;
    this->DatabaseNV = new QLNhanVien();
    fstream fileNhanVien;
    fileNhanVien.open(dataNhanVien, ios_base::in);
    this->DatabaseNV->docFile(fileNhanVien);

    this->DatabaseSP = new QLSanPham();
    fstream fileSanPham;
    fileSanPham.open(dataSanPham, ios_base::in);
    this->DatabaseSP->docFile(fileSanPham);

    this->DatabaseKH = new QLKhachHang();
    fstream fileKhachHang;
    fileKhachHang.open(dataKhachHang, ios_base::in);
    this->DatabaseKH->docFile(fileKhachHang);

    this->DatabaseHD = new QLHoaDon(this->DatabaseNV, this->DatabaseKH, this->DatabaseSP);
    fstream fileHoaDon;
    fileHoaDon.open(dataHoaDon, ios_base::in);
    this->DatabaseHD->docFile(fileHoaDon);

    fileNhanVien.close();
    fileSanPham.close();
    fileKhachHang.close();
    fileHoaDon.close();
}

Menu::~Menu()
{
    delete this->DatabaseNV;
    delete this->DatabaseSP;
    delete this->DatabaseKH;
    delete this->DatabaseHD;
}

void Menu::setLog(const bool &log)
{
    this->log = log;
}

void Menu::checkLogin()
{
    while (true)
    {
        system("cls");
        printUI("src/components/data/Pages/dangnhap.txt");
        string mk;
        // Ma tk;
        string tk;
        cout << "\t\tVui long nhap tai khoan, mat khau de dang nhap he thong.";
        cout << "\n\t\tTen dang nhap: ";
        fflush(stdin);
        getline(cin, tk);
        cout << "\t\tMat Khau: ";
        fflush(stdin);
        string tempPass = "";
        char c;
        c = getch();
        while (c != 10 && c != 13)
        {
            if (c != 8)
            {
                cout << "*";
                tempPass += c;
                c = getch();
            }
            else if (tempPass.length() > 0)
            {
                cout << "\b \b";
                tempPass = tempPass.erase(tempPass.size() - 1);
                c = getch();
            }
            else
            {
                c = getch();
            }
        }
        mk = tempPass;
        fstream fileAdmin;
        fileAdmin.open("src/components/data/Admin.DAT");

        int size;
        fileAdmin >> size;
        fileAdmin.ignore(1);
        for (int i = 0; i < size; i++)
        {
            Ma checkMa;
            string checktk, checkmk;

            // getline(fileAdmin, checktk, '|');
            checkMa.docFile(fileAdmin);
            getline(fileAdmin, checkmk, '|');
            // cout << checktk << " " << string(tk) << endl;
            if (checkmk.compare(mk) == 0 && string(checkMa).compare(tk) == 0)
            {
                this->checkRole = 3;
                // cout << "Hello !! Ban dang truy cap voi quyen quan tri vien." << endl;
                // Ma ma("AD", 1);
                this->DatabaseHD->setMaDangNhap(checkMa);

                return;
                break;
            }
        }
        Ma matemp;
        int role = DatabaseNV->checkRole(tk, mk, matemp);
        if (role == -1)
        {
            printError("Tai khoan dang nhap hoac mat khau khong chinh xac! Vui long thu lai");
            char q;
            cout << "\n\tBan co muon tiep tuc dang nhap (y/n)?";
            fflush(stdin);
            q = getchar();
            cout << "\n";
            if (q == 'n')
                return;
        }
        else
        {
            this->checkRole = role;
            this->DatabaseHD->setMaDangNhap(matemp);
            return;
        }
    }
};

void Menu::login()
{
    while (this->log)
    {
        Menu::checkLogin();
        switch (this->checkRole)
        {
        case 1:
            NVMenu::nvMenu(*this);
            break;
        case 2:
            AdminMenu::adMenu(*this);
            break;
        case 3:
            AdminMenu::adMenu(*this);
            break;
        }
    }
}