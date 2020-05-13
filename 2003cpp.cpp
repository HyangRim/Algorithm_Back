#include <iostream>
#include <vector>

using namespace std;
int N, M;
int s, e;
int ans;
int result = 0;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;

	vector<int> v1(N);
	for (int x = 0; x < N; x++) {
		cin >> v1[x];
	}
	while (1) {
		if (ans >= M) ans -= v1[s++];
		else if (e == N) break;
		else ans += v1[e++];
		if (ans == M) result++;
	}
	cout << result;
	return 0;
}