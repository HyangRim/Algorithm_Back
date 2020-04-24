#include <iostream>
#include <algorithm>
using namespace std;
int arr[10005];
int dp[10005];
int drk(int N) {
	if (N < 1) {
		return arr[N];
	}
	if (dp[N] != 0) {
		return dp[N];
	}
	else {
		return dp[N] = max(drk(N - 1), max(drk(N - 2) + arr[N], drk(N - 3) + arr[N - 1] + arr[N]));
	}
}
int main() {
	int N;
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int x = 0; x < N; x++) {
		cin >> arr[x];
	}
	cout << drk(N);
	return 0;
}