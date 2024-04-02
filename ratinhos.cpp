#include<bits/stdc++.h>
#define N 100010
#define endl "\n"

using namespace std;

int n;
vector <pair <int, int>> v;
int h[N];
int pai[N];

struct LCA{
    int find[N][20];
    void build(){
        for(int i = 0;i <= n;i++) find[i][0] = pai[i];
        for(int bit = 1;bit < 20;bit++){
            for(int i = 0;i <= n;i++){
                find[i][bit] = find[find[i][bit-1]][bit-1];
            }
        }
        return;
    }
    int lca(int a, int b){
        if(h[a] > h[b]) swap(a, b);
        int t = h[b] - h[a];
        int res = 0;
        for(int i = 0;i < 20;i++){
            if((1 << i) & t){
                b = find[b][i];
                res += (1 << i);
            }
        }
        if(a == b) return res;
        for(int i = 19;i >= 0;i--){
            if(find[a][i] != find[b][i]){
                a = find[a][i];
                b = find[b][i];
                t = (1 << i);
                res += t;
                res += t;
            }
        }
        return res+2;
    }
} lca;


void build(){
    sort(v.begin(), v.end());
    pai[0] = 0;
    stack <array <int, 3>> s;
    s.push({-1, (int) 1e7, 0});
    h[0] = 0;
    for(int i = 0;i < n;i++){
        auto [l, r] = v[i];
        while(!(s.top()[0] <= l and r <= s.top()[1])){
            s.pop();
        }
        pai[i+1] = s.top()[2];
        h[i+1] = h[pai[i+1]] + 1;
        s.push({l, r, i+1});
    }
    lca.build();
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for(int i = 0;i < n;i++){
        int a, b, x;
        cin >> a >> x >> b >> x;
        v.push_back({a, b});
    }
    int q;
    cin >> q;
    build();
    while(q--){
        int k, a, b;
        cin >> k >> a >> b;
        int l = 0, r = n-1;
        int posa = 0;
        while(l <= r){
            int mid = (l+r)/2;
            if(v[mid].first > a) r = mid-1;
            else if(v[mid].second < a) l = mid+1;
            else if(v[mid].first <= a and a <= v[mid].second){
                posa = mid;
                l = mid+1;
            }
        }
        if(v[posa].first <= a and a <= v[posa].second) posa++;
        l = 0;
        r = n-1;
        int posb = 0;
        while(l <= r){
            int mid = (l+r)/2;
            if(v[mid].first > b) r = mid-1;
            else if(v[mid].second < b) l = mid+1;
            else if(v[mid].first <= b and b <= v[mid].second){
                posb = mid;
                l = mid+1;
            }
        }
        if(v[posb].first <= b and b <= v[posb].second) posb++;
        cout << lca.lca(posa, posb) << "\n";
    }
    return 0;
}
