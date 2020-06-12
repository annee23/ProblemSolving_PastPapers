#include<iostream>
#include<vector>
#include<cmath>
#include<deque>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	int T; cin >> T;
	int M, N;
	while (T--) {
		cin >> M >> N;
		int t, sum = 0;
		vector<int>output;
		for (int j = 0; j < M; j++) {
			vector<int>v;
			for (int i = 0; i < N; i++)
			{
				cin >> t;
				v.push_back(t);
			}
			cin >> sum;
			int plus = 0, multi = 1;
			for (int i = 0; i < N; i++)
			{
				plus += v[i];
				multi *= v[i];
			}
			if (sum == plus || sum == multi)
				output.push_back(1);
			else
			{
				bool flag = false;
				for (int i = 0; i < pow(2, N - 1); i++) {
					int addup = 0;
					deque<int> num;
					vector<int> bin;
					for (int j = N - 2; j >= 0; j--)
					{
						bin.push_back(((i >> j) & 1) ? 1 : 0);
					}
					for (int j = 0; j < N; j++)
					{
						num.push_back(v[j]);
					}
					for (int k = 0; k < bin.size(); k++)
					{
						if (bin[k] == 0)
						{
							int temp = num.front();
							num.pop_front();
							int temp2 = num.front();
							num.pop_front();
							num.push_front(temp * temp2);
						}
						else
						{
							int temp = num.front();
							num.pop_front();
							num.push_back(temp);
						}
					}
					while (num.size())
					{
						addup += num.front();
						num.pop_front();
					}
					if (addup == sum)
					{
						flag = true;
						output.push_back(1);
						break;
					}

				}
				if (!flag)
					output.push_back(0);
			}

		}
		for (int i = 0; i < output.size(); i++)
			cout << output[i] << " ";
		cout << "\n";
	}
}