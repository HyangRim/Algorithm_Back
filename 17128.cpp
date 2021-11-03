#include <iostream>


using namespace std;
int N, Q;

int cow[200001];
int cowking[200001];
long long sum = 0;

void Trick(int q) {
	int index = q;
	for (int x = 0; x < 4; x++) {
		sum -= cowking[index];
		cowking[index] *= -1;
		sum += cowking[index];
		index--;
		if (index == 0) index = N;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> Q;
	for (int x = 1; x <= N; x++) {
		cin >> cow[x];
	}
	for (int x = 1; x <= N; x++) {
		int index = x;
		int tmp = 1;
		for (int y = 0; y < 4; y++) {
			tmp *= cow[index];
			index++;
			if (index > N) index = 1;
		}
		cowking[x] = tmp;
		sum += cowking[x];
	}

	for (int x = 0; x < Q; x++) {
		int tmp;
		cin >> tmp;
		Trick(tmp);
		cout << sum << "\n";
	}
	return 0;
}