#include "pch.h"
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<conio.h>
using namespace std;
#define MAX 50
void nhapmangngaunhien(int a[], int n);
void nhapmang(int a[], int n);
void xuatmang(int a[], int n);
void xoak(int a[], int n, int k);
int max(int a[], int n);
void lietkemax(int a[], int n);
int min(int a[], int n);
void lietkemin(int a[], int n);
int demsoam(int a[], int n);
void ammax(int a[], int n);
void duongmin(int a[], int n);
int timkiemtuyentinh(int a[], int n, int x);
int BinarySearch(int a[], int n, int x);
int dempt(int a[], int n, int x);
void swap(int x1, int x2);
void selectionsort(int a[], int n);
void interchangesort(int a[], int n);
void bubblesort(int a[], int n);
void InsertionSort(int a[], int n);
void QuickSort(int a[], int left, int right);
int main()
{

	do {
		int a[MAX], n, k, x, l, x1;
		cout << "Moi nhap vao so phan tu ";
		cin >> n;
		nhapmang(a, n);
		//1a
		xuatmang(a, n);
		//1b
		cout << "nhap vao vi tri can xoa: ";
		cin >> k;
		if (k >= 0 && k < n)
		{
			xoak(a, n, k);
		}
		else cout << "Vi tri nhap vao khong hop le!" << endl;
		//1c
		cout << "Nhung phan tu mang gia tri lon nhat cua mang: " << endl;
		lietkemax(a, n);
		//1d
		cout << "Nhung phan tu mang gia tri nho nhat cua mang: " << endl;
		lietkemin(a, n);
		//1e
		cout << "So phan tu am cua mang la: " << demsoam(a, n) << endl;
		//1f
		ammax(a, n);
		//1g
		duongmin(a, n);
		//1h
		cout << "Nhap vao phan tu can tim (tim kiem tuyen tinh) ";
		cin >> x;
		if (timkiemtuyentinh(a, n, x) == -1) 
			cout << "Phan tu can tim khong co trong mang!" << endl;
		else
			cout << "Phan tu can tim o tri vi thu "<< timkiemtuyentinh(a, n, x) << endl;
		//1i
		cout << "Nhap vao phan tu de dem: ";
		cin >> x1;
		if (dempt(a, n, x1) == 0) cout << "Khong co phan tu " << x1 << " trong mang!" << endl;
		else cout << "Co " << dempt(a, n, x1) << " phan tu " << x1 << " trong mang!" << endl;
		//1j
		//Nhap vao mang ngau nhien de sap xep
		//Selectionsort
		cout << "Nhap vao 1 mang ngau nhien de sap xep: ";
		nhapmangngaunhien(a, n);
		xuatmang(a, n);
		cout << "Mang sau khi sap xep bang Selectionsort: ";
		selectionsort(a,n);
		xuatmang(a, n);
		//interchangesort
		cout << "Nhap vao 1 mang ngau nhien de sap xep: ";
		nhapmangngaunhien(a, n);
		xuatmang(a, n);
		cout << "Mang sau khi sap xep bang Interchangesort: ";
		interchangesort(a, n);
		xuatmang(a, n);
		//bublesort
		cout << "Nhap vao 1 mang ngau nhien de sap xep: ";
		nhapmangngaunhien(a, n);
		xuatmang(a, n);
		cout << "Mang sau khi sap xep bang Bubblesort: ";
		bubblesort(a, n);
		xuatmang(a, n);
		//InsertionSort
		cout << "Nhap vao 1 mang ngau nhien de sap xep: ";
		nhapmangngaunhien(a, n);
		xuatmang(a, n);
		cout << "Mang sau khi sap xep bang insertionsort: ";
		InsertionSort(a, n);
		xuatmang(a, n);
		//Qicksort
		cout << "Nhap vao 1 mang ngau nhien de sap xep: ";
		nhapmangngaunhien(a, n);
		xuatmang(a, n);
		cout << "Mang sau khi sap xep bang qicksort: ";
		QuickSort(a, 0,n-1);
		xuatmang(a, n);
		
		//1k
		cout << "Nhap vao phan tu can tim (tim kiem nhi phan) ";
		cin >> l;
		int kq = BinarySearch(a, n, l);
		if (kq == -1) cout << "Khong tim thay phan tu " << l << " o trong mang!\n";
		else cout << "Phan tu " << l << " o vi tri thu " << kq << " trong mang!\n";






		cout << "Nhan phim ESC se thoat...!" << endl;
	} while (_getch() != 27);
	return 0;
}
void QuickSort(int a[], int left, int right) {
	int i, j;
	int x;
	x = a[(left + right) / 2];
	i = left; j = right;
	do
	{
		while (a[i] < x) i++;
		while (a[j] > x) j--;
			if (i <= j) 
			{
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
				i++; j--;
			}
	} while (i < j);
	if(left < j) QuickSort(a, left, j);
	if (i < right) QuickSort(a, i, right);
}
void InsertionSort(int a[], int n) 
{
	int i, j;
	for (i = 1; i < n; i++)
	{
		int x = a[i];
		//Chen x vao vi tri thich hop
		for (j = i - 1; j >= 0; j--)
			if (a[j] > x)
				a[j + 1] = a[j];
			else
				break;
		a[j + 1] = x;
	}
}
void bubblesort(int a[], int n) {
	for (int i = 0; i < n - 1; i++)
		for (int j = n - 1; j > i; j--)
			if (a[j] < a[j - 1]) {
				int temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
			}
}
void interchangesort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] > a[j])
			{
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
}
void selectionsort(int a[], int n)
{
	int min; //min là chỉ số phần tử nhỏ nhất
	for (int i = 0; i < n - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < n; j++)
			if (a[j] < a[min])
				min = j; //tìm min trong các phần tử còn lại
		if (min != i)
		{
			int temp = a[i];
			a[i] = a[min];
			a[min] = temp;
		}
	}
}
void swap(int x1, int x2)
{
	int t = x1;
	x1 = x2;
	x2 = t;
}
int dempt(int a[], int n, int x)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
		if (a[i] == x)
			dem++;
	return dem;
}
int BinarySearch(int a[], int n, int x) {
	int l = 0, r = n - 1;
	int mid;
	do {
		mid = (l + r) / 2;
		if (x == a[mid])
			return mid;//Tim thay x tai vi tri mid
		else
			if (x < a[mid])
				r = mid - 1;
			else
				l = mid + 1;
	} while (l <= r);
	return -1;//Khong tim thay x
}
int timkiemtuyentinh(int a[], int n, int x)
{
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		if (x == a[i])
		{
			return i;
			k = 1;
			break;
		}
	}
	if (k == 0) return -1;
}
void duongmin(int a[], int n)
{
	int duongmin, k;
	int maxx = max(a, n);
	for (int i = 0; i < n; i++)
		if (a[i] > 0) k = 1;
		else k = 0;
	if (k = 0) cout << "Mang khong co so duong!";
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (a[i] > 0 && a[i] <= maxx)
			{
				duongmin = a[i];
				maxx = a[i];
			}
		}
		cout << "So duong nho nhat cua mang la " << duongmin << endl;
	}
}
void ammax(int a[], int n)
{
	int ammax;
	int minam = min(a, n);
	if (demsoam(a, n) == 0) cout << "Mang khong co so am!" << endl;
	else
	{
		for(int i=0;i<n;i++)
		{
			if (a[i] >= minam && a[i] < 0)
			{
				ammax = a[i];
				minam = a[i];
			}
		}
		cout << "So am lon nhat cua mang la:" << ammax << endl;
	}
	
}
int demsoam(int a[], int n)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] < 0)
			dem++;
	}
	return dem;
}
void lietkemin(int a[], int n)
{
	int mina = min(a, n);
	for (int i = 0; i < n; i++)
	{
		if (a[i] == mina)
			cout << a[i] << " ";
	}
	cout << endl;
}
int min(int a[], int n)
{
	int min = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] <= min)
			min = a[i];
	}
	return min;
}
void xoak(int a[], int n, int k)
{
	
	for (int i = k + 1; i < n; i++)				// lần lượt xét từng vị trí sau vị trí k
		a[i - 1] = a[i];		// dời lên 1 vị trí
	n--;
	cout << "mang sau khi xoa :\n ";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
void nhapmangngaunhien(int a[], int n)
{
	int r;
	srand(time(NULL));	//khoi tao bo so ngau nhien
						// khoi tao so ngau nhien tu 1 den 100
						// so ngau nhien thuoc [a,b]: r=a+rand() %(b-a+1)
	for (int i = 0; i < n; i++)
	{
		r = rand() % 100 + 1;
		a[i] = r;

	}
}
void nhapmang(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "nhap phan tu thu " << i << ": ";
		cin >> a[i];
		cout << endl;
	}
}
void xuatmang(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
int max(int a[], int n)
{
	int max = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] >= max)
			max = a[i];
	}
	return max;
}
void lietkemax(int a[], int n)
{
	int maxa = max(a, n);
	for (int i = 0; i < n; i++)
	{
		if (a[i] == maxa)
			cout << a[i] << " ";
	}
	cout << endl;
}
