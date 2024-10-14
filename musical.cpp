#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    int maior = 0, menor = 101;
    for(int i = 1;i <= n;i++){
        int x;
        cin>>x;
        maior=max(maior, x);
        menor=min(menor, x);
    }
    cout << 2*maior-2*menor << '\n';
}
