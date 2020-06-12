#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<cmath>
#include<deque>
#include<string>
#include<algorithm>
using namespace std;
int parent[1000];
int treesize[1000];
void updateroot(int u, int v) {
	if (treesize[u] <treesize[v])
	{
		parent[u] = v;
		treesize[v] += treesize[u];
		//treesize[u] = treesize[v];
	}
	else {
		parent[v] = u;
		treesize[u] += treesize[v];
		//treesize[v] = treesize[u];
	}
}
int findroot(int u) {
	if (parent[u] == u)
		return u;
	else
		return findroot(parent[u]);
}
int main() {
	std::ios::sync_with_stdio(false);
	int T; cin >> T;
	while (T--) {
		int n;
		vector<int> cost;
		vector<int> pack;
		vector<vector<int>> edge;
		cin >> n;
		int N = n;
		int t, tt;
		cost.push_back(0);
		pack.push_back(0);
		while (n--) {
			cin >> t >> tt;
			cost.push_back(t);
			pack.push_back(tt);
		}
		int p_cost = 0, sub_cost = 0;
		for (int i = 1; i <= N+1; i++) {
			parent[i] = i;
			treesize[i] = 1;
		}
		
		for (int i = 1; i <=N; i++) {
			p_cost += cost[i];
			vector<int>t;
			t.push_back(cost[i]);
			t.push_back(i);
			t.push_back(N+1);
			edge.push_back(t);
			if (i > 1)
			{
				t[0] = pack[i];
				t[1] = i - 1;
				t[2] = i;
				
				edge.push_back(t);
			}
		}
		sort(edge.begin(), edge.end());
		for (int i = 0; i < edge.size(); i++) {
			vector<int >t;
			t = edge[i];
			int u = t[1], v = t[2];
			int ru, rv;
			ru = findroot(u);
			rv = findroot(v);
			if(ru!=rv)
			{
				updateroot(ru, rv);
				sub_cost += t[0];
			}

		}
		cout << p_cost + sub_cost << "\n";
	}
	return 0;
}
