#include <bits/stdc++.h>

#define endl                         '\n'
#define pb(x)                        push_back(x)
#define mp                           make_pair
#define ALLONS_Y                     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

bool comp(pair<int,int> &a, pair<int,int> &b){
	return a.second > b.second;
}

int main() {
	
	int n,r;
	while(cin >> n >> r){		
		
		cout << " Start " << endl;
		cout << " -------------------------------------" << endl << endl;
		if(n == 0 && r == 0) break;

		int series = 2,sum = 0;		
		vector<pair<int,int> > cost(n+1);    			//node , cost	

		vector<int> parent(n+1,-1);
		vector<int> cost_only(n+1,-100);

		cost[0] = mp(0,-100);

		for(int i = 1; i <= n; i++){
			int a;
			cin >> a;
			cost[i] = mp(i,a);
			cost_only[i] = a;
			if( i == r) sum = a;
		}

		for(int i = 1; i < n; i++){
			int src, dest;
			cin >> src >> dest;
			parent[dest] = src;
		}

		bool visited[n+1] = {false};
		visited[r] = true;	
		visited[0] = true;

		sort(cost.begin(),cost.end(),comp);
		
		cout << "After sorting" << endl;
		for(int i = 0; i <= n; i++){
			cout << cost[i].first << " " << cost[i].second << endl;
		}

		stack<int> Q;
		
		int i = 0;
		cout << " sum  = " << sum << endl;

		while(i < n){											

			while(visited[cost[i].first]){
				cout << cost[i].first << " already processed " << endl;
				i++;
			}			
	
			int ch =  cost[i].first;
			int m  =  cost[i].second;						
			cout << " i choose " << ch << " with cost " << m << endl;
			i++;
				
			Q.push(m);
			cout << " i push " << m << endl;
			visited[ch] = true;

			while(!visited[parent[ch]]){										
				Q.push(cost_only[parent[ch]]);	
				cout << " i push " << cost_only[parent[ch]] << endl;
				visited[parent[ch] ] = true;
				ch = parent[ch];							
			}		

			while(!Q.empty()){
				int top = Q.top();
				Q.pop();											   
				sum += series * top;
				cout << " add " << series << " * " << top << " = " << series*top << endl;
				series++;
			}
		
		}
		cout << sum << endl;
	}
			
	return 0;
}
