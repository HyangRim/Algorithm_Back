#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;
int N;
int s, e;
int D, S, L, R;

bool visited[10000];

struct node {
	int se;
	string reg;
};

void bfs() {
	queue<node> que;
	que.push({s, ""});
	visited[s] = true;

	while (!que.empty()) {
		int ss = que.front().se;
		string st = que.front().reg;

		//cout << ss << "\n";

		que.pop();

		if (ss == e) {
			cout << st << "\n";
			return;
		}

		// D
		D = ss * 2 % 10000;
		S = ss - 1 < 0 ? 9999 : ss - 1;
		L = (ss % 1000) * 10 + (ss / 1000);
		R = ss / 10 + (ss % 10) * 1000;

		if (!visited[D]) {
			visited[D] = true;
			que.push({ D, st + "D" });
		}
		// S
		if (!visited[S]) {
			visited[s] = true;
			que.push({ S, st + "S" });
		}

		//L
		if (!visited[L]) {
			visited[L] = true;
			que.push({ L, st + "L" });
		}

		//R
		if (!visited[R]) {
			visited[R] = true;
			que.push({ R, st + "R" });
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	while (N--) {
		cin >> s >> e;
		memset(visited, false, sizeof(visited));
		bfs();
	}
	return 0;
}