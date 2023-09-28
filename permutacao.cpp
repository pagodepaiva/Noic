#include<bits/stdc++.h>
#define int long long

using namespace std;

int32_t main(){
    int n;
    cin >> n;

    int res = 0;

    for(int i = 1;i <= n;i++){
        res += abs(n-i+1-i);
    }

    cout << res << "\n";
    return 0;
}
