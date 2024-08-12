#include <bits/stdc++.h>
using namespace std;

const int MAX = 75;

int n, x[MAX], y[MAX];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; i++)
		cin >> x[i] >> y[i];

	for(int i = 1; i <= n; i++)
	{
		int ataques = 0;

		for(int j = 1; j <= n; j++)
		{
			if(i == j) continue;

			int dx = x[j] - x[i], dy = y[j] - y[i];

			if(dx == 0 || dy == 0 || abs(dx) == abs(dy))
				ataques++; 
		}

		cout << ataques << '\n';
	}
}
