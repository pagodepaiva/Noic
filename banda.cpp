#include<bits/stdc++.h>
#define int long long

using namespace std;

int n, k;
map <string, vector <int>> m;
set <string> v;

int32_t main(){
    cin >> n >> k;

    for(int i = 0;i < n;i++){
        string s;
        cin >> s;
        int x;
        cin >> x;
        m[s].push_back(x);
        v.insert(s);
    }

    int res = 0;

    for(auto x : v){
        int p;
        p = m[x].size();
        sort(m[x].begin(), m[x].end());
        reverse(m[x].begin(), m[x].end());
        for(int i = 0;i < min(k, p);i++){
            res += m[x][i];
        }
    }

    cout << res << "\n";

    return 0;
}
