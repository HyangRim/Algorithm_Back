#include <iostream>
#include <string>
#include <cmath>

using namespace std;



string str;
int N;
unsigned long long HashNum;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	cin >> str;
	for (int x = 0; x < N; x++) {
		int Num = str[x] - 'a' + 1;
		HashNum += (unsigned long long)(Num * pow(31, x)) % 1234567891;
	}
	cout << HashNum;
}