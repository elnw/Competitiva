#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,m,x,y;
	
	while(cin >> n >> m){
		unordered_map<int,vector<int>> grafo;
		y=1;
		while(n--){
			cin >> x;
			if(grafo.find(x) != grafo.end()){
				grafo[x].push_back(y);
			}else{
				grafo[x] = vector<int>();
				grafo[x].push_back(y);
			}
			y++;
		}
		
		while(m--){
			cin >> x >> y;
			if(grafo[y].size() < x){
				cout << 0 << endl;
			}else{
				cout << grafo[y][x-1] << endl;
			}
		}
		
		
	}
	return 0;
}