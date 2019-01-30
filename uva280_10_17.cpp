#include <bits/stdc++.h>

#define ull                          unsigned long long int
#define ll                           long long int
#define endl                         '\n'
#define all(v)                       begin(v), end(v)
#define pb(x)                        push_back(x)
#define mp                           make_pair
#define ALLONS_Y                     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define contains(container, value)   container.find(value) != container.end()
#define rep(i,a,b)                   for(int i  = a; i < b; i++)

using namespace std;

int c = 0;
void find(vector<int> v[], int start,bool visited[]){
	for(auto it = v[start].begin(); it != v[start].end(); it++){		
		if(!visited[*it]){		
			visited[*it] = true;
			c++;
			find(v,*it,visited);		
		}
	}
}

int main() {
	ALLONS_Y;
	int n,num,a,b;	

	while(cin >> n){	
		if( n == 0){
			break;
		}

		vector<int> v[n+1];

		while(cin >> a){
			if(a == 0) break;

			while(cin >> b){		
				if(b == 0) break;

				v[a].pb(b);
			}
		}

		int t;		
		cin >> t;
		while(t--){			
			cin >> num;
		
			bool visited[n+1] = {false};

			find(v,num,visited);
 
			cout << n - c;

			for(int i = 1; i <= n; i++){
				if(!visited[i])
					cout << " " << i;
			}
			cout << endl;
			c = 0;		
		}		
	}	
	return 0;
}
