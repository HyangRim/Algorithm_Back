#include <iostream>

using namespace std;
int arr[14];
bool visited[14];
int N;

void DFS(int Idx, int Cnt) {
	if (Cnt == 6) {
		for (int i = 0; i < N; i++) {
			if (visited[i])
				cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int x = Idx; x < N; x++) {
		if (visited[x]) continue;
		visited[x] = true;

		DFS(x, Cnt + 1);
		visited[x] = false;
	}

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while (1) {
		cin >> N;
		if (N == 0) break;
		for (int x = 0; x < N; x++) {
			cin >> arr[x];
		}
		DFS(0, 0);
		cout << "\n";
	}
	return 0;
}