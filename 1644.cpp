#include <iostream>
#include <vector>
using namespace std;
int N;
int eratos[4000001];
int s, e;
void era() {
	for (int x = 2; x <= N; x++) {
		eratos[x] = x;
	}
	for (int x = 2; x <= N; x++) {
		if (eratos[x] == 0) continue;

		for (int y = 2 * x; y <= N; y += x) {
			eratos[y] = 0;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	era();
	vector<int> v1;
	for (int x = 2; x <= N; x++) {
		if (eratos[x] != 0) v1.push_back(x);
	}
	int sum = 0;
	int result = 0;
	int len = v1.size();
	while (1) {
		if (sum >= N) sum -= v1[s++];
		else if (e == len) break;
		else sum += v1[e++];
		if (sum == N) result++;
	}
	cout << result;
	return 0;
}