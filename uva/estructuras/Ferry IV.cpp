#include <bits/stdc++.h>
#define debug cout << "a" << endl;
using namespace std;

int main(){
	int c,l,m,x,ll;
	string dir;
	cin >> c;
	
	while(c--){
		queue<int> izq,der;
		cin >> l >> m;
		l*=100;
		while(m--){
			cin >> x >> dir;
			if(dir=="left"){
				izq.push(x);
			}else{
				der.push(x);
			}
		}
		x=0;
		
		while(!izq.empty() || !der.empty()){
			if(!izq.empty()){
				x++;
				ll=l;
				while(ll>=0 && !izq.empty()){
					if(ll-izq.front() >=0){
						ll-=izq.front();
						izq.pop();
					}else{
						break;
					}
				}
				
			}else{
				if(!der.empty())x++;
			}
			
			if(!der.empty()){
				x++;
				ll=l;
				while(ll>=0 && !der.empty()){
					if(ll-der.front() >= 0){
						ll-=der.front();
						der.pop();
					}else{
						break;
					}
				}
				
			}else{
				if(!izq.empty())x++;
			}

		}
		
		cout << x << endl;
		
		
	}
	return 0;
}