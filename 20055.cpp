#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int N, K;

deque<int> Dura;
deque<bool> belt;


void rotate() {
	belt.push_front(belt.back());
	belt.pop_back();

	Dura.push_front(Dura.back());
	Dura.pop_back();
	belt[N - 1] = false;
}

void move()
{
	for (int x = N - 2; x >= 0; x--) {
		if (((!belt[x + 1]) && (Dura[x + 1] > 0) && (belt[x]))) {
			belt[x] = false;
			belt[x + 1] = true;
			Dura[x + 1]--;
		}
	}
	belt[N - 1] = false;
}

void robot() {
	if (!belt[0] && Dura[0] > 0) {
		belt[0] = true;
		Dura[0]--;
	}
}

int check()
{
	int ct = 0;
	for (int x = 0; x < N * 2; x++) {
		if (!Dura[x]) ct++;
	}
	return ct;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	int ans = 1;
	for (int x = 0; x < N * 2; x++) {
		int tmp;
		cin >> tmp;
		Dura.push_back(tmp);
		belt.push_back(false);
	}

	while (true) {
		rotate();
		move();
		robot();

		int chk = check();
		if (chk >= K) {
			cout << ans;
			break;
		}
		ans++;
	}
	return 0;
}