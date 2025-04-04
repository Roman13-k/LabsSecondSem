#include <iostream>
using namespace std;

struct Car {
	char mark[20];
	int year;
	double speed;
	double v;
};
double p_barier(Car[], int, int);
double p_binary(Car[], int, int);

int main() {
	/*int n;
	cout << "Kol auto: ";
	cin >> n;

	cout << "Inf of auto: " << endl;
	Car* cars = new Car[n];
	for (int i = 0; i < n; i++) {
		cout << "Mark:";
		cin >> cars[i].mark;
		cout << "Mark:";
		cin >> cars[i].speed;
		cout << "Mark:";
		cin >> cars[i].v;
		cout << "Mark:";
		cin >> cars[i].year;
		cout << endl;
	}*/
	int n = 6;
	Car cars[] = {
	{"Dasd", 1996, 223, 123},
	{"BMW", 2000, 240, 12},
	{"Dasd", 2003, 223, 432},
	{"Audi", 2009, 300, 3},
	{"Mers", 2023, 267, 3.23},
	{"Popasd", 20054, 234, 43},
	};

	double res;
	int k;
	cout << "Search: 1-barier, 2-binary: ";
	cin >> k;
	switch (k)
	{
	case(1):
	{
		res = p_barier(cars, n, 1996);
		break;
	}
	case(2): {
		res = p_binary(cars, n, 1996);
		break;
	}
	default: {
		cout << "Nevern vbr";
		return 0;
	}
	}
	if (res == -1) {
		cout << "Element not found";
		return 0;
	}
	cout << "Max speed: " << res;

	return 0;
}

double p_barier(Car cars[], int n, int x) {
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