#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;


char map[501][501];
int dp[501][501];

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };


int N, M;

int dir_to_idx(char A) {
	if (A == 'U') return 3;
	else if (A == 'R') return 0;
	else if (A == 'D') return 2;
	else if (A == 'L') return 1;
}

int dfs(int x, int y) {
	if (x >= N || y >= M || x < 0 || y < 0) return 1;
	if (dp[x][y] != -1) return dp[x][y];
	dp[x][y] = 0;
	int dir = dir_to_idx(map[x][y]);
	dp[x][y] = dfs(x + dx[dir], y + dy[dir]);
	return dp[x][y];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	string tmp;
	for (int x = 0; x < N; x++) {
		cin >> tmp;
		int tlen = tmp.length();
		for (int y = 0; y < M; y++) {
			map[x][y] = tmp[y];
			dp[x][y] = -1;
		}
	}
	int val = 0;

	for (int x = 0; x < N; x++) {
		for (int y = 0; y < M; y++) {
			val += dfs(x, y);
		}
	}
	cout << val;
	return 0;
}