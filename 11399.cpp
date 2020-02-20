#include <iostream>
#include <algorithm>
using namespace std;

pair<int,int> arr[1001];
int N;
bool tmp(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	int temp;
	for (int x = 0; x < N; x++) {
		cin >> temp;
		arr[x].first = x;
		arr[x].second = temp;
	}
	sort(arr, arr + N, tmp);
	int sum = 0;
	int ans = 0;
	for (int x = 0; x < N; x++) {
		sum = sum + arr[x].second;
		ans += sum;
	}
	cout << ans;
	return 0;
}