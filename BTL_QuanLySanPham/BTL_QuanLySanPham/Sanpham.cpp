#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<stdio.h>
#include<conio.h>
#include<string.h>
using namespace std;
#define MAX 100

//Khởi Tạo Struct Sản Phẩm
struct SanPham
{
	string maSP;
	string tenSP;
	string donViTinh;
	double giaMua;
	double giaBan;
};

//Khai Báo Nguyên Mẫu Hàm
void doc1SP(ifstream &inFile, SanPham &sp);
void xuatThongTin1SP(SanPham sp);
void docDSSP(ifstream &inFile, SanPham arrSP[MAX]);
void xuatDSSP(SanPham arrSP[MAX], int &n);
void timKiemSPTheoMaSP(SanPham arrSP[MAX], int &n, string maSP);
bool kiemTraTrungMaSP(SanPham arrSP[MAX], int &n, string maSP);
void themSP(ofstream &outFile, SanPham arrSP[MAX], int &n, int vt);
void inDanhSachSPTheoKhoangGia(SanPham arrSP[MAX], int &n, int tuGia, int denGia);
void hoanDoiHaiSanPhamTheoGia(SanPham arrSP[MAX], int &n);
void inDanhSachSanPhamGiamDanTheoGia(SanPham arrSP[MAX], int &n);
void xoaSanPham(SanPham arrSP[MAX], int &n, int vt);
void hoanDoiHaiSanPhamTheoTen(SanPham arrSP[MAX], int &n);
void inDanhSachSanPhamTangDanTheoTen(SanPham arrSP[MAX], int &n);
void xoaSanPhamTheoMaSP(SanPham arrSP[MAX], int &n, string maSP);


