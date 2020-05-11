#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;

	cin >> N;
	int ans;
	for (int x = 0; x < N; x++) {
		cin >> ans;
		if ((ans&(-ans)) == ans) cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}