#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;
int W, H;
char map[101][101];
int visited[101][101];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };

pair<int, int> st, ed;
int bfs(int sx, int sy) {
	queue<pair<pair<int, int>, pair<int, int>>> que;

	for (int i = 0; i < 4; i++) {
		que.push({ {sx,sy},{i,0} });//좌표 ,  각도, 거울
	}
	visited[sx][sy] = 0;

	while (!que.empty()) {
		int x = que.front().first.first;
		int y = que.front().first.second;
		int di = que.front().second.first;
		int mir = que.front().second.second;

		que.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nmir = mir;

			if (nx < 0 || ny < 0 || nx >= H || ny >= W) continue;
			if (map[nx][ny] == '*') continue;
			if (di != i) nmir += 1;
			if (visited[nx][ny] >= nmir) {
				visited[nx][ny] = nmir;
				que.push({ {nx,ny},{i,nmir} });
			}
		}
	}
	return visited[ed.first][ed.second];
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> W >> H;
	int tmp = 0;
	for (int x = 0; x < H; x++) {
		for (int y = 0; y < W; y++) {
			cin >> map[x][y];
			if (map[x][y] == 'C') {
				if (tmp == 0) {
					st.first = x;
					st.second = y;
					tmp++;
				}
				else {
					ed.first = x;
					ed.second = y;
				}
			}
			visited[x][y] = 987654321;
		}
	}
	cout << bfs(st.first, st.second);
	return 0;
}