//bicoloring problem using dfs approach...

#include <bits/stdc++.h>

#define ull                          unsigned long long int
#define ll                           long long int
#define endl                         '\n'
#define all(v)                       begin(v), end(v)
#define pb(x)                        push_back(x)
#define mp                           make_pair
#define ALLONS_Y                     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

bool dfs(int start,list<int> g[],int color[]){
	
	for(auto it = g[start].begin(); it != g[start].end(); it++){
		if(color[*it] == 1000){
			color[*it] = 1 - color[start];
			if(! dfs(*it,g,color)){
				return false;
			}
		}else if(color[*it] == color[start]){			
			return false;
		}
	}
	return true;
}

int main() {
	ALLONS_Y;
	
	int v,e;
	int src,dest;

	while(cin >> v){
	if(v == 0) break;

		cin >> e;
		list<int> g[v];	

		for(int i = 0; i < e; i++){			
			cin >> src >> dest;
			g[src].pb(dest);
			g[dest].pb(src);
		}

		int colors[v] = {1000};				//1000 represents no color, 0 & 1 represents any two colors.
		fill(colors,colors+v,1000);			//every vertex is uncolored.
		colors[0] = 0;						//source vertex has color - 0


		bool status = dfs(0,g,colors);

		if(!status){
			cout << "NOT BICOLORABLE." << endl;
		}else{
			cout << "BICOLORABLE." << endl;
		}
	}
		
	return 0;
}

