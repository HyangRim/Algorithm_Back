#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int N, C;
int map[51][51];
vector<pair<int, int>> v1;//치킨 가게. 
vector<pair<int, int>> v2;//사람
bool visited[13];
int ans;

int distance(pair<int, int> &a, pair<int, int> &b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

void DFS(int Idx, int Cnt) {
	if (Cnt == C) {
		int tmp = 0;
		for (int x = 0; x < v2.size(); x++) {
			int dist = 987654321;
			for (int j = 0; j < v1.size(); j++)
				if (visited[j])
					dist = min(dist, distance(v2[x], v1[j]));
			tmp += dist;
		}
		ans = min(ans, tmp);
		return;
	}
	if (Idx == v1.size())
		return;

	visited[Idx] = true;
	DFS(Idx+1, Cnt + 1);
	visited[Idx] = false;
	DFS(Idx + 1, Cnt);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> C;
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			cin >> map[x][y];
			if (map[x][y] == 1) {
				v2.push_back(make_pair(x, y));
			}
			if (map[x][y] == 2) {
				v1.push_back(make_pair(x,y));
			}
		}
	}
	ans = 987654321;
	DFS(0, 0);
	cout << ans;
	return 0; 
}