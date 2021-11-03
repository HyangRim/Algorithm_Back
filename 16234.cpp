#include <iostream>
#include <algorithm>
#include <queue>
#include <math.h>
#include <cstring>

using namespace std;
int N, L, R;
int map[51][51];
int visited[51][51];

int val[2501];

int dy[4] = { 0,-1,0,1 };
int dx[4] = { 1,0,-1,0 };
int ans = 0;

struct node {
	int y, x;
};

void bfs(int y, int x, int ct) {
	queue<node> que;

	que.push({ y,x });
	visited[y][x] = ct;

	int sum = 0;
	int many = 0;
	while (!que.empty()) {
		int qy = que.front().y;
		int qx = que.front().x;

		sum += map[qy][qx];
		many++;


		que.pop();

		for (int i = 0; i < 4; i++) {
			int ny = qy + dy[i];
			int nx = qx + dx[i];

			int gap = abs(map[ny][nx] - map[qy][qx]);
			if (ny >= 0 && nx >= 0 && ny < N && nx < N) {
				if (!visited[ny][nx]) {
					if (L <= gap && gap <= R) {
						visited[ny][nx] = ct;
						que.push({ ny,nx });
					}
				}
			}
		}
	}

	val[ct] = sum / many;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> L >> R;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
		}
	}

	while (1) {
		memset(visited, 0, sizeof(visited));
		int count = 0;

		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				if (visited[y][x] == 0) {
					count++;
					bfs(y, x, count);
				}
			}
		}
		//debug_print();
		if (count == N * N) break;
		ans++;
		for (int i = 1; i <= count; i++) {
			for (int y = 0; y < N; y++) {
				for (int x = 0; x < N; x++) {
					if (visited[y][x] == i) map[y][x] = val[i];
				}
			}
		}
	}

	cout << ans;
	return 0;
}