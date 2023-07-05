#include<bits/stdc++.h>
#define int long long
#define N 200010

using namespace std;

int dp[N][2];
int at[N];

void solve(){
    int n;
    cin >> n;
    dp[0][0] = dp[0][1] = 0;

    for(int i = 1;i <= n;i++){
        int x;
        cin >> x;
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
        dp[i][1] = (at[x] == 0 ? 0 : max(max(dp[at[x]-1][0], dp[at[x]-1][1]) + i - (at[x]-1), dp[at[x]][1] + i-at[x])); 
        at[x] = i;
    }

    cout << max(dp[n][0], dp[n][1]) << "\n";

    for(int i = 0;i <= n;i++){
        // cout << dp[i][0] << " " << dp[i][1] << "\n";
        dp[i][0] = dp[i][1] = at[i] = 0;
    }
}

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
