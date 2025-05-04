/*
перевод числа из 10 в систему с основанием n (2<=n<=9)
*/
#include <iostream>
using namespace std;

int convertFromDecimal(int, int,int);

int main() {
    int number;
    int n;

    cout << "Vvedite osnovanie i chislo: ";
    cin >> n>>number;

    if (n < 2 || n > 9) {
        cout << "Error: n from 2 to 9." << endl;
        return 1;
    }

    cout << convertFromDecimal(number, n,1);
    return 0;
}

int convertFromDecimal(int number, int n,int power) {
    if (number == 0) return 0;
    int digit = number % n;
    return convertFromDecimal(number / n, n, power * 10) + (digit * power);
}