#include <iostream>
#include <deque>
#include <string>
using namespace std;

int T, N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while (T--)
	{
		string P;
		string Ipt;
		deque<int> dq;
		cin >> P >> N >> Ipt;
		int Iptlen = Ipt.size();
		string temp;
		for (int x = 0; x < Iptlen; x++) {
			//dq.push_back(int(Ipt[x]-48));
			if (Ipt[x] == '[')
				continue;
			else if ('0' <= Ipt[x] && Ipt[x] <= '9')
				temp += Ipt[x];
			else if (Ipt[x] == ',' || Ipt[x] == ']') {
				if (!temp.empty()) {
					dq.push_back(stoi(temp));
					temp.clear();
				}
			}
		}
		bool isCorrect = true;
		int Psize = P.size();

		int Dcount = 0;
		for (int x = 0; x < Psize; x++) {
			if (P[x] == 'D') Dcount++;
		}
		//cout << Dcount << "\n\n\n";
		if (Dcount > N) {
			cout << "error\n";
			continue;
		}
		for (int x = 0; x < Psize; x++) {
			if (P[x] == 'R') {
				if (isCorrect) isCorrect = false;
				else {
					isCorrect = true;
				}
			}
			else if (P[x] == 'D') {
				if (isCorrect) {
					dq.pop_front();
				}
				else {
					dq.pop_back();
				}
			}
		}
		int dqsize = dq.size();
		cout << "[";
		if (isCorrect) {
			for (int x = 0; x < dqsize; x++) {
				cout << dq[x];
				if (x != dqsize - 1) {
					cout << ",";
				}
			}
		}
		else {
			for (int x = dqsize-1; x > -1; x--) {
				cout << dq[x];
				if (x != 0) {
					cout << ",";
				}
			}
		}
		cout << "]\n";
	}
	return 0;
}