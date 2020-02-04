#include <iostream>
#include <queue>
using namespace std;


int T, N, M, ipt;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	for (int x = 0; x < T; x++) {
		int count = 0;
		cin >> N >> M;
		int cnt = 0;
		queue<pair<int, int>> q;
		priority_queue<int> pq;

		for (int y = 0; y < N; y++) {
			cin >> ipt;
			q.push({ y,ipt });
			pq.push(ipt);
		}
		while (!q.empty()) {
			int index = q.front().first;
			int value = q.front().second;
			q.pop();
			if (pq.top() == value) {
				pq.pop();
				++count;
				if (index == M) {
					cout << count << endl;
					break;
				}
			}
			else q.push({ index,value });
		}

	}
	
	return 0;
}