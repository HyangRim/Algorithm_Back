#include <iostream>
#include <algorithm>

using namespace std;
int N, K, Q, M, S, E;
bool sleep[5005];
bool check[5005];
int ans[50005];
int tmp;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K >> Q >> M;
	while (K--) {
		cin >> tmp;
		sleep[tmp] = true;
	}

	while (Q--) {
		cin >> tmp;
		if (sleep[tmp]) continue;
		for (int x = tmp; x <= N + 2; x += tmp) {
			if (sleep[x]) continue;
			check[x] = true;
		}
	}

	for (int x = 3; x <= N + 2; x++) {
		ans[x] = ans[x - 1] + (check[x] == false);
	}

	for (int x = 0; x < M; x++) {
		cin >> S >> E;
		cout << ans[E] - ans[S - 1] << "\n";
	}
	return 0;
}