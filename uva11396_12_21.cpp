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

bool is_bip = true;

void is_bipartite(int src,list<int> g[],int colors[]){
	for(auto it = g[src].begin(); it != g[src].end(); it++){
		if(colors[*it] == -1){
			colors[*it] = 1 - colors[src];
			is_bipartite(*it,g,colors);
		}else if(colors[*it] == colors[src]){
			is_bip = false;
			return;
		}
	}	
}

int main() {
	ALLONS_Y;
	
	int v,src,dest;
	
	while(cin >> v){
		if(v == 0) break;

		list<int> g[v];
	
		while(cin >> src >> dest){
			if(src + dest == 0) break;

			g[src-1].pb(dest-1);
			g[dest-1].pb(src-1);
		}
		
		int colors[v];
		fill(colors,colors+v,-1);
		
		bool status;
		is_bip = true;
		for(int src = 0; src < v; src++){			
			if(colors[src] == -1){
				colors[src] = 0;

				is_bipartite(src,g,colors);
				status = is_bip;

			}
			if(!status) break;
		}

		if(status){
			  cout << "YES" << endl;
		}else cout << "NO" << endl;

	}

	return 0;
}

