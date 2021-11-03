#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
struct node {
	int a, b, c;
};
vector<node> ans;

int INF = 987654321;
int arr[101][101];
int N, M;
int a, b;


bool chk(node a, node b) {
	if (a.c == b.c) {
		if (a.a == b.a) return a.b < b.b;
		return a.a < b.a;
	}
	return a.c < b.c;
}
int chicken(int a, int b) {
	int tmp = 0;
	for (int x = 1; x <= N; x++) {
		if (!(a == x || b == x)) {
			tmp += (min(arr[a][x], arr[b][x])) * 2;
		}
	}
	return tmp;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int x = 0; x <= N; x++) {
		for (int y = 0; y <= N; y++) {
			arr[x][y] = INF;
		}
	}
	for (int x = 0; x < M; x++) {
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}
	for (int x = 0; x <= N; x++) {
		for (int y = 0; y <= N; y++) {
			for (int z = 0; z <= N; z++) {
				if (arr[y][x] + arr[x][z] < arr[y][z]) {
					arr[y][z] = arr[y][x] + arr[x][z];
				}
			}
		}
	}
	int tmp = 0;
	while (tmp++) {
		if (tmp > N) break;
		arr[tmp][tmp] = 0;
	}

	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= N; y++) {
			if (x == y) continue;
			int len = chicken(x, y);
			ans.push_back({ x,y,len });
			//cout << len << "\n";
		}
	}
	sort(ans.begin(), ans.end(), chk);
	cout << ans[0].a << " " << ans[0].b << " " << ans[0].c;
	/*for (int x = 0; x < ans.size(); x++) {
		cout << ans[x].a << " " << ans[x].b << " " << ans[x].c << "\n";
	}*/
	return 0;
}