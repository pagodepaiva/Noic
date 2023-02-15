#include<bits/stdc++.h>
#define N 200010
#define pb push_back

using namespace std;

int n;
vector <int> g[N];
int dp[N];

int solve(int v, int p){
    for(auto x : g[v]){
        if(x == p) continue;
        dp[v] += solve(x, v);
    }

    dp[v]++;
    return dp[v];
}

int main(){
    cin >> n;

    for(int i = 2;i <= n;i++){
        int a;
        cin >> a;
        g[a].pb(i);
        g[i].pb(a);
    }

    solve(1, 1);

    for(int i = 1;i <= n;i++){
        cout << --dp[i] << "\n";
    }

    return 0;
}
