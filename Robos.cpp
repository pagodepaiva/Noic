#include<bits/stdc++.h>
#define N 100010
using namespace std;
const int maxn = 1e5 + 5;

int n, m, ini, fim, k, l;
set <int> linhas[N], colunas[N];

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) linhas[i].insert(0), linhas[i].insert(m+1);
    for(int i = 1; i <= m; i++) colunas[i].insert(0), colunas[i].insert(n+1);

    cin >> ini >> fim;
    cin >> k >> l;

    for(int i = 0; i < k; i++){
        int x, y; cin >> x >> y;
        linhas[x].insert(y);
        colunas[y].insert(x);
    }

    for(int i = 0, d=0; i < l; i++, d = (d+1)%4){
        // cout << "penis" << endl;
        if(d==0){
            //direita
            fim = *linhas[ini].lower_bound(fim);
            fim--;
        }
        if(d==1){
            //baixo
            ini = *colunas[fim].lower_bound(ini);
            ini--;
        }
        if(d==2){
            //esquerda
            fim = *prev(linhas[ini].lower_bound(fim));
            fim++;
        }
        if(d==3){
            //cima
            ini = *prev(colunas[fim].lower_bound(ini));
            ini++;
        }
    }

    cout << ini << " " << fim << "\n";

    return 0;
}
