#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int N, M, H;
struct tomato {
	int y, x, z;
	int day;
};
int toma[101][101][101];
int dx[6] = { 0, 0, 1, 0, 0, -1 };
int dy[6] = { 0, 1, 0, 0, -1, 0 };
int dz[6] = { 1, 0, 0, -1, 0, 0 };


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> M >> N >> H;

	queue<tomato> que;
	for (int z = 0; z < H; z++) {
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				cin >> toma[y][x][z];
				if (toma[y][x][z] == 1) {
					que.push({ y,x,z,0 });
				}
			}
		}
	}
	int ans = 0;
	while (!que.empty()) {
		int x = que.front().x;
		int y = que.front().y;
		int z = que.front().z;
		int day = que.front().day;
		que.pop();

		for (int i = 0; i < 6; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];
			if (ny >= 0 && ny < N && nx >= 0 && nx < M && nz >= 0 && nz < H) {
				if (toma[ny][nx][nz] == 0) {
					toma[ny][nx][nz] = 1;
					que.push({ ny, nx, nz, day + 1 });
				}
			}
		}
		ans = max(ans, day);
	}
	for (int z = 0; z < H; z++) {
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				if (toma[y][x][z] == 0) {
					cout << -1;
					return 0;
				}
			}
		}
	}
	cout << ans;
	return 0;
}