#include "pch.h"
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<conio.h>
#include<string>
#define MAX 100
using namespace std;



struct sinhvien {
	char ten[MAX], MSSV[MAX];
	float diemtb;
};

void nhapdanhsach(sinhvien sv[], int &n);
void indanhsach(sinhvien sv[], int &n);
void lietke(sinhvien sv[], int &n);
void demsv(sinhvien sv[], int &n);
void timsv(sinhvien sv[], int &n);
float max(sinhvien sv[], int n);
void xoasv(sinhvien sv[], int &n);
void QuickSort(sinhvien sv[], int left, int right);
void InsertionSort(sinhvien sv[], int n);
void bubblesort(sinhvien sv[], int n);
void interchangesort(sinhvien sv[], int n);
void selectionsort(sinhvien sv[], int n);
void xuatsvdiemtb(sinhvien sv[], int &n);
void chensv(sinhvien sv[], int &n);

int main()
{

	do {
		int n;
		sinhvien sv[MAX];
		cout << "Nhap vao so sinh vien cua lop: ";
		cin >> n;
		nhapdanhsach(sv, n);
		//2.a
		indanhsach(sv, n);
		//2.b
		lietke(sv, n);
		//2.c
		demsv(sv, n);
		//2.d
		timsv(sv, n);
		//2.e
		xoasv(sv, n);
		//indanhsach(sv, n);
		cout << endl;
		//2f Sắp xếp danh sách sinh viên tăng theo điểm trung bình bằng thuật toán sắp xếp
			//Selection Sort
		cout << "Sap xep bang selectionsort\n";
		selectionsort(sv, n);
		xuatsvdiemtb(sv, n);
			//Interchange Sort
		cout << "Sap xep bang interchangesort\n";
		interchangesort(sv, n);
		xuatsvdiemtb(sv, n);
			//Bubble Sort
		cout << "Sap xep bang bubblesort\n";
		bubblesort(sv, n);
		xuatsvdiemtb(sv, n);
			//Insertion Sort
		cout << "Sap xep bang intersort\n";
		InsertionSort(sv, n);
		xuatsvdiemtb(sv, n);
			//Quick Sort
		cout << "Sap xep bang qicksort\n";
		QuickSort(sv,0, n-1);
		xuatsvdiemtb(sv, n);
		//2g
		chensv(sv, n);

		cout << "Nhan phim ESC se thoat...!\n\n";
	} while (_getch() != 27);
}
void chensv(sinhvien sv[], int &n)
{
	sinhvien x[MAX];
	int k = n;
	cout << "Nhap vao thong tin sinh vien can chen\n";
	cout << "  Ten sinh vien: ";
	//cin.ignore();
	cin.getline(x[0].ten, 100);
	cout << "  MSSV: ";
	cin.getline(x[0].MSSV, 100);
	cout << "  Diem trung binh: ";
	cin >> x[0].diemtb;
	for (int i = n - 1; i >= k; i--)
		sv[i + 1] = sv[i];
	sv[k] = x[0];
	n++;
	selectionsort(sv, n);
	xuatsvdiemtb(sv, n);

}
void xuatsvdiemtb(sinhvien sv[], int &n)
{
	cout << "\nDanh sach sinh vien sau khi sap xep diem trung binh tang dan: \n";
	for (int i = 0; i < n; i++)
	{
		cout << sv[i].ten << ": " << sv[i].diemtb << endl;
	}
}
void xoasv(sinhvien sv[], int &n)
{
	sinhvien xoa[MAX];
	int k = 0;
	char mssv[MAX];
	cout << "Nhap vao ma sinh vien can xoa: ";
	//cin.ignore();
	cin.getline(mssv, 100);
	for (int i = 0; i < n; i++)
	{
		if (strcmp(mssv, sv[i].MSSV) == 0)
		{
			k = 1;
			xoa[0] = sv[i];
			sv[i] = sv[i+1];
			n--;

		}
	}
	if (k == 0) cout << "Sinh vien voi ma so " << mssv << " khong tim thay trong danh sach!\n";
	else 
	{
		cout << "Sinh vien voi ma so " << mssv << " da bi xoa khoi danh sach!\n";
		cout << "Thong tin sinh vien vua bi xoa:\n";
		cout << "  Ten sinh vien: " << xoa[0].ten << endl;
		cout << "  MSSV: " << xoa[0].MSSV << endl;
		cout << "  Diem trung binh: " << xoa[0].diemtb << endl;

	}
}
void timsv(sinhvien sv[], int &n)
{
	int k = 0;
	char timten[MAX];
	cout << "Nhap vao ten sinh vien de tim kiem: ";
	cin.ignore();
	cin.getline(timten, 100);
	for (int i = 0; i < n; i++)
	{
		if (strcmp (timten,sv[i].ten)==0)
		{
			k = 1;
			cout << " Sinh vien nay co trong danh sach lop hoc:\n";
			cout << "  Ten sinh vien: " << sv[i].ten << endl;
			cout << "  MSSV: " << sv[i].MSSV << endl;
			cout << "  Diem trung binh: " << sv[i].diemtb << endl;
		}
	}
	if (k == 0) cout << "Sinh vien nay khong co trong danh sach lop hoc!\n";
}
void demsv(sinhvien sv[], int &n)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (sv[i].diemtb >= 5)
			dem++;
	}
	if (dem == 0) cout << "Khong co sinh vien nao co diem trung binh>=5\n";
	else cout << "So sinh vien co diem trung binh>=5 la: " << dem<<endl;
}

