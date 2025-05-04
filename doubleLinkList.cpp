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

	bool empty() {
		if (front) return false;
		return true;
	}

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

	void pop() {
		TNode* spt = front;
		front = front->right;
		delete spt;
		if (!front) back = nullptr;
		else front->left = nullptr;
	}

	void print() {
		TNode* spt = front;
		while (spt) {
			cout << spt->inf << " ";
			spt = spt->right;
		}
	}

	TNode* search(int x) {
		if (!front) return nullptr;
		TNode* spt = front;
		while (spt->inf != x && spt->right != nullptr)spt = spt->right;
		if (spt->inf == x) return spt;
		else return nullptr;
	}

	void del(int x) {
		TNode* spt = search(x);
		if (!spt) return;

		if (front == back) {
			front = back = nullptr;
		}
		else
			if (!spt->left) {
				front = spt->right;
				front->left = nullptr;
			} else
				if (!spt->right) {
					back = spt->left;
					back->right = nullptr;
				}
				else {
					spt->right->left = spt->left;
					spt->left->right = spt->right;
				}
		delete spt;
	}

	// добавление после заданого
	void pushleft(TNode* spp, int inf) {
		TNode* spt = new TNode;
		spt->inf = inf;
		spt->right = spp->right;
		spt->left = spp;
		spp->right = spt;
		if (spt->right) spt->right->left = spt;
		else back = spt;
	}
};

int main() {
	// двусвязный список
	list List;

	for (int i = 0; i < 11; i++) {
		List.push(i);
	}
	List.pop();
	cout << List.search(10)->inf<<endl;

	List.del(7);
	List.del(3);

	List.print();
	cout << endl;

	List.pushleft(List.search(4), 200);
	List.print();
	//циклический двусвязный список

	return 0;
}