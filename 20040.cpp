#include <iostream>


using namespace std;
int N, M;
int node[500001];
int find_root(int a) {
	if (node[a] == -1) return a;
	return node[a] = find_root(node[a]);
}

void group(int a, int b) {
	a = find_root(a);
	b = find_root(b);

	if (a == b)return;
	else {
		if (a < b)node[b] = a;
		else node[a] = b;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int x = 0; x < N; x++) {
		node[x] = -1;
	}
	for (int x = 0; x < M; x++) {
		int i, j;
		cin >> i >> j;
		if (find_root(i) == find_root(j)) {
			cout << x + 1;
			return 0;
		}
		group(i, j);
	}
	cout << 0;
	return 0;
}