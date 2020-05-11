#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	vector<int> v1(N+2);
	for (int x = 0; x < N; x++) {
		cin >> v1[x];
	}
	int result = 0;
	for (int x = N; x > 1; x--) {
		int y;
		for (y = 1; y <= N; y++) {
			if (v1[y] == x) break;
		}
		
		result += v1[y] - max(v1[y - 1], v1[y + 1]);

		for (; y <= N; y++) {
			v1[y] = v1[y + 1];
		}
	}
	cout << result;
	return 0;
}