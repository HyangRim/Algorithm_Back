#include <iostream>
#include <queue>

using namespace std;

int arr[501][501];
int N, M, B;
int time_result = 987654321;
int block_height = 987654321;
int mina = 987654321;
int maxa = -987654321;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> B;
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < M; y++) {
			cin >> arr[x][y];
			if (mina > arr[x][y]) mina = arr[x][y];
			if (maxa < arr[x][y]) maxa = arr[x][y];
		}
	}
	for (int x = mina; x <= maxa; x++) {
		int time = 0;
		int block = B;
		for (int y = 0; y < M; y++) {
			for (int z = 0; z < M; z++) {
				int height = arr[y][z] - x;
				if (height > 0) {
					time = time + height * 2;
					block = block + height;
				}
				else if (height < 0) {
					time = time - height;
					block = block + height;
				}
			}
		}
		if (block >= 0) {
			if (time <= time_result) {
				time_result = time;
				block_height = x;
			}
		}
	}
	cout << time_result << " " << block_height;
}