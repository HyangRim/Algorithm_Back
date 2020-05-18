#include <cstdio>
#include <algorithm>
using namespace std;
int N, M;
int s, e;
int ans = 2e9;
int arr[100001];
int main() {
	scanf("%d %d", &N, &M);
	for (int x = 0; x < N; x++) {
		scanf("%d", &arr[x]);
	} 
	sort(arr,arr+N);
	while (e < N) {
		if (arr[e] - arr[s] < M) e++;
		else ans = min(ans, arr[e] - arr[s++]);
	}
	printf("%d", ans);
	return 0;
}