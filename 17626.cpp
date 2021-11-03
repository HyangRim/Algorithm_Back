#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int N;
int dp[50001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	dp[1] = 1;
	for (int x = 1; x <= N; x++) {
		dp[x] = dp[1] + dp[x - 1];
		for (int y = 2; y * y <= x; y++) {
			dp[x] = min(dp[x], 1 + dp[x - y * y]);
		}
	}
	cout << dp[N];
	return 0;
}