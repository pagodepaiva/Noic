#include<bits/stdc++.h>

using namespace std;

int vencedorPartida(int a, int b);
int numeroVitorias(int competidor);
void responde(int tamanho, int array[]);

int saida[1001];

int query(int a, int b){
    return vencedorPartida(a, b);
}

void mergesort(vector <int> &v){
    if(v.size() <= 1) return;

    vector <int> a;
    vector <int> b;

    int t = v.size();
    t = t/2;

    for(int i = 0;i < t;i++){
        a.push_back(v[i]);
    }

    for(int i = t; i < v.size();i++){
        b.push_back(v[i]);
    }

    mergesort(a);
    mergesort(b);
    v.clear();

    int l = 0, r = 0;

    while(l < a.size() or r < b.size()){
        if(l == a.size()){
            while(r < b.size()){
                v.push_back(b[r]);
                r++;
            }
            break;
        }

        else if(r == b.size()){
            swap(l, r);
            swap(a, b);
            continue;
        }

        if(query(a[l], b[r]) == a[l]){
            v.push_back(b[r]);
            r++;
        }
        else{
            v.push_back(a[l]);
            l++;
        }
    }

    return;
}

void processaTorneio(int S, int n) {
    vector <int> resp;

    for(int i = 1;i <= n;i++){
        resp.push_back(i);
    }

    mergesort(resp);

    for(int i = 0;i < n;i++){
        saida[resp[i]-1] = i;
    }

    responde(n,&saida[0]);
    return;
}
