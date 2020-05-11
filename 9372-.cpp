#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
int T;
int N, M;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	cin >> T;
	while (T--) {
		cin >> N >> M;
		int a, b;
		for (int x = 0; x < M; x++) {
			cin >> a >> b;
		}
		cout << N - 1 << "\n";
	}
	return 0;
}