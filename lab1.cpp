#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

typedef double(*uf)(double&, double&);
void table(double&,double&,double&,uf);
double y(double&, double&);
double s(double&, double&);

int main() {
	double a, b, e = 0.0001;
	cout << "Vvedite a: ";
	cin >> a;
	cout << "Vvedite b: ";
	cin >> b;

	cout << setw(8) << "x" << setw(15) << "y(x)" << endl;
	table(a,b,e,y);
	cout << endl;
	cout<< setw(8) << "x" << setw(15) << "s(x)" << endl;
	table(a,b,e,s);
	return 0;
}

void table(double& a, double& b,double&e,uf fun) {
	double h = (b - a) / 10;
	double sum;
	for (double x = a; x < b + h / 2; x += h) {
		sum = fun(x, e);

		cout << setw(8) << x << setw(15) << sum << endl;
	}
}

double y(double& x, double& e) {
	return x * atan(x);
}

double s(double& x, double& e) {
	double a, sum;
	sum = a = pow(x,2); 

	int i = 1;
	while (abs(a) > e) { 
		a *= -pow(x,2) * (2 * i - 1) / (2 * i + 1);;
		sum += a;
		i++;
	}

	return sum;
}