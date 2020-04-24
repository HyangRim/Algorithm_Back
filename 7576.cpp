#include <iostream>
#include <queue>

int mx[4] = { 1,0,-1,0 };
int my[4] = { 0,-1,0,1 };
int map[1001][1001];
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	queue<pair<int, int>> que;

	int M, N;
	cin >> M >> N;
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < M; y++) {
			cin >> map[x][y];

			if (map[x][y] == 1) {
				que.push({ x,y });
			}
		}
	}
	while (!que.empty()) {
		int y = que.front().first;
		int x = que.front().second;

		que.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + mx[i];
			int ny = y + my[i];

			if (nx >= 0 && ny >= 0 && nx < M && ny < N) {
				if (map[ny][nx] == 0) {
					que.push({ ny,nx });
					map[ny][nx] = map[y][x] + 1;
				}
			}
		}
	}
	int ans = 0;
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < M; y++) {
			if (map[x][y] == 0) {
				cout << -1 << "\n";
				return 0;
			}
			ans = max(ans, map[x][y]);
		}
	}
	cout << ans - 1 << "\n";
	return 0;
}