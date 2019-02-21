#include <bits/stdc++.h>

#define endl                         '\n'
#define pb(x)                        push_back(x)
#define ALLONS_Y                     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

int T,n,x,y;
vector<int> g[200];
int col[2];
vector<int> color;
bool bad = false;

void bipartite(int src ,int c){

	if(src < n){
		color[src] = c;
		col[c]++;	

		for(auto it : g[src]){
			if(color[it] == -1){	
				bipartite(it,1-c);					
			}else if(color[it] == color[src]){
				bad = true;	
			}
		}
	}
}

int main() {
	ALLONS_Y;
	
	cin >> T;
	while(T--){
		
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> x;
			while(x--){
				cin >> y;
				y--;
				g[i].pb(y);
				g[y].pb(i);
			}
		}
	
		for(int i = 0; i < 200; i++) color.pb(-1);
				
		int ans = 0;
		for(int i = 0; i < n; i++){
			if(color[i] != -1) continue;
			
			col[0] = col[1] = 0;

			bipartite(i,0);
			
			if(!bad)
				ans += max(col[0],col[1]);
			else bad = false;

		}		

		cout << ans << endl;
		
		for(int i = 0; i < 200; i++) g[i].clear();
		color.clear();
	}
			
	return 0;
}

