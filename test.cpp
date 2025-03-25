#include <iostream>
using namespace std;

int f(const char str[], int i,int length) {
	if (str[i] == '\0') return length;

	return f(str, ++i, ++length);
}

void main(){
	const char *str =  "123456\0";

	int len = f(str, 0, 0);
	cout << len;
}