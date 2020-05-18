#include <iostream>
#include <deque>
#include <cstring>
#include <algorithm>

using namespace std;

struct prison {
	int x, y;
};
char map[102][102];
int dist[102][102][3];
deque<prison> dq;
int dx[4] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

int H, W;
void bfs() {
	dq.push_back({ 0,0 });
	for (int q = 0; q < 3; q++) {
		int sx = dq.back().x;
		int sy = dq.back().y;

		dq.pop_back();

		deque<prison> que;
		que.push_back({ sx,sy });
		dist[sx][sy][q] = 0;

		while (!que.empty()) {
			int x = que.front().x;
			int y = que.front().y;

			que.pop_front();
			
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || nx > H + 1 || ny < 0 || ny > W + 1) continue;
				if (dist[nx][ny][q] >= 0 || map[nx][ny] == '*') continue;
				if (map[nx][ny] == '.') {
					dist[nx][ny][q] = dist[x][y][q];
					que.push_back({ nx,ny });
				}
				else if (map[nx][ny] == '#') {
					dist[nx][ny][q] = dist[x][y][q] + 1;
					que.push_back({ nx,ny });
				}

			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		memset(dist, -1, sizeof(dist));
		cin >> H >> W;
		for (int x = 0; x < H + 2; x++) {
			for (int y = 0; y < W + 2; y++) {
				if (x == 0 || x == H + 1 || y == 0 || y == W + 1) map[x][y] = '.';
				else cin >> map[x][y];
				if (map[x][y] == '$') {
					map[x][y] = '.';
					dq.push_back({ x,y });
				}
			}
		}
		bfs();
		int ans = 9876654321;
		for (int x = 0; x < H + 2; x++) {
			for (int y = 0; y < W + 2; y++) {
				if (map[x][y] == '*') continue;
				int z = dist[x][y][0] + dist[x][y][1] + dist[x][y][2];
				if (map[x][y] == '#') z -= 2;
				ans = min(ans, z);
			}
		}
		cout << ans << "\n";
	}
}