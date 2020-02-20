#include <iostream>
#include <algorithm>

using namespace std;
struct mtrm {
	int start, end;
};
mtrm arr[100001];
int N;
bool cmp(mtrm a, mtrm b) {
	if (a.end == b.end)
		return a.start < b.start;
	return a.end < b.end;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int x = 0; x < N; x++) {
		cin >> arr[x].start >> arr[x].end;
	}
	sort(arr, arr + N, cmp);
	int endtime = 0;
	int ans = 0;
	for (int x = 0; x < N; x++) {
		if (endtime <= arr[x].start) {
			endtime = arr[x].end;
			ans++;
		}
	}
	cout << ans;
	return 0;
}