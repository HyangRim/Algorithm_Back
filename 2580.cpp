#include <iostream>
#include <string>


using namespace std;
int map[9][9];
bool isclear = false;

bool isRight(int x, int y, int z) {
	bool isEmpty = true;
	for (int i = 0; i < 9; i++) {
		if (map[i][y] == z) return false;
		if (map[x][i] == z) return false;
	}
	int nx = x / 3;
	int ny = y / 3;

	for (int i = 0; i < 3; i++) {
		if (map[i + (nx * 3)][ny * 3] == z) return false;
		if (map[i + (nx * 3)][(ny * 3) + 1] == z) return false;
		if (map[i + (nx * 3)][(ny * 3) + 2] == z) return false;
	}
	return true;
}
void dfs() {
	for (int x = 0; x < 9; x++) {
		for (int y = 0; y < 9; y++) {
			if (map[x][y] == 0) {
				for (int z = 1; z <= 9; z++) {
					if (isRight(x, y, z)) {
						map[x][y] = z;
						dfs();
						if (isclear) return;
						map[x][y] = 0;
					}
				}
				return;
			}
		}
	}
	isclear = true;
	return;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for (int x = 0; x < 9; x++) {
		for (int y = 0; y < 9; y++) {
			cin >> map[x][y];
		}
	}
	dfs();
	for (int x = 0; x < 9; x++) {
		for (int y = 0; y < 9; y++) {
			cout << map[x][y] << " ";
		}
		cout << "\n";
	}
	return 0;
}