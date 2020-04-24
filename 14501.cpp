#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int N;

struct cls {
	int day, profit;
};
cls arr[17];
int dp[17];
int ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int x = 1; x <= N; x++) {
		cin >> arr[x].day >> arr[x].profit;
	}
	for (int x = 1; x <= N +1; x++) {
		for (int y = 1; y < x; y++) {
			dp[x] = max(dp[x], dp[y]);

			if (y + arr[y].day == x) {
				dp[x] = max(dp[x], dp[y] + arr[y].profit);
			}
		}
		ans = max(ans, dp[x]);
	}
	cout << ans;
	return 0;
}