#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int N, M;
int map[301][301];
int cmap[301][301];
bool visited[301][301];

int nx[4] = {1,0,-1,0};
int ny[4] = {0,-1,0,1};

void bfs(int a, int b) {
	queue<pair<int, int>> que;

	que.push({ a,b });
	visited[a][b] = true;

	while (!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;
		que.pop();

		for (int i = 0; i < 4; i++) {
			int dx = x + nx[i];
			int dy = y + ny[i];

			if (dx >= 0 && dy >= 0 && dx < N && dy < M) {
				if (visited[dx][dy] == false && map[dx][dy] != 0) {
					visited[dx][dy] = true;
					que.push({ dx,dy });
				}
			}
		}
	}
}

int melt(int x, int y) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int dx = x + nx[i];
		int dy = y + ny[i];
		if (map[dx][dy] == 0)cnt++;
	}
	return cnt;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	int year = 0;

	while (1) {
		int Land_Cnt = 0;
		memset(visited, false, sizeof(visited));
		memset(cmap, 0, sizeof(cmap));

		for (int x = 0; x < N; x++) {
			for (int y = 0; y < M; y++) {
				if (map[x][y] != 0 && visited[x][y] == false) {
					Land_Cnt++;
					bfs(x, y);
				}
			}
		}

		if (Land_Cnt > 1) {
			cout << year << "\n";
			break;
		}
		if (Land_Cnt == 0) {
			cout << 0 << "\n";
			break;
		}

		for (int x = 0; x < N; x++) {
			for (int y = 0; y < M; y++) {
				if (map[x][y] != 0) {
					cmap[x][y] = map[x][y] - melt(x, y);
					if (cmap[x][y] < 0) cmap[x][y] = 0;
				}
			}
		}
		
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < M; y++) {
				map[x][y] = cmap[x][y];
			}
		}

		year++;
	}
	return 0;
}