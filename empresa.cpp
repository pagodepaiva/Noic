#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<int> salario;
vector<int> chefe;
vector<int> insatisfacoes;

int f;

void dfs(int i) {
    for (auto u : adj[i]) {
        if (u == chefe[i]) continue;
        if (salario[u] > salario[i]) {
            if (insatisfacoes[i] == 0) f++;
            insatisfacoes[i]++;
        }
        dfs(u);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a;
    cin >> n;
    adj.resize(n+1);
    salario.resize(n+1);
    chefe.resize(n+1);
    insatisfacoes.resize(n+1);

    for (int i = 1; i <= n; i++) {
        cin >> chefe[i] >> salario[i];
        adj[chefe[i]].push_back(i);
    }

    dfs(1);
    cout << f << "\n";
    cin >> a;
    while (a--) {
        int i, novoSalario;
        cin >> i >> novoSalario;
        if (i != 1) {
            if ((salario[chefe[i]] >= salario[i]) and (novoSalario > salario[chefe[i]])) {
                insatisfacoes[chefe[i]]++;
                if (insatisfacoes[chefe[i]] == 1) f++;
            }
            else if ((salario[i] > salario[chefe[i]]) and (salario[chefe[i]] >= novoSalario)) {
                insatisfacoes[chefe[i]]--;
                if (insatisfacoes[chefe[i]] == 0) f--;
            }
        }
        for (auto u : adj[i]) {
            if ((salario[i] >= salario[u]) and (salario[u] > novoSalario)) {
                insatisfacoes[i]++;
                if (insatisfacoes[i] == 1) f++;
            }
            else if ((salario[u] > salario[i]) and (novoSalario >= salario[u])) {
                insatisfacoes[i]--;
                if (insatisfacoes[i] == 0) f--;
            }
        }
        cout << f << "\n";
        salario[i] = novoSalario;
    }
}
