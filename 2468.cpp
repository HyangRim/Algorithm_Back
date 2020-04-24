#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
int arr[101][101];
bool visited[101][101];
int N;
int cnt = 0;
int nx[4] = {1,0,-1,0};
int ny[4] = {0,-1,0,1};
void dfs(int x,int y,int a) {
	visited[x][y] = true;
	cnt++;
	for (int i = 0; i < 4; i++) {
		int dx = x + nx[i];
		int dy = y + ny[i];
		if (0 <= dx && 0 <= dy && dx < N && dy < N) {
			if (!visited[dx][dy] && (a < arr[dx][dy])) {
				dfs(dx, dy, a);
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	int max = 0;
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			cin >> arr[x][y];
			if (max < arr[x][y]) max = arr[x][y];
		}
	}
	vector<int> slv;
	for (int a = 1; a <= max; a++) {
		cnt = 0;
		memset(visited, false, sizeof(visited));
		vector<int> v1;
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < N; y++) {
				if (!visited[x][y] && (a < arr[x][y])) {
					cnt = 0;
					dfs(x, y,a);
					v1.push_back(cnt);
				}
			}
		}
		slv.push_back(v1.size());
	}
	int ans = -987654321;
	for (int x = 0; x < slv.size(); x++) {
		if (ans < slv[x]) 	ans = slv[x];
	}
	cout << ans;
	return 0;
}