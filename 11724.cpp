#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int graph[1001][1001];
bool visited[1001];
int Ans;
int N, M;
void DFS(int x) {

	visited[x] = true;
	for (int y = 0; y < N; y++) {
		if (graph[x][y] == 1 && !visited[y]) {
			DFS(y);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	int a, b;
	for (int x = 0; x < M; x++) {
		cin >> a >> b;
		graph[a - 1][b - 1] = 1;
		graph[b - 1][a - 1] = 1;
	}

	for (int x = 0; x < N; x++) {
		if (visited[x] == false) {
			Ans++;
			DFS(x);
		}
	}

	cout << Ans;
	return 0;
}