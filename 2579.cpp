#include <iostream>
#include <algorithm>
using namespace std;
int dp[301];
int arr[301];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	for (int x = 1; x <= N; x++) {
		cin >> arr[x];
	}

	for (int x = 1; x <= 3 && x <= N; x++) {//처음부터 3까지.
		if (x != 3) {
			dp[x] = dp[x - 1] + arr[x];
		}
		else {
			dp[x] = max(arr[x] + dp[x - 2], arr[x] + arr[x - 1]);
		}
	}
	for (int x = 4; x <= N; x++) {
		dp[x] = max(arr[x] + dp[x - 2], arr[x] + arr[x - 1] + dp[x - 3]);
	}
	cout << dp[N];
	return 0;
}