#include<bits/stdc++.h>
#define inf 1e15
#define int long long
#define N 210

using namespace std;

int n;
int s[N][N], dp[N][N];
double f;
int m(int x){
    return (x+n-1) % n;
}

int sum(int i, int j){
    if(s[i][j] != -1) return s[i][j];
    return s[i][j] = sum(i, m(j)) + s[j][j];
}

int solve(int i, int j){
    if(dp[i][j] != -1) return dp[i][j];

    dp[i][j] = inf;

    for(int k = j;k != i;k = m(k)){
        dp[i][j] = min(dp[i][j], solve(i, m(k)) + solve(k, j) + max(sum(i, m(k)), sum(k, j)));
    }

    return dp[i][j];
}

int32_t main(){
    cin >> n >> f;

    memset(dp, -1, sizeof dp);
    memset(s, -1, sizeof s);

    for(int i = 0;i < n;i++){
        cin >> s[i][i];
        dp[i][i] = 0;
    }

    int res = inf;
    for(int i = 0;i < n;i++){
        res = min(res, solve(i, m(i)));
    }

    cout << fixed << showpoint;
    cout << setprecision(2) << res*f << "\n";

    return 0;
}
