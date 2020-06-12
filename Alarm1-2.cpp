#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	int T, n, d, t;
	cin >> T;
	while (T--) {
		queue<int> q;
		vector<int>v;
		cin >> n >> d;
		for(int i=0;i<n;i++)
		{
			cin >> t;
			v.push_back(t);
		}
		int a[200] = { 0, };
		for (int i = 0; i < d; i++)
		{
			q.push(v[i]);
			a[v[i]]++;
		}
		if (d % 2 == 1) {
			int dd = d / 2 + 1;
			int count = 0;
			for (int i = d; i < n; i++) {
				int tcount = 0;
				for (int j = 0; j < 200; j++) {
					if (a[j] != 0)
						tcount += a[j];
					if (tcount >= dd) {
						if(j*2<=v[i])
							count++;
						break;
					}
				}
				q.push(v[i]);
				a[v[i]]++;
				a[v[i - d]]--;
			}
			cout << count << "\n";
		}
		else {
			int dd = d / 2;
			int count = 0;
			for (int i = d; i < n; i++) {
				int tcount = 0;
				int tmp = 0;
				bool b = false;
				for (int j = 0; j < 200; j++) {
					if (a[j] != 0)
						tcount += a[j];
					if (!b &&tcount == dd)
					{
						tmp += j;
						b = true;
					}
					else if (tcount > dd) {
						if (tmp != 0 && j + tmp <= v[i]) {
							count++;
						}
						else if (tmp==0&&j * 2 <= v[i])
							count++;

						break;
					}
				}
				q.push(v[i]);
				a[v[i]]++;
				a[v[i - d]]--;
			}
			cout << count << "\n";
		}
	}
	return 0;
	
}