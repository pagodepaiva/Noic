#include<bits/stdc++.h>
#define N 260
#define SUM 260*260

using namespace std;

int n, x;
int dp[N][SUM];
int v[N];

int solve(int pos, int val){
    if(val < 0) return -2;
    if(dp[pos][val] != -1) return dp[pos][val];

    if(solve(pos-1, val) != -2){
        dp[pos][val] = dp[pos-1][val];
    }

    else if(solve(pos-1, val-v[pos]) != -2){
        dp[pos][val] = pos;
    }

    else{
        dp[pos][val] = -2;
    }

    return dp[pos][val];
}

int main(){
    cin >> n >> x;

    for(int i = n;i > 0;i--) cin >> v[i];
    // reverse()
    memset(dp, -1, sizeof dp);

    for(int i = 0;i < SUM;i++) dp[0][i] = -2;

    dp[0][0] = 0;

    solve(n, x);

    if(dp[n][x] == -2){
        cout << "N\n";
        return 0;
    }

    int pos = dp[n][x];
    cout << "S\n";

    while(pos != 0 and pos != -2){
        cout << n-pos << " ";
        x -= v[pos];
        // cout << x << ' '<< v[pos] << "\n";
        pos--;
        pos = dp[pos][x];
    }

    cout << "\n";

    return 0;
}
