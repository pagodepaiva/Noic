#include<bits/stdc++.h>
#define int long long 
#define pb push_back
#define pi pair <int,int>
#define itn int
#define N 100010
#define INF 1e16
 
/*
Meu template acima. Eu uso int = long long porque eu boto INF = 1e16, que passa do
limite de memoria do int. Também uso itn = int pelo meme.
*/

using namespace std;
 
int n, m;
vector <pi> g[N];
int dist[N][2]; // as duas respostas dos dois dijkstra. dist[i][0] retorna a do primeiro dijkstra, e dist[i][1] a do segundo
int mark[N];

main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
 
    for(int i =0;i < m;i++){
        int a, b, w;
        cin >> a >> b >> w;
        g[a].pb({b, w});
    }
 
    for(int i = 0;i <N;i++){ dist[i][0] = INF; dist[i][1] = INF;}
    dist[1][0] = 0;
    priority_queue <pi> pq;
    pq.push({0, 1});
 
    while(!pq.empty()){
        int v = pq.top().second; pq.pop();
 
        if(mark[v]) continue;
        mark[v] = 1;
 
        for(auto x : g[v]){
            if(dist[x.first][0] > dist[v][0] + x.second){
                dist[x.first][0] = dist[v][0] + x.second;
                pq.push({-dist[x.first][0], x.first});
            }
        }
    }
 
    priority_queue <pi> q;
    q.push({0, 1});
    memset(mark, 0, sizeof mark);
    dist[1][1] = 0;
 
    while(!q.empty()){
        int v = q.top().second; q.pop();
 
        if(mark[v] == 1) continue;
        mark[v] = 1;
 
        for(auto x : g[v]){
            if(dist[x.first][1] > dist[v][1] + x.second or dist[x.first][1] > dist[v][0] + x.second/2){
                dist[x.first][1] = min(dist[v][1] + x.second, dist[v][0] + x.second/2);
                q.push({-dist[x.first][1], x.first});
            }
        }
    }  
 
    cout << dist[n][1] << "\n";
 
    return 0;
}
