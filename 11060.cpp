#include <iostream>

using namespace std;
int dp[1001];
int N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	int Num;
	dp[1] = 1;
	for (int x = 1; x <= N; x++) {
		cin >> Num;
		if (dp[x] == 0) continue;
		for (int y = 1; (y <= Num) && (x + y <= 1000); y++) {
			if (dp[x] + 1 <= dp[x + y] || dp[x + y] == 0)
				dp[x + y] = dp[x] + 1;
		}
	}
	if (dp[N] == 0)
		cout << -1;
	else
		cout << dp[N]-1;
	return 0;
}