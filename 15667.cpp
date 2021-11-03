#include <iostream>

using namespace std;

int main() {
	int N;

	cin >> N;

	for (int K = 1; K <= 10101; K++) {
		if ((1 + K + (K * K)) == N) {
			cout << K;
			return 0;
		}
	}
	return 0;
}