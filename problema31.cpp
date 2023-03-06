#include<bits/stdc++.h>
#define int long long 
#define ms(v) memset(v, -1, sizeof v)
#define pi pair<int, int>
#define pb push_back
#define fr first
#define sc second
#define all(x) x.begin(), x.end()
#define INF 1e17
#define mp make_pair
#define itn int
#define N 200010

using namespace std;

int dp[N];

int choose(int x){
    return (x*(x-1))/2;
}

int solve(int x){
    if(x < 0) return INF;
    if(dp[x] != -1) return dp[x];

    dp[x] = INF;

    for(int i = 2;choose(i) <= x;i++){
        dp[x] = min(dp[x], solve(x - choose(i)) + i);
    }

    return dp[x];
}

int32_t main(){
    ios::sync_with_stdio(false); cin.tie(0);
    /*freopen("in.in", r, stdin)
    freopen("out.out", w, stdout)*/

    ms(dp);
    dp[0] = 0;
    for(int i = 1;i <= 2*100000;i++){
        solve(i);
    }

    int p;
    cin >> p;

    cout << dp[p] << " " << choose(dp[p]) - p << "\n";

    return 0;   
}
