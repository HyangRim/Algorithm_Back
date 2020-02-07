#include <iostream>

using namespace std;


int arr[3] = { -1, };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (1) {
		cin >> arr[0] >> arr[1] >> arr[2];
		if (!arr[0] && !arr[1] && !arr[2]) break;
		int maxNum = -987654321, idx;
		for (int x = 0; x < 3; x++) {
			if (arr[x] > maxNum) {
				idx = x;
				maxNum = arr[x];
			}
		}
		int Sum = 0;
		for (int x = 0; x < 3; x++) {
			if (idx == x) continue;
			Sum += arr[x] * arr[x];
		}
		if (maxNum*maxNum == Sum) {
			cout << "right\n";
		}
		else {
			cout << "wrong\n";
		}
	}
}