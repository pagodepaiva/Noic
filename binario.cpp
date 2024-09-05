#include<bits/stdc++.h>

using namespace std;

int main(){
    int resposta = 1;
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int i = 0;i < n;i++){
        resposta = 2*resposta + (s[i] == 'D');
    }
    cout << resposta << '\n';
}
