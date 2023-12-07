#include<bits/stdc++.h>

using namespace std;

int ask(int a, int b, int c){
    cout << "? " << a << ' ' << b << " " << c << "\n";
    cout.flush();
    int res;
    cin >> res;
    return res;
}

void solve(){
    int n;
    cin >> n;
    int a, b;
    int im, cr;

    for(int i = 1;i <= n;i += 3){
        int r = ask(i, i+1, i+2);
        if(r == 0) a = i;
        else b = i;
    }

    int r1, r2, r3, r4;
    r1 = ask(a, b, a+1);
    r2 = ask(a, b, a+2);
    r3 = ask(a, b, b+1);
    r4 = ask(a, b, b+2);

    if(r1 == r2 and r2 == r3 and r3 == r4){
        if(r1 == 0){
            cr = b+1;
            im = a;
        }

        else{
            cr = b;
            im = a+1;
        }
    }

    else{
        vector <pair <int, int>> v = {{r1, a+1}, {r2, a+2}, {r3, b+1}, {r4, b+2}};

        sort(v.begin(), v.end());

        for(int i = 0;i < 3;i++){
            if(v[i].first != v[i+1].first){
                im = v[i].second;
                cr = v[i+1].second;
            }
        }
    }

    vector <int> impostores;
    impostores.push_back(im);

    for(int i = 1;i <= n;i++){
        if(i == im or i == cr) continue;
        int r = ask(i, im, cr);
        if(r == 0){
            impostores.push_back(i);
        }
    }

    cout << "! " << impostores.size() << " ";

    for(auto x : impostores){
        cout << x << " ";
    }

    cout << "\n";
    cout.flush();

    return;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        solve();
    }
}
