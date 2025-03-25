/*
Вычислить произведение двух целых положительных чисел Р = a·b по следующему алгоритму:
если в четное, то Р = 2(а * b / 2), иначе
P = a + (a*(b - 1)).Если b = 0, то Р = 0.
*/ 

#include <iostream>
using namespace std;

int withoutRec(int, int);
int rec(int, int);

int main() {
	int a, b;
	cout << "Vvedite 2 cel chisla:";
	cin >> a >> b;

	cout << "Without rec: "<<withoutRec(a,b)<<endl;
	cout << "With rec: " << rec(a, b) << endl;

	return 0;
}

int withoutRec(int a, int b) {
	if (b == 0) return 0;

	if (b%2==0) return 2*(a * b / 2);
	else return a + (a*(b - 1));
}

int rec(int a, int b) {
	if (b == 0) return 0;

	if (b % 2 == 0) return 2 * rec(a, b / 2);
	else return  a + rec(a, b - 1);
}

