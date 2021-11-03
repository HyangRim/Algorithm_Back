#include <iostream>
#include <vector>


int T;
char map[3][3];
using namespace std;

bool chk() {
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			if (map[y][x] != map[0][0]) return false;
		}
	}
	return true;
}

void Nega(int y, int x, int i) {
	if (i == 0) {//가로
		for (int z = 0; z < 3; z++) {
			if (map[y][z] == 'H') map[y][z] = 'T';
			else map[y][z] = 'H';
		}
	}
	else if (i == 1) {//세로
		for (int z = 0; z < 3; z++) {
			if (map[z][x] == 'H') map[z][x] = 'T';
			else map[z][x] = 'H';
		}
	}
	else if (i == 2) {//대각선
		int ny = y, nx = x;
		while (1) {
			if (ny >= 3 || nx >= 3) break;
			if (map[ny][nx] == 'H')map[ny][nx] = 'T';
			else map[ny][nx] = 'H';
			ny++;
			nx++;
		}
		ny = y, nx = x;

		while (1) {
			if (ny < 0 || nx < 0) break;
			if (map[ny][nx] == 'H')map[ny][nx] = 'T';
			else map[ny][nx] = 'H';
			ny--;
			nx--;
		}
	}
	return;
}
void dfs(int y, int x, int N) {

	bool check = chk();
	if (check) {
		cout << N << "\n";
		return;
	}

	if (N > 1) {
		cout << -1;
		return;
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				Nega(i, j, k);
				dfs(i, j, N + 1);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		for (int y = 0; y < 3; y++) {
			for (int x = 0; x < 3; x++) {
				cin >> map[y][x];
			}
		}
		dfs(0, 0, 0);
	}
	return 0;
}