#include <bits/stdc++.h>

#define endl                         '\n'
#define pb(x)                        push_back(x)
#define mp                           make_pair
#define ALLONS_Y                     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

char orient[] = {'N','E','S','W'};
int xd[] = {0, 1, 0,-1};
int yd[] = {1, 0,-1, 0};

bool isLost(int x,int y,int bx,int by){
	if(x >= 0 && x <= bx && y >= 0 && y <= by) return false;
	return true;
}

int main() {
	ALLONS_Y;
	
	int x,y;
	cin >> x >> y;

	int c_x,c_y; char c_o;
	string s;
	int pos;
	set<pair<int,int> > st;

	while(cin >> c_x >> c_y >> c_o){
	
		if(c_o == 'N')       pos = 0;
		else if(c_o == 'E')  pos = 1;
		else if(c_o == 'S')  pos = 2;
		else                 pos = 3;
		
		bool lost = false;
		int safe = 0;

		cin >> s;
		for(int i= 0; i < s.size(); i++){
			if(s[i] == 'L'){
				pos--;
				if(pos < 0) pos = 3;			
			}else if(s[i] == 'R'){
				pos = (pos + 1) % 4;
			}else{	
				lost = isLost(c_x+xd[pos],c_y+yd[pos],x,y);
				safe = st.count(mp(c_x,c_y));

				if(lost){

					if(safe){																
						lost = false;
						continue;
					}

					st.insert(mp(c_x,c_y));
					cout << c_x << " " << c_y << " " << orient[pos]  << " LOST" << endl;			
					break;
				}		
							
				c_x += xd[pos];
				c_y += yd[pos];
			}		
		}
		if(lost) continue;	
		cout << c_x << " " << c_y << " " << orient[pos] << endl;
	}

	return 0;
}
