
#include "..\..\..\Class\QuanLi.h"
#include <fstream>
#include <conio.h>

QuanLi::QuanLi()
{
    this->DatabaseNV = new QLNhanVien();
    fstream fileNhanVien;
    fileNhanVien.open("Data/NhanVien.DAT", ios_base::in);
    this->DatabaseNV->nhapTuFile(fileNhanVien);

    this->DatabaseSP = new QLSanPham();
    fstream fileSanPham;
    fileSanPham.open("Data/SanPham.DAT", ios_base::in);
    this->DatabaseSP->nhapTuFile(fileSanPham);

    this->DatabaseKH = new QLKhachHang();
    fstream fileKhachHang;
    fileKhachHang.open("Data/KhachHang.DAT", ios_base::in);
    this->DatabaseKH->nhapTuFile(fileKhachHang);

    this->DatabaseHD = new QLHoaDon(DatabaseSP, DatabaseNV, DatabaseKH);
    fstream fileHoaDon;
    fileHoaDon.open("Data/HoaDon.DAT", ios_base::in);
    this->DatabaseHD->nhapTuFile(fileHoaDon);

    fileNhanVien.close();
    fileSanPham.close();
    fileKhachHang.close();
    fileHoaDon.close();
}

QuanLi::~QuanLi()
{
}

void QuanLi::nhapFile()
{
    fstream fileSanPham;
    fstream fileNhanVien;
    fstream fileKhachHang;
    fstream fileHoaDon;

    fileSanPham.open("Data/SanPham.DAT", ios_base::out);
    this->DatabaseSP->ghiVaoFile(fileSanPham);

    fileNhanVien.open("Data/NhanVien.DAT", ios_base::out);
    this->DatabaseNV->ghiVaoFile(fileNhanVien);

    fileKhachHang.open("Data/KhachHang.DAT", ios_base::out);
    this->DatabaseKH->ghiVaoFile(fileKhachHang);

    fileHoaDon.open("Data/HoaDon.DAT", ios_base::out);
    this->DatabaseHD->ghiVaoFile(fileHoaDon);

    fileSanPham.close();
    fileNhanVien.close();
    fileKhachHang.close();
    fileHoaDon.close();
}

int QuanLi::getRole()
{
    return checkRole;
}

void QuanLi::dangNhap()
{
    while (true)
    {
        system("cls");
        printUI("Data/Pages/dangnhap.txt");
        string tk, mk;
        cout << "\t\tVui long nhap tai khoan, mat khau de dang nhap he thong.";
        cout << "\n\t\tTen dang nhap: ";
        fflush(stdin);
        getline(cin, tk);
        cout << "\t\tMat Khau: ";
        fflush(stdin);
        string tempPass = "";
        char c = getchar();
        while (c != 10 && c != 13)
        {
            if (c != 8)
            {
                cout << '*';
                tempPass += c;
                c = getchar();
            }
            else if (tempPass.length() > 0)
            {
                cout << "\b \b";
                tempPass = tempPass.erase(tempPass.size() - 1);
                c = getchar();
            }
            else
            {
                c = getchar();
            }
        }
        mk = tempPass;
        fstream fileAdmin;
        fileAdmin.open("Data/Admin.data");

        int size;
        fileAdmin >> size;
        fileAdmin.ignore(1);
        for (int i = 0; i < size; i++)
        {
            string checktk, checkmk;

            getline(fileAdmin, checktk, '|');
            getline(fileAdmin, checkmk, '|');
            if (checkmk.compare(mk) == 0 && checktk.compare(tk) == 0)
            {
                this->checkRole = 3;
                // cout << "Hello !! Ban dang truy cap voi quyen quan tri vien." << endl;
                this->DatabaseHD->setMaDangNhap(1);

                return;
                break;
            }
        }

        Node<NhanVien> *pTemp = this->DatabaseNV->getQLNV()->getpHead();

        for (int i = 0; i < this->DatabaseNV->getSize(); i++)
        {
            string checktk, checkmk;
            checktk = to_string(pTemp->getData().getMaNhanVien());
            checkmk = pTemp->getData().getMatKhau();

            if (checkmk.compare(mk) == 0 && checktk.compare(tk) == 0)
            {
                if (pTemp->getData().getMaNhanVien() < 2000)
                {
                    this->checkRole = 1;
                    // cout << "Hello Nhan Vien";
                }
                else
                {
                    this->checkRole = 2;
                    // cout << "Hello Quan li ..";
                }
                this->DatabaseHD->setMaDangNhap(pTemp->getData().getMaNhanVien());
                return;
            }
            pTemp = pTemp->getpNext();
        }
        printError("Tai khoan dang nhap hoac mat khau khong chinh xac! Vui long thu lai");
        char q;
        cout << "\n\tBan co muon tiep tuc dang nhap (y/n)?";
        fflush(stdin);
        q = getch();
        cout << "\n";
        if (q == 'n')
            return;
    }
}
