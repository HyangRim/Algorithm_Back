#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
int T;
int W, H;
char map[1001][1001];
bool visited[1001][1001];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };


struct sang {
	int x, y;
};
int sx, sy;
vector<sang> fire;
int bfs() {
	queue<sang> que;
	queue<sang> flame;
	que.push({ sx,sy });
	for (int i = 0; i < fire.size(); i++) {
		flame.push(fire[i]);
	}
	int result = 0;

	while (!que.empty()) {
		
		int flamesz = flame.size();
		for (int i = 0; i < flamesz; i++) {
			int x = flame.front().x;
			int y = flame.front().y;

			flame.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (0 <= nx && 0 <= ny && nx < H && ny < W) {
					if (map[nx][ny] == '.') {
						map[nx][ny] = '*';
						flame.push({ nx,ny });
					}
				}
			}
		}
		//불 이동
		int cur = que.size();
		for (int i = 0; i < cur; i++) {
			int x = que.front().x;
			int y = que.front().y;

			que.pop();

			if (y == 0 || x == 0 || y == W - 1 || x == H - 1) return result + 1;

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (0 <= nx && 0 <= ny && nx < H && ny < W) {
					if (!visited[nx][ny] && map[nx][ny] != '*' && map[nx][ny] != '#') {
						visited[nx][ny] = true;
						que.push({ nx,ny });
					}
				}
			}
		}
		//사람 이동
		result++;
	}
	return -1;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while (T--) {
		fire.clear();
		memset(map, 0, sizeof(map));
		memset(visited, false, sizeof(visited));
		cin >> W >> H;
		for (int x = 0; x < H; x++) {
			for (int y = 0; y < W; y++) {
				cin >> map[x][y];
				if (map[x][y] == '@') {
					sx = x;
					sy = y;
				}
				else if (map[x][y] == '*') {
					fire.push_back({ x,y });
				}
			}
		}
		int ans = bfs();
		if (ans == -1) {
			cout << "IMPOSSIBLE\n";
		}
		else {
			cout << ans << "\n";
		}
	}
	return 0;
}