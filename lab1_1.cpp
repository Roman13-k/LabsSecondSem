// ф-я принимает матрицу(динамическая) выводит кол чётных и кол чётных больше нуля

#include <iostream>
#include <iomanip>
using namespace std;

void kolEven(int**, int&, int&, int, int);

int main() {
	int n, m;
	cout << "Vvedite razmer matrix NxM:" << endl;
	cin >> n >> m;
	int** matrix;
	matrix = new int* [n];
	for (int i = 0; i < n; i++) {
		matrix[i] = new int[m];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << "Vvedite m["<<i<<"]["<<j<<"]: ";
			cin >> matrix[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout <<setw(8)<< matrix[i][j];
		}
		cout << endl;
	}

	int allEven=0,positivEven=0;
	kolEven(matrix, allEven, positivEven, n, m);
	cout << "All Even: " << allEven <<endl<< "Positiv Even:" << positivEven;

	for (int i = 0; i < n; i++)
		delete[]matrix[i];
	delete[]matrix;
	return 0;
}

void kolEven(int **matrix, int& all, int& pos, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (matrix[i][j] % 2 == 0) {
				all++;
				if (matrix[i][j] > 0) pos++;
			}
		}
	}
}