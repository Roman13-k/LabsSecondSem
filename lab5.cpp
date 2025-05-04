#include <iostream>
#include <math.h>
using namespace std;

struct Human {
	char surname[20];
	char address[20];
	int number;
};

struct TNode {
	Human inf;
	TNode* a;
};

struct THash {
	TNode** H = nullptr;
	int m;

	void create(int n) {
		m = n;
		H = new TNode * [m];
		for (int i = 0; i < m; i++) H[i] = nullptr;
	}

	void push(Human inf) {
		int k = abs(inf.number % m);
		TNode* spt=new TNode;
		spt->inf = inf;
		spt->a = H[k];
		H[k] = spt;
	}

	TNode* search(int inf) {
		int k = abs(inf % m);
		TNode* spt = H[k];
		while (spt && spt->inf.number != inf)spt = spt->a;
		return spt;
	}

	void print(TNode* inf) {
		cout << inf->inf.surname << " " << inf->inf.address << " " << inf->inf.number << endl;
	}

	void del() {
		TNode* spt;
		for (int i = 0; i < m; i++) {
			cout << endl << i << "->";
			while (H[i]) {
				spt = H[i];
				H[i] = H[i]->a;
				cout << spt->inf.number << "";
				delete spt;
			}
		}
		delete[]H;
	}
};

void print_human(Human human);

int main() {
	int n;
	/*cout << "Kol auto: ";
	cin >> n;

	cout << "Inf of auto: " << endl;
	Human* humans = new Human[n];
	for (int i = 0; i < n; i++) {
		cout << "Surname: ";
		cin >> humans[i].surname;
		cout << "Address: ";
		cin >> humans[i].address;
		cout << "Number: ";
		cin >> humans[i].number;
		cout << endl;
	}*/

	n = 6;
	Human humans[] = {
	{"DKJdf", "2 Sdsddd 4", 30021232},
	{"Dnjsfnk", "12 fwfew 3", 24232130},
	{"Fbkbf", "12 wefe 2", 262327},
	{"Alfrkoa", "54 we 34", 23433233},
	{"SLsdf", "123 sefew 24", 712331353},
	{"SDOjdnf", "44 wer 43", 224234334},
	};

	for (int i = 0; i < n; i++) {
		print_human(humans[i]);
	}

	THash h;
	h.create(15);
	for (int i = 0; i < n; i++) h.push(humans[i]);

	int num;
	cout << "Number for search: ";
	cin >> num;
	h.print(h.search(num));

	h.del();
	return 0;
}

void print_human(Human human) {
	cout << human.surname << " " << human.address << " " << human.number << endl;
}