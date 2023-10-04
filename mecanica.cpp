#include<bits/stdc++.h>
#define N 100010
#define int long long

using namespace std;

long long c[N];

int32_t main(){
    int n, m;
    cin >> n >> m;

    vector <int> v;
    vector <int> p;

    for(int i = 0;i < n;i++){
        int x;
        cin >> x;
        v.push_back(x);
    }

    for(int i = 0;i < m;i++){
        int x;
        cin >> x;
        p.push_back(x);
    }

    sort(v.begin(), v.end());
    sort(p.begin(), p.end());

    long long res = 0;

    reverse(v.begin(), v.end());

    priority_queue <pair <int, int>> pq;

    for(int i = 0;i < p.size();i++){
        pq.push({0, i});
    }

    for(auto x : v){
        int pos = pq.top().second, val = -x*pq.top().first;
        pq.pop();
        c[pos]++;
        res += val;
        pq.push({-c[pos]*p[pos], pos});
    }

    cout << res << "\n";

    return 0;
}
