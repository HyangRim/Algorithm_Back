#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

int N;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	queue<int> qt;
	for (int x = 1; x <= N; x++) {
		qt.push(x);
	}
	bool isOne = true;
	while (qt.size() != 1) {
		if (isOne) {
			qt.pop();
			isOne = false;
		}
		else {
			qt.push(qt.front());
			qt.pop();
			isOne = true;
		}
	}
	cout << qt.front();
	return 0;
}