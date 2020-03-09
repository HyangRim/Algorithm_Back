#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
int map[301][301];
bool visited[301][301];

int mx[2] = {1,0};
int my[2] = {0,1};
int N, M;

void dfs() {
	queue <pair<pair<int, int>, int >> que;
	que.push(make_pair(make_pair(0, 0),0));
	visited[0][0] = true;
	while (!que.empty()) {
		int x = que.front().first.first;
		int y = que.front().first.second;
		int count = que.front().second;
		que.pop();
		if (x == N - 1 && y == M - 1) {
			cout << count;
			return;
		}
		for (int i = 0; i < 2; i++) {
			for (int j = 1; j <= map[x][y]; j++) {
				int nx = x + mx[i] * j;
				int ny = y + my[i] * j;

				if (0 <= nx && 0 <= ny && nx < N && ny < M) {
					if (!visited[nx][ny]) {
						visited[nx][ny] = true;
						que.push(make_pair(make_pair(nx, ny), count + 1));
					}
				}
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < M; y++) {
			cin >> map[x][y];
		}
	}
	dfs();
	return 0;
}