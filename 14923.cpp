#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int N, M;
int hx, hy;
int sx, sy;
struct hk {
	int x, y, time, br;
};
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int map[1024][1024];
bool visited[1024][1024][2];
int bfs() {
	queue<hk> que;
	visited[sx][sy][1] = true;
	que.push({ sx,sy,0,1 });

	while (!que.empty()) {
		int x = que.front().x;
		int y = que.front().y;
		int time = que.front().time;
		int br = que.front().br;

		que.pop();

		if (x == hx && y == hy) return time;

		for (int i = 0; i < 4; i++) {

			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (visited[nx][ny][br]) continue;
			if (map[nx][ny] == 0) {
				visited[nx][ny][br] = true;
				que.push({ nx,ny,time + 1,br });
			}
			else if(map[nx][ny] == 1 && br == 1) {
				visited[nx][ny][br] = true;
				que.push({ nx,ny,time + 1,br - 1 });
			}
			/*if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
				if (map[nx][ny] == 0 && !visited[nx][ny][br]) {
					visited[nx][ny][br] = true;
					que.push({ nx,ny,time + 1,br });
				}
				else if (map[nx][ny] == 1 && !visited[nx][ny][br] && br == 1) {
					visited[nx][ny][br] = true;
					que.push({ nx,ny,time + 1,br - 1 });
				}
			}
			*/
		}
	}
	return -1;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	cin >> sx >> sy;
	sx--, sy--;
	cin >> hx >> hy;
	hx--, hy--;
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < M; y++) {
			cin >> map[x][y];
		}
	}
	cout << bfs();
	return 0;
}