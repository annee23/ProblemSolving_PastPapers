#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	int T;
	cin >> T;
	string big;
	string small;

	while (T--) {
		vector<int>a;
		vector<int>b;
		cin >> big >> small;

		for (int i = 0; i < big.size(); i++)
			a.push_back(big[i] - '0');
		for (int i = 0; i < small.size(); i++)
			b.push_back(small[i] - '0');

		int times = big.size() - small.size();
		int pointer = small.size();
		int left = 0;
		int A = 0, B = 0;

		for (int j = 0; j < small.size(); j++)
		{
			A += a[j] * pow(10, small.size() - j - 1);
			B += b[j] * pow(10, small.size() - j - 1);

		}
		while (A >= B)
			A = A - B;
		left = A;
		for (int i = 0; i < times; i++)
		{
			A = left * 10 + a[pointer];
			while (A >= B)
				A = A - B;
			left = A;
			pointer++;
		}
		if (left == 0)
			cout << "1\n";
		else
			cout << "0\n";
	}
	return 0;
}
