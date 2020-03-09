#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

bool era[100001];
bool visited[1000001];
int T;
int N, A, B;

int bfs() {
	queue<pair<int, int>> que;
	que.push(make_pair(N, 0));
	visited[N] = true;
	while (!que.empty()) {

		int Num = que.front().first;
		int Count = que.front().second;
		que.pop();

		if (Num >= A && Num <= B && !era[Num]) {
			return Count;
		}
		if (!visited[Num / 3]) {
			que.push(make_pair(Num / 3, Count + 1));
			visited[Num / 3] = true;
		}
		if (!visited[Num / 2]) {
			que.push(make_pair(Num / 2, Count + 1));
			visited[Num / 2] = true;
		}
		if (!visited[Num + 1] && Num +1 <= 1000000) {
			que.push(make_pair(Num + 1, Count + 1));
			visited[Num + 1] = true;
		}
		if (!visited[Num - 1] && Num -1 >= 1) {
			que.push(make_pair(Num - 1, Count + 1));
			visited[Num - 1] = true;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for (int x = 2; x <= sqrt(100000); x++) {
		for (int y = x + x; y <= 100000; y += x) {
			era[y] = true;
		}
	}
	cin >> T;
	while (T--) {
		cin >> N >> A >> B;
		memset(visited, 0, sizeof(visited));
		bool sig = false;
		for (int x = A; x <= B; x++) {
			if (!era[x]) sig = true;
		}
		if (!sig) {
			cout << -1 << "\n";
			continue;
		}
		cout << bfs() << "\n";
	}

	return 0;
}