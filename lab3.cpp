// QS и выбором

#include <iostream>
using namespace std;

struct TNode {
	int l;
	int r;
	TNode* a;
};

struct stack {
	TNode* top = nullptr;

	void push(int lt,int rt) {
		TNode* spt = new TNode;
		spt->l = lt;
		spt->r = rt;
		spt->a = top;
		top = spt;
	}

	void pop(int &lt,int &rt) {
		TNode* spt = top;
		lt = spt->l;
		rt = spt->r;
		top = spt->a;
		delete spt;
	}
};

struct Car {
	char mark[20];
	int year;
	double speed;
	double v;
};

void QS(Car[],int);
void choise(Car[],int);

int main(){
	int n;
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
	}

	/*n = 6;
	Car cars[] = {
	{"Audi", 2009, 300, 3},
	{"BMW", 2000, 240, 12},
	{"Mers", 2023, 267, 3.23},
	{"Dasd", 2003, 223, 432},
	{"Faasd", 20043, 753, 432},
	{"Popasd", 20054, 234, 43},
	};*/

	int k;
	cout << "Sort: 1-QS, 2-choise: ";
	cin >> k;
	switch (k)
	{
	case(1):
	{
		QS(cars,n);
		break;
	}
	case(2): {
		choise(cars,n);
		break;
	}
	default: {
		cout << "Nevern vbr";
		return;
	}
	}
	
	cout << "After sorting(key-year):" << endl;
	for (int i = 0; i < n; i++) {
		cout <<cars[i].year << " " <<cars[i].mark<<" " <<cars[i].speed << " " << cars[i].v << endl;
	}

	return 0;
}

void choise(Car cars[], int n) {
	int imin;
	for (int i = 0; i < n; i++) {
		imin = i;
		for (int j = i + 1; j < n; j++) {
			if (cars[imin].year > cars[j].year) imin = j;
			if (imin != i) swap(cars[imin], cars[i]);
		}
	}
}

void QS(Car cars[], int n) {
	int i, j, left, right;
	Car x;
	stack st;
	st.push(0, n - 1);
	while (st.top) {
		st.pop(left, right);
		while (left < right) {
			i = left; j = right; x = cars[(left + right) / 2];
			while (i <= j) {
				while (cars[i].year < x.year) i++;
				while (cars[j].year > x.year) j--;

				if (i <= j) {
					swap(cars[i], cars[j]);
					i++;
					j--;
				}

				if (j - left < right - i) {
					if (i < right) st.push(i, right);
					right = j;
				}
				else {
					if (left < j) st.push(left, j);
					left = i;
				}
			}
		}
	}
}
