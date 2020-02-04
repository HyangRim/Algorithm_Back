#include <iostream>
#include <queue>
using namespace std;


int N, K;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	

	cin >> N >> K;
	queue<int> qt;
	for (int x = 1; x <= N; x++) {
		qt.push(x);
	}
	int isK = 1;
	cout << "<";
	bool isOne = false;
	while (!qt.empty()) {
		if (isK == 1 && isOne) {
			cout << ", ";
		}
		else {
			isOne = true;
		}
		if (isK != K) {
			qt.push(qt.front());
			qt.pop();
			isK++;
		}
		else {
			cout << qt.front();
			qt.pop();
			isK = 1;
		}
	}
	cout << ">";
	return 0;
}