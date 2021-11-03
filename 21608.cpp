#include <iostream>
#include <string>

int N;

using namespace std;


struct info {
	int x, y, blankcnt = 0, friendcnt = 0;
};
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

int map[21][21];
int like_person[21][4];
int check_empty(int y,int x) {
	int empty_place = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (map[nx][ny] == 0)empty_place++;
	}
	
	return empty_place;
}

int like_place(int cnt, int y, int x) {
	int many_like = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		for (int j = 0; j < 4; j++) {
			if (map[ny][nx] == like_person[cnt][j]) {
				many_like++;
				break;
			}
		}
	}
	return many_like;
}

void batch(int cnt) {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {

		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int x = 0; x < N * N; x++) {
		int a, b, c, d, e;
		cin >> a;
		for (int y = 0; y < 4; y++) {
			int tmp;
			cin >> tmp;
			like_person[a][y] = tmp;
		}
		batch(a);
	}
	return 0;
}