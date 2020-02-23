#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<string> inputStr;
char str[21];

bool isVowel(char ch)
{
	if ((ch == 'a') || (ch == 'e') || (ch == 'i') || (ch == 'o') || (ch == 'u'))
		return true;
	else
		return false;
}

bool isCorrect1(string str)
{
	for (int i = 0; i < str.size(); i++)
	{
		if (isVowel(str[i]))
			return true;
	}
	return false;
}

bool isCorrect2(string arr)
{
	if ((arr.size() == 1) || (arr.size() == 2))
		return true;

	for (int i = 0; (i + 2) < arr.size(); i++)
	{
		if ((isVowel(arr[i])) && (isVowel(arr[i + 1])) && (isVowel(arr[i + 2])))
			return false;
		if ((!isVowel(arr[i])) && (!isVowel(arr[i + 1])) && (!isVowel(arr[i + 2])))
			return false;
	}
	return true;
}


bool isCorrect3(string arr)
{
	if (arr.size() == 1)
		return true;

	for (int i = 0; (i + 1) < arr.size(); i++)
	{
		if ((arr[i] == arr[i + 1]) && (!((arr[i] == 'e') && (arr[i + 1] == 'e'))) && (!((arr[i] == 'o') && (arr[i + 1] == 'o'))))
			return false;
	}
	return true;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while (true)
	{
		cin >> str;
		if (strcmp(str, "end") == 0)
			break;

		inputStr.push_back(str);
	}

	for (int i = 0; i < inputStr.size(); i++)
	{
		if ((isCorrect1(inputStr[i])) && (isCorrect2(inputStr[i])) && (isCorrect3(inputStr[i])))
			cout << "<" << inputStr[i] << "> " << "is acceptable." << endl;
		else
			cout << "<" << inputStr[i] << "> " << "is not acceptable." << endl;
	}

	return 0;
}