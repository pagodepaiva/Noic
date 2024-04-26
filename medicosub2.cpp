#include<bits/stdc++.h>
#define N 310
#define int long long

using namespace std;

int n;
int v[N][N];
int dp[N][N];
int qt[N][N];

int iv, ip;
const int mod = (1 << 30);

int solve(int pos, int val){
    if(pos == 0 and val == 0) {qt[pos][val] = 1; return dp[pos][val] = 0;}
    if(val < 0) return -2;
    if(pos == 0 and val > 0) return -2;
    if(dp[pos][val] != -1) return dp[pos][val];
    if(pos == ip) {solve(pos-1, val); qt[pos][val] = qt[pos-1][val]; return dp[pos][val] = solve(pos-1, val);}

    bool aux = false;
    dp[pos][val] = 0;

    for(int i = 1;i <= n;i++){
        if(v[pos][i] < iv){
            dp[pos][val] += (solve(pos-1, val) != -2 ? solve(pos-1, val) + ((iv - v[pos][i])*qt[pos-1][val]) % mod : 0);
            dp[pos][val] %= mod;
            if(solve(pos-1, val) != -2) {qt[pos][val] += qt[pos-1][val]; qt[pos][val] %= mod;}
            if(solve(pos-1, val) != -2) aux = true;
        }

        else{
            dp[pos][val] += (solve(pos-1, val-1) != -2 ? solve(pos-1, val-1) + ((v[pos][i] - iv)*qt[pos-1][val-1]) % mod : 0);
            dp[pos][val] %= mod;
            if(solve(pos-1, val-1) != -2) {qt[pos][val] += qt[pos-1][val-1]; qt[pos][val] %= mod;}
            if(solve(pos-1, val-1) != -2) aux =true;
        }
    }

    return (aux ? dp[pos][val] : dp[pos][val] = -2);
}

int32_t main(){
    cin >> n;

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            cin >> v[i][j];
        }
    }

    int res = 0;

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            memset(dp, -1, sizeof dp);
            memset(qt, 0, sizeof qt);
            iv = v[i][j];
            ip = i;

            res += (solve(n, (n-1)/2) == -2 ? 0 : solve(n, (n-1)/2));
            res %= mod;
        }
    }

    cout << res << '\n';

    return 0;
}
