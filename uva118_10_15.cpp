#include <bits/stdc++.h>

#define endl                         '\n'
#define pb(x)                        push_back(x)
#define mp                           make_pair
#define ALLONS_Y                     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

char orient[] = {'N','E','S','W'};
int xd[] = {0, 1, 0,-1};
int yd[] = {1, 0,-1, 0};

inline bool checkLost(int x,int y , int w ,int l){
	if(x == -1 || x == l+1 || y == -1 || y == w+1) return true;	
	return false;
}

int main() {
	ALLONS_Y;
	
	int mx,my;
	cin >> mx >> my;

	int rx,ry,fn;
	char face;
	set<pair<int,int> > safed;

	bool isLost;
	int isSafe;

	while(cin >> rx >> ry >> face){
		
		isLost = false;		
		isSafe = 0;

		for(int i = 0; i < 4; i++) 
			if(face == orient[i]){
				 fn = i;
				 break;
			}

		string input;
		cin >> input;

		for(int i = 0; i < input.size(); i++){
			if(input[i] == 'L'){				
				fn = (fn-1);
				if(fn < 0) fn = 3;
			}else if(input[i] == 'R'){
				fn = (fn+1)%4;
			}else{
				isLost = checkLost(rx+xd[fn],ry+yd[fn],my,mx);
				if(isLost){
					isSafe = safed.count(mp(rx,ry));					
					if(!isSafe){											
						safed.insert(mp(rx,ry));
						cout << rx << " " << ry << " " << orient[fn] << " LOST" << endl;					
						break;
					}
					isLost = false;
				}else{					
					rx += xd[fn];
					ry += yd[fn];					
				}				
			}			
		}
		if(!isLost) cout << rx << " " << ry << " " << orient[fn] << endl;		
	}		
	return 0;
}