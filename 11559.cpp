#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
char map[12][6];
bool visited[12][6];

int mx[4] = { 1,0,-1,0 };
int my[4] = { 0,1,0,-1 };
vector<pair<int, int>> tmp, v1;

int boom = 0;
int temp = 0;
void dfs(int y,int x) {
	for (int i = 0; i < 4; i++) {
		int nx = x + mx[i];
		int ny = y + my[i];

		if (nx >= 0 && ny >= 0 && nx < 6 && ny < 12) {
			if (map[ny][nx] != '.' && !visited[ny][nx] && map[ny][nx] == map[y][x]) {
				temp++;
				visited[ny][nx] = true;
				tmp.push_back({ ny,nx });
				dfs(ny, nx);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for (int y = 0; y < 12; y++) {
		for (int x = 0; x < 6; x++) {
			cin >> map[y][x];
		}
	}

	bool flag;
	int ans = 0;
	while (1) {
		flag = false;
		memset(visited, false, sizeof(visited));
		v1.clear();

		for (int y = 0; y < 12; y++) {
			for (int x = 0; x < 6; x++) {
				if (map[y][x] != '.' && !visited[y][x]) {
					temp = 1;
					tmp.push_back({ y,x });
					visited[y][x] = true;
					dfs(y, x);

					if (temp >= 4) {
						flag = true;
						for (int i = 0; i < tmp.size(); i++) {
							v1.push_back(tmp[i]);
						}
					}
					tmp.clear();
				}
			}
		}
		for (int i = 0; i < v1.size(); i++) {
			int x = v1[i].second;
			int y = v1[i].first;

			map[y][x] = '.';
		}
		for (int y = 10; y >= 0; y--) {
			for (int x = 0; x < 6; x++) {
				if (map[y][x] == '.') continue;
				int tp = y;

				while (1) {
					if (tp == 11 || map[tp + 1][x] != '.') break;

					map[tp + 1][x] = map[tp][x];
					map[tp][x] = '.';
					tp++;
				}
			}
		}
		if (flag) ans++;
		else break;
	}
	cout << ans;


	return 0;
}