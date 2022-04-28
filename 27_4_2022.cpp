// 27_4_2022.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

using namespace std;

void bubblesort(int num[], int n)
{

	int f, a;
	for (f = 0; f < n - 1; f++)

		for (a = 0; a < n - f - 1; a++)

			if (num[a] > num[a + 1])

				swap(num[a], num[a + 1]);//intercambia los numeros
}
void impnum(int num[], int size)
{

	int f;
	for (f = 0; f < size; f++)
		cout << num[f] << " ";
	cout << endl;
}

void insertionsort(int num[], int n)
{

	int f, a, key;
	for (f = 1; f < n; f++)
	{
		key = num[f];
		a = f - 1;
		while (a >= 0 && num[a] > key)
		{
			num[a + 1] = num[a];
			a = a - 1;

		}
		num[a + 1] = key;
	}
}
void impinst(int num[], int n)
{
	int f;
	for (f = 0; f < n; f++)
		cout << num[f] << " ";
	cout << endl;
}
void swap(int* f, int* a)
{
	int w = *f;
	*f = *a;
	*a = w;
}
int partir(int num[], int low, int high)
{
	int pivot = num[high];
	int n = (low - 1);
	for (int a = low; a <= high - 1; a++)
	{
		if (num[a] < pivot)
		{
			a++;
			swap(&num[n], &num[a]);
		}
	}
	swap(&num[n + 1], &num[high]);
	return(n + 1);
}
void quicksort(int num[], int low, int high)
{
	if (low < high)
	{
		int pi = partir(num, low, high);
		quicksort(num, low, pi - 1);
		quicksort(num, pi + 1, high);
	}
}
void impquick(int num[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << num[i] << " ";
	cout << endl;
}
void merge(int num[], int const left, int const mid, int const right)
{
	auto const subnumuno = mid - left + 1;
	auto const subnumdos = right - mid;
	auto* leftnum = new int[subnumuno];
	auto* rightnum = new int[subnumdos];
	for (auto i = 0; i < subnumuno; i++)
		leftnum[i] = num[left + i];
	for (auto j = 0; j < subnumdos; j++)
		rightnum[j] = num[mid + 1 + j];
	auto indexOfsubnumuno = 0,
		indexOfsubnumdos = 0;
	int indexOfmergednum = left;
	while (indexOfsubnumuno < subnumuno && indexOfsubnumdos < subnumdos)
	{
		if (leftnum[indexOfsubnumuno] <= rightnum[indexOfsubnumdos])
		{
			num[indexOfmergednum] = leftnum[indexOfsubnumuno];
			indexOfsubnumuno++;
		}
		else
		{
			num[indexOfmergednum] = rightnum[indexOfsubnumdos];
			indexOfsubnumdos++;
		}
		indexOfmergednum++;
	}
	while (indexOfsubnumuno < subnumuno)
	{
		num[indexOfmergednum] = leftnum[indexOfsubnumuno];
		indexOfsubnumuno++;
		indexOfmergednum++;
	}
	while (indexOfsubnumdos < subnumdos)
	{
		num[indexOfmergednum] = rightnum[indexOfsubnumdos];
		indexOfsubnumdos++;
		indexOfmergednum++;
	}
}
void mergesort(int num[], int const begin, int const end)
{
	if (begin >= end)
		return;
	auto mid = begin + (end - begin) / 2;
	mergesort(num, begin, mid);
	mergesort(num, mid + 1, end);
	merge(num, begin, mid, end);
}
void impmerge(int A[], int size)
{
	for (auto i = 0; i < size; i++)
		cout << A[i] << " ";
}
void heapify(int num[], int a, int b)
{
	int largo = b;
	int l = 2 * b + 1;
	int r = 2 * b + 2;
	if (l< a && num[l]>num[largo])
		largo = l;
	if (r<b && num[r]>num[largo])
		largo = r;
	if (largo != b)
	{
		swap(num[b], num[largo]);
		heapify(num, a, largo);
	}
}
void heapSort(int num[], int n)
{
	
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(num, n, i);

	
	for (int i = n - 1; i > 0; i--) {
		
		swap(num[0], num[i]);

	
		heapify(num, i, 0);
	}
}


void impheap(int num[], int n)
{
	for (int i = 0; i < n; ++i)
		cout << num[i] << " ";
}
int binarySearch(int num[], int l, int r, int x)
{
	if (r >= l) 
	{
		int mid = l + (r - l) / 2;

		if (num[mid] == x)
			return mid;

		if (num[mid] > x)
			return binarySearch(num, l, mid - 1, x);

		return binarySearch(num, mid + 1, r, x);
	}
	return -1;
}

int main()
{
	int num[] = { 5,9,4,1,6,7,10,8,2,3 };
	int op;
	int n = sizeof(num) / sizeof(num[0]);
	auto num_size = sizeof(num) / sizeof(num[0]);
    int x = 10;
	cout << "menu\n";
	cout << "1.bubble\n";
	cout << "2.insertion\n";
	cout << "3.quick sort\n";
	cout << "4.merge sort\n";
	cout << "5.heap sort \n";
	cout << "6.busqueda binaria\n";
	cin >> op;
	switch (op)
	{
	case 1:

		bubblesort(num, n);
		impnum(num, n);
		return 0;
		break;

	case 2:

		insertionsort(num, n);
		impinst(num, n);
		return 0;
		break;

	case 3:

		quicksort(num, 0, n - 1);
		impquick(num, n);
		return 0;

	case 4:
		impmerge(num, num_size);
		mergesort(num, 0, num_size - 1);
		return 0;

	case 5:
		heapSort(num, n);
		impheap(num, n);

	case 6:
		int result = binarySearch(num, 0, n - 1, x);
		(result == -1);
	}
}



