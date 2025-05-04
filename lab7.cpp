// преобразовать двусвязанный список из n целых чисел в два списка:
// первый только положительные
// второй только отрицательные

#include <iostream>
using namespace std;

struct TNode {
	int inf;
	TNode* left;
	TNode* right;
};

struct list {
	TNode* front = nullptr;
	TNode* back = nullptr;

	void push(int inf) {
		TNode* spt = new TNode;
		spt->inf = inf;
		spt->right = nullptr;

		if (!front) {
			spt->left = nullptr;
			front = back = spt;

		}
		else {
			back->right = spt;
			spt->left = back;
			back = spt;
		}
	}

	void print() {
		TNode* spt = front;
		while (spt) {
			cout << spt->inf << " ";
			spt = spt->right;
		}
		cout << endl;
	}
};

void splitList(list& List, list& Positive, list& Negative);

int main() {
	list List,PosList,NegList;
	int n;
	cout << "Kol Elements: ";
	cin >> n;
	
	/*int tmp;
	for (int i = 0; i < n; i++) {
		cout << "Vvedite element: ";
		cin >> tmp;
		List.push(tmp);
	}*/

	for (int i = -n/2; i < n/2; i++) {
		List.push(i);
	}
	cout << "Ishodnyi spisok: ";
	List.print();
	
	splitList(List, PosList, NegList);

	cout << "Polozhitelnye: ";
	PosList.print();

	cout << "Otritsatelnye: ";
	NegList.print();

	return 0;
}

void splitList(list& List, list& Positive, list& Negative) {
	TNode* spt = List.front;

	while (spt) {
		if (spt->inf > 0) Positive.push(spt->inf);
		else if (spt->inf < 0) Negative.push(spt->inf);
		spt = spt->right;
	}
}