#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
int M, N;
int map[1001][1001];
int visited[1001][1001];
int mx[4] = {1,0,-1,0};
int my[4] = {0,-1,0,1};

queue<pair<int, int>> q;
int bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + mx[i];
			int ny = y + my[i];

			if (0 <= nx && 0 <= ny && nx < M && ny < N) {
				if (map[nx][ny] == 0 && visited[nx][ny] == -1) {
					visited[nx][ny] = visited[x][y] + 1;
					q.push({ nx,ny });
				}
			}
		}
	}
	int ans = 0;
	for (int x = 0; x < M; x++) {
		for (int y = 0; y < N; y++) {
			ans = max(ans, visited[x][y]);
		}
	}

	for (int x = 0; x < M; x++) {
		for (int y = 0; y < N; y++) {
			if (map[x][y] == 0 && visited[x][y] == -1) {
				ans = -1;
			}
		}
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> M >> N;
	for (int x = 0; x < M; x++) {
		for (int y = 0; y < N; y++) {
			cin >> map[x][y];
			visited[x][y] = -1;
			if (map[x][y] == 1) {
				q.push({ x,y });
				visited[x][y] = 0;
			}
		}
	}
	cout << bfs();
	return 0;
}