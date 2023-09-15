#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("248.in", "r", stdin);

	int n;

	cin >> n;

	vector<int> a(n);

	int best = 0;

	for (int i = 0; i < n; i++) {

		cin >> a[i];

		best = max(best, a[i]);

	}

	vector<vector<int>> dp(n, vector<int>(n, -1));


	for (int len = 1; len <= n; len++) {

		for (int l = 0; l + len - 1 < n; l++) {

			int r = l + len - 1;


			if (l == r) {

				dp[l][r] = a[l];

				continue;

			}

			for (int rr = l; rr < r; rr++) {

				if (dp[l][rr] != -1 && dp[l][rr] == dp[rr + 1][r]) {

					dp[l][r] = max(dp[l][r], dp[l][rr] + 1);

				}

			}

			best = max(best, dp[l][r]);

		}

	}


	freopen("248.out", "w", stdout);

	cout << best << endl;

}
