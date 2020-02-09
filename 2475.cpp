#include <iostream>

using namespace std;


long long temp;
long long Num;
int main() {
	for (int x = 0; x < 5; x++) {
		cin >> temp;
		Num += temp * temp;
	}
	cout<<Num%10;
	

	return 0;
}