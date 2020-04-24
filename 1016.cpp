#include <iostream>
#include <cmath>
using namespace std;
long long N, M;

bool era[1000001];
long long eratos[1000001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;

	long long sq_max = (long long)sqrt(M);
	long long sq_cnt = 0;
	for (long long x = 2; x <= sq_max; x++) {
		eratos[x] = x * x;
		sq_cnt++;
	}
	int ans = 0;
	for (int x = 2; x < sq_cnt + 2; x++) {
		long long div_min = N;

		if (div_min % eratos[x] != 0) {
			div_min = (N / eratos[x] + 1) * eratos[x];
		}
		for (long long temp = div_min; temp <= M; temp += eratos[x]) {
			if (!era[temp - N]) {
				era[temp - N] = true;
				ans++;
			}
		}
	}
	cout << M - N - ans + 1;
	return 0;
}