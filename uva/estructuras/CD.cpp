#include<bits/stdc++.h>

using namespace std;

int main(){
	int n,m,x;
	
	while(cin >> n >> m){
		unordered_map<int,int> discos;
		while(n--){
			discos[x]++;
		}
		
		while(m--){
			discos[x]++;
		}
		
		x=0;
		for(auto v: discos){
			if(v.second == 2)x++;
		}
		
		cout << x << endl;
	}
	
	return 0;
}