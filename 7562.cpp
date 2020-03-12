#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

bool visited[301][301];
int mx[8] = {1,2,2,1,-1,-2,-2,-1};
int my[8] = {2,1,-1,-2,-2,-1,1,2};
int T, I;
int kx, ky;//목표 나이트 좌표. 
int cnt;
int bfs(int x,int y) {
	queue<pair<pair<int, int>, int>>que;
	que.push(make_pair(make_pair(x, y), 0));
	visited[x][y] = true;

	while (!que.empty()) {
		int qx = que.front().first.first;
		int qy = que.front().first.second;
		int Count = que.front().second;

		que.pop();

		if (qx == kx && qy == ky) {
			return Count;
		}


		for (int i = 0; i < 8; i++) {
			int nx = qx + mx[i];
			int ny = qy + my[i];
			if (nx >= 0 && ny >= 0 && nx < I && ny < I) {
				if (!visited[nx][ny]) {
					visited[nx][ny] = true;
					que.push(make_pair(make_pair(nx,ny),Count+1));
				}
			}
		}
	}
	return -1;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while (T--) {
		int x, y;
		memset(visited, false, sizeof(visited));
		cin >> I;
		cin >> x >> y;
		cin >> kx >> ky;
		cout << bfs(x, y) << "\n";
	}
	return 0;
}