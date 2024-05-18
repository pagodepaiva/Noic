#include<bits/stdc++.h>
#define int long long

using namespace std;

int lg(int x){
    int prod = 1, con = 0;

    while(prod <= x){
        if(prod*2 > x) return con;
        con++;
        prod *= 2;
    }

    return con;
}

vector <int> solve1(int n){
    vector <int> fat;

    for(int i = 2;i*i <= n;i++){
        while(n % i == 0){
            fat.push_back(i);
            n = n/i;
        }
    }

    if(n != 1) fat.push_back(n);

    vector <int> res;
    
    int con = 1;

    for(auto x : fat){
        for(int i = con+x-1;i >= con;i--){
            res.push_back(i);
        }
        con = con + x;
    }

    return res;
}

vector <int> solve2(int n){
    vector <int> p = solve1(n-1);

    int val = n+1, con = 0;
    int m = p.size();

    reverse(p.begin(), p.end());

    for(auto x : p){
        if(val > x){
            val = x;
            con++;
        }
    }

        // reverse(p.begin(), p.end());
    for(int i = m+con;i >= m+1;i--){
        p.push_back(i);
    }

    reverse(p.begin(), p.end());

    return p;
}

vector <int> solve3(int n){
    vector <int> res;
    int con = 0;
    int qt = 0;

    for(int i = 0;i <= 30;i++) if(((1 << i) & n) != 0) qt = i;

    for(int i = 0;i <= 30;i++){
        if(((1 << i) & n) == 0) continue;
        vector <int> ans = solve1((1 << i));
        reverse(res.begin(), res.end());
        
        int t = ans.size();
        t /= 2;
        int k = ans.size();

        for(int i = k + 1; i <= k + qt - t;i++){
            ans.push_back(i);
        }

        reverse(ans.begin(), ans.end());
        
        for(auto x : ans){
            res.push_back(x+con);
        }

        reverse(res.begin(), res.end());

        int aux = 0;

        for(auto x : ans){
            aux = max(aux, x);
        }    

        con = con+aux;
    }   

    // for(auto x : res) cout << x << ' ';
    //     cout << '\n';
    return res;
}

int32_t main(){
    int n;
    cin >> n;

    if(n == 1){
        cout << 1 << '\n';
        cout << 1 << '\n';
        return 0;
    }

    if(n == 2){
        cout << 2 << '\n';
        cout << 2 << ' ' << 1 << '\n';
    }

    vector <int> res = solve1(n);
    vector <int> aux = solve2(n);

    if(aux.size() < res.size()) res = aux;

    aux = solve3(n);
    // cout << aux.size() << '\n';

    if(aux.size() < res.size()) res = aux;

    cout << res.size() << '\n';

    for(auto x : res){
        cout << x << ' ';
    }
    cout << '\n';
    return 0;
}
