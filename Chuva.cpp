#include<bits/stdc++.h>
#define int long long // esse int long long é importante pois a resposta pode ser n*(n-1)/2 que é O(N^2), que passa do limite do int
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
