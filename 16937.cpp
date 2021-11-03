#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;
int H, W, N, ans = 0;
int map[101][101];
int R[101], C[101];
vector<pair<int, int>> v1;
bool roll(int r1, int r2, int c1, int c2) {
	if (r1 + r2 <= H && max(c1, c2) <= W) return true;
	if (max(r1, r2) <= H && c1 + c2 <= W) return true;
	return false;
}

bool possible(int r1, int r2, int c1, int c2) {
	if (roll(r1,r2,c1,c2)) return true;
	if (roll(c1,r2,r1,c2)) return true;
	if (roll(r1,c2,c1,r2)) return true;
	if (roll(c1,c2,r1,r2)) return true;
	return false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> H >> W >> N;
	for (int x = 0; x < N; x++) {
		cin >> R[x] >> C[x];
	}

	for (int x = 0; x < N; x++) {
		for (int y = x + 1; y < N; y++) {
			int r1 = R[x], c1 = C[x];
			int r2 = R[y], c2 = C[y];

			if (possible(r1, r2, c1, c2)) {
				ans = max(ans, r1*c1 + r2*c2);
			}
		}
	}
	cout<<ans;
	return 0;
}