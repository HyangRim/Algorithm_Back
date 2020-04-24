#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	vector<int> v1(N);
	vector<int> idx(N);
	for (int x = 0; x < N; x++) {
		cin >> v1[x];
		idx[x] = v1[x];
	}
	sort(idx.begin(), idx.end());

	idx.erase(unique(idx.begin(), idx.end()), idx.end());

	for (auto& i : v1) {
		auto pos = lower_bound(idx.begin(), idx.end(), i) - idx.begin();
		cout << pos << " ";
	}
	return 0;
}