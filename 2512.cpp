#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, M;
int low, high, mid;
int v1[10001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	int sum = 0;
	for (int x = 0; x < N; x++) {
		cin >> v1[x];
		sum += v1[x];
	}
	cin >> M;
	sort(v1, v1 + N);
	if (sum <= M) {
		cout << v1[N - 1];
		return 0;
	}
	else {
		low = 0, high = M;
		while (low + 1 < high) {
			mid = (low + high) / 2;
			sum = 0;
			for (int x = 0; x < N; x++) {
				if (v1[x] < mid)
					sum += v1[x];
				else
					sum += mid;
			}
			if (sum <= M)
				low = mid;
			else
				high = mid;
		}
	}
	cout << low;
	return 0;
}