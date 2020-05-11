#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
int R, C;
using namespace std;

char map[51][51];
char nmap[51][51];
bool visited[51][51];

int mx[4] = {0,1,0,-1};
int my[4] = {1,0,-1,0};

queue<pair<int, int>> wq;

void water() {
	for (int x = 0; x < R; x++) {
		for (int y = 0; y < C; y++) {
			nmap[x][y] = map[x][y];
		}
	}

	while (!wq.empty()) {
		int x = wq.front().first;
		int y = wq.front().second;

		wq.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + mx[i];
			int ny = y + my[i];

			if (0 <= nx && 0 <= ny && nx < R && ny < C) {
				if (map[nx][ny] == '.') {
					nmap[nx][ny] = '*';
				}
			}
		}
	}
}

int bfs(int a, int b) {
	visited[a][b] = true;

	queue<pair<pair<int, int>, int>> que;
	int tmp = -1;
	que.push({ {a,b}, 0 });
	while (!que.empty()) {
		int x = que.front().first.first;
		int y = que.front().first.second;
		int step = que.front().second;

		que.pop();

		if (map[x][y] == 'D') {
			//cout << 1231231 << "\n";
			return step;
		}
		//다음 지도 예상. 
		if (step == tmp + 1) {
			tmp++;
			water();
		}

		//
		for (int i = 0; i < 4; i++) {
			int nx = x + mx[i];
			int ny = y + my[i];
			
			if (nx >= 0 && ny >= 0 && nx < R && ny < C) {
				if (!visited[nx][ny] && (nmap[nx][ny] == '.' || nmap[nx][ny] == 'D')) {
					visited[nx][ny] = true;
					que.push({ {nx,ny},step + 1 });
					//cout << nx << " " << ny << "\n\n";
				}
			}
		}

		//

		for (int a = 0; a < R; a++) {
			for (int b = 0; b < C; b++) {
				map[a][b] = nmap[a][b];
				if (map[a][b] == '*')
					wq.push({ a,b });
			}
		}
		//맵 옮기기.

		/*for (int a = 0; a < R; a++) {
			for (int b = 0; b < C; b++) {
				cout << map[a][b] << " ";
			}
			cout << "\n";
		}
		cout << "\n\n";*/
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> R >> C;
	int startx, starty;
	for (int x = 0; x < R; x++) {
		for (int y = 0; y < C; y++) {
			cin >> map[x][y];
			if (map[x][y] == 'S') {
				startx = x;
				starty = y;
			}
			else if (map[x][y] == '*') {
				wq.push({ x,y });
			}
		}
	}
	int ans = bfs(startx, starty);
	if (ans == -1) {
		cout << "KAKTUS";
	}
	else {
		cout << ans;
	}
	return 0;
}