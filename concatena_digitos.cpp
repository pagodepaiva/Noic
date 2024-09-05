#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N = 100010;
int n, q;
int v[N];
int p[N];

int32_t main(){
    cin >> n >> q;
    for(int i = 1;i <= n;i++){
        cin >> v[i];
        p[i] = p[i-1] + v[i];
    }
    for(int i = 0;i < q;i++){
        int l, r;
        cin >> l >> r;
        cout << 11*(r-l)*(p[r]-p[l-1]) << '\n';
    }
}
