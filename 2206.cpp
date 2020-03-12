#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

string str[1001];
bool visited[1001][1001][2];
int N, M;
int mx[4] = { 1,0,-1,0 };
int my[4] = { 0,-1,0,1 };
int bfs() {
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push(make_pair(make_pair(0, 0), make_pair(0, 1)));
	visited[0][0][0] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int br = q.front().second.first;
		int Count = q.front().second.second;

		q.pop();
		if (x == N - 1 && y == M - 1) {
			return Count;
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + mx[i];
			int ny = y + my[i];
			if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
				if (str[nx][ny] == '1' && !br) {
					visited[nx][ny][br + 1] = true;
					q.push(make_pair(make_pair(nx,ny), make_pair(br+1,Count+1)));
				}
				else if (str[nx][ny] == '0'&& !visited[nx][ny][br]) {
					visited[nx][ny][br] = true;
					q.push(make_pair(make_pair(nx, ny), make_pair(br, Count+1)));
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
	cin >> N >> M;
	for (int x = 0; x < N; x++) {
		cin >> str[x];
	}
	cout << bfs();
	return 0;
}