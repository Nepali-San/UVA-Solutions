#include <bits/stdc++.h>

#define pb(x)                        push_back(x)
#define ALLONS_Y                     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define mp							 make_pair

using namespace std;

int v;
vector<char> vc;
map<char,int> mvc;

void alltopo(vector<int> g[],vector<bool> &visited,vector<int> &indeg,vector<int> &ans){
	bool flag = false;
	for(int i = 0; i < v; i++){
		if(indeg[i] == 0 && !visited[i]){

			for(auto it : g[i]) indeg[it]--;
			visited[i] = true;
			ans.pb(i);

			alltopo(g,visited,indeg,ans);

			for(auto it : g[i]) indeg[it]++;
			visited[i] = false;
			ans.erase(ans.end()-1);

			flag = true;

		}	
	}

	if(!flag){

		if(ans.size() != v){
			cout << "NO" << endl;
			return;
		}
		
		for(int i = 0; i < ans.size(); i++){
			cout << vc[ans[i]];
		}
		cout << endl;
	}
}

int main() {
	ALLONS_Y;
	string line;
	
	int st = 0;
	while(getline(cin,line)){

		if(st != 0) cout << endl;
		st++;

		int i = 0; 
		while(i < line.size()){
			if(line[i] != ' ') vc.pb(line[i]);
			i++;
		}

		v = vc.size();

		vector<int> g[v];
		vector<int> indeg(v,0);

		sort(vc.begin(),vc.end());

		for(int i = 0; i < v; i++){
			mvc.insert(mp(vc[i],i));
		}
		
		getline(cin,line);
		i = 0;
		int src,dest;
		while(i < line.size()){
			char csrc,cdest;
			csrc = line[i];
			cdest = line[i+2];
			src = mvc[csrc]; dest = mvc[cdest];
			g[src].pb(dest);
			indeg[dest]++;
			i += 4;
		}
		
		vector<bool> visited(v,false);
		vector<int> ans;
		alltopo(g,visited,indeg,ans);
		vc.clear();
		mvc.clear();

	}
		
	return 0;
}

