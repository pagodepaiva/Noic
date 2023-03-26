#include<bits/stdc++.h>
#define N 100010
#define pb push_back

using namespace std;

vector <int> g[N];
int mark[N];

void dfs(int v, int con){
    if(mark[v] != 0) return;

    mark[v] = con;

    for(auto x : g[v]){
        dfs(x, con);
    }

    return;
}

int sum[N];

int main(){
    int n, m, k;
    cin >> n >> m >> k;

    for(int i = 0;i < m;i++){
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }

    int con = 1;

    for(int i = 1;i <= n;i++) {
        if(mark[i] == 0) {dfs(i, con); con++;}
    }

    for(int i = 1;i <= n;i++) sum[mark[i]]++;

    con--;

    vector <int> v;

    for(int i = 1;i <= con;i++){
        v.pb(sum[i]);
    }

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    int res = 0;

    for(int i = 0;i < min(k+1, con);i++){
        res += v[i];
    }

    cout << res << "\n";

    return 0;
}
