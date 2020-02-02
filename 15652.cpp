#include <iostream>


using namespace std;

int N, M;
int arr[9];
bool visited[9];
void BFS(int cnt) {

	if (cnt == M) {
		for (int x = 0; x < M; x++) {
			cout << arr[x] << " ";
		}
		cout << "\n";
		return;
	}
	for (int x = (cnt == 0) ? 1 : arr[cnt - 1]; x <= N; x++) {
		//if (!visited[x]) {
			//visited[x] = true;
		arr[cnt] = x;
		BFS(cnt + 1);
		//visited[x] = false;
	//}
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;

	BFS(0);
}

