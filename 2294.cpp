#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int N, K;
int arr[101];
int dp[10001];
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;
	for (int x = 1; x <= K; x++) {
		dp[x] = 10001;
	}

	for (int x = 1; x <= N; x++) {
		cin >> arr[x];
		for (int j = arr[x]; j <= K; j++) {
			dp[j] = min(dp[j], dp[j - arr[x]] + 1);
		}
	}

	if (dp[K] == 10001) cout << -1;
	else cout << dp[K];
	return 0;
}