#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<stdio.h>
#include<conio.h>
#include<string.h>
using namespace std;
#define MAX 50

struct SinhVien
{
	string mssv;
	string ho;
	string ten;
	double diemMon1;
	double diemMon2;
};

void doc1SV(ifstream &inFile, SinhVien &sv);
void xuatThongTin1SV(SinhVien sv);
void docDSSV(ifstream &inFile, SinhVien arrSV[MAX]);
void xuatDSSV(SinhVien arrSV[MAX], int &n);
void timKiemSVTheoMSSV(SinhVien arrSV[MAX], int &n, string mssv);
void themSV(ofstream &outFile, SinhVien arrSV[MAX], int &n, int vt);
void inDanhSachSVDau(SinhVien arrSV[MAX], int &n);
void inDanhSachSVRot(SinhVien arrSV[MAX], int &n);
void hoanDoiHaiSinhVienTheoDTB(SinhVien arrSV[MAX], int &n);
void inDanhSachSinhVienGiamDanTheoDTB(SinhVien arrSV[MAX], int &n);
void xoaSinhVien(SinhVien arrSV[MAX], int &n, int vt);
void hoanDoiHaiSinhVienTheoTen(SinhVien arrSV[MAX], int &n);
void inDanhSachSinhVienTangDanTheoTen(SinhVien arrSV[MAX], int &n);


int main()
{
	ifstream inFile;
	inFile.open("input.txt", ios::in);

	SinhVien sv;
	//Khởi tạo Mảng danh sách sinh viên
	SinhVien arrSV[MAX];

	//Kiểm tra tình trạng đọc file
	if (inFile.is_open())
	{
		cout << "Mo file thanh cong !!!" << endl;
		cout << "\n--------------------------------------------------\n" << endl;
	}
	else
	{
		cout << "Khong mo duoc file !!!" << endl;
		cout << "\n--------------------------------------------------\n" << endl;
	}
	//--------------------------------------

	int choice;
	do {
		cout << "\n================QUAN LY SINH VIEN================\n";
		cout << "\n= 1 . In Danh Sach Sinh Vien                    =\n";
		cout << "\n= 2 . Tim Sinh Vien Theo MSSV                   =\n";
		cout << "\n= 3 . In Danh Sach Sinh Vien Theo Ten Tang Dan  =\n";
		cout << "\n= 4 . In Danh Sach Sinh Vien Theo DTB Giam Dan  =\n";
		cout << "\n= 5 . In Danh Sach Sinh Vien Dau                =\n";
		cout << "\n= 6 . In Danh Sach Sinh Vien Rot                =\n";
		cout << "\n= 7 . Them Sinh Vien                            =\n";
		cout << "\n= 8 . Xoa Sinh Vien                             =\n";
		cout << "\n= 9 . Thoat                                     =\n";
		cout << "\n=================================================\n";

		cout << "Nhap lua chon cua ban: ";
		cin >> choice;

		int n;
		cout << "\nNhap so luong Sinh Vien can xuat: ";
		cin >> n;

		//Đọc dữ liệu từ file input.txt
		docDSSV(inFile, arrSV);

		switch (choice)
		{
		case 1:
		{
			cout << "\n ++ Danh Sach Sinh Vien ++ \n" << endl;
			xuatDSSV(arrSV, n);
			break;
		}
		case 2:
		{
			string mssv;
			cout << "Hay nhap MSSV Sinh Vien can tim: ";
			cin >> mssv;
			timKiemSVTheoMSSV(arrSV, n, mssv);
			break;
		}
		case 3:
		{
			cout << "\n++ In danh sach Sinh Vien theo ten ++\n";
			inDanhSachSinhVienTangDanTheoTen(arrSV, n);
			break;
		}
		case 4:
		{
			cout << "\n++ Danh sach Sinh Vien giam dan theo Diem TB ++\n";
			inDanhSachSinhVienGiamDanTheoDTB(arrSV, n);
			break;
		}
		case 5:
		{
			cout << "\n++ Danh sach Sinh Vien dau ++\n";
			inDanhSachSVDau(arrSV, n);
			break;
		}
		case 6:
		{
			cout << "\n++ Danh sach Sinh Vien rot ++\n";
			inDanhSachSVRot(arrSV, n);
			break;
		}
		case 7:
		{
			ofstream outFile;
			outFile.open("input.txt", ios::app);

			int vt;
			cout << "\nNhap thu tu them Sinh Vien: ";
			cin >> vt;

			cout << endl;
			themSV(outFile, arrSV, n, vt);
			break;
		}
		case 8:
		{
			int vtXoaSV;
			cout << "\nNhap MSSV can xoa: ";
			cin >> vtXoaSV;
			xoaSinhVien(arrSV, n, vtXoaSV);
			break;
		}
		case 9:
			cout << "\nKet Thuc Chuong Trinh !!!" << endl;
			exit(0);
		}

	} while (choice > 0);

	//Đóng file khi hoàn thành
	inFile.close();

	system("pause");
	return 0;
}

void doc1SV(ifstream &inFile, SinhVien &sv)
{
	getline(inFile, sv.mssv, '-');
	getline(inFile, sv.ho, '-'); //Đọc trên một chuỗi, tới dấu - thì dừng
	getline(inFile, sv.ten, '-');
	inFile >> sv.diemMon1;
	inFile.ignore(1); //Bỏ qua dấu '-'
	inFile >> sv.diemMon2;
	inFile.ignore(1); //Bỏ qua newline
}

void docDSSV(ifstream &inFile, SinhVien arrSV[MAX])
{
	for (int i = 0; inFile.eof() == false; i++)
	{
		doc1SV(inFile, arrSV[i]);
		arrSV[i].mssv;
		arrSV[i].ho;
		arrSV[i].ten;
		arrSV[i].diemMon1;
		arrSV[i].diemMon2;	
	}
}

