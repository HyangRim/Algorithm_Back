#include <iostream>
#include <string>

using namespace std;

int K;
bool visited[10];
char buho[10];
int ans[10];

long long max_ans;
long long min_ans;
long long mkn() {

	long long num = 0;
	for (int x = 0; x <= K; x++) {
		num = (num * 10) + ans[x];
	}
	return num;
}
void bck(int n, int idx) {
	ans[idx] = n;
	visited[n] = true;

	if (idx == K) {
		long long num_ans = mkn();

		if (min_ans == 0) min_ans = num_ans;
		if (max_ans == 0 || max_ans < num_ans) max_ans = num_ans;
		
		return;
	}

	for (int x = 0; x <= 9; x++) {
		if (!visited[x]) {
			if (((buho[idx] == '>') && ans[idx] > x) || ((buho[idx] == '<') && ans[idx] < x)) {
				bck(x, idx + 1);
				ans[idx + 1] = 0;
				visited[x] = false;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> K;
	for (int x = 0; x < K; x++) {
		cin >> buho[x];
	}
	for (int x = 0; x <= 9; x++) {
		bck(x, 0);
		visited[x] = false;
	}

	string max_val = to_string(max_ans);
	string min_val = to_string(min_ans);

	if (max_val.length() != K + 1)cout << "0" + max_val << "\n";
	else cout << max_val << "\n";
	if (min_val.length() != K + 1)cout << "0" + min_val << "\n";
	else cout << min_val << "\n";

	return 0;
}
