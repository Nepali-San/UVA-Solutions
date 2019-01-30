#include <bits/stdc++.h>

#define pb(x)  push_back(x)

using namespace std;

int colors[220];
vector<int> g[220];
vector<int> cnt(2,0);
bool bad = false;
int src,dest;

void dfs(int src, int clr){

	colors[src] = clr;

	cnt[clr]++;

	for(auto it:g[src]){
		if(colors[it] == -1){
			dfs(it,1-clr);
		}
		else if(colors[it]^colors[src] == 0){
			bad = true;
			return;
		}
	}
}

int main() {
	
	int T;
	scanf("%d",&T);	

	while(T--){
		int v,e;

		scanf("%d%d",&v,&e);

		for(int i = 0; i < e; i++){
			scanf("%d%d",&src,&dest);
			g[src].pb(dest);
			g[dest].pb(src);
		}
	
		for(int i = 0; i < v; i++) colors[i] = -1;
		
		int ans = 0;

		for(int src = 0; src < v; src++){
			
			cnt[0] = cnt[1] = 0;

			if(colors[src] != -1) continue;

			dfs(src,0);

			if(bad){
				puts("-1");
				break;
			}


			if(cnt[0] == 1 && cnt[1] == 0) ans += 1;
			else
			ans += min(cnt[0],cnt[1]);
		
		}

		if(!bad) printf("%d\n",ans);

		for(int i = 0; i < v; i++) g[i].clear();

		bad = false;

	}
		
	return 0;
}
