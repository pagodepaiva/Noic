#include<bits/stdc++.h>
#define fr first
#define sc second;
#define int long long

using namespace std;

int n;
vector <pair <int, int>> v;

pair <int, int> solve(){
    set <pair <int, int>> lar, com;
    int sum = 0;

    for(int i = 0;i < n;i++){
        lar.insert({v[i].first, i});
        com.insert({v[i].second, i});
        sum += v[i].first*v[i].second;
    }

    auto it = lar.end();
    it = prev(it);
    pair <int, int> aux = *it;
    int res1, res2;
    if(sum % aux.first != 0){
        return {-1, -1};
    }

    int l = aux.first, c = sum/aux.first;
    int t = 0;
    res1 = l;
    res2 = c;

    while(lar.size() != 0){
        // cout << "hihih\n";
        if(t == 0){
            it = lar.end();
            it = prev(it);
            aux = *it;

            if(aux.first != l){
                return {-1, -1};
            }

            while(aux.first == l and lar.size() != 0){
                // cout << "sus\n";
                pair <int, int> aux2 = {v[aux.second].second, aux.second};
                c -= aux2.first;
                lar.erase(aux);
                com.erase(aux2);
                if(lar.size() == 0) break;
                it = lar.end();
                it = prev(it);
                aux = *it;
            }

            t++;
        }

        else{
            it = com.end();
            it = prev(it);
            aux = *it;

            if(aux.first != c){
                return {-1, -1};
            }

            while(aux.first == c and com.size() != 0){
                pair <int, int> aux2 = {v[aux.second].first, aux.second};
                l -= aux2.first;
                lar.erase(aux2);
                com.erase(aux);
                if(com.size() == 0) break;
                it = com.end();
                it = prev(it);
                aux = *it;
            }

            t--;
        }
    }

    return {res1, res2};
}

int32_t main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;

    while(t--){
        cin >> n;
        v.clear();

        for(int i = 0;i < n;i++){
            int a, b;
            cin >> a >> b;
            v.push_back({a, b});
        }

        vector <pair <int, int>> ans;
        pair <int, int> p;
        p = solve();
        
        if(p.first != -1) ans.push_back(p);         
        // ans.push_back(solve());

        for(int i = 0;i < n;i++){
            v[i] = {v[i].second, v[i].first};
        }

        // if(ans[0].first == -1) ans.pop_back();
        p = solve();
        if(p.first != -1) ans.push_back({p.second, p.first});

        if(ans.size() == 2 and ans[0] == ans[1]){
            ans.pop_back();
        }

        cout << ans.size() << "\n";

        for(auto x : ans){
            cout << x.first << " " << x.second << "\n";
        }
    }
}
