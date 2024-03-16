int vencedorPartida(int a, int b);
int numeroVitorias(int competidor);
void responde(int tamanho, int array[]);

int saida[101];
int m[101][101];

void processaTorneio(int s, int n) {
    int tamanho = n; // Tamanho do array a retornar
    for(int i = 1;i <= n;i++){
        for(int j = i+1;j <= n;j++){
            int x = vencedorPartida(i,j);
            if(x == i) m[i][j] = 1;
            else m[i][j] = 0;
            m[j][i] = m[i][j]^1;
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            saida[i] += m[i][j];
        }
    }
    responde(tamanho, &saida[1]);
}
