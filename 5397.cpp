#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		string str;
		cin >> str;
		int Leng = str.size(), LeL = 0;
		list<char> l1;
		list<char>::iterator l1_iter = l1.begin();
		while (LeL < Leng) {
			if (str[LeL] == '<') {
				if (l1_iter != l1.begin()) l1_iter--;
			}
			else if (str[LeL] == '>') {
				if (l1_iter != l1.end()) l1_iter++;
			}
			else if (str[LeL] == '-') {
				if(l1_iter != l1.begin())
					l1.erase((--l1_iter)++);
			}
			else {
				l1.insert(l1_iter, str[LeL]);
			}
			LeL++;
		}
		for (auto x : l1) cout << x;
		cout << "\n";
	}

	return 0;
}