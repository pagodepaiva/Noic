#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int n;
    cin >> n;

    int x;
    cin >> x;

    int pref = 0;
    map <int, int> m;
    m[pref] = 1;

    int res = 0;

    for(int i = 0;i < n;i++){
        int a; cin >> a;
        pref += a;
        res += m[pref-x];
        m[pref]++;
    }

    cout << res << "\n";

    return 0;
}
