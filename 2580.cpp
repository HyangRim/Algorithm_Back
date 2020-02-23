#include <iostream>
#include <algorithm>
#include <stack>



using namespace std;
int arr[9][9];


bool CheckRow(int y, int target) {
	for (int x = 0; x < 9; x++) {
		if (arr[x][y] == target)
			return false;
	}
	return true;
}

bool CheckCol(int x, int target) {
	for (int y = 0; y < 9; y++) {
		if (arr[x][y] == target)
			return false;
	}
	return true;
}
bool CheckBox(int x, int y, int target) {
	int a = x / 3;
	int b = y / 3;
	a *= 3;
	b *= 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (arr[a + i][b + j] == target)
				return false;
		}
	}
	return true;
}


bool isTrue(int x, int y, int target) {
	if (CheckRow(y, target) && CheckCol(x, target) && CheckBox(x, y, target))
		return true;
	return false;
}
bool sdoku() {
	int x, y;
	bool Check = true;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (arr[i][j] == 0) {
				Check = false;
				x = i;
				y = j;
				break;
			}
		}
		if (!Check) break;
	}
	if (Check) return true;
	for (int target = 1; target <= 9; target++) {
		if (isTrue(x, y, target)) {
			arr[x][y] = target;
			if (sdoku()) return true;
		}
		arr[x][y] = 0;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int x = 0; x < 9; x++) {
		for (int y = 0; y < 9; y++) {
			cin >> arr[x][y];
		}
	}
	sdoku();
	cout << "\n\n";
	for (int x = 0; x < 9; x++) {
		for (int y = 0; y < 9; y++) {
			cout << arr[x][y] << " ";
		}
		cout << "\n";
	}

	return 0;
}