#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int arr[101][101];
bool visited[101][101];

int M, N, K;

int mx[4] = { 1,0,-1,0 };
int my[4] = { 0,-1,0,1 };
int cnt = 0;
void dfs(int y,int x) {
	visited[y][x] = true;

	cnt++;

	for (int i = 0; i < 4; i++) {
		int nx = x + mx[i];
		int ny = y + my[i];

		if (0 <= nx && 0 <= ny && nx < N && ny < M) {
			if (!visited[ny][nx] && arr[ny][nx] == 0) {
				dfs(ny, nx);
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> M >> N >> K;

	int lx, ly, rx, ry;
	for (int a = 0; a < K; a++) {
		cin >> lx >> ly >> rx >> ry;

		for (int y = ly; y < ry; y++) {
			for (int x = lx; x < rx; x++) {
				arr[y][x] = 1;
			}
		}
	}
	vector<int> v1;
	for (int y = 0; y < M; y++) {
		for (int x = 0; x < N; x++) {
			if (arr[y][x] == 0 && !visited[y][x]) {
				cnt = 0;
				dfs(y, x);
				v1.push_back(cnt);
			}
		}
	}
	sort(v1.begin(), v1.end());
	cout << v1.size() << "\n";
	for (int x = 0; x < v1.size(); x++) {
		cout << v1[x] << " ";
	}
	return 0;
}