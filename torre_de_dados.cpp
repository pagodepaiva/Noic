#include<bits/stdc++.h>
#define pb push_back

using namespace std;

int dadolol(int x){
    if(x == 0) return 5;
    if(x == 1) return 3;
    if(x == 2) return 4;
    if(x == 3) return 1;
    if(x == 4) return 2;
    if(x == 5) return 0;
}

int main(){
    int n;
    cin >> n;

    vector < array <int, 6> > v;

    for(int i = 0;i < n;i++){
        int a, b, c, d, e, f;
        cin >> a >> b >> c >> d >> e >> f;

        v.pb({a, b, c, d, e, f});
    }

    int resmax = 0;

    for(int x = 0;x < 6;x++){
        int res = 0;
        int ban = x;
        int valf = v[0][x], valb = v[0][dadolol(x)];
        int m = 0;

        // cout << valf << " " << valb << "\n";


        for(int i = 0;i < 6;i++){
            if(v[0][i] == valf or v[0][i] == valb) continue;
            m = max(m, v[0][i]);
        }

        res += m;
		resmax = max(resmax, res);

        if(n == 1) continue;

        valf = valb;

        for(int i = 0;i < 6;i++){
            if(valf == v[1][i]) ban = i;
        }

        valb = v[1][dadolol(ban)];

        for(int i = 1;i < n;i++){
            // cout << valf << " " << valb << "\n";

            m = 0;
            for(int j = 0;j < 6;j++){
                if(v[i][j] == valf or v[i][j] == valb) continue;
                m = max(m, v[i][j]);
            }

            res += m;
            if(i == n-1) continue;
            valf = valb;
            for(int t = 0;t < 6;t++){
                if(valf == v[i+1][t]) ban = t;
            }
            valb = v[i+1][dadolol(ban)];
        }

        // cout << "\n" << " " << "\n";

        resmax = max(resmax, res);
    }

    cout << resmax << "\n";
}
