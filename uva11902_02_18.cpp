#include <bits/stdc++.h>

#define endl                         '\n'
#define pb(x)                        push_back(x)
#define ALLONS_Y                     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;
vector<bool> visited;
vector<bool> reachable;

void dfs(vector<int> g[],int src){
	visited[src] = true;
	for(auto it : g[src]){
		if(!visited[it]){
			dfs(g,it);
		}
	}
}

void dfs2(vector<int> g[],int src,int i){
		
	if(i == src){
		return;
	}else		
		reachable[src] = true;

	for(auto it : g[src]){
		if(!reachable[it] && it != i && visited[it]){
			dfs2(g,it,i);		
		}
	}
}

int main() {
	ALLONS_Y;
	
	int t;
	cin >> t;
	for(int cas = 0; cas < t; cas++){
		int n;
		cin >> n;
		int x;

		vector<int> g[n];

		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> x;
				if(x == 1){
					g[i].pb(j);
				}
			}
		}

		for(int i = 0; i < n; i++) visited.pb(false);
		dfs(g,0);

		string sep = "+";
		for(int i = 0; i < 2*n-1; i++) sep +=  "-";
		sep += "+";
		
		cout << "Case " << cas+1 << ":" << endl;

		for(int i = 0; i < n; i++){		

			cout << sep << endl;

			for(int k = 0; k < n; k++) reachable.pb(false);

			dfs2(g,0,i);

			for(int j = 0; j < n; j++){
				cout << "|";				
				(reachable[j] == 0 && visited[j] == 1) ? cout << "Y" : cout << "N";
			}
			cout << "|" << endl;	
			reachable.clear();
		}			
		cout << sep << endl;
		visited.clear();
	}	
		
	return 0;
}

