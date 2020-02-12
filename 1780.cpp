#include <iostream>
#include <vector>

using namespace std;

int N;
int arr[2790][2790];
int Ans[3];
bool All_Same(const int x, const int y, const int size) {
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (arr[i][j] != arr[x][y]) return false;
		}
	}
	return true;
}
void Solve(int x, int y, int size) {
	if (All_Same(x, y, size)) {
		Ans[arr[x][y] + 1]++;
	}
	else {
		int SmallSize = size / 3;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				Solve(x + i * SmallSize, y + j * SmallSize, SmallSize);
			}
		}
	}
}
int main() {

	cin >> N;
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			cin >> arr[x][y];
		}
	}
	Solve(0, 0, N);
	for (int x = 0; x < 3; x++) {
		cout << Ans[x] << "\n";
	}
	return 0;
}