#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;


int N, M;
vector<int> v1;
int binar(int target) {
	int left = 0, right = N;
	int cnt = 0, mid;

	while (left < right) {
		mid = (left + right) / 2;
		if (v1[mid] < target) {
			left = mid + 1;
		}
		else {
			right = mid;
		}

		if (v1[mid] == target) cnt++;
	}

	if (cnt != 0) return right;
	else return -1;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	int tmp;
	for (int x = 0; x < N; x++) {
		cin >> tmp;
		v1.push_back(tmp);
	}
	sort(v1.begin(), v1.end());

	for (int x = 0; x < M; x++) {
		cin >> tmp;
		cout << binar(tmp) << "\n";
	}
	return 0;
}