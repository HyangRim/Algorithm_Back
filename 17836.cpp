#include <iostream>
#include <queue>
#include <algorithm>

int N, M, T;
using namespace std;

int map[101][101];
bool visited[101][101][2];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
struct node {
	int y, x, cnt, sword;
};


void bfs() {
	queue<node> que;

	que.push({ 0,0,0,0 });

	while (!que.empty()) {
		int y = que.front().y;
		int x = que.front().x;
		int cnt = que.front().cnt;
		int nsword = que.front().sword;

		que.pop();

		if (cnt > T) {
			cout << "Fail";
			return;
		}
		if (y == N - 1 && x == M - 1) {
			cout << cnt;
			return;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nsword == 0) {//없을 경우
				if (nx >= 0 && ny >= 0 && ny < N && nx < M) {
					if (!visited[ny][nx][0] && map[ny][nx] != 1) {
						visited[ny][nx][0] = true;
						if (map[ny][nx] == 0)	que.push({ ny,nx,cnt + 1, 0 });
						else que.push({ ny,nx,cnt + 1, 1 });
					}
				}
			}
			else if(nsword == 1){//있을 경우
				if (nx >= 0 && ny >= 0 && ny < N && nx < M) {
					if (!visited[ny][nx][1]) {
						visited[ny][nx][1] = true;
						que.push({ ny,nx,cnt + 1, 1 });
					}
				}
			}
		}
	}
	cout << "Fail";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> T;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> map[y][x];
		}
	}
	bfs();
	return 0;
}