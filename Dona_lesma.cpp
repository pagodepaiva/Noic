#include <iostream>

using namespace std;

int main(){
	int A, D, S;
	
	cin >> A >> S >> D;
	
	int altura = 0, dia = 0;
	
	while(true){
		altura += S;
		dia++;
		if(altura >= A) break;
		altura -= D;
	}
	
	cout << dia << "\n";
	
    return 0;
}