void xuatThongTin1SV(SinhVien sv)
{
	cout << "MSSV: " << sv.mssv << endl;
	cout << "Ho: " << sv.ho << endl;
	cout << "Ten: " << sv.ten << endl;
	cout << "Diem mon 1 " << sv.diemMon1 << endl;
	cout << "Diem mon 2: " << sv.diemMon2 << endl;
	cout << "Diem trung binh: " << (sv.diemMon1 + sv.diemMon2) / 2 << endl;
}

void xuatDSSV(SinhVien arrSV[MAX], int &n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Sinh vien thu " << i + 1 << endl;
		xuatThongTin1SV(arrSV[i]); //xuat ra sinh vien thu i
		cout << "==========================" << endl;
	}
}

//Tìm kiếm sinh viên
void timKiemSVTheoMSSV(SinhVien arrSV[MAX], int &n, string mssv)
{
	for (int i = 0; i < n; i++)
	{
		if (arrSV[i].mssv == mssv) {
			cout << "\n==> Tim thay Sinh Vien !!" << endl;
			xuatThongTin1SV(arrSV[i]);
			return;
		}
	}
	cout << "\nKhong tim thay Sinh Vien nay !!" << endl;
}

//Thêm Sinh Viên
void themSV(ofstream &outFile, SinhVien arrSV[MAX], int &n, int vt)
{
	cin.ignore();
	cout << "MSSV: ";
	cin >> arrSV[vt].mssv;
	cin.ignore();
	cout << "Ho: ";
	getline(cin, arrSV[vt].ho);
	cout << "Ten: ";
	cin >> arrSV[vt].ten;
	cout << "Diem mon 1: ";
	cin >> arrSV[vt].diemMon1;
	cout << "Diem mon 2: ";
	cin >> arrSV[vt].diemMon2;

	arrSV[n + 1] = arrSV[vt];

	//Ghi vào cuối file
	if (outFile.is_open()) {
		outFile << arrSV[vt].mssv << '-' << arrSV[vt].ho << '-' << arrSV[vt].ten << '-' << arrSV[vt].diemMon1 << '-' << arrSV[vt].diemMon2 << endl;
		outFile.close();
		cout << "\nThem Sinh Vien thanh cong !!" << endl;
	}
	else
		cout << "\nThem Sinh Vien khong thanh cong !!" << endl;

	//Xuat DS Sinh Vien sau khi them
	for (int i = 0; i < n + 1; i++)
	{
		cout << "Sinh vien thu " << i + 1 << endl;
		xuatThongTin1SV(arrSV[i]); //xuat ra sinh vien thu i
		cout << "==========================" << endl;
	}
}

//Xóa Sinh Viên
void xoaSinhVien(SinhVien arrSV[MAX], int &n, int vt){
	for (int i = vt - 1; i < n; i++) {
		arrSV[i] = arrSV[i + 1];
	}
	n--;
	xuatDSSV(arrSV, n);
}

//In danh sách Sinh Viên Đậu, Rớt
void inDanhSachSVDau(SinhVien arrSV[MAX], int &n) 
{
	for (int i = 0; i < n; i++) {
		if (((arrSV[i].diemMon1 + arrSV[i].diemMon2)*1.0 / 2) >= 5)
		{
			xuatThongTin1SV(arrSV[i]);
			cout << endl;
		}
	}
}
//In danh sách Sinh Vien rớt
void inDanhSachSVRot(SinhVien arrSV[MAX], int &n)
{
	for (int i = 0; i < n; i++) {
		if (((arrSV[i].diemMon1 + arrSV[i].diemMon2)*1.0 / 2) < 5)
		{
			xuatThongTin1SV(arrSV[i]);
			cout << endl;
		}
	}
}
//Swap hai Sinh Viên theo điểm TB
void hoanDoiHaiSinhVienTheoDTB(SinhVien arrSV[MAX], int &n)
{
	SinhVien tempSv;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if ((((arrSV[i].diemMon1 + arrSV[i].diemMon2)*1.0) / 2) <
				(((arrSV[j].diemMon1 + arrSV[j].diemMon2)*1.0) / 2)) {
				tempSv = arrSV[i];
				arrSV[i] = arrSV[j];
				arrSV[j] = tempSv;
			}
		}
	}
}
//In danh sách Sinh Viên có điểm TB giảm dần
void inDanhSachSinhVienGiamDanTheoDTB(SinhVien arrSV[MAX], int &n)
{
	hoanDoiHaiSinhVienTheoDTB(arrSV, n);
	xuatDSSV(arrSV, n);
}
//Swap hai Sinh Viên theo tên
void hoanDoiHaiSinhVienTheoTen(SinhVien arrSV[MAX], int &n) {
	for (int i = 0; i < n - 1; i++) {
		char* cstr1 = new char[arrSV[i].ten.length() + 1];
		strcpy(cstr1, arrSV[i].ten.c_str());

		for (int j = i + 1; j < n; j++) {
			char* cstr2 = new char[arrSV[j].ten.length() + 1];
			strcpy(cstr2, arrSV[j].ten.c_str());

			if (strcmp(cstr1, cstr2) > 0) {
				SinhVien tempSv = arrSV[i];
				arrSV[i] = arrSV[j];
				arrSV[j] = tempSv;
			}
		}
	}
}
//In danh sách Sinh Viên theo Tên tăng dần
void inDanhSachSinhVienTangDanTheoTen(SinhVien arrSV[MAX], int &n) {
	hoanDoiHaiSinhVienTheoTen(arrSV, n);
	xuatDSSV(arrSV, n);
}
