#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;


int N, M;

vector<string> v1;
vector<int> v2;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	string ntmp;
	int ptmp;

	cin >> N >> M;


	for (int x = 0; x < N; x++) {
		cin >> ntmp >> ptmp;
		v1.push_back(ntmp);
		v2.push_back(ptmp);
	}

	for (int y = 0; y < M; y++) {
		cin >> ptmp;
		int ans = upper_bound(v2.begin(), v2.end(), ptmp-1) - v2.begin();
		cout << v1[ans] << "\n";
	}
	return 0;
}