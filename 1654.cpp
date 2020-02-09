#include <iostream>

using namespace std;


int K, N;
long long lan[10001];
long long maxa;
int main() {
	cin >> K >> N;
	for (int x = 0; x < K; x++) {
		cin >> lan[x];
	}
	long long left = 0;
	long long right = 9876543213;
	while (left <= right) {
		long long mid = (left + right) / 2;
		int result = 0;

		for (int x = 0; x < K; x++) {
			result += lan[x] / mid;
		}
		if (result >= N) {
			left = mid + 1;
			if (mid > maxa)
				maxa = mid;
			//cout << maxa << "\n";
		}
		else {
			right = mid - 1;
		}
	}
	cout << maxa;


	return 0;
}