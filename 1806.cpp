#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, S;
int s, e;
vector<int> len;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> S;
	vector<int> v1(N);
	for (int x = 0; x < N; x++) {
		cin >> v1[x];
	}
	int sum = 0;
	int result = 0;
	int leng = v1.size();
	while (1) {
		if (sum >= S) sum -= v1[s++];
		else if (e == leng) break;
		else sum += v1[e++];
		if (sum >= S) len.push_back(e - s);
	}

	if (!len.empty()) {
		sort(len.begin(), len.end());
		cout << len[0];
	}
	else {
		cout << 0;
	}

	return 0;
}