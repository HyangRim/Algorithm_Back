#include <iostream>
#include <list>

using namespace std;


int N;
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;

	int temp;
	list<pair<int,int>> l1;
	for (int x = 0; x < N; x++) {
		cin >> temp;
		l1.push_back(make_pair(temp, x+1));
	}

	auto it = l1.begin();
	for(int i = 0; i< N-1;i++) {
		cout << it->second << " ";
		int step = it->first;

		if (step > 0) {
			auto temp = it;
			++temp;
			if (temp == l1.end()) {
				temp = l1.begin();
			}
			l1.erase(it);
			it = temp;
			for (int x = 1; x < step; x++) {
				++it;
				if (it == l1.end()) {
					it = l1.begin();
				}
			}
		}
		else if (step < 0) {
			step = -step;
			auto temp = it;
			if (temp == l1.begin()) {
				temp = l1.end();
			}
			--temp;
			l1.erase(it);
			it = temp;
			for (int x = 1; x < step; x++) {
				if (it == l1.begin()) {
					it = l1.end();
				}
				--it;
			}
		}
	}
	cout << l1.front().second << "\n";
	return 0;
}