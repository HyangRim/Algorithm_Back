#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int T, M, N, K;
int cnt = 0;
bool Vegeta[51][51];
bool visited[51][51];
int nx[4] = {1,0,-1,0};
int ny[4] = { 0,-1,0,1 };


int mx[4] = { 1,0,-1,0 };
int my[4] = { 0,-1,0,1 };

void dfs(int x, int y) {
	visited[x][y] = true;
	cnt++;
	for (int i = 0; i < 4; i++) {
		int nx = x + mx[i];
		int ny = y + my[i];
		if (0 <= nx && nx < M && 0 <= ny && ny < N) {
			if (!visited[nx][ny] && Vegeta[nx][ny]) {
				dfs(nx, ny);
			}
		}
	}
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int a, b;
	cin >> T;
	while (T--) {
		vector<int> v1;
		memset(Vegeta, false, sizeof(Vegeta));
		memset(visited, false, sizeof(visited));
		cin >> M >> N >> K;
		for (int x = 0; x < K; x++) {
			cin >> a >> b;
			Vegeta[a][b] = true;
		}
		for (int x = 0; x < M; x++) {
			for (int y = 0; y < N; y++) {
				if (Vegeta[x][y] && !visited[x][y]) {
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