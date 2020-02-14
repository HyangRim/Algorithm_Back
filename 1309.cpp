#include <iostream>

using namespace std;
int N;
int dp[100001][3];
int main() {
	cin >> N;
	dp[1][0] = dp[1][1] = dp[1][2] = 1;

	for (int x = 2; x <= N; x++) {
		dp[x][0] = (dp[x - 1][0] + dp[x - 1][1] + dp[x - 1][2]) % 9901;
		dp[x][1] = (dp[x - 1][0] + dp[x - 1][2]) % 9901;
		dp[x][2] = (dp[x - 1][0] + dp[x - 1][1]) % 9901;
	}
	cout << (dp[N][0] + dp[N][1] + dp[N][2]) % 9901;
	return 0;
}
