#include<bits/stdc++.h>
#define N 100010

using namespace std;

int n;

struct BIT{
    int tree[N];

    void update(int x, int val){
        for(;x <= n;x += (x&(-x))){
            tree[x] += val;
        }
    }

    int query(int x){
        int res = 0;
        for(;x > 0;x -= (x&(-x))){
            res += tree[x];
        }
        return res;
    }
} bit;

int q;

int main(){
    cin >> n >> q;

    vector <int> v;
    for(int i = 1;i <= n;i++){
        int x;
        cin >> x;
        bit.update(i,x);
        v.push_back(x);
    }

    for(int i = 0;i < q;i++){
        int a;
        cin >> a;

        if(a == 0){
            int b, c;
            cin >> b >> c;
            bit.update(b, c - v[b-1]);
            v[b-1] = c;
        }

        else{
            int b;
            cin >> b;
            cout << bit.query(b) << "\n";
        }
    }
}
