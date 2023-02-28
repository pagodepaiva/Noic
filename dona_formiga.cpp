#include <bits/stdc++.h>
#define pb push_back
#define ms(v) memset(v, -1, sizeof v)
#define N 100010

using namespace std;

int n, m, st;
int alt[N];
vector <int> g[N];
int dist[N];

int solve(int v){
    if(dist[v] != -1) return dist[v];

    dist[v] = 0;
    for(auto x : g[v]){
        dist[v] = max(dist[v], solve(x)+1);
    }

    return dist[v];
}

int main(){
    cin >> n >>m >> st;

    for(int i = 1;i <= n;i++) cin >> alt[i];

    for(int i = 0;i < m;i++){
        int a, b;
        cin >> a >> b;

        if(alt[a] > alt[b]) swap(a, b);
        if(alt[a] == alt[b]) continue;

        g[b].pb(a);
    }

    ms(dist);

    solve(st);

    cout << dist[st] << "\n";

    return 0;
}
