#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
int T;
int N;
int homex, homey;
vector<int> map[102];
bool visited[102];


int cpr(pair<int, int> p1, pair<int, int> p2) {
	return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

void dfs(int node) {
	visited[node] = true;


	for (int i = 0; i < map[node].size(); i++) {
		int next = map[node][i];
		if (!visited[next]) dfs(next);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while (T--) {
		for (int x = 0; x < 102; x++) {
			map[x].clear();
		}
		memset(visited, false, sizeof(visited));
		cin >> N;
		vector<pair<int, int>> coord;

		for (int y = 0; y < N + 2; y++) {
			int a, b;//y,x
			cin >> a >> b;
			coord.push_back({ a, b });
		}


		for (int y = 0; y < N + 2; y++) {
			for (int z = y + 1; z < N + 2; z++) {
				if (cpr(coord[y], coord[z]) <= 1000) {
					map[y].push_back(z);
					map[z].push_back(y);
				}
			}
		}
		dfs(0);
		if (visited[N + 1]) cout << "happy\n";
		else cout << "sad\n";
	}
	return 0;
}