#include "Sample.h"

class QLKhachHang : public QuanLi{
    List<KhachHang> *dbKH;
    int count;

    public:
    QLKhachHang();
    ~QLKhachHang();

    void docFile(fstream &);
    void ghiFile(fstream &);
    void create();      // Nhap tu nguoi dung
    void update();      // Chinh sua
    void read();        // Xuat ra man hinh
    void find();        // Tim Kiem
    void deleteIndex(); // Xoa
};