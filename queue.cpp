#include <iostream>
using namespace std;

struct TNode {
	int inf;
	TNode* a;
};

struct queue {
	TNode* front = nullptr; // начало очереди
	TNode* back = nullptr; // конец очереди

	bool empty() {
		if (front) return false;
		else return true;
	}

	void push(int inf) {
		TNode* spt = new TNode;
		spt->inf = inf;
		spt->a = nullptr;
		if (!front) front = back = spt;
		else {
			back->a = spt;
			back = spt;
		}
	}

	void pop() {
		if (!front) return;
		TNode* spt = front;     
		front = front->a;    

		delete spt;             
		if (!front) back = nullptr;
	}

	void print() {
		cout << endl;
		TNode* spt = front;
		while (spt) {
			cout << spt->inf << " ";
			spt = spt->a;
		}
	}
};

int main() {
	queue Q;
	
	for (int i = 0; i < 11; i++) {
		Q.push(i);
	}
	Q.print();
	Q.pop(); Q.pop();
	Q.print();

	return 0;
}