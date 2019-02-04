#include <bits/stdc++.h>

#define endl                         '\n'
#define pb(x)                        push_back(x)
#define ALLONS_Y                     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

int main() {
	ALLONS_Y;
	
	int v,e;
	cin >> v >> e;
	
	int src,dest;
	vector<int> g[v];
	vector<int> indeg(v,0);

	while(e--){
		cin >> src >> dest;
		g[src].pb(dest);
		indeg[dest]++;
	}


	queue<int> q;
	for(int i = 0; i < v; i++){
		if(indeg[i] == 0){
			q.push(i);
		}
	}

	while(!q.empty()){
		int src = q.front();
		q.pop();
		
		cout << src << " ";
		for(auto it : g[src]){
			indeg[it]--;
			if(indeg[it] == 0) q.push(it);
		}
	}

	cout << endl;
		
	return 0;
}

