#include <iostream>

using namespace std;
unsigned long long dp[91];
int N;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 2;
	dp[4] = 3;
	for (int x = 5; x <= N; x++) {
		dp[x] = dp[x - 1] + dp[x - 2];
	}

	cout << dp[N];

	return 0;
}