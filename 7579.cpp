#include <iostream>
#include <algorithm>

using namespace std;
int N, M;
int c[101];
int m[101];
int dp[101][10001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int x = 0; x < N; x++) {
		cin >> m[x];
	}
	for (int x = 0; x < N; x++) {
		cin >> c[x];
	}
	int ans = 987654321;
	dp[0][c[0]] = m[0];
	for (int x = 1; x < N; x++) {
		for (int y = 0; y <= 10000; y++) {
			if (y - c[x] >= 0)
				dp[x][y] = max(dp[x][y], dp[x - 1][y - c[x]] + m[x]);

			dp[x][y] = max(dp[x][y], dp[x - 1][y]);

			if (dp[x][y] >= M)
				ans = min(ans, y);
		}
	}
	cout << ans;
	return 0;
}