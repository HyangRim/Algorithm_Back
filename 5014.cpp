#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int F, S, G, U, D;
bool visited[1000001];
//F는 전체 층 수
//S는 현재 있는 층
//G는 목표층
//U는 위로 한 번에 가는 수
//D는 아래로 한 번에 가는 수
int bfs() {
	queue<pair<int, int>> que;
	que.push({ S,0 });
	visited[S] = true;
	while (!que.empty()) {
		int Cur = que.front().first;
		int Bt = que.front().second;
		
		que.pop();
		if (Cur == G) {
			return Bt;
		}
		//if (Bt > 1000000) return -1;

		if (Cur + U >= 1 && Cur + U <= F && !visited[Cur+U]) {
			visited[Cur + U] = true;
			que.push({Cur+U,Bt+1});
		}
		if (Cur - D >= 1 && Cur - D <= F && !visited[Cur-D]) {
			visited[Cur - D] = true;
			que.push({Cur-D,Bt+1});
		}
	}
	return -1;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> F >> S >> G >> U >> D;

	int ans = bfs();
	if (ans == -1) cout << "use the stairs";
	else {
		cout << ans;
	}
	return 0;
}