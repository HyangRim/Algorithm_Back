#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000001];
int ans;
int main() {

	int C;
	cin >> C;
	arr[1] = 0;
	for (int x = 2; x <= C; x++) {
		arr[x] = arr[x - 1] + 1;
		if (x % 2 == 0)
			arr[x] = min(arr[x], arr[x / 2] + 1);
		if (x % 3 == 0)
			arr[x] = min(arr[x], arr[x / 3] + 1);
	}
	cout << arr[C];
	return 0;
}