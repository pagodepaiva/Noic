#include<bits/stdc++.h>

using namespace std;

int main(){
	int con;
	int n;
	cin >> n;
	con = 0;

	for(int i = 0;i < n;i++){
		int a, b;
		cin >> a >> b;

		if(a == 0 and b == 1) con++;
	}

	cout << n-con << "\n";
	return 0;
}
