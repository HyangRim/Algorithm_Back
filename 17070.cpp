#include <iostream>

using namespace std;


int N, ans;
int map[16][16];

struct node {
	int y, x;
};

node dr[3] = { {0,1},{1,0},{1,1} };

void dfs(int y, int x, int pipe) {
	if (y == N - 1 && x == N - 1) {
		ans++;
		return;
	}

	for (int i = 0; i < 3; i++) {
		if ((i == 0 && pipe == 1) || (i == 1 && pipe == 0)) continue;

		int nx = x + dr[i].x;
		int ny = y + dr[i].y;

		if (ny >= N || nx >= N || map[ny][nx] == 1) continue;
		if (i == 2 && (map[y][x + 1] == 1 || map[y + 1][x] == 1)) continue;


		dfs(ny, nx, i);
	}
}
int main() {
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int x = 0; x < N; x++) {
		for (int y = 0; y< N; y++) {
			cin >> map[x][y];
		}
	}
	dfs(0, 1, 0);
	cout << ans;
	return 0;
}