#include <iostream>
#include <vector>
using namespace std;
int N;
int arr[1001];
int dp[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int x = N-1; x>= 0; x--) {
		cin >> arr[x];
	}
	for (int x = 0; x < N; x++) {
		dp[x] = 1;
		for (int y = 0; y < x; y++) {
			if (arr[x] > arr[y] && dp[y] + 1 > dp[x]) {
				dp[x] = dp[y] + 1;
			}
		}
	}
	int ans = 0;
	for (int x = 0; x < N; x++) {
		if (ans < dp[x])
			ans = dp[x];
	}
	cout << ans;
	return 0;
}