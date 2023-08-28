#include <bits/stdc++.h>
using namespace std;
 
const int LOG = 21;
const int MAX = 2e5 + 10;
 
// Implementacao de Seg com Lazy
// Possivel fazer com Seg/BIT + soma de prefixos

int n, m, fort[MAX], dp[MAX][LOG], resp[MAX];
int seg[4 * MAX], lzSum[4 * MAX];
 
vector<int> adj[MAX];
vector<pair<int, int>> reunioes[MAX];
 
void refresh(int p, int l, int r) // Atualizar o valor do no p
{
	if(lzSum[p] == 0) return;
	int add = lzSum[p]; lzSum[p] = 0;
 
	seg[p] += (r - l + 1) * add;
 
	if(l == r) return;
 
	int e = 2 * p, d = e + 1;
	lzSum[e] += add;
	lzSum[d] += add;
}
 
int query(int a, int b, int p, int l, int r) // Query no intervalo [a, b], no atual p de intervalo [l, r]
{
	refresh(p, l, r);
 
	if(a > r || b < l) return 0;
	if(a <= l && r <= b) return seg[p];
 
	int m = (l + r) >> 1, e = 2 * p, d = e + 1;
	return query(a, b, e, l, m) + query(a, b, d, m + 1, r);
}
 
void update(int a, int b, int x, int p, int l, int r) // Update de somar x no intervalo [a, b], no atual p e intervalo atual [l, r]
{
	refresh(p, l, r);
 
	if(a > r || b < l) return;
	if(a <= l && r <= b){
		lzSum[p] += x;
		refresh(p, l, r);
		return;
	}
 
	int m = (l + r) >> 1, e = 2 * p, d = e + 1;
	update(a, b, x, e, l, m); update(a, b, x, d, m + 1, r);
 
	seg[p] = seg[e] + seg[d];
}
 
void dfs(int u, int p)
{
	// Adiciono as reunioes do no u (somo 1 nos intervalos de fortunas)
	for(auto [e, d] : reunioes[u])
		update(e, d, 1, 1, 1, MAX);
 
	// Resposta do no atual eh o numero de festas que contem a sua fortuna
	resp[u] = query(fort[u], fort[u], 1, 1, MAX);
 
	for(auto v : adj[u])
		if(v != p) dfs(v, u);
 	
	// Retiro as reunioes do no u (subtrario 1 nos intervalos de fortunas)
	for(auto [e, d] : reunioes[u])
		update(e, d, -1, 1, 1, MAX);
}
 
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	cin >> n >> m;
 
	for(int i = 1; i <= n; i++){
		cin >> fort[i] >> dp[i][0];
 
		adj[i].push_back(dp[i][0]);
		adj[dp[i][0]].push_back(i);
	}
 	
	// Calculo a DP do binary lifting
	for(int j = 1; j < LOG; j++)
		for(int i = 1; i <= n; i++)
			dp[i][j] = dp[ dp[i][j - 1] ][j - 1];
 
	while(m--)
	{
		int u, l, r; cin >> u >> l >> r;
 		
		// Calculo o ancestral de maior fortuna para qual posso "mandar" a reuniao, T_i
		for(int j = LOG - 1; j >= 0; j--)
			if(dp[u][j] && fort[ dp[u][j] ] <= r) u = dp[u][j];
 		
		// Adiciono a reuniao ao no u
		reunioes[u].emplace_back(l, r);
	}
 
	dfs(1, 1);
 
	for(int i = 1; i <= n; i++)
		cout << resp[i] << ' ';
	cout << '\n';
}
