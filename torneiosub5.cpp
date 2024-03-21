#include<bits/stdc++.h>

using namespace std;

int vencedorPartida(int a, int b);
int numeroVitorias(int competidor);
void responde(int tamanho, int array[]);

int saida[1001];

int query(int a, int b){
    return vencedorPartida(a, b);
}

void ask(vector <int> &v, int novo){
    for(auto x : v){
        if(query(x, novo) == x){
            saida[novo]++;
        }
        else{
            saida[x]++;
        }
    }

    if(saida[novo] <= 4) v.push_back(novo);

    vector <int> at;

    for(auto x : v){
        if(saida[x] <= 4) at.push_back(x);
    }

    v = at;
    return;
}

int resposta[1001];

void processaTorneio(int S, int n) {
    vector <int> resp;

    resp.push_back(1);

    for(int i = 2;i <= n;i++){
        ask(resp, i);
    }
    int con = 0;

    for(auto x : resp){
        int deg = 0;

        for(int i = 1;i <= n;i++){
            if(i == x) continue;
            if(query(i, x) == i) deg++;
        }

        if(deg <= 4){
            resposta[con] = x;
            con++;
        }
    }

    responde(con, &resposta[0]);
}
