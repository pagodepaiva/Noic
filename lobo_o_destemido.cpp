    #include<bits/stdc++.h>
    #define N 3010
    #define int long long
     
    using namespace std;
     
    int n, m;
    char c[N][N];
    int dir[N][N], bai[N][N];
     
    int32_t main(){
        cin >> n >> m;
     
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                cin >> c[i][j];
            }
        }
     
        for(int i = 1;i <= n;i++){
            for(int j = m;j > 0;j--){
                dir[i][j] = dir[i][j+1] + (c[i][j] == 'O' ? 1 : 0);
            }
        }
     
        for(int j = 1;j <= m;j++){
            for(int i = n;i > 0;i--){
                bai[i][j] = bai[i+1][j] + (c[i][j] == 'I' ? 1 : 0);
            }
        }
     
        int res = 0;
     
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                if(c[i][j] == 'J'){
                    res += dir[i][j]*bai[i][j];
                }
            }
        }
     
        cout << res << "\n";
     
        return 0;
    }
