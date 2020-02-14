#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int map[1011][1011];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, W;
	int x, y;
	cin >> N >> W;

	pair<int, int> policecar[2];
	policecar[0].first = 1;
	policecar[0].second = 1;

	policecar[1].second = N;
	policecar[1].first = N;
	long long result = 0;
	vector<int> v1(W);
	for (int i = 0; i < W; i++) {
		cin >> x >> y;
		if (abs(policecar[0].first - x) + abs(policecar[0].second - y) < abs(policecar[1].first - x) + abs(policecar[1].second - y)) {
			result += abs(policecar[0].first - x) + abs(policecar[0].second - y);
			policecar[0].first = x;
			policecar[0].second = y;
			v1[i] = 1;
		}
		else {
			result += abs(policecar[1].first - x) + abs(policecar[1].second - y);
			policecar[1].first = x;
			policecar[1].second = y;
			v1[i] = 2;
		}
	}
	cout << result << "\n";
	for (int x = 0; x < W; x++) {
		cout << v1[x] << "\n";
	}
	return 0;
}