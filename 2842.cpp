#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;


int N;
char map[51][51];
int hmap[50][50];
bool visited[50][50];
int vec[2505];
int sx, sy;
int s, l;
int ans = 987654321;
const int dx[8] = { 1,1,0,-1,-1,-1,0,1 };
const int dy[8] = { 0,-1,-1,-1,0,1,1,1 };

void dfs(int y, int x) {
	if (0 > x || 0 > y || x >= N || y >= N || visited[y][x]) return;
	if (hmap[y][x] < vec[s] || hmap[y][x] > vec[l]) return;
	visited[y][x] = true;
	for (int i = 0; i < 8; i++) {
		dfs(y + dy[i], x + dx[i]);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
			if (map[y][x] == 'P') {
				sy = y;
				sx = x;
			}
		}
	}
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> hmap[y][x];
			vec[y*N + x] = hmap[y][x];
		}
	}
	sort(vec, vec + N * N);

	while (l < N*N) {
		dfs(sy, sx);
		bool flag = false;
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				if (!visited[y][x] && map[y][x] == 'K') flag = true;
				visited[y][x] = false;
			}
		}
		flag ? l++ : ans = min(ans, vec[l] - vec[s++]);
	}
	
	
	cout << ans;


	return 0;
}