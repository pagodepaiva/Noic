#include <iostream>

using namespace std;

int main(){
    int a, b;
	cin >> a >> b;
	
	int con = 0; 
	
	/*
	IMPORTANTE: Quando for iniciar um contador parecido com o do esse problema, sempre se
	lembre de iniciar o con com o valor 0, pois, se você não fizer isso, o compilador vai
	colocar um valor aleatório no con, dando valores absurdos pro seu problema.
	*/
	
	if(a < 18) con += 15;
	else if(a >= 60) con += 20;
	else con += 30;
	
	
	if(b < 18) con += 15;
	else if(b >= 60) con += 20;
	else con += 30;
	
	cout << con << "\n";
		
    return 0;
}
