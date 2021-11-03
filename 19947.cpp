#include <queue>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <math.h>

using namespace std;

int H, Y;
int dp[11];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> H >> Y;
	dp[0] = H;
	for (int x = 1; x <= Y; x++) {
		dp[x] = (int)(dp[x - 1] * 1.05);
		if (x >= 3) dp[x] = (int)max(dp[x], static_cast<int>(dp[x - 3] * 1.2));
		if (x >= 5) dp[x] = (int)max(dp[x], static_cast<int>(dp[x - 5] * 1.35));
	}
	cout << dp[Y];
	return 0;
}