int main()
{
	ifstream inFile;
	inFile.open("inputSP.txt", ios::in);

	SanPham sp;
	//Khởi tạo Mảng danh sách Sản Phẩm
	SanPham arrSP[MAX];

	//Kiểm tra tình trạng đọc file
	if (inFile.is_open())
	{
		cout << "==> Mo file thanh cong !!!" << endl;
		cout << "\n--------------------------------------------------\n" << endl;
	}
	else
	{
		cout << "==> Khong mo duoc file !!!" << endl;
		cout << "\n--------------------------------------------------\n" << endl;
	}
	//---------------------------------------------------------------------------

	int choice;
	do {
		cout << "\n===================QUAN LY SAN PHAM===================\n";
		cout << "\n= 1 . In Danh Sach San Pham                          =\n";
		cout << "\n= 2 . Tim San Pham Theo Ma San Pham                  =\n";
		cout << "\n= 3 . In Danh Sach San Pham Theo Ten Tang Dan        =\n";
		cout << "\n= 4 . In Danh Sach San Pham Theo Gia Ban Giam Dan    =\n";
		cout << "\n= 5 . In Danh Sach San Pham Theo Khoang Gia          =\n";
		cout << "\n= 6 . Them San Pham									=\n";
		cout << "\n= 7 . Xoa San Pham                                   =\n";
		cout << "\n= 8 . Thoat                                          =\n";
		cout << "\n======================================================\n";

		cout << "Nhap lua chon cua ban: ";
		cin >> choice;

		//Đọc dữ liệu từ file input.txt
		docDSSP(inFile, arrSP);

		switch (choice)
		{
		case 1:
		{
			int n;
			cout << "\nNhap so luong San Pham can xuat: ";
			cin >> n;

			cout << "\n ++ Danh Sach San Pham ++ \n" << endl;
			xuatDSSP(arrSP, n);
			break;
		}
		case 2:
		{
			int n;
			cout << "\nNhap so luong San Pham can xuat: ";
			cin >> n;

			string maSP;
			cout << "Hay nhap Ma San Pham can tim: ";
			cin >> maSP;
			timKiemSPTheoMaSP(arrSP, n, maSP);
			break;
		}
		case 3:
		{
			int n;
			cout << "\nNhap so luong San Pham can xuat: ";
			cin >> n;

			cout << "\n++ In danh sach San Pham theo Ten Tang Dan (a - z) ++\n";
			inDanhSachSanPhamTangDanTheoTen(arrSP, n);
			break;
		}
		case 4:
		{
			int n;
			cout << "\nNhap so luong San Pham can xuat: ";
			cin >> n;

			cout << "\n++ Danh sach San Pham giam dan theo Gia Ban ++\n";
			inDanhSachSanPhamGiamDanTheoGia(arrSP, n);
			break;
		}
		case 5:
		{
			int tuGia, denGia;
			cout << "\n---> Nhap vao khoang gia\n";
			cout << "\nTu Gia: ";
			cin >> tuGia;
			cout << "\nDen Gia: ";
			cin >> denGia;

			int n;
			cout << "\nNhap so luong San Pham can xuat: ";
			cin >> n;

			cout << "\n++ Danh sach San Pham theo Khoang Gia ++\n";
			inDanhSachSPTheoKhoangGia(arrSP, n, tuGia, denGia);
			break;
		}
		case 6:
		{
			//Lưu ý: Nhập số lượng Sản Phẩm cần xuất = Số thứ tự Sản Phẩm muốn thêm kế tiếp
			ofstream outFile;
			outFile.open("inputSP.txt", ios::app);

			int n;
			cout << "\nNhap so luong San Pham can xuat: ";
			cin >> n;

			int vt;
			//Nhập số thứ tự Sản Phẩm tiếp theo
			cout << "\nNhap thu tu them SanPham: ";
			cin >> vt;

			cout << endl;
			themSP(outFile, arrSP, n, vt);
			break;
		}
		case 7:
		{

			//Lưu ý: Vẫn nhập số lượng Sản Phẩm cần xuất như số lượng hiện tại
			int n;
			cout << "\nNhap so luong San Pham can xuat: ";
			cin >> n;

			string maSP;
			cout << "\nNhap Ma San Pham can xoa: ";
			cin >> maSP;
			cout << "\n++ Danh Sach San Pham sau khi xoa ++\n";
			xoaSanPhamTheoMaSP(arrSP, n, maSP);
			break;
		}
		case 8:
		{
			cout << "\nKet Thuc Chuong Trinh !!!" << endl;
			exit(0);
		}
		}

	} while (choice > 0);

	//Đóng file khi hoàn thành
	inFile.close();

	system("pause");
	return 0;
}
//Đọc 1 Sản Phẩm trên 1 dòng từ file txt
void doc1SP(ifstream &inFile, SanPham &sp)
{
	getline(inFile, sp.maSP, '#');
	getline(inFile, sp.tenSP, '#'); //Đọc trên một chuỗi, tới dấu # thì dừng
	getline(inFile, sp.donViTinh, '#');
	inFile >> sp.giaMua;
	inFile.ignore(1); //Bỏ qua dấu '#'
	inFile >> sp.giaBan;
	inFile.ignore(1); //Bỏ qua newline
}
//Đọc danh sách Sản Phẩm
void docDSSP(ifstream &inFile, SanPham arrSP[MAX])
{
	for (int i = 0; inFile.eof() == false; i++)
	{
		doc1SP(inFile, arrSP[i]);
		arrSP[i].maSP;
		arrSP[i].tenSP;
		arrSP[i].donViTinh;
		arrSP[i].giaMua;
		arrSP[i].giaBan;
	}
}
//Xuất thông tin 1 Sản Phẩm
void xuatThongTin1SP(SanPham sp)
{
	cout << "Ma SP: " << sp.maSP << endl;
	cout << "Ten SP: " << sp.tenSP << endl;
	cout << "Don Vi Tinh: " << sp.donViTinh << endl;
	cout << "Gia Mua: " << sp.giaMua << endl;
	cout << "Gia Ban: " << sp.giaBan << endl;
}
//Xuất danh sách Sản Phẩm
void xuatDSSP(SanPham arrSP[MAX], int &n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "San pham thu " << i + 1 << endl;
		xuatThongTin1SP(arrSP[i]); //In ra Sản Phẩm thứ i
		cout << "==========================" << endl;
	}
}
//Tìm kiếm Sản Phẩm theo Mã Sản Phẩm
void timKiemSPTheoMaSP(SanPham arrSP[MAX], int &n, string maSP)
{
	for (int i = 0; i < n; i++)
	{
		if (arrSP[i].maSP == maSP) {
			cout << "\n==> Tim thay San Pham !!" << endl;
			xuatThongTin1SP(arrSP[i]);
			return;
		}
	}
	cout << "\nKhong tim thay San Pham nay !!" << endl;
}
//Kiểm tra trùng tính trùng lặp Mã Sản Phẩm
bool kiemTraTrungMaSP(SanPham arrSP[MAX], int &n, string maSP) {
	bool flag = true;

	char* cstr2 = new char[maSP.length() + 1]; //Chuyển chuỗi sang kiểu char để dùng c_string
	strcpy(cstr2, maSP.c_str());

	for (int i = 0; i < n; i++) {
		char* cstr1 = new char[arrSP[i].maSP.length() + 1]; //Chuyển chuỗi sang kiểu char để dùng c_string
		strcpy(cstr1, arrSP[i].maSP.c_str());

		if (strcmp(cstr1, cstr2) == 0) {
			flag = false;
			return flag;
		}
	}

	return flag;
}
//Thêm Sản Phẩm mới vào mảng SP & thêm dòng mới vào inputSP.txt
void themSP(ofstream &outFile, SanPham arrSP[MAX], int &n, int vt)
{
	vt--;
	cin.ignore();
	cout << "Ma San Pham: ";
	cin >> arrSP[vt].maSP;
	cin.ignore();
	cout << "Ten San Pham: ";
	getline(cin, arrSP[vt].tenSP);
	cout << "Don Vi Tinh: ";
	getline(cin, arrSP[vt].donViTinh);
	cout << "Gia Mua: ";
	cin >> arrSP[vt].giaMua;
	cout << "Gia Ban: ";
	cin >> arrSP[vt].giaBan;

	n--; //Giảm độ dài mảng xuống 1 ô, chỉ xét tính trùng lặp của các Sản Phẩm ban đầu
	if (kiemTraTrungMaSP(arrSP, n, arrSP[vt].maSP)) {
		outFile << arrSP[vt].maSP << '#' << arrSP[vt].tenSP << '#' << arrSP[vt].donViTinh << '#' << arrSP[vt].giaMua << '#' << arrSP[vt].giaBan << endl;
		outFile.close();
		cout << "\n==> Them San Pham thanh cong !!" << endl;
		//Xuất DS Sản Phẩm sau khi thêm
		cout << "\n++ Danh sach San Pham sau khi them ++" << endl;
		n++; //Tăng mảng lên 1 ô để xuất đủ số lượng Sản Phẩm sau khi thêm 1 Sản Phẩm mới
		xuatDSSP(arrSP, n);
	}
	else {
		cout << "\n==> Trung Ma San Pham !!" << endl;
		cout << "\n++ Danh sach San Pham ban dau ++" << endl;
		xuatDSSP(arrSP, n);
	}
}
//Xóa Sản Phẩm theo Mã Sản Phẩm
void xoaSanPhamTheoMaSP(SanPham arrSP[MAX], int &n, string maSP) {

	int vt = 0;

	char* cstr2 = new char[maSP.length() + 1]; //Chuyển chuỗi sang kiểu char để dùng c_string
	strcpy(cstr2, maSP.c_str());

	for (int i = 0; i < n; i++) {
		char* cstr1 = new char[arrSP[i].maSP.length() + 1]; //Chuyển chuỗi sang kiểu char để dùng c_string
		strcpy(cstr1, arrSP[i].maSP.c_str());

		if (strcmp(cstr1, cstr2) == 0) {
			vt = i;
			break;
		}
	}
	xoaSanPham(arrSP, n, vt);
}
//Xóa Sản Phẩm theo số thứ tự
void xoaSanPham(SanPham arrSP[MAX], int &n, int vt) {
	for (int i = vt; i < n; i++) {
		arrSP[i] = arrSP[i + 1];
	}
	n--; //Trừ đi 1 ô, giảm kích thước mảng sau khi xóa 1 Sản Phẩm
	xuatDSSP(arrSP, n);
}
////In danh sách Sản Phẩm theo khoảng giá
void inDanhSachSPTheoKhoangGia(SanPham arrSP[MAX], int &n, int tuGia, int denGia)
{
	for (int i = 0; i < n; i++) {
		if (arrSP[i].giaBan >= tuGia && arrSP[i].giaBan <=denGia)
		{
			xuatThongTin1SP(arrSP[i]);
			cout << endl;
		}
	}
}
//Swap (Hoán đổi) hai Sản Phẩm theo giá bán
void hoanDoiHaiSanPhamTheoGia(SanPham arrSP[MAX], int &n)
{
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arrSP[i].giaBan < arrSP[j].giaBan) {
				SanPham tempSP = arrSP[i];
				arrSP[i] = arrSP[j];
				arrSP[j] = tempSP;
			}
		}
	}
}
//In danh sách Sản Phẩm có Giá Bán giảm dần
void inDanhSachSanPhamGiamDanTheoGia(SanPham arrSP[MAX], int &n)
{
	hoanDoiHaiSanPhamTheoGia(arrSP, n);
	xuatDSSP(arrSP, n);
}
//Swap (Hoán đổi) hai Sản Phẩm theo tên
void hoanDoiHaiSanPhamTheoTen(SanPham arrSP[MAX], int &n) {
	for (int i = 0; i < n - 1; i++) {
		char* cstr1 = new char[arrSP[i].tenSP.length() + 1]; //Chuyển chuỗi sang kiểu char để dùng c_string
		strcpy(cstr1, arrSP[i].tenSP.c_str());

		for (int j = i + 1; j < n; j++) {
			char* cstr2 = new char[arrSP[j].tenSP.length() + 1]; //Chuyển chuỗi sang kiểu char để dùng c_string
			strcpy(cstr2, arrSP[j].tenSP.c_str());

			//Chú Thích:
			// > 0 => a -> z ;
			// < 0 => z -> a ;
			// = 0 => Hai chuỗi bằng nhau 
			if (strcmp(cstr1, cstr2) > 0) {
				SanPham tempSP = arrSP[i];
				arrSP[i] = arrSP[j];
				arrSP[j] = tempSP;
			}
		}
	}
}
//In danh sách Sản Phẩm theo Tên tăng dần
void inDanhSachSanPhamTangDanTheoTen(SanPham arrSP[MAX], int &n) {
	hoanDoiHaiSanPhamTheoTen(arrSP, n);
	xuatDSSP(arrSP, n);
}
