#include<bits/stdc++.h>
using namespace std;
int n,v[1010][7],m[1010][7],maior;
int vinc(int x){
    if(x == 1){
        return 6;
    }
    if(x == 2){
        return 4;
    }
    if(x == 3){
        return 5;
    }
    if(x == 4){
        return 2;
    }
    if(x == 5){
        return 3;
    }
    return 1;
}
int valor(int a ,int b){
    if(a != 6 && b != 6){
        return 6;
    }
    if(a != 5 && b != 5){
        return 5;
    }
    return 4;
}
int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= 6;j++){
            cin >> v[i][j];
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= 6;j++){
            for(int k = 1;k <= 6;k++){
                if(v[i][k] == j){
                    int g = vinc(k);
                    int x = valor(v[i][g] , j);
                    m[i][v[i][g]] = m[i - 1][j] + x;
                }
            }
        }
    }
    for(int i = 1;i <= 6;i++){
        maior = max(maior , m[n][i]);
    }
    cout << maior;
    return 0;
}
