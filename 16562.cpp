#include <iostream>
#include <algorithm>

using namespace std;
int N, M, K;

int node[10001];
int cost[10001];

int aa, bb;

int find_root(int a) {
	if (node[a] < 0)return a;
	else return node[a] = find_root(node[a]);
}

void group(int a, int b) {
	a = find_root(a);
	b = find_root(b);

	if (a != b) {
		if (cost[a] < cost[b])node[b] = a;
		else node[a] = b;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> K;

	for (int x = 0; x <= N; x++) {
		node[x] = -1;
	}
	for (int x = 1; x <= N; x++) {
		cin >> cost[x];
	}
	for (int x = 0; x < M; x++) {
		cin >> aa >> bb;
		group(aa, bb);
	}

	int ans = 0;
	for (int x = 1; x <= N; x++) {
		if (node[x] == -1) ans += cost[x];
	}

	if (ans > K) cout << "Oh no";
	else cout << ans;
	return 0;
}