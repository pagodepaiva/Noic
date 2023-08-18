#include<bits/stdc++.h>

using namespace std;

int main(){
	int n, m, p;
	cin >> n >> m >> p;

	int v[n+1][m+1];

	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cin >> v[i][j];
		}
	}

	int l = 0, e = 0;
	// int con = 0;

	for(int i = 0;i < p;i++){
		int a, b;
		cin >> a >> b;

		for(int x = 1;x <= n;x++){
			if(i % 2 == 0) e += v[x][b];
			else l += v[x][b];
			v[x][b] = 0;
		}

		for(int x = 1;x <= m;x++){
			if(i % 2 == 0) e += v[a][x];
			else l += v[a][x];
			v[a][x] = 0;
		}
	}

	if(e > l){
		cout << "Enzo\n";
	}

	else if(e < l){
		cout << "Lobo\n";
	}

	else{
		cout << "Empate\n";
	}

	return 0;
}
