#include <bits/stdc++.h>

using namespace std;

bool Compare(pair<int,int> a, pair<int,int> b){
	if(a.second == b.second){
		return a.first > b.first;	
	}else{
		return a.second > b.second;
	}
}

int main(){
	priority_queue<pair<int,int>, vector<pair<int,int>>, function<bool(pair<int,int>,pair<int,int>)>> argus(Compare);
	unordered_map<int,int> control;
	string s;
	int x,y,z;
	while(cin >> s){
		if(s!= "#")cin >> x >> y;
		else break;
		argus.push(make_pair(x,y));
		control[x] = y;
	}
	cin >> z;
	pair<int,int> dum;
	while(z--){
		dum = argus.top();
		cout << dum.first << endl;
		argus.pop();
		dum.second+=control[dum.first];
		argus.push(dum);
	}
	
	return 0;
}
