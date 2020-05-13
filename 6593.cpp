#include <iostream>
#include <queue>
#include <cstring>
#include <tuple>
#include <algorithm>
using namespace std;
int L, R, C;//층, 행, 열

int dx[6] = { -1,1,0,0,0,0 };
int dy[6] = { 0,0,-1,1,0,0 };
int dz[6] = { 0,0,0,0,-1,1 };

char map[32][32][32];
bool visited[32][32][32];
int sx, sy, sz;//시작점
int ex, ey, ez;//END.
int sec = 999999999;
bool bfs() {
	queue<tuple<int, int, int, int>> que;
	visited[sz][sy][sx] = true;

	que.push({ sz,sy,sx,0 });

	while (!que.empty()) {
		tuple<int, int, int, int> tmp = que.front();
		que.pop();
		if (map[get<0>(tmp)][get<1>(tmp)][get<2>(tmp)] == 'E') {
			sec = min(sec, get<3>(tmp));
			return true;
		}

		for (int i = 0; i < 6; i++) {
			int nx = get<2>(tmp) + dx[i];
			int ny = get<1>(tmp) + dy[i];
			int nz = get<0>(tmp) + dz[i];

			if (nx >= 0 && ny >= 0 && nz >= 0 && L > nz && R > ny && C > nx) {
				if (map[nz][ny][nx] != '#' && !visited[nz][ny][nx]) {
					visited[nz][ny][nx] = true;
					que.push({ nz,ny,nx, get<3>(tmp) + 1 });
				}
			}
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (1) {
		cin >> L >> R >> C;
		if (L == 0 && R == 0 && C == 0) return 0;
		
		for (int z = 0; z < L; z++) {
			for (int y = 0; y < R; y++) {
				for (int x = 0; x < C; x++) {
					cin >> map[z][y][x];
					if (map[z][y][x] == 'S') {
						sx = x;
						sy = y;
						sz = z;
					}
					else if (map[z][y][x] == 'E') {
						ex = x;
						ey = y;
						ez = z;
					}
				}
			}
		}
		if (bfs()) {
			cout << "Escaped in " << sec << " minute(s)." << "\n";
		}
		else {
			cout << "Trapped!" << "\n";
		}
		memset(map, 0, sizeof(map));
		memset(visited, false, sizeof(visited));
		sec = 999999999;
	}
	return 0;
}