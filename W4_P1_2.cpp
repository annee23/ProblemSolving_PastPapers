#include<iostream>
#include<vector>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	int T; cin >> T;
	while (T--) {
		int N, t; cin >> N;
		vector<int>choose;
		choose.push_back(-1);	//0���̾ƴ� 1�����ͽ����ϴϱ� 
		vector<int>pair;
		pair.push_back(-1);
		pair.resize(N+1);
		for (int i = 0; i < N; i++) {// i+1��° ����� ���� �����ߴ��� ����
			cin >> t;
			choose.push_back(t);
		}
		for (int i = 1; i < N + 1; i++) {
			if (pair[i] != 0)		//¦�� ������ ��ŵ
				continue;
			if (choose[i] == i)		//������� �����̸� 2�� �ֱ�(2�� �ǹ̴� ȥ�����̶�°�)
			{
				pair[i] = 2;
			}
			else
			{
				int tmp; bool boo = false;
				vector<int>v;
				tmp = choose[i];
				while (tmp != i)		//������� ������ ������� �� ���� �� ���ϱ�
				{
					if (tmp == choose[tmp]) //���� ȥ������ ����̸� �� ��������°� �����
					{
						pair[i] = 0;
						boo = true;
						break;
					}
					else if(pair[tmp]!=0)   //������� ȥ������ ����̿��� �� ��������°� �����
					{
						pair[i] = 0;
						boo = true;
						break;
					}
					else
					{
						for (int j = 0; j < v.size(); j++)
							if(tmp==v[j])
							{
								pair[i] = 0;
								boo = true;
								break;
							}
						if (boo)
							break;
						v.push_back(tmp);
						tmp = choose[tmp];		//������� ����
					}
				}
				if (!boo)
				{
					pair[i] = 1;			//���� �ִ�.
					for (int j = 0; j < v.size(); j++)
						pair[v[j]] = 1;			//������ ��ο��� �����ִٴ� �ǹ��� 1�� �־���
				}
			}
		}
		int count = 0;
		for (int i = 1; i < N + 1; i++) {	//���� ���»�� ��� ���ϱ�
			if (pair[i]==0)
				count++;
		}
		cout << count << "\n";
	}
}