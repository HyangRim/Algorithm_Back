#include <iostream>

using namespace std;



int map[19][19];

int mx[4] = {1,1,1,0};
int my[4] = {1,0,-1,-1};

bool is_in_range(int x, int y) {
	return (x >= 0 && y >= 0 && x < 19 && y < 19);
}

int getMap(int x, int y) {
	if (0 <= x && 0 <= y && x < 19 && y < 19)
		return map[x][y];
	else
		return 0;
}
int main() {
	for (int x = 0; x < 19; x++) {
		for (int y = 0; y < 19; y++) {
			cin >> map[x][y];
		}
	}

	int ans_x, ans_y, ans_c = -1;

	for (int i = 0; i < 4; i++) {
		for (int x = 0; x < 19; x++) {
			for (int y = 0; y < 19; y++) {
				if (map[x][y] == 0) continue;
				
				if (getMap(x + mx[i], y + my[i]) == map[x][y]) continue;

				int yy = y;
				int xx = x;
				int cnt = 0;
				while (1) {
					yy += my[i];
					xx += mx[i];
					if (!is_in_range(xx, yy)) break;

					if (map[xx][yy] != map[x][y]) break;

					cnt++;
				}
				if (cnt == 4) {
					ans_x = x;
					ans_y = y;
					ans_c = map[x][y];
				}
			}
		}
	}
	if (ans_c == -1) {
		cout << "0";
		return 0;
	}
	cout << ans_c << "\n" << ans_x + 1 << ans_y + 1;
	return 0;
}