#include<bits/stdc++.h>
#define int long long
using namespace std;

int k, r;
int dp[21][110][110];

int solve(int pos, int pes, int lastn){
    if(pes < 0) return 0;
    if(dp[pos][pes][lastn] != -1) return dp[pos][pes][lastn];
    if(pos == 0 and pes == 0) return dp[pos][pes][lastn] = 1;
    if(pos == 0 and pes > 0) return 0;
    if(pos > 0 and pes == 0) return 0;
    
    dp[pos][pes][lastn] = 0;

    for(int i = 1;i < lastn;i++){
        dp[pos][pes][lastn] += solve(pos-1, pes-i, i);
    }

    return dp[pos][pes][lastn];
}

int32_t main(){
    cin >> r >> k;
    memset(dp, -1, sizeof dp);
    cout << solve(k, r, r+1) << "\n";
    return 0;
}