float max(sinhvien sv[], int n)
{
	float maxa = sv[0].diemtb;
	for (int i = 0; i < n; i++)
	{
		if (sv[i].diemtb >= maxa)
			maxa = sv[i].diemtb;
	}
	return maxa;
}
void lietke(sinhvien sv[], int &n)
{
	cout << "Sinh vien co diem trung binh cao nhat:\n";
	for (int i = 0; i < n; i++)
	{
		if (sv[i].diemtb == max(sv,n))
		{
			cout << sv[i].ten << endl;
		}

	}
}
void nhapdanhsach(sinhvien sv[], int &n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap sinh vien thu " << i << ":\n";
		cout << "  Ten sinh vien: ";
		cin.ignore();
		cin.getline(sv[i].ten,100);
		cout << "  MSSV: ";
		cin.getline(sv[i].MSSV,100);
		cout << "  Diem trung binh: ";
		cin >> sv[i].diemtb;
	}
}
void indanhsach(sinhvien sv[], int &n)
{
	cout << "Danh sach sinh vien: \n";
	for (int i = 0; i < n; i++)
	{
		cout << " Sinh vien thu " << i << " :\n";
		cout << "  Ten sinh vien: "<<sv[i].ten << endl;
		cout << "  MSSV: "<<sv[i].MSSV << endl;
		cout << "  Dien trung binh: "<<sv[i].diemtb << endl;
	}
}
//Cac ham sap xep
void selectionsort(sinhvien sv[], int n)
{
	int min; //min là chỉ số phần tử nhỏ nhất
	for (int i = 0; i < n - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < n; j++)
			if (sv[j].diemtb < sv[min].diemtb)
				min = j; //tìm min trong các phần tử còn lại
		if (min != i)
		{
			sinhvien temp = sv[i];
			sv[i] = sv[min];
			sv[min] = temp;
		}
	}
}
void interchangesort(sinhvien sv[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (sv[i].diemtb > sv[j].diemtb)
			{
				sinhvien temp = sv[i];
				sv[i] = sv[j];
				sv[j] = temp;
			}
}
void bubblesort(sinhvien sv[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = n - 1; j > i; j--)
			if (sv[j].diemtb < sv[j - 1].diemtb) {
				sinhvien temp = sv[j];
				sv[j] = sv[j - 1];
				sv[j - 1] = temp;
			}
}
void InsertionSort(sinhvien sv[], int n)
{
	int i, j;
	for (i = 1; i < n; i++)
	{
		sinhvien x = sv[i];
		//Chen x vao vi tri thich hop
		for (j = i - 1; j >= 0; j--)
			if (sv[j].diemtb > x.diemtb)
				sv[j + 1] = sv[j];
			else
				break;
		sv[j + 1] = x;
	}
}
void QuickSort(sinhvien sv[], int left, int right) 
{
	int i, j;
	sinhvien x;
	x = sv[(left + right) / 2];
	i = left; j = right;
	do
	{
		while (sv[i].diemtb < x.diemtb) i++;
		while (sv[j].diemtb > x.diemtb) j--;
		if (i <= j)
		{
			sinhvien temp = sv[i];
			sv[i] = sv[j];
			sv[j] = temp;
			i++; j--;
		}
	} while (i < j);
	if (left < j) QuickSort(sv, left, j);
	if (i < right) QuickSort(sv, i, right);
}


