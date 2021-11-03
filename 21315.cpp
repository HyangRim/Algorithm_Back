#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

bool arr[51][51];
int N, M, K;
int lenx = -1;
int ans = 0;

int chk() {
	for (int y = 0; y < M; y++) {
		int len = 0;
		for (int x = 0; x < N; x++) {
			if (arr[x][y] == false)len++;
			else len = 0;
		}
		lenx = max(len, lenx);
	}
}

void nega(int y) {
	for (int x = 0; x < N; x++) {
		if (arr[x][y]) arr[x][y] = false;
		else arr[x][y] = true;
	}
}
void dfs(int x, int y, int cnt) {

	if (cnt == K) {
		ans = max(ans, chk());
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			nega(j);
			dfs(i, j, cnt+1);
			nega(j);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string str;
	cin >> N >> M;
	for (int x = 0; x < N; x++) {
		cin >> str;
		for (int y = 0; y < str.size(); y++) {
			if (str[y] == 1) arr[x][y] = true;
			else arr[x][y] = false;
		}
	}
	cin >> K;
	dfs(0, 0, 0);
	cout << ans;
	return 0;
}