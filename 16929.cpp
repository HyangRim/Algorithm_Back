#include <iostream>
#include <algorithm>

using namespace std;
int N, M;
char map[51][51];
bool visited[51][51];

int dy[4] = { 0,0,-1,1 };
int dx[4] = { 1,-1,0,0 };

bool dfs(int y, int x, int py, int px, char cc) {
	if (visited[y][x]) return true;
	visited[y][x] = true;

	bool chk = false;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny == py && nx == px)continue;
		if (ny < 0 || ny >= N || nx < 0 || nx >= M)continue;
		if (cc != map[ny][nx]) continue;

		chk += dfs(ny, nx, y, x, cc);
	}
	return chk;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> map[y][x];
		}
	}

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (visited[y][x]) continue;
			if (dfs(y, x, -1, -1, map[y][x])) {
				cout << "Yes";
				return 0;
			}
		}
	}
	cout << "No";
	return 0;
}