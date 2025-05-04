#include <iostream>
using namespace std;

struct TNode {
	int inf;
	TNode* a;
};

struct stack {
	TNode* top = nullptr;

	bool empty() {
		if (top) return false;
		else return true;
	}

	void push(int inf) {
		TNode* spt = new TNode;
		spt->inf = inf;
		spt->a = top;
		top = spt;
	}

	void pop() {
		TNode* spt = top;
		top = top->a;
		delete spt;
	}

	void print() {
		TNode* spt = top;
		while (spt) {
			cout << spt->inf << " ";
			spt = spt->a;
		}
	}

	TNode* search(int x) {
		if (!top) return nullptr;
		TNode* spt = top;
		while (spt->inf != x && spt->a != nullptr) spt = spt->a;
		if (spt->inf == x) return spt;
		else return nullptr;
	}

	TNode* searchp(int x) {
		if (!top && !top->a)return nullptr;
		TNode* spt = top;
		while (spt->a->inf != x && spt->a->a != nullptr) spt=spt->a;
		if (spt->a->inf == x) return spt;
		else return nullptr;
	}

	void del(int x) {
		if (!top) return;
		if (top->inf == x) pop();
		TNode* spt, * spp;
		spp = searchp(x);
		spt = spp->a;
		spp->a = spp->a->a;
		delete spt;
	}

	// обмен следующих за указаным элементом
	void exchange(TNode *sp) {
		TNode* spt;
		spt = sp->a->a;
		sp->a->a = spt->a;
		spt->a = sp->a;
		sp->a = spt;
	}
};

int main() {
	stack st;
	for (int i = 0; i < 11; i++) st.push(i);

	st.exchange(st.search(10));
	st.print();
	return 0;
}