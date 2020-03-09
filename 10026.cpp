#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

string map[101];
bool visited[101][101];
int N;
int cnt;

int mx[4] = {0,0,-1,1};
int my[4] = {1,-1,0,0};


void dfs(int x,int y,char sig) {
	visited[x][y] = true;
	cnt++;
	for (int i = 0; i < 4; i++) {
		int nx = x + mx[i];
		int ny = y + my[i];
		if (0 <= nx && 0 <= ny && nx < N && ny < N) {
			if (!visited[nx][ny] && map[nx][ny] == sig)
				dfs(nx, ny, sig);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int x = 0; x < N; x++) {
		cin >> map[x];
	}
	vector<int> v1;
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			if (!visited[x][y]) {
				cnt = 0;
				dfs(x, y, map[x][y]);
				v1.push_back(cnt);
			}
		}
	}
	cout << v1.size() << " ";
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			if (map[x][y] == 'G') map[x][y] = 'R';
		}
	}

	v1.clear();
	memset(visited, 0, sizeof(visited));
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			if (!visited[x][y]) {
				cnt = 0;
				dfs(x, y, map[x][y]);
				v1.push_back(cnt);
			}
		}
	}
	cout << v1.size() << " ";
	return 0;
}