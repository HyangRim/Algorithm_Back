#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int House[200001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int max = 0;
	cin >> N >> M;
	for (int x = 0; x < N; x++) {
		cin >> House[x];
		max = max < House[x] ? House[x] : max;
	}
	sort(House, House + N);

	int start = 0, end = max;
	int max_len = 0;
	while (start <= end) {
		int mid = (start + end) / 2;
		int num = 1;
		int startNum = House[0];

		for (int x = 1; x < N; x++) {
			if (House[x] - startNum >= mid) {
				startNum = House[x];
				num++;
			}
		}
		if (num >= M) {
			max_len = mid;
			start = mid + 1;
		}
		else end = mid - 1;
	}
	cout << max_len;
	return 0;
}