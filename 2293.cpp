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
	for (int x = 1; x <= N; x++) {
		cin >> arr[x];
	}
	dp[0] = 1;
	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= K; y++) {
			if (y >= arr[x]) {
				dp[y] += dp[y - arr[x]];
			}
		}
	}

	cout << dp[K];
	return 0;
}