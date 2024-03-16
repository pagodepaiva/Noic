#include<bits/stdc++.h>

using namespace std;

int vencedorPartida(int a, int b);
int numeroVitorias(int competidor);
void responde(int tamanho, int array[]);

int saida[1001];

int divide(vector <int> x){
    int t = x.size();
    if(t == 1) return x[0];

    t = t/2;
    vector <int> a;
    vector <int> b;

    for(int i = 0;i < t;i++){
        a.push_back(x[i]);
    }

    for(int i = t;i < x.size();i++){
        b.push_back(x[i]);
    }

    if(a.size() > b.size()) swap(a, b);

    vector <int> resp;

    for(int i = 0;i < min((int) a.size(), (int) b.size());i++){
        int v = vencedorPartida(a[i], b[i]);
        resp.push_back(v);
    }

    if(a.size() < b.size()) resp.push_back(b.back());

    return divide(resp);
}

void processaTorneio(int S, int n) {
    vector <int> resp;

    for(int i = 1;i <= n;i++) resp.push_back(i);

    int t = divide(resp);

    for(int i = 1;i <= n;i++){
        if(i == t) continue;

        if(vencedorPartida(i, t) != t){
            vector <int> aux;
            responde(0, &saida[0]);
            return;
        }
    }

    vector <int> aux;
    aux.push_back(t);
    saida[0] = t;
    responde(1, &saida[0]);
    return;
}
