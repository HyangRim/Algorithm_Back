#include <iostream>
#include <string>
using namespace std;

int R, C;
string str[11];
char map[11][11];
int nx[4] = {1,0,-1,0};
int ny[4] = {0,-1,0,1};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> R >> C;
	for (int x = 0; x < R; x++) {
		cin >> str[x];
	}


	for (int x = 0; x < R; x++) {
		for (int y = 0; y < C; y++) {
			int Count = 0;
			if (str[x][y] == 'X') {
				for (int i = 0; i < 4; i++) {
					int qx = x + nx[i];
					int qy = y + ny[i];
					if (qx >= 0 && qy >= 0 && qx < R && qy < C) {
						if (str[qx][qy] == '.') Count++;
					}
					else {
						Count++;
					}
				}
				if (Count >= 3) map[x][y] = '.';
				else map[x][y] = 'X';
			}
			else if (str[x][y] == '.')
				map[x][y] = '.';
		}
	}
	int low_x = -1;
	int high_x = 987654321;
	int left_y = -1;
	int right_y = 987654321;
	for (int x = 0; x < R; x++) {
		for (int y = 0; y < C; y++) {
			if (map[x][y] == 'X') {
				if (low_x < x) low_x = x;
				if (high_x > x) high_x = x;
				if (left_y < y) left_y = y;
				if (right_y > y) right_y = y;
			}
		}
	}
	for (int x = high_x; x <= low_x; x++) {
		for (int y = right_y; y <= left_y; y++) {
			cout << map[x][y];
		}
		cout << "\n";
	}
	return 0;
}