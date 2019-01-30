#include <bits/stdc++.h>

using namespace std;

int x[] = {1,-1, 0,0,-1,1,-1, 1 };
int y[] = {0, 0,-1,1,-1,1, 1,-1 };

int t;

bool isValid(int x,int y){
	if(x >= 0 && x < t && y >= 0 && y < t) return true;
	return false;
}

void dfs(int i,int j,vector<vector<bool> > &visited,string s[]){
	visited[i][j] = true;

	for(int k = 0; k < 8; k++){
		int x_pos = i+x[k]; int y_pos = j+y[k];

		if(!isValid(x_pos,y_pos)) continue;

		if(!visited[x_pos][y_pos] && s[x_pos][y_pos] == '1'){
			dfs(x_pos,y_pos,visited,s);		
		} 
	}	
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int i = 0;

	while(cin >> t){
		
		i++;

		string s[t];

		for(int i = 0; i < t; i++){
			cin >> s[i];
		}

		vector< vector<bool> > visited(t,vector<bool>(t,false));
		
		int ans = 0;
		for(int i = 0; i < t; i++){
			for(int j = 0; j < t; j++){

				if(!visited[i][j] && s[i][j] == '1'){					
					 dfs(i,j,visited,s);
					 ans++;
				}

			}
		}

		cout << "Image number " << i << " contains " << ans << " war eagles.\n";

	}
	return 0;
}

