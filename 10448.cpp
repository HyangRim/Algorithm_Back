#include <iostream>
#include <vector>
using namespace std;
vector<int> v1;

bool solve(int a) {
	int len = v1.size();
	for (int x = 0; x < len; x++) {
		for (int y = 0; y < len; y++) {
			for (int z = 0; z < len; z++) {
				if (v1[x] + v1[y] + v1[z] == a) return true;
			}
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, tmp;

	int a = 1;
	while ((a)*(a + 1) / 2 < 1000) {
		v1.push_back(a*(a + 1) / 2);
		a++;
	}

	cin >> N;
	for (int x = 0; x < N; x++) {
		cin >> tmp;
		cout << solve(tmp) << "\n";
	}

	return 0;
}