#include<bits/stdc++.h>
#define int long long
#define ms(v) memset(v, -1, sizeof v)
#define pb push_back
#define mp make_pair
#define ll long long int
#define pi pair <int,int>
#define itn int
#define fr first
#define sc second
#define srt(v) sort(v.begin(), v.end())
#define rvs(v) reverse(v.begin(), v.end())
#define mod 1000000007
#define INF 1e18
#define N 200010
 
using namespace std;
 
int n;
vector <int> pops;
vector <int> g[N];
int pai[N];
int mark[N];
 
void dfs(int x, int p){
    for(auto v : g[x]){
        if(v == p) continue;
        dfs(v, x);
    }
 
    pops.pb(x);
    pai[x] = p;
    return;
}
 
int solve(){
    int res = 0;
 
    for(auto v : pops){
        if(mark[v] == -1 and mark[pai[v]] == -1){
            mark[v] = 1;
            mark[pai[v]] = 1;
            res++;
        }
    }
 
    return res;
}
 
int32_t main(){
    ios::sync_with_stdio(false); cin.tie(0);
    
    ms(mark);
    mark[0] = 1;
 
    cin >> n;
 
    for(int i = 1;i < n;i++){
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
 
    dfs(1, 0);
    cout << solve() << "\n";
    return 0;
}
