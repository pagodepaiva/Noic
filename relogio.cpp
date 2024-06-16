#include<bits/stdc++.h>

using namespace std;

int main(){
    int h, m, s;
    cin >> h >> m >> s;
    int t;
    cin >> t;
    s += t;
    while(s >= 60){
        m++;
        s -= 60;
    }
    while(m >= 60){
        h++;
        m -= 60;
    }
    h %= 24;
    cout << h << '\n' << m << '\n' << s << '\n';
}
