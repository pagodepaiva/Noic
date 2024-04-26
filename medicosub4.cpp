#include<bits/stdc++.h>
#define N 80
#define int long long
#define inf 1e7

using namespace std;

int n;
int v[N][N];
int dp[N][N];
int qt[N][N];
int pref[N][N];
int suf[N][N];

int iv, ip;
const int mod = (1 << 30);

int solve(int pos, int val){
    if(pos == 0 and val == 0) {qt[pos][val] = 1; return dp[pos][val] = 0;}
    if(val < 0) return -2;
    if(pos == 0 and val > 0) return -2;
    if(dp[pos][val] != -1) return dp[pos][val];
    if(pos == ip) {solve(pos-1, val); qt[pos][val] = qt[pos-1][val]; return dp[pos][val] = solve(pos-1, val);}

    dp[pos][val] = 0;

    int l = 0, r = n+1;

    while(l < r){
        int mid = (l+r) >> 1;

        if(v[pos][mid] < iv){
            l = mid+1;
        }

        else {r = mid;}
    }

    l--;

    solve(pos-1, val);
    solve(pos-1, val-1);

    bool aux = false;

    if(l > 0 and solve(pos-1, val) != -2) aux = true;
    if(l < n and solve(pos-1, val-1) != -2) aux = true;

    qt[pos][val] = (solve(pos-1, val) != -2 ? (qt[pos-1][val]*l) % mod : 0) + (solve(pos-1, val-1) != -2 ? (qt[pos-1][val-1]*(n-l)) % mod : 0);
    qt[pos][val] %= mod;
    dp[pos][val] = (solve(pos-1, val) != -2 ? ((solve(pos-1, val)*l) % mod + (iv*l - pref[pos][l])*qt[pos-1][val]) % mod : 0);
    dp[pos][val] %= mod;
    dp[pos][val] += (solve(pos-1, val-1) != -2 ? ((solve(pos-1, val-1)*(n-l)) % mod + (suf[pos][l+1] - iv*(n-l))*qt[pos-1][val-1]) % mod : 0);
    dp[pos][val] %= mod;

    return (aux ? dp[pos][val] : dp[pos][val] = -2);
}

int32_t main(){
    cin >> n;

    for(int i = 1;i <= n;i++){
        vector <int> aux;

        for(int j = 1;j <= n;j++){
            cin >> v[i][j];
            aux.push_back(v[i][j]);
        }

        v[i][n+1] = inf;

        sort(aux.begin(), aux.end());

        for(int j = 1;j <= n;j++){
            v[i][j] = aux[j-1];
            pref[i][j] = pref[i][j-1] + v[i][j];
        }

        for(int j = n;j >= 1;j--){
            suf[i][j] = suf[i][j+1] + v[i][j];
        }
    }

    int res = 0;

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            memset(dp, -1, sizeof dp);
            memset(qt, 0, sizeof qt);
            iv = v[i][j];
            ip = i;

            res += (solve(n, (n-1)/2) == -2 ? 0 : solve(n, (n-1)/2));

            res %= mod;
        }
    }

    cout << res << '\n';

    return 0;
}
