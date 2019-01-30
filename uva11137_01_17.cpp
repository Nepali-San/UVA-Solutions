#include <bits/stdc++.h>

#define ull                          unsigned long long int
#define endl                         '\n'
#define ALLONS_Y                     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

int coins[30];
ull table[10004];

int main() {
	ALLONS_Y;
	
	for(int i = 1; i <= 21; i++){
		coins[i] = i*i*i;	
	}
	
	table[0] = 1;
	for(int i = 1; i <= 21; i++){
		for(int j = coins[i]; j < 10004; j++){
			table[j] += table[j-coins[i]];
		}
	}

	int t;	
	while(cin >> t){
		cout << table[t] << endl;
	}

	return 0;
}

