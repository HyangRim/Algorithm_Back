#include <iostream>
#include <queue>
using namespace std;

bool isvisited[100001];
int N, K;

int bfs(int N,int K) {
	queue<pair<int, int>> q;
	
	q.push(make_pair(N, 0));
	isvisited[N] = true;
	while (!q.empty()) {
		int curloc = q.front().first;
		int cursec = q.front().second;
		q.pop();

		if (curloc == K) return cursec;

		if (curloc + 1 < 100001 && !isvisited[curloc + 1]) {
			q.push(make_pair(curloc + 1, cursec + 1));
			isvisited[curloc + 1] = true;
		}
		if (curloc - 1 >= 0 && !isvisited[curloc - 1]) {
			q.push(make_pair(curloc - 1, cursec + 1));
			isvisited[curloc - 1] = true;
		}
		if (curloc * 2 < 100001 && !isvisited[curloc *2]) {
			q.push(make_pair(curloc * 2, cursec + 1));
			isvisited[curloc * 1] = true;
		}
	}
}
int main() {
	cin >> N >> K;
	cout << bfs(N, K);
	return 0;
}