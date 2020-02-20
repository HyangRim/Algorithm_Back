#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

bool visited[51][51];
bool vegeta[51][51];
int mx[4] = {1,0,-1,0};
int my[4] = {0,-1,0,1};
int T, M, N, K;

int cnt = 0;

void dfs(int x, int y) {
	visited[x][y] = true;
	cnt++;
	for (int i = 0; i < 4; i++) {
		int nx = x + mx[i];
		int ny = y + my[i];
		if (0 <= nx && nx < M && 0 <= ny && ny < N) {
			if (!visited[nx][ny] && vegeta[nx][ny]) {
				dfs(nx, ny);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while (T--) {
		vector<int> v1;
		memset(visited, false, sizeof(visited));
		memset(vegeta, false, sizeof(vegeta));
		cin >> M >> N >> K;
		int a, b;
		for (int x = 0; x < K; x++) {
			cin >> a >> b;
			vegeta[a][b] = true;
		}
		for (int x = 0; x < M; x++) {
			for (int y = 0; y < N; y++) {
				if (vegeta[x][y] && !visited[x][y]) {
					cnt = 0;
					dfs(x, y);
					v1.push_back(cnt);
				}
			}
		}
		cout << v1.size() << "\n";
	}
	return 0;
}