#include<bits/stdc++.h>
#define N 300
#define int long long

using namespace std;

const int mod = (1 << 30);
int v[N][N];

int32_t main(){
    int n;
    cin >> n;

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            cin >> v[i][j];
        }
    }

    int sum = 0;

    for(int i = 1;i <= n;i++){
        sum += v[(n+1)/2][i];
        sum %= mod;
    }

    int prod = 1;

    for(int i = 1;i <= n-2;i++){
        prod *= n;
        prod %= mod;
    }

    int res = 0;

    for(int i = 1;i <= n;i++){
        if(i == (n+1)/2) continue;
        for(int j = 1;j <= n;j++){
            for(int t = 1;t <= n;t++){
                res += prod*(abs(v[i][j] - v[(n+1)/2][t]));
                res %= mod;
            }
        }
    }

    cout << res << '\n';

    return 0;
}
