int vencedorPartida(int a, int b);
int numeroVitorias(int competidor);
void responde(int tamanho, int array[]);
#include<bits/stdc++.h>
#define N 1010

using namespace std;

int saida[1001];
int deg[N];

int qdeg(int x){
    return numeroVitorias(x);
}

bool comp(int a, int b){
    return deg[a] < deg[b];
}

bool comp2(int a, int b){
    return deg[a] > deg[b];
}


void processaTorneio(int S, int n) {
    for(int i = 1;i <= n;i++) deg[i] = qdeg(i);
    set <int> s;
    for(int i = 1;i <= n;i++) s.insert(i);
    while(true){
        int t = -1;
        for(auto x : s){
            if(deg[x] == 0){
                t = x;
            }
        }
        if(t == -1) break;
        for(int i = 1;i <= n;i++) deg[i]--;
        s.erase(t);
    }
    vector <int> v;
    for(auto x : s) v.push_back(x);
    sort(v.begin(), v.end(), comp);
    vector <int> win, lose;
    for(int i = 1;i < v.size();i++){
        if(vencedorPartida(v[0], v[i]) == v[0]){
            lose.push_back(v[i]);
        }
        else win.push_back(v[i]);
    }
    sort(lose.begin(), lose.end(), comp2);
    for(auto x : win){
        if(vencedorPartida(x, lose[0]) == lose[0]){
            saida[0] = v[0];
            saida[1] = lose[0];
            saida[2] = x;
            responde(3, &saida[0]);
        }
    }
    return;
}
