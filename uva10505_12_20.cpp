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

int c_0,c_1;
bool is_bipartite = true;
int no_of_people;

void dfs(int start,list<int> g[],int* color){

	for(auto it = g[start].begin(); it != g[start].end(); it++){
		if(color[*it] == 1000){

			if(is_bipartite)
				color[*it] = 1 - color[start];
			else color[*it] = 2;
						
			if(color[*it] == 0) 		c_0++;
			else if(color[*it] == 1)    c_1++;
			

			dfs(*it,g,color);
		}else if(color[*it] == color[start]){
			is_bipartite = false;
		}		
	}
}

int main() {
	ALLONS_Y;
	
	int TC,n,count_of_enemies,data,ans;

	cin >> TC;
	
	while(TC--){
		
		ans = 0;

		cin >> no_of_people;
		list<int> g[200];

		for(int i = 1; i <= no_of_people; i++){
			cin >> count_of_enemies;		
			while(count_of_enemies--){
				cin >> data;
				if(data > no_of_people+1) break;
				g[i].pb(data);
				g[data].pb(i);				
			}
		}
		
		
		int color[no_of_people+1];
		fill(color,color+no_of_people+1,1000);
		
		for(int src = 1; src <= no_of_people; src++){
			is_bipartite = true;
			if(color[src] == 1000){
				
				c_0 = 1; c_1 = 0;
				color[src] = 0;			
				
				dfs(src,g,color);
				if(!is_bipartite){
					ans += 1;
					break;
				}															

				ans += max(c_0,c_1);			
			}
		}

		cout << ans << endl;
	}
		
	return 0;
}

