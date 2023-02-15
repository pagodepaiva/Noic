#include<bits/stdc++.h>
#define int long long
#define ms(v) memset(v, -1, sizeof v)
#define pb push_back
#define mp make_pair
#define sv size
#define ll long long int
#define pi pair <int,int>
#define itn int
#define fr first
#define sc second
#define srt(v) sort(v.begin(), v.end())
#define rvs(v) reverse(v.begin(), v.end())
#define N 200010
 
using namespace std;
 
int n;
vector <int> g[N];
int sz[N];
 
int solve(int v){
    sz[v] = 0;
 
    for(auto x : g[v]){
        sz[v] += solve(x);
    }
 
    sz[v]++;
    return sz[v];
}
 
main(){
    ios::sync_with_stdio(false); cin.tie(0);
    
    ms(sz);
 
    cin >> n;
 
    for(int i = 2;i <= n;i++){
        int a;
        cin >> a;
        g[a].pb(i);
    }
 
    solve(1);
    for(int i = 1;i <= n;i++){
        cout << --sz[i] << " ";
    }
 
    cout << "\n";
    
    return 0;
}
