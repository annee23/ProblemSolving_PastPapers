#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	int tT, M, N, t;
	char c;
	string s;
	cin >> tT;
	while (tT--) {
		cin >> M >> N;
		vector<string> st;
		for(int i=0;i<M;i++) {
			cin >> s;
			st.push_back(s);
		}
		vector<char> P;
		int C = 0, G = 0, T = 0, A = 0;
		for (int j = 0; j < N; j++) {
			C = 0, G = 0, T = 0, A = 0;
			for (int i = 0; i < M; i++) {
				if (st[i][j] == 'A')
					A++;
				else if (st[i][j] == 'G')
					G++;
				else if (st[i][j] == 'T')
					T++;
				else if (st[i][j] == 'C')
					C++;
			}
			if (A >= C && A >= G && A >= T)
				P.push_back('A');
			else if (A < C && C >= G && C >= T)
				P.push_back('C');
			else if (G > C && A < G && G >= T)
				P.push_back('G');
			else 
				P.push_back('T');
		}
		for (int i = 0; i < P.size(); i++)
			cout << P[i];
		cout << "\n";
		int count = 0;
		for (int j = 0; j < M; j++) {
			for (int i = 0; i < N; i++) {
				if (P[i] != st[j][i])
					count++;
			}
		}
		cout << count << "\n";
	}
}