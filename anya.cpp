#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, x;
    cin >> n >> x;

    vector <int> v;

    vector <pair <int, int>> p;

    for(int i = 0;i < n;i++){
        int a;
        cin >> a;
        v.push_back(a);
        p.push_back({a, i});
    }

    sort(v.begin(), v.end());
    sort(p.begin(), p.end());

    for(int k = 0;k < n;k++){
        int l = 0, r = n-1;
        int sum = x - v[k];

        while(l < r){
            if(l == k){
                l++;
                continue;
            }

            if(r == k){
                r--;
                continue;
            }

            if(v[l] + v[r] == sum){
                cout << p[l].second+1 << " " << p[r].second+1 << " " << p[k].second+1 << "\n";
                return 0;
            }

            if(v[l] + v[r] > sum){
                r--;
                continue;
            }

            l++;
            continue;
        }
    }

    cout << "IMPOSSIBLE" << "\n";

    return 0;
}
