#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    int v[n+5];

    for(int i = 1;i <= n;i++){cin >> v[i];}

    int l = 0, r = n;
    int lt = 1;

    while(r-l > 1){
        int mid = (l+r)/2;

        int con = 0;

        for(int i = 1;i <= n;i++){
            if(v[i] >= mid) con++;
        }

        if(con >= mid){
            l = mid;
        }

        else{
            r = mid-1;
        }
    }

    int con = 0;

    for(int i = 1;i <= n;i++){
        if(v[i] >= r) con++;
    }

    if(con >= r){
        cout << r << "\n";
    }

    else{
        cout << l << "\n";
    }
}
