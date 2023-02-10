#include <iostream>

using namespace std;

int main(){
    int a, b;
	cin >> a >> b;
	
	int con = 0;
	
	if(a < 18) con += 15;
	else if(a >= 60) con += 20;
	else con += 30;
	
	
	if(b < 18) con += 15;
	else if(b >= 60) con += 20;
	else con += 30;
	
	cout << con << "\n";
		
    return 0;
}
