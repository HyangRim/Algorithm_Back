#include <iostream>
#include <vector>
#include <string>
using namespace std;
int M, N;
char str[11];
int main() {
	cin >> M;
	int num;
	for(int x = 0; x < M; x++) {
		scanf(" %s", &str);
		scanf(" %d", &num);
		if (str[0] == 'a'&& str[1] == 'd') N |= (1 << num);
		else if (str[0] == 'r')	N &= ~(1 << num);
		else if (str[0] == 'c') printf("%d\n", (N&(1 << num)) == 0 ? 0 : 1);
		else if (str[0] == 't') N ^= (1 << num);
		else if (str[0] == 'a' && str[1] == 'l') N = (1 << 21) - 1;
		else N = 0;
	}
	return 0;
}