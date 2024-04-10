#include<bits/stdc++.h>
#define endl '\n'
#define int long long
#define fr first
#define sc second
#define inf 1e18
#define N 200010
 
using namespace std;
 
int pref[N];
 
int32_t main(){
    int n;
    cin >> n;
    vector <int> v;
    for(int i = 0;i < n;i++){
        int x;cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    if(n % 2){
        int x1 = v[n/2];
        int x2 = v[n/2 - 1];
        int res1 = 0, res2 = 0;
        for(int i = 0;i < n;i++){
            res1 += abs(v[i] - x1);
            res2 += abs(v[i] - x2);
        }
        cout << min(res1, res2) << endl;
    }
    else{
        int x = v[(n-1)/2];
        int res = 0;
        for(int i = 0;i < n;i++){
            res += abs(v[i] - x);
        }
        cout << res << endl;
    }
    return 0;
}
