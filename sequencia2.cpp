#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

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

    cout << res.size() << '\n';

    for(auto x : res){
        cout << x << ' ';
    }

    cout << '\n';

    return 0;
}
