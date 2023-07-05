#include<bits/stdc++.h>
#define inf 1e8

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        int dp[n+1], m[n+1];
        dp[0] = 0;

        for(int i = 0;i < n+1;i++) m[i] = inf;

        for(int i = 1;i <= n;i++){
            int x;
            cin >> x;

            dp[i] = min(dp[i-1]+1, m[x]);
            m[x] = min(m[x], dp[i-1]);
        }

        cout << n - dp[n] << "\n";
    }

    return 0;
}
