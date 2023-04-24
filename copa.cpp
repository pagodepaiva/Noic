#include<bits/stdc++.h>

using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
	
	a--;
	b--;

    int x = a/8, y = b/8;

    if(x != y){
        cout << "final\n";
        return 0;
    }

    if(x > 0){
        a -= 8;
        b -= 8;
    }

    x = a/4;
    y = b/4;

    if(x != y){
        cout << "semifinal\n";
        return 0;
    }

    if(x > 0){
        a -= 4;
        b -= 4;
    }

    x = a/2;
    y = b/2;


    if(x != y){
        cout << "quartas\n";
    }

    else{
        cout << "oitavas\n";
    }

    return 0;
}
