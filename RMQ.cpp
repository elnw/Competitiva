#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

#define FORN( i , s , n ) for( int i = (s) ; i < (n) ; i++ )
#define FOR( i , n ) FORN( i , 0 , n )
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define sz size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define clr(a, v) memset( a , v , sizeof(a) )
#define FORIT( i , x ) for( typeof x.begin() i = x.begin() ; i != x.end() ; i++ )
#define trace(x)    cout << #x << ": " << x << endl;
#define trace2(x, y) cout << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define read ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;
using namespace __gnu_pbds;

typedef long long int64;
typedef vector <int> vi;
typedef pair <int,int> ii;
typedef vector <string> vs;
typedef vector <ii> vii;

const int MAX = 1000005, LN = 21;

int Log2[MAX];

void prelog2(){
	for( int i = 1, k = 0; i < MAX; i++ )
		Log2[i] = k = k + ( 1<<(k+1) == i );
}

struct RMQ{
	int64 a[MAX], p[LN][MAX];

	void init( int n, int64 b[MAX]){
		for(int i=0;i<n;i++){
			a[i] = b[i];
		}
		int ln = Log2[n], i1, i2;
		FOR( i , n ) p[0][i] = i;
		FORN( i , 1 , ln+1 ){
			FOR( j , n - (1<<i) + 1 ){
				i1 = p[i-1][j];
				i2 = p[i-1][ j + (1<<(i-1)) ];
				p[i][j] = a[i1] <= a[i2] ? i1 : i2;
			}
		}
	}

	int64 rmq( int i , int j ){
		int k = Log2[j-i+1];
		int i1 = p[k][i], i2 = p[k][j-(1<<k)+1];
		return min( a[i1], a[i2] );
	}
};

RMQ dir, inv;
int64 a[MAX], acum_dir[MAX], acum_inv[MAX];

int main(){
	int  n,index; 
	long long v;
	string orden;
	prelog2();
	while(cin >> n){
		index=-1;
		for(int i=0;i<n;i++){
			
		cin >> orden;
		if(orden == "PUSH"){
			cin >> v;
			index++;
			a[index]=v;
		
		}else{
			if(orden == "MIN"){
				dir.init(n,a);
				cout << dir.rmq(0,index) << endl;
			}else{
				index--;
			}
			
		
		}
		
	}
	
	}

		
	
	return 0;
}