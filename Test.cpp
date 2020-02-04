#include <iostream>
#include <list>

using namespace std;


int main() {

	list<int> l1;
	for (int x = 0; x < 100000000; x++) {
		if (x % 100000 == 0) cout << x << "\n";
		l1.push_front(x);
	}
	cout << "end";
	return 0;
}