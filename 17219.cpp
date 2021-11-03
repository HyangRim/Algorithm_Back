#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <map>

using namespace std;
int N, M;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s1, s2;
	unordered_map<string, string> password;
	cin >> N >> M;
	for (int x = 0; x < N; x++) {
		cin >> s1 >> s2;
		password.insert({s1,s2});
	}
	for (int x = 0; x < M; x++) {
		cin >> s2;
		cout << password[s2] << "\n";
	}
	return 0;
}