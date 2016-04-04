#include <iostream>

using namespace std;

int** AllocMemory(int);
void DisplayMatrix(int**, int);
void FreeMemory(int**, int);
void SourceMatrix(int**, int);
void MatrixAfterChange(int**, int**, int);
int ElementInMatrixAfterChange(int**, int, int, int);


int main()
{
	while (true)
	{
		system("cls");
		int n;
		while (true)
		{
			cout << "Enter the size of matrix n > 1 " << endl;
			cin >> n;
			system("cls");
			if (n > 1) break;
			cout << "Error! Please, enter the other sixe of matrix " << endl;
		}
		int** a = AllocMemory(n);
		SourceMatrix(a, n);
		system("cls");
		cout << "Source matrix" << endl;
		DisplayMatrix(a, n);
		int** b = AllocMemory(n);
		MatrixAfterChange(a, b, n);
		cout << endl << "Matrix after changes " << endl;
		DisplayMatrix(b, n);

		char yes;
		cout << "If you would like to continue, please, press y or Y " << endl;
		cin >> yes;
		if (yes == 'y' || yes == 'Y')
			continue;
		break;
	}
	return 0;
}

int** AllocMemory(int n)
{
	int** a = new int*[n];
	for (int i = 0; i < n; i++)
		a[i] = new int[n];
	return a;
}
void FreeMemory(int** a, int n)
{
	for (int i = 0; i < n; i++)
		delete[]a[i];
	delete[]a;
}

void DisplayMatrix(int** a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout.width(4);
			cout << a[i][j];
		}
		cout << endl;
	}
}

void SourceMatrix(int** a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "a[" << (i + 1) << "][" << (j + 1) << "] = ";
			cin >> a[i][j];
		}
	}
}
void MatrixAfterChange(int** a, int** b, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			b[i][j] = ElementInMatrixAfterChange(a, n, i, j);
		}
	}
}
int ElementInMatrixAfterChange(int** a, int n, int i, int j)
{
	int max = a[i][j];
	for (int m = 0; m < n; m++)
	{
		for (int k = 0; k < n; k++)
		{
			if ((i == j && m == k && i == k && a[m][k]>max) || (m <=k && m >= i && k<=j && a[m][k] > max) || ( m>= k && m<=i && k>=j && a[m][k]>max))
				max = a[m][k];
		}
	}
	return max;
}
