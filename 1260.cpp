#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


int N, M;
vector<int> graph[1001];
bool visited[1001];

void dfs(int x) {
	visited[x] = true;
	cout << x << " ";

	for (int to : graph[x])
		if (!visited[to])
			dfs(to);
}

void bfs(int x) {
	bool visited[1001] = {};
	queue<int> q;

	visited[x] = true;
	q.push(x);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		cout << x << " ";
		for (int to : graph[x]) {
			if (!visited[to]) {
				visited[to] = true;
				q.push(to);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M;
	cin >> N >> M;
	int a, b;
	for (int x = 0; x < M; x++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int x = 0; x < N; x++) {
		sort(graph[x].begin(), graph[x].end());
	}


	return 0;
}