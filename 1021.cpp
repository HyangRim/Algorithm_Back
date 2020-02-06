#include <iostream>
#include <queue>
#include <deque>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int count = 0;
	int N, M;
	cin >> N >> M;
	deque<int> dq;
	int K;
	for (int x = 1; x <= N; x++) {
		dq.push_back(x);
	}
	for (int x = 0; x < M; x++) {

		cin >> K;
		if (dq[x] == K) {

		}
	}
	return 0;
}