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

int main() {
	ALLONS_Y;
	
	int v,e,src,dest;

	while(cin >> v){
		if(v == 0) break;

		cin >> e; 

		list<int> g[v];
		for(int i = 0; i < e; i++){
			cin >> src >> dest;
			g[src].pb(dest);
			g[dest].pb(src);
		}

		int color[v];
		fill(color,color+v,1000);
		color[0] = 0;

		bool is_bipartite = true;
		queue<int> Q;
		Q.push(0);

		while(!Q.empty() && is_bipartite){
			int top = Q.front();
			Q.pop();

			for(auto it = g[top].begin(); it != g[top].end(); it++){
				
				if(color[*it] == 1000){
					color[*it] = 1 - color[top];
					Q.push(*it);
				}else if(color[*it] == color[top]){
					is_bipartite = false;
					break;
				}
			}
		}

		if(is_bipartite){
			cout << "BICOLORABLE." << endl;
		}else cout << "NOT BICOLORABLE."  << endl;
	}
		
	return 0;
}

