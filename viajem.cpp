// código de Endy Miyashita
#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e5+10;

int n, q, k, frutas[MAXN][70], pai[MAXN], h[MAXN], anc[MAXN][20], mark[MAXN], f[70];
vector <int> g[MAXN];

void init(int t, int ca){

	mark[t]=1;

	for(int i=0 ; i<g[t].size() ; i++){
		int filho = g[t][i];

		if(mark[filho] == 0){
			pai[filho] = t;
			anc[filho][0] = t;
			h[filho] = h[t]+1;

			for(int j=1 ; j<=ca ; j++) frutas[filho][j] += frutas[t][j]; // c[filho][j] já tá inicializado em frutas[filho][j]

			init(filho, ca);
		}
	}

	return;
}

int lca(int x, int y){

	if(h[x] > h[y]) swap(x, y); // x sempre tera menor altura

	for(int i=19 ; i>=0 ; i--){
		if(h[y] - (1 << i) >= h[x]) y = anc[y][i];
	}

	if(x == y) return x;

	for(int i=19 ; i>=0 ; i--){

		if(anc[x][i] != anc[y][i]){
			x = anc[x][i];
			y = anc[y][i];
		}
	}

	return pai[x];
}

int main(){

	ios::sync_with_stdio(false); cin.tie(0);

	cin >> n >> k;

	for(int i=0 ; i<n-1 ; i++){

		int a, b;
		cin >> a >>b;

		g[a].push_back(b);
		g[b].push_back(a);
	}

	for(int i=1 ; i<=n ; i++){
		for(int j=1 ; j<=k ; j++) cin >> frutas[i][j];
	}
	
	pai[1]=1;
	anc[1][0]=1;
	h[1]=1;
	init(1, k);

	for(int i=1 ; i<20 ; i++){
		for(int j=1 ; j<=n ; j++) anc[j][i] = anc[anc[j][i-1]][i-1];
	}

	cin >> q;

	for(int i=0 ; i<q ; i++){

		int a, b;
		cin >> a >> b;
		
		int lowest_anc = lca(a, b);

		int ans=0;

		for(int i=1 ; i<=k ; i++){
			if(lowest_anc == 1) f[i] = frutas[a][i]+frutas[b][i]-frutas[lowest_anc][i];
			else f[i] = frutas[a][i]+frutas[b][i]-frutas[lowest_anc][i]-frutas[pai[lowest_anc]][i]; // veja que frutas[pai[l]][f] + c[l][f] = frutas[l][f], ai a fórmula difere um pouco do que tá no comentário
			if(f[i]%2 == 1) ans++;
		}

		cout << ans << endl;
	}

	return 0;
}
