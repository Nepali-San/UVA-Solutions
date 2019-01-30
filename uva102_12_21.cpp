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

int main() {
	ALLONS_Y;
	
	ull arr[9];

	while(cin >> arr[0]){

		for(int i = 1; i < 9; i++) cin >> arr[i];
		
		ull B = arr[0] + arr[3] + arr[6];
		ull G = arr[1] + arr[4] + arr[7];
		ull C = arr[2] + arr[5] + arr[8];		
		
		ull op[6];
		op[0] = (B-arr[0]) + (C-arr[5]) + (G-arr[7]);  //BCG
		op[1] = (B-arr[0]) + (G-arr[4]) + (C-arr[8]);  //BGC
		op[2] = (C-arr[2]) + (B-arr[3]) + (G-arr[7]);  //CBG
		op[3] = (C-arr[2]) + (G-arr[4]) + (B-arr[6]);  //CGB
		op[4] = (G-arr[1]) + (B-arr[3]) + (C-arr[8]);  //GBC
		op[5] = (G-arr[1]) + (C-arr[5]) + (B-arr[6]);  //GCB
	
		int min = op[0];
		int idx = 0;

		for(int i = 1; i < 6; i++){
			if(min > op[i]){
				min = op[i];
				idx = i;
			}
		}

		string ans[6] = {"BCG","BGC","CBG","CGB","GBC","GCB"};

		cout << ans[idx] << " " << op[idx] << endl;
		
	}
		
	return 0;
}

