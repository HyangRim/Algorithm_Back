#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 8;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

int N, M;

int map[9][9];
int visited[9][9];

int best = 987654321;

vector<pair<int, int>> v1;


void check(int y, int x, int i, int num) {
	int ny = y;
	int nx = x;

	while (1) {
		ny += dy[i];
		nx += dx[i];
		if (map[ny][nx] == 6) break;
		//if (ny < 0 || nx < 0 || nx >= M || ny >= N)break;
		if (!(ny >= 0 && ny < N && nx >= 0 && nx < M)) break;
		visited[ny][nx] += num;
	}
}


void rotate(int cnt, int i, int num) {
	int qy = v1[cnt].first;
	int qx = v1[cnt].second;

	int number = map[qy][qx];

	if (number == 1) {
		check(qy, qx, (i + 1) % 4, num);
	}
	else if (number == 2) {
		check(qy, qx, (i + 1) % 4, num);
		check(qy, qx, (i + 3) % 4, num);
	}
	else if (number == 3) {
		check(qy, qx, (i + 1) % 4, num);
		check(qy, qx, (i + 0) % 4, num);
	}
	else if (number == 4) {
		check(qy, qx, (i + 1) % 4, num);
		check(qy, qx, (i + 0) % 4, num);
		check(qy, qx, (i + 3) % 4, num);
	}
	else if (number == 5) {
		check(qy, qx, (i + 1) % 4, num);
		check(qy, qx, (i + 0) % 4, num);
		check(qy, qx, (i + 3) % 4, num);
		check(qy, qx, (i + 2) % 4, num);
	}
}
void dfs(int cnt) {
	/*
	if (cnt > v1.size() - 1) {
		int ct = 0;
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				if (visited[y][x] == 0)ct++;
			}
		}


		best = min(best, ct);
		return;
	}
	for (int i = 0; i < 4; i++) {
		rotate(cnt, i, 1);
		dfs(cnt + 1);
		rotate(cnt, i, -1);
	}
	*/
	if (cnt > v1.size() - 1) {
		int ct = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (visited[i][j] == 0)
					ct++;
			}
		}


		best = min(best, ct);
		return;
	}
	for (int i = 0; i < 4; ++i)
	{
		rotate(cnt, i, 1);
		dfs(cnt + 1);
		rotate(cnt, i, -1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> map[y][x];

			if (map[y][x] != 0 && map[y][x] != 6) {
				v1.push_back({ y,x });
				visited[y][x] = map[y][x];
			}

			if (map[y][x] == 6) visited[y][x] = 6;
		}
	}

	if (v1.size() == 0) {
		int ct = 0;
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				if (map[y][x] == 0)ct++;
			}
		}
		cout << ct;
	}
	else {
		dfs(0);
		cout << best;
	}
	return 0;
}