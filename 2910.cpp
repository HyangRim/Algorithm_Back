#include <iostream>
#include <list>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;


int N, C;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	list<int> l;
	multimap<int, int, greater<int>> m;
	cin >> N >> C;
	int num, i;
	vector<int> v;
	while (N--) {
		cin >> i;
		l.push_back(i);
	}

	while (!l.empty()) {
		i = 0;
		for (auto n : l) {
			num = l.front();
			if (n == num)
				i++;
		}
		m.insert(make_pair(i, num));
		l.remove(num);
	}

	for (auto it = m.begin(); it != m.end(); it++)
		for (int i = 0; i < it->first; i++)
			v.push_back(it->second);

	for (auto n : v)
		cout << n << " ";
	return 0;
}