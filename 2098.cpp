#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int N;
int map[17][17];
int dp[1 << 17][17];
int solve(int visited, int cnt) {
	if (visited == (1 << N) - 1) {
		if (map[cnt][0] != 0)
			return map[cnt][0];
		return 987654321;
	}

	int &result = dp[visited][cnt];
	if (result != -1) return result;
	result = 987654321;

	for (int x = 0; x < N; x++) {
		if (visited & (1 << x) || map[cnt][x] == 0) continue;
		result = min(result, map[cnt][x] + solve(visited | (1 << x), x));
	}
	return result;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			cin >> map[x][y];
		}
	}
	memset(dp, -1, sizeof(dp));
	cout << solve(1, 0);
	return 0;
}