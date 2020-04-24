#include <iostream>

using namespace std;
int N;
int arr[1001];
int dp[1001];

int bigger(int a, int b) {
	if (a > b) return a;
	else return b;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int x = 1; x <= N; x++) {
		cin >> arr[x];
	}
	dp[0] = arr[0];
	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= x; y++) {
			dp[x] = bigger(dp[x], dp[x - y] + arr[y]);
		}
	}
	cout << dp[N];
	return 0;
}