#include<bits/stdc++.h>
#define int long long
#define ms(v) memset(v, -1, sizeof v)
#define pb push_back
#define mp make_pair
#define sz size
#define ll long long int
#define pi pair <int,int>
#define itn int
#define fr first
#define sc second
#define srt(v) sort(v.begin(), v.end())
#define rvs(v) reverse(v.begin(), v.end())
#define mod 1000000007
#define INF 1e18
#define N 510
 
using namespace std;
 
int a, b; int dp[N][N];
 
int solve(int i, int j){
    if(dp[i][j] != -1) return dp[i][j];
    if(i == j) return dp[i][j] = 0;
 
    dp[i][j] = INF;
 
    for(int k = 1;k < i;k++){
        dp[i][j] = min(solve(k, j) + solve(i-k, j) + 1, dp[i][j]);
    }
 
    for(int k = 1;k < j;k++){
        dp[i][j] = min(solve(i, k) + solve(i, j-k) + 1, dp[i][j]);
    }
 
    return dp[i][j];
}
 
int32_t main(){
    ios::sync_with_stdio(false); cin.tie(0);
    
    cin >> a >> b;
 
    ms(dp);
    solve(a, b);
 
    cout << dp[a][b] << "\n";
 
    return 0;
}
