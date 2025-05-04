#include <iostream>
using namespace std;

struct TNode {
	int inf;
	TNode* a;
};

struct stack {
	TNode* top = nullptr;

	void push(int inf) {
		TNode* spt = new TNode;
		spt->inf = inf;
		spt->a = top;
		top = spt;
	}

	void print() {
		TNode* spt = top;
		cout << endl;
		while (spt) {
			cout << spt->inf << " ";
			spt = spt->a;
		}
		cout << endl;
	}

	TNode* searchBeforeBEnd() {
		if (!top || !top->a) return nullptr;
		TNode* spt = top;
		while (spt->a->a->a!=nullptr) spt = spt->a;
		return spt;
	}

	// замена второго и предпоследнего
	void exchange() {
	if (!top || !top->a || !top->a->a || !top->a->a->a) return; 

	TNode* second = top->a;
	TNode* beforeBEnd = searchBeforeBEnd();
	top->a = beforeBEnd->a;                
	beforeBEnd->a = second;              
	
	TNode* tmp = second->a;               
	second->a = top->a->a;                
	top->a->a = tmp;                       
}
};

int main() {
	int n;
	cout << "Count of elements: ";
	cin >> n;
	stack st;
	for (int i = 0; i < n; i++) st.push(i);

	st.print();
	st.exchange();
	st.print();
	return 0;
}