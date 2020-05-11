#include <iostream>
#include <vector>
#include <functional>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;

	cin >> N;
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	int oper;
	for (int x = 0; x < N; x++) {
		cin >> oper;
		if (oper == 0) {
			if (pq.empty()) {
				cout << "0\n";
			}
			else {
				cout << pq.top().second << "\n";
				pq.pop();
			}
		}
		else {
			pq.push({ abs(oper),oper });
		}
	}
	return 0;
}