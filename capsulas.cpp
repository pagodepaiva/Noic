#include<bits/stdc++.h>
#define int long long

using namespace std;

int32_t main(){
    int n, f;
    cin >> n >> f;
    int v[n];

    for(int i = 0;i < n;i++){
        cin >> v[i];
    }

    int l = 0, r = 1e18;

    while(l < r){
        int mid = (l+r)/2;
        int res = 0;

        for(int i = 0;i < n;i++){
            int t = mid/v[i];
            res += t;
        }

        if(res >= f){
            r = mid;
        }

        else{
            l = mid+1;
        }
    }

    cout << l << "\n";
    return 0;
}
