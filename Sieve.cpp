#include <bits/stdc++.h>
using namespace std;

int main() {
	int n = (int)1e6;
	vector<char> is_prime(n+1, true);
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i <= n; i++) {
		if (is_prime[i] && (long long)i * i <= n) {
			for (int j = i * i; j <= n; j += i)
				is_prime[j] = false;
		}
	}
	
	int a;
	
	while(cin >> a){
		if(is_prime[a]){
			cout << "es" << endl;
		}else{
			cout << "no es" << endl;
		}
	}
	
	
	return 0;
}
