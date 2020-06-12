#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	int T, M, N, t, L;
	string s;
	char c;
	cin >> T;
	while (T--) {
		vector<string>v;
		vector<char>C;
		cin >> M >> N;
		v.resize(M);
		for (int i = 0; i < M; i++)
		{
			cin >> s;
			v[i] = s;
		}
		cin >> L;
		int tL = L / N;
		while (tL--)
		{
			vector<char> b;
			vector<int>count = { 0, };
			count.resize(M);
			for (int i = 0; i < N; i++)
			{
				cin >> c;
				b.push_back(c);
			}
			for (int i = 0; i < M; i++) {
				for (int j = 0; j < N; j++)
				{
					if (v[i][j] != b[j])
						count[i]++;
				}
			}
			int min = 128;
			int idx_of_max = 0;
			for (int i = 0; i < M; i++) {
				if (count[i]<min)
				{
					min = count[i];
					idx_of_max = i;
				}
			}
			C.push_back((char)(idx_of_max + 65));
		}
		for (int k = 0; k < C.size(); k++)
			cout << C[k];
		cout << "\n";
	}
	return 0;
}