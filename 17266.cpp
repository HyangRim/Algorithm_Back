#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int N, M;
int arr[100001] = { 0, };

bool Check(vector<int>& v1, int height) {
	int len = v1.size();
	int ds = 0;
	for (int x = 0; x < len; x++) {//가로등 위치 하나하나 보면서
		if (v1[x] - height <= ds) {//첫 가로등은 어두운 부분의 시작이 0. v1[x]-height는 0은 되야지 충분히 밝혀지는 것. 
			ds = v1[x] + height;//다음 어둠 시작점.
		}
		else {
			break;//어두운 부분 있으면 break.
		}
	}
	return N - ds <= 0;//해서 마지막까지 true, false
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	int tmp;
	vector<int> v1(M);
	for (int x = 0; x < M; x++) {
		cin >> v1[x];//위치 받기.
	}

	int left = 1, right = N;
	int mid, ans = 0;

	while (left <= right) {
		mid = (left + right) / 2;//1 ~ N까지 탐색
		if (Check(v1, mid)) {//만약 되면...
			ans = mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	cout << ans << "\n";
	return 0;
}