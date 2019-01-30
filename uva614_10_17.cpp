#include <bits/stdc++.h>

#define endl                         '\n'
#define pb(x)                        push_back(x)
#define mp                           make_pair
#define ALLONS_Y                     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

int yd[] = {-1,  0, 1, 0};
int xd[] = {0 , -1, 0, 1};

bool found;
int m,n;

bool isValid(int x,int y){
	if( x >= 0 && x < m && y >= 0 && y < n) return true;
	return false;
}

void find_path(vector<vector<int> > &maze, int x,int y, int sx,int sy, int ex,int ey,vector< vector<bool> > &visited,int c,vector<vector<int> > &m2){

	visited[x][y] = true;

	if(x == ex && y == ey){	
		found = true;	
		m2[x][y] = c;
		return;
	}

	for(int i = 0; i < 4; i++){

		if(isValid(x+xd[i],y+yd[i]) && !visited[x+xd[i]][y+yd[i]] && !found){
			
			//conditions to check for possible walls in all 4 directions...
			if(i == 0 && (maze[x+xd[i]][y+yd[i]] == 1 || maze[x+xd[i]][y+yd[i]] == 3)) continue;
			if(i == 1 && (maze[x+xd[i]][y+yd[i]] == 2 || maze[x+xd[i]][y+yd[i]] == 3)) continue; 
			if(i == 2 && (maze[x][y] == 1 || maze[x][y] == 3)) continue; 
			if(i == 3 && (maze[x][y] == 2 || maze[x][y] == 3)) continue; 
					
			find_path(maze,x+xd[i],y+yd[i],sx,sy,ex,ey,visited,c+1,m2);
		}		
	}

	if(found){
		m2[x][y] = c;
	}
	
}

int main() {
	ALLONS_Y;
	
	int sx,sy,ex,ey;
	int maze_no = 1;
	while(cin >> m >> n >> sx >> sy >> ex >> ey){

		found = false;
		if(m+n+sx+sy+ex+ey == 0) break;

		cout << "Maze " << maze_no << endl << endl;
		maze_no++;
		
		vector< vector<int> > maze(m,vector<int> (n));
		vector< vector<bool> > visited(m,vector<bool> (n,false));

		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				cin >> maze[i][j];
			}
		}
		
		vector< vector < int > > m2(m,vector<int> (n,-1));
		int c = 1;

		sx--;
		sy--;
		ex--;
		ey--;

		find_path(maze,sx,sy,sx,sy,ex,ey,visited,c,m2);
		
		string s = "+";
		for(int i = 0; i < n; i++){
			s += "---+";
		}
		
		cout << s << endl;

		for(int i = 0; i < m; i++){
			
			cout << "|";

			for(int j = 0; j < n; j++){			

				if(m2[i][j] == -1){
					if(visited[i][j]){
						cout << "???";
					}
					else cout << "   ";
				}
				else cout << setw(3) <<  right << m2[i][j];
				
				if(j != n-1 && (maze[i][j] == 1 || maze[i][j] == 3)) cout << "|";
				else if( j != n-1) cout << " ";

				if(j == n-1) cout << "|" << endl;	

			}
				
			if(i != m-1){
				cout << "+";
				for(int k = 0; k < n; k++){			
					if(maze[i][k] == 2 || maze[i][k] == 3) cout << "---+";
					else cout << "   +";
				}
				cout << endl;
			}

		}
		cout << s << endl;
		cout << endl << endl;
	}
		
	return 0;
}
