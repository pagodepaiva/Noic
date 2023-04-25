#include<bits/stdc++.h>
#define N 19
#define int long long
using namespace std;

int n;
int dp[N];
int m[N][N];

int32_t main(){
    cin >> n;

    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            cin >> m[i][j];
        }
    }

    for(int mask = 1;mask < (1 << n);mask++){
        for(int i = 0;i < n;i++){
            if((mask & (1 << i)) == 0) continue;
            for(int j = i+1;j < n;j++){
                if((mask & (1 << j)) == 0) continue;
                dp[mask] += m[i][j];
            }
        }

        dp[mask] = dp[mask];

        for(int s = mask; s > 0;s = ((s-1)&mask)){
            dp[mask] = max(dp[mask], dp[s] + dp[(mask^s)]);
        }
    }

    cout << dp[(1 << n)-1] << "\n";

    return 0;
}
