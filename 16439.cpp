#include <iostream>
#include <algorithm>

using namespace std;
int N, M;
int ans;
int map[31][31];
void dfs(int i, int ct, int score[]) {
	int tmp[31];

	for (int j = 0; j < N; j++) {
		tmp[j] = max(score[j], map[j][i]);
	}

	if (ct == 3) {
		int sum = 0;
		for (int j = 0; j < N; j++) sum += tmp[j];
		ans = max(ans, sum);
		return;
	}
	for (int y = i + 1; y < M; y++) {
		dfs(y, ct + 1, tmp);
	}
	return;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int score[31];

	memset(score, 0, sizeof(score));
	cin >> N >> M;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> map[y][x];
		}
	}
	for (int x = 0; x < M; x++) {
		dfs(x, 1, score);
	}
	cout << ans << "\n";
	return 0;
}