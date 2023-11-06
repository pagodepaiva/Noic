#include<bits/stdc++.h>
#define N 100010
#define fr first
#define sc second
 
using namespace std;
 
int n, k;
vector <int> g[N];
int res[N];
pair <int, int> dp[N];
pair <int, int> maxs[N];
vector <int> topsort;
int deg[N];
int pai[N];

void solve(){
    for(int i = 1;i <= n;i++){
        dp[i] = {0, 0};
        maxs[i] = {0, 0};
    }

    for(auto x : topsort){
    // cout << x << '\n'
        int v = pai[x];

        dp[x].sc = maxs[x].fr+1;
        if(dp[x].sc >= k) {dp[x].sc = 0; dp[x].fr++;}
        else if(maxs[x].fr+1 + maxs[x].sc >= k){dp[x].sc = 0; dp[x].fr++;}

        if(x == 1) continue;
        
        dp[v].fr += dp[x].fr;
        if(dp[x].sc > maxs[v].fr){
            swap(maxs[v].fr, maxs[v].sc);
            maxs[v].fr = dp[x].sc;
        }

        else if(dp[x].sc > maxs[v].sc){
            maxs[v].sc = dp[x].sc;
        }
    }

    return;
}

void dep(int t){
    k = t;
    solve();
    res[t] = dp[1].fr;
}
 
void busca(int l, int r){
    if(l > r) return;
    if(res[l] == -1) dep(l);
    if(res[r] == -1) dep(r);
 
    if(res[l] == res[r]){
        for(int i = l;i < r;i++){
            res[i] = res[r];
        }
 
        return;
    }
 
    int mid = (l+r)/2;
    if(res[mid] == -1) dep(mid);

    if(res[l] != res[mid]) busca(l, mid-1);
    else{
        for(int i = l;i <= mid;i++) res[i] = res[l];
    }

    if(res[r] != res[mid]) busca(mid+1, r);
    else{
        for(int i = mid;i <= r;i++) res[i] = res[r];
    }
    return;
}

void dfs(int v, int p){
    pai[v] = p;

    for(auto x : g[v]){
        if(x == p) continue;
        pai[x] = v;
        dfs(x, v);
    }

    return;
}

void tops(){
    queue <int> q;
    dfs(1, 1);
    deg[1] = g[1].size()+1;
    for(int i = 2;i <= n;i++){
        deg[i] = g[i].size();
        if(deg[i] == 1) q.push(i);
    }

    while(!q.empty()){
        int x = q.front();
        q.pop();
        topsort.push_back(x);
        deg[pai[x]]--;

        if(deg[pai[x]] == 1) q.push(pai[x]);
    }

    return;
}

int main(){
    cin >> n;
    memset(res, -1, sizeof res);
 
    for(int i = 1;i < n;i++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    tops();
    busca(1, n);
 
    for(int i = 1;i <= n;i++){
        cout << res[i] << '\n';
    }
 
    return 0;
}
