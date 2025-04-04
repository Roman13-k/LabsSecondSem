#include <iostream>
using namespace std;

struct Car {
	char mark[20];
	int year;
	double speed;
	double v;
};

double p_lin1(Car[], int, int );
double p_lin2(Car[], int, int );
double p_binary(Car[], int, int );
double p_intrp(Car[], int, int );

int main() {
	
	int n = 7;
	Car cars[] = {
	{"Dasd", 1996, 223, 123},
	{"BMW", 2000, 240, 12},
	{"Dasd", 2003, 223, 432},
	{"Audi", 2009, 300, 3},
	{"Mers", 2023, 267, 3.23},
	{"Popasd", 20054, 234, 43},
	};

	double res = p_intrp(cars, n,1996);
	if (res == -1) {
		cout << "Element not found";
		return 0;
	}
	cout <<"Max speed: " << res;

	return 0;
}

double p_lin1(Car cars[], int n,int x) {
	for (int i = 0; i < n; i++) {
		if (cars[i].year == x) return cars[i].speed;
	}
	return -1;
}

double p_lin2(Car cars[], int n, int x) {
	cars[n].year = x;
	int i = 0;
	while (cars[i].year != x)i++;
	if (i != n)return cars[i].speed;
	return -1;
}

double p_binary(Car cars[], int n, int x) {
	int i = 0, j = n - 1, m;
	while (i < j) {
		m = (i + j) / 2;
		if (cars[m].year < x) i = m + 1; else j = m;
	}
	if (cars[i].year == x) return cars[i].speed;
	return -1;
}

double p_intrp(Car cars[], int n, int x) {
	int i = 0, j = n - 1, m;
	while (i < j) {
		if (cars[i].year == cars[j].year)
			if (cars[i].year == x) return cars[i].speed;
			else return -1;

		m = i+(j-i)*(x-cars[i].year)/(cars[j].year-cars[i].year);
		if (cars[m].year == x) return cars[i].speed;
		else if (cars[m].year < x) i = m + 1; else j = m-1;
	}
	return -1;
}