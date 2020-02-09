#include <iostream>

using namespace std;

int N, gap = 987654321;
int arr[21][21];
bool visited[21];

void DFS(int A, int pos) {
	if (A == N / 2) {
		int start = 0, link = 0;
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < N; y++) {
				if (visited[x] && visited[y]) start += arr[x][y];
				if (!visited[x] && !visited[y]) link += arr[x][y];
			}
		}
		int tmp = abs(start - link);
		if (gap > tmp) gap = tmp;
	}
	for (int x = pos; x < N; x++) {
		visited[x] = true;
		DFS(A + 1, x + 1);
		visited[x] = false;
	}
}
int main() {
	cin >> N;
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			cin >> arr[x][y];
		}
	}
	DFS(0, 0);
	cout << gap;
	return 0;
}