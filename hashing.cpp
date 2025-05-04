#include <iostream>
#include <math.h>
using namespace std;

int random[100];

// линейная адресация
/*
void H_add(int *H, int n, int inf) {
	int i = inf % n;
	while (H[i] != -1) {
		i++;
		if (i == n) i = 0;
	}
	H[i] = inf;
}

int H_search(int* H, int n, int inf) {
	int i = abs(inf % n);
	while (H[i] != -1) {
		if (H[i] == inf) return i;

		i++;
		if (i >= n) i = 0;
	}
	return -1;
}
*/

// квадратичная адресация
/*
void H_add(int* H, int n, int inf) {
	int i = inf % n;
	int p = 1; // номер попытки
	while (H[i] != -1) {
		i = (i + p * p) % n;
		p++;
	}
	H[i] = inf;
}

int H_search(int* H, int n, int inf) {
	int i = abs(inf % n);
	int p = 1;
	while (H[i] != -1) {
		if (H[i] == inf) return i;

		i = (i + p * p) % n;
		p++;
	}
	return -1;
}*/

// произвольная адресация
/*
void H_add(int* H, int n, int inf) {
	int i = inf % n;
	int p = 1; // номер попытки
	while (H[i] != -1) {
		i = (i +random[p]) % n;
		p++;
	}
	H[i] = inf;
}

int H_search(int* H, int n, int inf) {
	int i = abs(inf % n);
	int p = 1;
	while (H[i] != -1) {
		if (H[i] == inf) return i;

		i = (i + random[p]) % n;
		p++;
	}
	return -1;
}
*/

//двойное хеширование 
/*
void H_add(int* H, int n, int inf) {
	int h1 = inf % n;
	int h2 = 1 + (inf % (n - 2));
	int i = h1;
	int p = 1;

	while (H[i] != -1) {
		i = (h1 + p * h2) % n;
		p++;

	}
	H[i] = inf;
}

int H_search(int* H, int n, int inf) {
	int h1 = abs(inf % n);
	int h2 = 1 + (inf % (n - 2));
	int i = h1;
	int p = 1;

	while (H[i] != -1) {
		if (H[i] == inf) return i;

		i = (h1 + p * h2) % n;
		p++;
	}
	return -1;
}
*/

//на основе связаных списков
struct TNode {
	int inf;
	TNode* a;
};

struct THesh {
	TNode** H = nullptr;
	int m;

	void create(int n) {
		m = n;
		H = new TNode * [m];
		for (int i = 0; i < m; i++) H[i] = nullptr;
	}

	void push(int inf) {
		TNode* spt = new TNode;
		spt->inf = inf;
		int k = abs(inf % m);
		spt->a = H[k];
		H[k] = spt;
	}

	TNode* search(int inf) {
		int k = abs(inf % m);
		TNode* spt = H[k];
		while (spt && spt->inf != inf) spt = spt->a;
		return spt;
	}

	void print(TNode* x) {
		if (x) cout << "Element: " << x->inf << " found";
		else cout << "Elemet not found";
	}

	void del() {
		TNode* spt;
		for (int i = 0; i < m; i++) {
			cout << endl << i << "->";
			while (H[i]) {
				spt = H[i];
				H[i] = H[i]->a;
				cout << spt->inf << " ";
				delete spt;
			}
		}
		delete[]H;
	}
};


int main() {
	int array[] = { 1,10,34,2,125,21,90,76,45,81,22 };
	int n = 11;
	int Hash[11];

	/*for (int i = 0; i < 100; i++) {
		random[i] = rand() % 20 + 1;
	}*/
	/*for (int i = 0; i < n; i++) Hash[i] = -1;
	for (int i = 0; i < n; i++) H_add(Hash, n, array[i]);*/

	/*cout << "Hash: " << endl;
	for (int i = 0; i < n; i++) {
		cout << Hash[i]<<endl;
	}

	int el=0,search;
	while (el != -1) {
		cin >> el;
		search = H_search(Hash, n, el);
		cout << search << endl;
	}*/

	//на основе связаных списков
	THesh ht;
	ht.create(n);

	for (int i = 0; i < n; i++) ht.push(array[i]);
	ht.print(ht.search(22));

	ht.del();
	return 0;
}