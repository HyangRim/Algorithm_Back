#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v1[300001];
int dist[300001];
vector<int> ans;

int N, M, K, X;

void bfs() {

	queue<pair<int, int>> que;

	que.push({ X,0 });
	dist[X] = 1;
	
	while (!que.empty()) {
		int cur = que.front().first;
		int length = que.front().second;

		que.pop();


		if (length == K) {
			ans.push_back(cur);
		}


		for (int i = 0; i < v1[cur].size(); i++) {
			int nx = v1[cur][i];

			if (!dist[nx]) {
				dist[nx] = 1;
				que.push({ nx,length + 1 });
			}
		}
	}
	
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	cin >> N >> M >> K >> X;
	int start, to;
	for (int x = 0; x < M; x++) {
		cin >> start >> to;
		v1[start].push_back(to);
	}

	bfs();

	if (ans.size() == 0) cout << -1;
	else {
		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << "\n";
		}
	}
	return 0;
}